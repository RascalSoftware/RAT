function [problemStruct,result,bayesResults] = processBayes(bayesOutputs,problem)

%problem = {problemStruct ; controls ; problemLimits ; problemCells};
problemStruct = problem{1};
controlsStruct = problem{2};
problemLimits = problem{3};
problemCells = problem{4};

% Need to impose that we calculate the SLD..
controlsStruct.calcSldDuringFit = true;

%... and use the Bayes bestpars
problemStruct.fitParams = bayesOutputs.bestPars;
problemStruct = unpackParams(problemStruct,controlsStruct);
parConfInts = prctileConfInts(bayesOutputs.chain);   %iterShortest(output.chain,length(fitNames),[],0.95);

% Calculate 'mean' best fit curves
result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controlsStruct);
bestFitMean.ref = result.reflectivity;
bestFitMean.sld = result.sldProfiles;
bestFitMean.chi = result.calculationResults.sumChi;
bestFitMean.data = result.shiftedData;

% 2. Reflectivity and SLD shading
predInts = refPrctileConfInts(bayesOutputs,problemStruct,problemCells,problemLimits,controlsStruct,result,parConfInts);


% ---------------------------------


% bayesResults.chain = bayesOutputs.chain;
%bayesResults.bestPars_Max = bestPars_max;
%bayesResults.bayesData = bayesOutputs.data;
% bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld, bestFitMax_chi};
bayesResults = struct('bestFitsMean',bestFitMean,'predlims',predInts,...
                      'parConfInts',parConfInts);

% bayesResults.bestFitsMean = bestFitMean;
% bayesResults.predlims = allPredInts;
% bayesResults.parConfInts = parConfInts;
% bayesResults.bestPars = bayesOutputs.bestPars;

end