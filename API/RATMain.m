function [problemStruct,result,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors)
coderEnums.initialize()

if strcmpi(problemStruct.TF, coderEnums.calculationTypes.Domains)
    domains = true;
else
    domains = false;
end

result = makeEmptyResultStruct(problemStruct.numberOfContrasts, length(problemStruct.fitParams), domains);
bayesResults = makeEmptyBayesResultsStruct(problemStruct.numberOfContrasts, domains, controls.nChains);

% Decide what we are doing....
switch controls.procedure
    case coderEnums.procedures.Calculate % Just a single reflectivity calculation
        result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);
    case coderEnums.procedures.Simplex
        if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
            fprintf('\nRunning simplex\n\n');
        end
        [problemStruct,result] = runSimplex(problemStruct,problemCells,problemLimits,controls);
    case coderEnums.procedures.DE
        if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
            fprintf('\nRunning Differential Evolution\n\n');
        end
        [problemStruct,result] = runDE(problemStruct,problemCells,problemLimits,controls);
    case coderEnums.procedures.NS
        if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
            fprintf('\nRunning Nested Sampler\n\n');
        end            
        [problemStruct,result,bayesResults] = runNestedSampler(problemStruct,problemCells,problemLimits,controls,priors);   
    case coderEnums.procedures.Dream
        if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
            fprintf('\nRunning DREAM\n\n');
        end
        [problemStruct,result,bayesResults] = runDREAM(problemStruct,problemCells,problemLimits,controls,priors);
    otherwise
        throw(exceptions.invalidOption(sprintf('procedure must be a procedures enum or one of the following strings (%s)', ...
            strjoin(procedures.values(), ', '))));
end

% Then just do a final calculation to fill in SLD if necessary
% (i.e. if calcSLD is no for fit)
if ~controls.calcSldDuringFit
    controls.calcSldDuringFit = true;
    controls.procedure = coderEnums.procedures.Calculate;
    result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);
end

end
