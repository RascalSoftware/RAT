function [problemStruct,result,bayesResults] = RATMain(problemStruct,problemLimits,controls,priors)
coderEnums.initialise()

if strcmpi(problemStruct.TF, coderEnums.calculationTypes.Domains)
    domains = true;
else
    domains = false;
end

result = makeEmptyResultStruct(problemStruct.numberOfContrasts, length(problemStruct.fitParams), domains);
bayesResults = makeEmptyBayesResultsStruct(problemStruct.numberOfContrasts, domains, controls.nChains);

if problemStruct.numberOfContrasts > 0
    switch controls.procedure
        case coderEnums.procedures.Calculate % Just a single reflectivity calculation
            controls.calcSldDuringFit = true;
            result = reflectivityCalculation(problemStruct,problemLimits,controls);
        case coderEnums.procedures.Simplex
            if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning simplex\n\n'));
            end
            [problemStruct,result] = runSimplex(problemStruct,problemLimits,controls);
        case coderEnums.procedures.DE
            if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning Differential Evolution\n\n'));
            end
            [problemStruct,result] = runDE(problemStruct,problemLimits,controls);
        case coderEnums.procedures.NS
            if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning Nested Sampler\n\n'));
            end            
            [problemStruct,result,bayesResults] = runNestedSampler(problemStruct,problemLimits,controls,priors);   
        case coderEnums.procedures.Dream
            if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning DREAM\n\n'));
            end
            [problemStruct,result,bayesResults] = runDREAM(problemStruct,problemLimits,controls,priors);
        otherwise
            error('The procedure "%s" is not supported. The procedure must be one of "%s"', controls.procedure, strjoin(fieldnames(coderEnums.procedures), '", "'));
    end

    % Then just do a final calculation to fill in SLD if necessary
    % (i.e. if calcSLD is no for fit)
    if ~controls.calcSldDuringFit
        controls.calcSldDuringFit = true;
        controls.procedure = coderEnums.procedures.Calculate;
        result = reflectivityCalculation(problemStruct,problemLimits,controls);
    end

else
    error("RAT cannot proceed without at least one contrast defined in the project");
end

end
