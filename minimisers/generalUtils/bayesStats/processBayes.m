function [problemDef,outProblem,result,bayesResults] = processBayes(bayesOutputs,allProblem)

%problem = {problemDef ; controls ; problemDefLimits ; problemDefCells};
problemDef = allProblem{1};
controlsStruct = allProblem{2};
problemDefLimits = allProblem{3};
problemDefCells = allProblem{4};

% Need to impose that we calculate the SLD..
controlsStruct.calcSldDuringFit = true;

%... and use the Bayes bestpars
problemDef.fitParams = bayesOutputs.bestPars;
problemDef = unpackParams(problemDef,controlsStruct);
parConfInts = prctileConfInts(bayesOutputs.chain);   %iterShortest(output.chain,length(fitNames),[],0.95);

% Calculate 'mean' best fit curves
[outProblem,result] = reflectivityCalculation(problemDef,problemDefCells,controlsStruct);
p = parseResultToStruct(outProblem,result);
bestFitMean.ref = p.reflectivity;
bestFitMean.sld = p.sldProfiles;
bestFitMean.chi = p.calculationResults.sumChi;
bestFitMean.data = p.shiftedData;

% 2. Reflectivity and SLD shading
allPredInts = refPrctileConfInts(bayesOutputs,problemDef,problemDefCells,problemDefLimits,controlsStruct,result,parConfInts);


% ---------------------------------


% bayesResults.chain = bayesOutputs.chain;
%bayesResults.bestPars_Max = bestPars_max;
%bayesResults.bayesData = bayesOutputs.data;
% bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld, bestFitMax_chi};
bayesResults = struct('bestFitsMean',bestFitMean,'predlims',allPredInts,...
                      'parConfInts',parConfInts);

% bayesResults.bestFitsMean = bestFitMean;
% bayesResults.predlims = allPredInts;
% bayesResults.parConfInts = parConfInts;
% bayesResults.bestPars = bayesOutputs.bestPars;

end