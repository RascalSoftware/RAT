function [problemStruct,result,bayesResults] = processBayes(bayesOutputs,problemStruct,problemCells,problemLimits,controls)

% Need to impose that we calculate the SLD..
controls.calcSldDuringFit = true;

%... and use the Bayes best params
problemStruct.fitParams = bayesOutputs.bestParams;
problemStruct = unpackParams(problemStruct,controls);
confidenceIntervals = prctileConfInts(bayesOutputs.chain);   %iterShortest(output.chain,length(fitNames),[],0.95);

% Calculate 'mean' best fit curves
result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);
bestFitMean.reflectivity = result.reflectivity;
bestFitMean.sld = result.sldProfiles;
bestFitMean.chi = result.calculationResults.sumChi;
bestFitMean.data = result.shiftedData;

% 2. Reflectivity and SLD shading
predInts = refPrctileConfInts(bayesOutputs,problemStruct,problemCells,problemLimits,controlsStruct,result,parConfInts);

% ---------------------------------


% bayesResults.chain = bayesOutputs.chain;
%bayesResults.bestParams_Max = bestParams_max;
%bayesResults.bayesData = bayesOutputs.data;
% bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld, bestFitMax_chi};
bayesResults = struct('bestFitMean',bestFitMean,'predictionIntervals',predInts,...
                      'confidenceIntervals',confidenceIntervals);

% bayesResults.bestFitMean = bestFitMean;
% bayesResults.predictionIntervals = allPredInts;
% bayesResults.confidenceIntervals = confidenceIntervals;
% bayesResults.bestParams = bayesOutputs.bestParams;

end
