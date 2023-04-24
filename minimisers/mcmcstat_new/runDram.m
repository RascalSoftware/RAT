function  [problemDef,outProblem,result,bayesResults] = runDram(problemDef,problemDefCells,problemDefLimits,controls,allPriors)

%#codegen

%coder.varsize('problemDef.contrastBacks',[1 Inf],[0 1]);

checks = controls.checks;
[problemDef,fitNames] = packparams(problemDef,problemDefCells,problemDefLimits,checks);
%fitPriors = packPriors(priors,checks);

% Seed the Random Number Generator
rng(0);

%fitPriors = packpriors(priors,checks);

%First deal with priors.
prior = {};
lims = problemDef.fitconstr;

% Preallocate params array to keep the compiler happy
params = cell(length(fitNames),1);
for i = 1:length(params)
    params{i} = cell(1,6);
end

% We have a list of 'fitPars' which is created by packparams.m
% packparams doesn't do the same for our priors however. So we need 
% to make an array of the priors for the fitted parameters 
% so that we can then build the params array for the algorithm

% Put all the priors into one array
% ** This won't work for code generation **
% priorsGroup = [priors.paramPriors ; ...
%     priors.backsPriors ; ...
%     priors.resolPriors ; ...
%     priors.nbaPriors ; ...
%     priors.nbsPriors ; ...
%     priors.shiftPriors ; 
%     priors.scalesPriors];

% totalNumber = size(priors.paramPriors,1) + size(priors.backsPriors,1) + ...
%     size(priors.resolPriors,1) + size(priors.nbaPriors,1) + size(priors.nbsPriors,1) + ...
%     size(priors.shiftPriors,1) + size(priors.scalesPriors,1);

% Expand the individual cells..
%allPriors = cell(totalNumber,2);    %Will be a char type....
% allPriors = strings(totalNumber,2);
% allPriorVals = cell(totalNumber,2);
% cellCount = 1;
% for i = 1:size(priors.paramPriors,1)
%     allPriors(cellCount,1) = string(priors.paramPriors{i}{1});
%     allPriors(cellCount,2) = string(priors.paramPriors{i}{2});
%     allPriorVals{cellCount,1} = priors.paramPriors{i}{3};
%     allPriorVals{cellCount,2} = priors.paramPriors{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.backsPriors,1)
%     allPriors(cellCount,1) = priors.backsPriors{i}{1};
%     allPriors(cellCount,2) = priors.backsPriors{i}{2};
%     allPriorVals{cellCount,1} = priors.backsPriors{i}{3};
%     allPriorVals{cellCount,2} = priors.backsPriors{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.resolPriors,1)
%     allPriors(cellCount,1) = priors.resolPriors{i}{1};
%     allPriors(cellCount,2) = priors.resolPriors{i}{2};
%     allPriorVals{cellCount,1} = priors.resolPriors{i}{3};
%     allPriorVals{cellCount,2} = priors.resolPriors{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.nbaPriors,1)
%     allPriors(cellCount,1) = priors.nbaPriors{i}{1};
%     allPriors(cellCount,2) = priors.nbaPriors{i}{2};
%     allPriorVals{cellCount,1} = priors.nbaPriors{i}{3};
%     allPriorVals{cellCount,2} = priors.nbaPriors{i}{4}; 
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.nbsPriors,1)
%     allPriors(cellCount,1) = priors.nbsPriors{i}{1};
%     allPriors(cellCount,2) = priors.nbsPriors{i}{2};
%     allPriorVals{cellCount,1} = priors.nbsPriors{i}{3};
%     allPriorVals{cellCount,2} = priors.nbsPriors{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.shiftPriors,1)
%     allPriors(cellCount,1) = priors.shiftPriors{i}{1};
%     allPriors(cellCount,2) = priors.shiftPriors{i}{2};
%     allPriorVals{cellCount,1} = priors.shiftPriors{i}{3};
%     allPriorVals{cellCount,2} = priors.shiftPriors{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.scalesPriors,1)
%     allPriors(cellCount,1) = priors.scalesPriors{i}{1};
%     allPriors(cellCount,2) = priors.scalesPriors{i}{2};
%     allPriorVals{cellCount,1} = priors.scalesPriors{i}{3};
%     allPriorVals{cellCount,2} = priors.scalesPriors{i}{4};
%     cellCount = cellCount + 1;
% end

