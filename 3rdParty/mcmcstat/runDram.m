function  [problemStruct,outProblem,result,bayesResults] = runDram(problemStruct,problemCells,problemLimits,controls,allPriors)

%#codegen

%coder.varsize('problemStruct.contrastBacks',[1 Inf],[0 1]);

checks = controls.checks;
[problemStruct,fitNames] = packParams(problemStruct,problemLimits,checks);
%fitPriors = packPriors(priors,checks);

% Seed the Random Number Generator
rng(0);

%fitPriors = packPriors(priors,checks);

%First deal with priors.
prior = {};
lims = problemStruct.fitLimits;

% Preallocate params array to keep the compiler happy
params = cell(length(fitNames),1);
for i = 1:length(params)
    params{i} = cell(1,6);
end

% We have a list of 'fitPars' which is created by packParams.m
% packParams doesn't do the same for our priors however. So we need 
% to make an array of the priors for the fitted parameters 
% so that we can then build the params array for the algorithm

% Put all the priors into one array
% ** This won't work for code generation **
% priorsGroup = [priors.param ; ...
%     priors.backgroundParam ; ...
%     priors.resolutionParam ; ...
%     priors.bulkIn ; ...
%     priors.bulkOut ; ...
%     priors.qzshift ; 
%     priors.scalefactor];

% totalNumber = size(priors.param,1) + size(priors.backgroundParam,1) + ...
%     size(priors.resolutionParam,1) + size(priors.bulkIn,1) + size(priors.bulkOut,1) + ...
%     size(priors.qzshift,1) + size(priors.scalefactor,1);

% Expand the individual cells..
%allPriors = cell(totalNumber,2);    %Will be a char type....
% allPriors = strings(totalNumber,2);
% allPriorVals = cell(totalNumber,2);
% cellCount = 1;
% for i = 1:size(priors.param,1)
%     allPriors(cellCount,1) = string(priors.param{i}{1});
%     allPriors(cellCount,2) = string(priors.param{i}{2});
%     allPriorVals{cellCount,1} = priors.param{i}{3};
%     allPriorVals{cellCount,2} = priors.param{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.backgroundParam,1)
%     allPriors(cellCount,1) = priors.backgroundParam{i}{1};
%     allPriors(cellCount,2) = priors.backgroundParam{i}{2};
%     allPriorVals{cellCount,1} = priors.backgroundParam{i}{3};
%     allPriorVals{cellCount,2} = priors.backgroundParam{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.resolutionParam,1)
%     allPriors(cellCount,1) = priors.resolutionParam{i}{1};
%     allPriors(cellCount,2) = priors.resolutionParam{i}{2};
%     allPriorVals{cellCount,1} = priors.resolutionParam{i}{3};
%     allPriorVals{cellCount,2} = priors.resolutionParam{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.bulkIn,1)
%     allPriors(cellCount,1) = priors.bulkIn{i}{1};
%     allPriors(cellCount,2) = priors.bulkIn{i}{2};
%     allPriorVals{cellCount,1} = priors.bulkIn{i}{3};
%     allPriorVals{cellCount,2} = priors.bulkIn{i}{4}; 
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.bulkOut,1)
%     allPriors(cellCount,1) = priors.bulkOut{i}{1};
%     allPriors(cellCount,2) = priors.bulkOut{i}{2};
%     allPriorVals{cellCount,1} = priors.bulkOut{i}{3};
%     allPriorVals{cellCount,2} = priors.bulkOut{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.qzshift,1)
%     allPriors(cellCount,1) = priors.qzshift{i}{1};
%     allPriors(cellCount,2) = priors.qzshift{i}{2};
%     allPriorVals{cellCount,1} = priors.qzshift{i}{3};
%     allPriorVals{cellCount,2} = priors.qzshift{i}{4};
%     cellCount = cellCount + 1;
% end
% 
% for i = 1:size(priors.scalefactor,1)
%     allPriors(cellCount,1) = priors.scalefactor{i}{1};
%     allPriors(cellCount,2) = priors.scalefactor{i}{2};
%     allPriorVals{cellCount,1} = priors.scalefactor{i}{3};
%     allPriorVals{cellCount,2} = priors.scalefactor{i}{4};
%     cellCount = cellCount + 1;
% end

% Get a list of all the prior names -- we can then use this to
% find the locations of the strings in 'fitNames'
%allPriorStrings = string(allPriors);

% coder.varsize('allPriorNames',[1 Inf],[0 1]);
% allPriorNames = {allPriors{:,1}};

priorNames = allPriors.priorNames;
priorValues = allPriors.priorValues;


for i = 1:length(fitNames)
    coder.varsize('name',[1 Inf],[0 1]);
    name = fitNames{i};
    value = problemStruct.fitParams(i);
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
    
    mu = real(str2double(priorValues{parPos,2}));
    sigma = real(str2double(priorValues{parPos,3}));
    
    thisGroup = {name, value, min, max, mu, sigma};
    params{i} = thisGroup;
end


loop = controls.repeats;
nsimu =  controls.nsimu;
burnin = controls.burnin;
adaptint = 100;%controls.adaptint;

output = runBayes(loop,nsimu,burnin,adaptint,params,problem,controls);

[problemStruct,result,bayesResults] = processBayes(output,problemStruct,problemCells,problemLimits,controls);

% problemStruct.fitParams = bayesResults.bestParamsMean;


% Post processing of Bayes
% --------------------------
%
% 1. Find the iterative shortest 95% Parameter confidence intervals
% confidenceIntervals = iterShortest(output.chain,length(fitNames),[],0.95);
% 
% % 2. Find maximum values of posteriors. Store the max and mean posterior 
% %    values, and calculate the best fit and SLD's from these.
% [bestParamsMax,posteriors] = findPosteriorsMax(output.chain);
% bestParamsMean = output.results.mean;
% 
% % Calulate Max best fit curves
% problemStruct.fitParams = bestParamsMax;
% problemStruct = unpackParams(problemStruct,controls.checks);
% result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);
% bestFitMax_Ref = result.reflectivity;
% bestFitMax_Sld = result.sldProfiles;
% bestFitMax_chi = result.calculationResultss.sumChi;
% 
% % Calculate 'mean' best fit curves
% problemStruct.fitParams = bestParamsMean;
% problemStruct = unpackParams(problemStruct,controls.checks);
% result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);
% bestFitMean_Ref = result.reflectivity;
% bestFitMean_Sld = result.sldProfiles;
% bestFitMean_chi = result.calculationResultss.sumChi;
% 
% % 2. Reflectivity and SLD shading
% predIntRef = mcmcpred_compile(output.results,output.chain,[],output.data,problem,500);
% predIntRef = predIntRef.predictionIntervals;
% 
% % Make sure the calc SLD flag is set in controls...
% problem{2}.calcSldDuringFit = true;
% predIntSld = mcmcpred_compile_sld(output.results,output.chain,[],output.data,problem,500);
% predIntSld = predIntSld.predictionIntervals;
% 
% % ---------------------------------
% 
% bayesResults.bayesRes = output.results;
% bayesResults.chain = output.chain;
% bayesResults.s2chain = output.s2chain;
% bayesResults.sschain = output.sschain;
% bayesResults.bestParamsMean = output.results.mean;

% bayesResults.bestParamsMax = bestParams_max;
% bayesResults.bayesData = output.data;
% bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld, bestFitMax_chi};
% bayesResults.bestFitMean = {bestFitMean_Ref, bestFitMean_Sld, bestFitMean_chi};
% bayesResults.predictionIntervals = {predIntRef, predIntSld};
% bayesResults.confidenceIntervals = confidenceIntervals;


end
