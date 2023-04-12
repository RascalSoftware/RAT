function [outProblem,result,bayesResults] = processBayes(output,fitNames,problem)

%problem = {problemDef ; controls ; problemDef_limits ; problemDef_cells};
problemDef = problem{1};
controls = problem{2};
problemDef_limits = problem{3};
problemDef_cells = problem{4};

parConfInts = iterShortest(output.chain,length(fitNames),[],0.95);

% 2. Find maximum values of posteriors. Store the max and mean posterior 
%    values, and calculate the best fit and SLD's from these.
[bestPars_max,posteriors] = findPosteriorsMax(output.chain);
bestPars_mean = output.results.mean;

% Calulate Max best fit curves
controls.calcSld = 1;
problemDef.fitpars = bestPars_max;
problemDef = unpackparams(problemDef,controls);
[outProblem,result] = reflectivityCalculationWrapper(problemDef,problemDef_cells,problemDef_limits,controls);
bestFitMax_Ref = result(1);
bestFitMax_Sld = result(5);
bestFitMax_chi = outProblem.calculations.sum_chi;

% Calculate 'mean' best fit curves
problemDef.fitpars = bestPars_mean;
problemDef = unpackparams(problemDef,controls);
[outProblem,result] = reflectivityCalculationWrapper(problemDef,problemDef_cells,problemDef_limits,controls);
bestFitMean_Ref = result(1);
bestFitMean_Sld = result(5);
bestFitMean_chi = outProblem.calculations.sum_chi;

% 2. Reflectivity and SLD shading
predIntRef = mcmcpred_compile(output.results,output.chain,[],output.data,problem,500);
predIntRef = predIntRef.predlims;

predIntSld_calcs = mcmcpred_compile_sld(output.results,output.chain,bestFitMean_Sld,[],output.data,problem,500);
predIntSld = predIntSld_calcs.predlims;
predIntSld_xdata = predIntSld_calcs.data;

% ---------------------------------

bayesResults.bayesRes = output.results;
bayesResults.chain = output.chain;
bayesResults.s2chain = output.s2chain;
bayesResults.sschain = output.sschain;
bayesResults.bestPars_Mean = output.results.mean;
bayesResults.bestPars_Max = bestPars_max;
bayesResults.bayesData = output.data;
bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld, bestFitMax_chi};
bayesResults.bestFitsMean = {bestFitMean_Ref, bestFitMean_Sld, bestFitMean_chi};
bayesResults.predlims = {predIntRef, predIntSld, predIntSld_xdata};
bayesResults.parConfInts = parConfInts;


end