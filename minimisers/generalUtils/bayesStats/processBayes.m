function [problemStruct,result,bayesResults] = processBayes(bayesOutputs,problemStruct,controls)

% Need to impose that we calculate the SLD..
controls.calcSldDuringFit = true;

% ... and use the Bayes best params
problemStruct.fitParams = bayesOutputs.bestParams;
problemStruct = unpackParams(problemStruct);
confidenceIntervals = percentileConfidenceIntervals(bayesOutputs.chain);   %iterShortest(output.chain,length(fitNames),[],0.95);

% Calculate 'mean' best fit curves
result = reflectivityCalculation(problemStruct,controls);

% 2. Reflectivity and SLD shading
predInts = refPercentileConfidenceIntervals(bayesOutputs,problemStruct,controls,result);

% ---------------------------------

% bayesResults.chain = bayesOutputs.chain;
bayesResults = struct('predictionIntervals',predInts,...
                      'confidenceIntervals',confidenceIntervals);

end
