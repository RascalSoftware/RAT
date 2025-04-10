function [problemStruct,results,bayesResults] = RATMain(problemStruct,controls)
  % Select and run the internal RAT procedure.
  %
  % Parameters
  % ----------
  % problemStruct : struct
  %     The project class in struct form (generated from parseClassToStructs)
  % controls : struct
  %     The controls struct (generated from parseClassToStructs)
  % 
  % Returns
  % -------
  % problemStruct : struct
  %     The output problem struct.
  % results : struct
  %     The calculation results.
  % bayesResults : struct
  %     Additional results from a Bayesian calculation.

    % Adds C struct names for inputs
    coder.cstructname(problemStruct.names, 'ParamNames');
    coder.cstructname(problemStruct.checks, 'CheckFlags');
    coder.cstructname(problemStruct, 'ProblemDefinition');
    coder.cstructname(controls, 'Controls');
    
    coderEnums.initialise()
    
    if strcmpi(problemStruct.TF, coderEnums.calculationTypes.Domains)
        domains = true;
    else
        domains = false;
    end
    
    results = makeEmptyResultStruct(problemStruct.numberOfContrasts, length(problemStruct.fitParams), domains);
    bayesResults = makeEmptyBayesResultsStruct(problemStruct.numberOfContrasts, domains, controls.nChains);

    % Set controls.calcSLD to 1 if we are doing customXY
    if strcmpi(problemStruct.modelType, coderEnums.modelTypes.CustomXY)
        controls.calcSldDuringFit = true;
    end

    if problemStruct.numberOfContrasts > 0
        switch controls.procedure
            case coderEnums.procedures.Calculate % Just a single reflectivity calculation
                controls.calcSldDuringFit = true;
                results = reflectivityCalculation(problemStruct,controls);
            case coderEnums.procedures.Simplex
                if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                    triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning simplex\n\n'));
                end
                [problemStruct,results] = runSimplex(problemStruct,controls);
            case coderEnums.procedures.DE
                if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                    triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning Differential Evolution\n\n'));
                end
                [problemStruct,results] = runDE(problemStruct,controls);
            case coderEnums.procedures.NS
                if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                    triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning Nested Sampler\n\n'));
                end            
                [problemStruct,results,bayesResults] = runNestedSampler(problemStruct,controls);   
            case coderEnums.procedures.Dream
                if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
                    triggerEvent(coderEnums.eventTypes.Message, sprintf('\nRunning DREAM\n\n'));
                end
                [problemStruct,results,bayesResults] = runDREAM(problemStruct,controls);
            otherwise
                coderException(coderEnums.errorCodes.invalidOption, 'The procedure "%s" is not supported. The procedure must be one of "%s"', controls.procedure, strjoin(fieldnames(coderEnums.procedures), '", "'));
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