% Get a list of all the prior names -- we can then use this to
% find the locations of the strings in 'fitNames'
%allPriorStrings = string(allPriors);

% coder.varsize('allPriorNames',[1 Inf],[0 1]);
% allPriorNames = {allPriors{:,1}};

priorNames = allPriors.priorNames;
priorVals = allPriors.priorVals;


for i = 1:length(fitNames)
    coder.varsize('name',[1 Inf],[0 1]);
    name = fitNames{i};
    value = problemDef.fitpars(i);
    min = lims(i,1);
    max = lims(i,2);
    
    % Find this parameter in the priors list
    parPos = find(strcmp(priorNames,name));
    
%     coder.varsize('newPos',[1,1],[0,0]);
%     newPos = 1;
%     if length(parPos) > 1
%         newPos = parPos(1);
%     elseif isempty(parPos)
%         newPos = 1;
%     end
    
%     if isempty(parPos) || length(parPos) > 1
%         error('Can"t identify this fitting parameter');
%     end
    
    mu = real(str2double(priorVals{parPos,2}));
    sigma = real(str2double(priorVals{parPos,3}));
    
    thisGroup = {name, value, min, max, mu, sigma};
    params{i} = thisGroup;
end


loop = controls.repeats;
nsimu =  controls.nsimu;
burnin = controls.burnin;
adaptint = 100;%controls.adaptint;

problem = {problemDef ; controls ; problemDefLimits ; problemDefCells};

output = runBayes(loop,nsimu,burnin,adaptint,params,problem,controls);

[problemDef,outProblem,result,bayesResults] = processBayes_newMethod(output,problem);

% problemDef.fitpars = bayesResults.bestPars_Mean;


% Post processing of Bayes
% --------------------------
%
% 1. Find the iterative shortest 95% Parameter confidence intervals
% parConfInts = iterShortest(output.chain,length(fitNames),[],0.95);
% 
% % 2. Find maximum values of posteriors. Store the max and mean posterior 
% %    values, and calculate the best fit and SLD's from these.
% [bestPars_max,posteriors] = findPosteriorsMax(output.chain);
% bestPars_mean = output.results.mean;
% 
% % Calulate Max best fit curves
% problemDef.fitpars = bestPars_max;
% problemDef = unpackparams(problemDef,controls);
% [outProblem,result] = reflectivityCalculationWrapper(problemDef,problemDefCells,problemDefLimits,controls);
% bestFitMax_Ref = result(1);
% bestFitMax_Sld = result(5);
% bestFitMax_chi = outProblem.calculations.sum_chi;
% 
% % Calculate 'mean' best fit curves
% problemDef.fitpars = bestPars_mean;
% problemDef = unpackparams(problemDef,controls);
% [outProblem,result] = reflectivityCalculationWrapper(problemDef,problemDefCells,problemDefLimits,controls);
% bestFitMean_Ref = result(1);
% bestFitMean_Sld = result(5);
% bestFitMean_chi = outProblem.calculations.sum_chi;
% 
% % 2. Reflectivity and SLD shading
% predIntRef = mcmcpred_compile(output.results,output.chain,[],output.data,problem,500);
% predIntRef = predIntRef.predlims;
% 
% % Make sure the calc SLD flag is set in controls...
% problem{2}.calcSld = 1;
% predIntSld = mcmcpred_compile_sld(output.results,output.chain,[],output.data,problem,500);
% predIntSld = predIntSld.predlims;
% 
% % ---------------------------------
% 
% bayesResults.bayesRes = output.results;
% bayesResults.chain = output.chain;
% bayesResults.s2chain = output.s2chain;
% bayesResults.sschain = output.sschain;
% bayesResults.bestPars_Mean = output.results.mean;

% bayesResults.bestPars_Max = bestPars_max;
% bayesResults.bayesData = output.data;
% bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld, bestFitMax_chi};
% bayesResults.bestFitsMean = {bestFitMean_Ref, bestFitMean_Sld, bestFitMean_chi};
% bayesResults.predlims = {predIntRef, predIntSld};
% bayesResults.parConfInts = parConfInts;


end
