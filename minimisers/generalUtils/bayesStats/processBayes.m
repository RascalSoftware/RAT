function [problemDef,outProblem,result,bayesResults] = processBayes(bayesOutputs,allProblem)

%problem = {problemDef ; controls ; problemDefLimits ; problemDefCells};
problemDef = allProblem{1};
controlsStruct = allProblem{2};
problemDefLimits = allProblem{3};
problemDefCells = allProblem{4};

% Need to impose that we calculate the SLD..
controlsStruct.calcSldDuringFit = true;

%... and use the Bayes bestpars
problemDef.fitpars = bayesOutputs.bestPars;
problemDef = unpackParams(problemDef,controlsStruct);
parConfInts = prctileConfInts(bayesOutputs.chain);   %iterShortest(output.chain,length(fitNames),[],0.95);

% % 2. Find maximum values of posteriors. Store the max and mean posterior 
% %    values, and calculate the best fit and SLD's from these.
% [bestPars_max,posteriors] = findPosteriorsMax(output.chain);
% bestPars_mean = output.results.mean;

% % Calculate Max best fit curves
% controls.calcSldDuringFit = true;
% problemDef.fitpars = bestPars_max;
% problemDef = unpackParams(problemDef,controls);
% [outProblem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);
% bestFitMax_Ref = result(1);
% bestFitMax_Sld = result(5);
% bestFitMax_chi = outProblem.calculations.sum_chi;

% Calculate 'mean' best fit curves
% problemDef.fitpars = parConfInts.mean;
% problemDef = unpackParams(problemDef,controlsStruct);
[outProblem,result] = reflectivityCalculation(problemDef,problemDefCells,controlsStruct);
p = parseResultToStruct(outProblem,result);
bestFitMean.ref = p.reflectivity;
bestFitMean.sld = p.sldProfiles;
bestFitMean.chi = p.calculationResults.sum_chi;
bestFitMean.data = p.shifted_data;

% 2. Reflectivity and SLD shading

% predIntRef = mcmcpred_compile(output.results,output.chain,[],output.data,problem,500);
% predIntRef = predIntRef.predlims;
% 
% predIntSld_calcs = mcmcpred_compile_sld(output.results,output.chain,bestFitMean_Sld,[],output.data,problem,500);
% predIntSld = predIntSld_calcs.predlims;
% predIntSld_xdata = predIntSld_calcs.data;

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