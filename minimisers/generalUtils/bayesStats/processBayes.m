function [problemStruct,result,bayesResults] = processBayes(bayesOutputs,problemStruct,problemCells,problemLimits,controls)

% Need to impose that we calculate the SLD..
controls.calcSldDuringFit = true;

%... and use the Bayes best params
problemStruct.fitParams = bayesOutputs.bestParams;
problemStruct = unpackParams(problemStruct,controls);
confidenceIntervals = percentileConfidenceIntervals(bayesOutputs.chain);   %iterShortest(output.chain,length(fitNames),[],0.95);

% Calculate 'mean' best fit curves
result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);
bestFitMean.reflectivity = result.reflectivity;
bestFitMean.sld = result.sldProfiles;
bestFitMean.chi = result.calculationResults.sumChi;
bestFitMean.data = result.shiftedData;

% 2. Reflectivity and SLD shading
predInts = refPercentileConfidenceIntervals(bayesOutputs,problemStruct,problemCells,problemLimits,controls);

% ---------------------------------


% bayesResults.chain = bayesOutputs.chain;
bayesResults = struct('bestFitMean',bestFitMean,'predictionIntervals',predInts,...
                      'confidenceIntervals',confidenceIntervals);

end
