function [problemStruct,result,bayesResults] = processBayes(bayesOutputs,problemStruct,controls)
% Process the output of a Bayesian optimisation.
%
% Parameters
% ----------
% bayesOutputs : struct
%     The outputs of the Bayesian optimisation.
% problemStruct : struct
%     The struct for the project.
% controls : struct
%     The struct for the controls.
%
% Returns
% -------
% problemStruct : struct
%     The struct for the output project.
% result : struct
%     The results object from the optimisation.
% bayesResults : struct
%     The Bayesian-specific results from the optimisation.

% Need to impose that we calculate the SLD..
controls.calcSldDuringFit = true;

% ... and use the Bayes best params
problemStruct.fitParams = bayesOutputs.bestParams;
problemStruct = unpackParams(problemStruct);
confidenceIntervals = percentileConfidenceIntervals(bayesOutputs.chain);

% Calculate 'mean' best fit curves
result = reflectivityCalculation(problemStruct,controls);

% 2. Reflectivity and SLD shading
predInts = refPercentileConfidenceIntervals(bayesOutputs,problemStruct,controls,result);

% ---------------------------------

% bayesResults.chain = bayesOutputs.chain;
bayesResults = struct('predictionIntervals',predInts,...
                      'confidenceIntervals',confidenceIntervals);

end
