function [problemStruct,results,bayesResults] = RATMain(problemStruct,problemLimits,controls)

    % Adds C struct names for inputs
    coder.cstructname(problemStruct.names, 'ParamNames');
    coder.cstructname(problemStruct.checks, 'CheckFlags');
    coder.cstructname(problemStruct, 'ProblemDefinition');
    coder.cstructname(controls, 'Controls');
    coder.cstructname(problemLimits,'ProblemLimits');
    
    coderEnums.initialise()
    
    if strcmpi(problemStruct.TF, coderEnums.calculationTypes.Domains)
        domains = true;
    else
        domains = false;
    end
    
    results = makeEmptyResultStruct(problemStruct.numberOfContrasts, length(problemStruct.fitParams), domains);
    bayesResults = makeEmptyBayesResultsStruct(problemStruct.numberOfContrasts, domains, controls.nChains);
    
    if problemStruct.numberOfContrasts > 0
        switch controls.procedure
            case coderEnums.procedures.Calculate % Just a single reflectivity calculation
                controls.calcSldDuringFit = true;
                results = reflectivityCalculation(problemStruct,controls);
            case coderEnums.procedures.Simplex
                if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                    triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning simplex\n\n'));
                end
                [problemStruct,results] = runSimplex(problemStruct,problemLimits,controls);
            case coderEnums.procedures.DE
                if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                    triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning Differential Evolution\n\n'));
                end
                [problemStruct,results] = runDE(problemStruct,problemLimits,controls);
            case coderEnums.procedures.NS
                if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                    triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning Nested Sampler\n\n'));
                end            
                [problemStruct,results,bayesResults] = runNestedSampler(problemStruct,problemLimits,controls);   
            case coderEnums.procedures.Dream
                if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                    triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning DREAM\n\n'));
                end
                [problemStruct,results,bayesResults] = runDREAM(problemStruct,problemLimits,controls);
            otherwise
                coderException(coderEnums.errorCodes.invalidOption, 'The procedure "%s" is not supported. The procedure must be one of "%s"', controls.procedure, strjoin(fieldnames(coderEnums.procedures), '", "'));
        end
    
        % Then just do a final calculation to fill in SLD if necessary
        % (i.e. if calcSLD is no for fit)
        if ~controls.calcSldDuringFit
            controls.calcSldDuringFit = true;
            results = reflectivityCalculation(problemStruct,controls);
        end
    
    else
        coderException(coderEnums.errorCodes.domainError, 'RAT cannot proceed without at least one contrast defined in the project');
    end
    
    % Adds C struct names for outputs
    coder.cstructname(results.calculationResults, 'CalculationResults');
    coder.cstructname(results.contrastParams, 'ContrastParams');
    coder.cstructname(results, 'Results');
    coder.cstructname(bayesResults.predictionIntervals, 'PredictionIntervals');
    coder.cstructname(bayesResults.confidenceIntervals, 'ConfidenceIntervals');
    coder.cstructname(bayesResults.dreamParams, 'DreamParams');
    coder.cstructname(bayesResults.dreamOutput, 'DreamOutput');
    coder.cstructname(bayesResults.nestedSamplerOutput, 'NestedSamplerOutput');
    coder.cstructname(bayesResults, 'BayesResults');
    
end
