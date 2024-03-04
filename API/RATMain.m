function [problemStruct,result,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors)
coderEnums.initialize()
if strcmpi(problemStruct.TF,'domains')
    domains = true;
else
    domains = false;
end

result = makeEmptyResultStruct(problemStruct.numberOfContrasts, length(problemStruct.fitParams), domains);
bayesResults = makeEmptyBayesResultsStruct(problemStruct.numberOfContrasts, domains, controls.nChains);

% Decide what we are doing....
switch lower(controls.procedure)
    case 'calculate' % Just a single reflectivity calculation
        result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning simplex\n\n');
        end
        [problemStruct,result] = runSimplex(problemStruct,problemCells,problemLimits,controls);
    case 'de'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning Differential Evolution\n\n');
        end
        [problemStruct,result] = runDE(problemStruct,problemCells,problemLimits,controls);
    case 'ns'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning Nested Sampler\n\n');
        end            
        [problemStruct,result,bayesResults] = runNestedSampler(problemStruct,problemCells,problemLimits,controls,priors);   
    case 'dream'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning DREAM\n\n');
        end
        [problemStruct,result,bayesResults] = runDREAM(problemStruct,problemCells,problemLimits,controls,priors);
end

% Then just do a final calculation to fill in SLD if necessary
% (i.e. if calcSLD is no for fit)
if ~controls.calcSldDuringFit
    controls.calcSldDuringFit = true;
    controls.procedure = 'calculate';
    result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);
end

end
