function [problemDefStruct,problem,resultCells,bayesResults] = RATMain(problemDefStruct,problemDefCells,problemDefLimits,controls,priors)

result = cell(1,1);
result{1} = {1};
resultCells = repmat(result,1,6);

numberOfContrasts = problemDefStruct.numberOfContrasts;
preAlloc = zeros(numberOfContrasts,1);

problem = struct('ssubs',preAlloc,...
                 'backgroundParams',preAlloc,...
                 'qzshifts',preAlloc,...
                 'scalefactors',preAlloc,...
                 'bulkIn',preAlloc,...
                 'bulkOut',preAlloc,...
                 'resolutionParams',preAlloc,...
                 'calculations',struct('allChis',preAlloc,'sumChi',0),...
                 'allSubRough',preAlloc,...
                 'resample',preAlloc);

if strcmpi(problemDefStruct.TF,'domains')
    domains = true;
else
    domains = false;
end

bayesResults = makeEmptyBayesResultsStruct(1e3, problemDefStruct.numberOfContrasts, domains, controls.nChains);

%Decide what we are doing....
switch lower(controls.procedure)
    case 'calculate' %Just a single reflectivity calculation
        [problem,resultCells] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning simplex\n\n');
        end
        [problemDefStruct,problem,resultCells] = runSimplex(problemDefStruct,problemDefCells,problemDefLimits,controls);
    case 'de'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning Differential Evolution\n\n');
        end
        [problemDefStruct,problem,resultCells] = runDE(problemDefStruct,problemDefCells,problemDefLimits,controls);
    case 'ns'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning Nested Sampler\n\n');
        end            
        [problemDefStruct,problem,resultCells,bayesResults] = runNestedSampler(problemDefStruct,problemDefCells,problemDefLimits,controls,priors);   
    case 'dream'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning DREAM\n\n');
        end
        [problemDefStruct,problem,resultCells,bayesResults] = runDREAM(problemDefStruct,problemDefCells,problemDefLimits,controls,priors);
end

% Then just do a final calculation to fill in SLD if necessary
% (i.e. if calcSLD is no for fit)
if ~controls.calcSldDuringFit
    controls.calcSldDuringFit = true;
    controls.procedure = 'calculate';
    [problem,resultCells] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);
end

end