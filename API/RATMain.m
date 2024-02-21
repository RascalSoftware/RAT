function [problemStruct,result,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors)

resultCell = cell(1,1);
resultCell{1} = {1};
resultCells = repmat(resultCell,1,6);

numberOfContrasts = problemStruct.numberOfContrasts;
preAlloc = zeros(numberOfContrasts,1);

contrastParams = struct('ssubs',preAlloc, ...
                        'backgroundParams',preAlloc,...
                        'qzshifts',preAlloc,...
                        'scalefactors',preAlloc,...
                        'bulkIn',preAlloc,...
                        'bulkOut',preAlloc,...
                        'resolutionParams',preAlloc,...
                        'calculations',struct('allChis',preAlloc,'sumChi',0),...
                        'allSubRough',preAlloc,...
                        'resample',preAlloc);

if strcmpi(problemStruct.TF,'domains')
    domains = true;
else
    domains = false;
end

bayesResults = makeEmptyBayesResultsStruct(1.0e3, problemStruct.numberOfContrasts, domains, controls.nChains);

%Decide what we are doing....
switch lower(controls.procedure)
    case 'calculate' %Just a single reflectivity calculation
        [contrastParams,resultCells] = reflectivityCalculation(problemStruct,problemCells,controls);
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning simplex\n\n');
        end
        [problemStruct,contrastParams,resultCells] = runSimplex(problemStruct,problemCells,problemLimits,controls);
    case 'de'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning Differential Evolution\n\n');
        end
        [problemStruct,contrastParams,resultCells] = runDE(problemStruct,problemCells,problemLimits,controls);
    case 'ns'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning Nested Sampler\n\n');
        end            
        [problemStruct,contrastParams,resultCells,bayesResults] = runNestedSampler(problemStruct,problemCells,problemLimits,controls,priors);   
    case 'dream'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning DREAM\n\n');
        end
        [problemStruct,contrastParams,resultCells,bayesResults] = runDREAM(problemStruct,problemCells,problemLimits,controls,priors);
end

% Then just do a final calculation to fill in SLD if necessary
% (i.e. if calcSLD is no for fit)
if ~controls.calcSldDuringFit
    controls.calcSldDuringFit = true;
    controls.procedure = 'calculate';
    [contrastParams,resultCells] = reflectivityCalculation(problemStruct,problemCells,controls);
end

% Construct the result struct
[~,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);
result = parseResultToStruct(contrastParams,resultCells,problemStruct.fitParams,fitNames);

end
