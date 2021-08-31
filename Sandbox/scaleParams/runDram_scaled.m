function  [problemDef,outProblem,result,bayesResults] = runDram_scaled(problemDef,problemDef_cells,problemDef_limits,priors,controls)

% Version of runDram that uses scaled parameters. Scaling and unscaling
% happens downstream in 'runBayes_scaled'.


%#codegen
%coder.varsize('problemDef.contrastBacks',[1 Inf],[0 1]);

% Get the fitpars out of problemDef
checks = controls.checks;
[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,checks);

% Seed the Random Number Generator
rng(0);

%fitPriors = packpriors(priors,checks);

%First deal with priors.
%Make uniform priors from the
%min/max limits for now.
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
allPriors = [priors.paramPriors ; ...
    priors.backsPriors ; ...
    priors.resolPriors ; ...
    priors.nbaPriors ; ...
    priors.nbsPriors ; ...
    priors.shiftPriors ; 
    priors.scalesPriors];

% Get a list of all the prior names -- we can then use this to
% find the locations of the strings in 'fitNames'
allPriorNames = allPriors(:,1);

for i = 1:length(fitNames)
    name = fitNames{i};
    value = problemDef.fitpars(i);
    min = lims(i,1);
    max = lims(i,2);
    
    % Find this parameter in the priors list
    parPos = find(strcmp(allPriorNames,name));
    
    if isempty(parPos)
        error('Can"t find this fitting parameter');
    end
    
    mu = allPriors{parPos,3};
    sigma = allPriors{parPos,4};
    
    thisGroup = {name, value, min, max, mu, sigma};
    params{i} = thisGroup;
end


loop = controls.repeats;
nsimu =  controls.nsimu;
burnin = controls.burnin;
adaptint = 100;%controls.adaptint;

problem = {problemDef ; controls ; problemDef_limits ; problemDef_cells};

output = runBayes_scaled(loop,nsimu,burnin,adaptint,params,problem);

% Post processing of Bayes
% --------------------------
%
% 1. Find the iterative shortest 95% Parameter confidence intervals
parConfInts = iterShortest(output.chain,length(fitNames),[],0.95);

% 2. Find maximum values of posteriors. Store the max and mean posterior 
%    values, and calculate the best fit and SLD's from these.
[bestPars_max,posteriors] = findPosteriorsMax(output.chain);
bestPars_mean = output.results.mean;

% Calulate Max best fit curves
problemDef.fitpars = bestPars_max;
problemDef = unpackparams(problemDef,controls);
[~,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);
bestFitMax_Ref = result(1);
bestFitMax_Sld = result(5);

% Calculate 'mean' best fit curves
problemDef.fitpars = bestPars_mean;
problemDef = unpackparams(problemDef,controls);
[outProblem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);
bestFitMean_Ref = result(1);
bestFitMean_Sld = result(5);

% 2. Reflectivity and SLD shading
predIntRef = mcmcpred_compile(output.results,output.chain,[],output.data,problem,500);
predIntRef = predIntRef.predlims;

% Make sure the calc SLD flag is set in controls...
problem{2}.calcSld = 1;
predIntSld = mcmcpred_compile_sld(output.results,output.chain,[],output.data,problem,500);
predIntSld = predIntSld.predlims;

% ---------------------------------

bayesResults.bayesRes = output.results;
bayesResults.chain = output.chain;
bayesResults.s2chain = output.s2chain;
bayesResults.sschain = output.sschain;
bayesResults.bestPars_Mean = output.results.mean;
bayesResults.bestPars_Max = bestPars_max;
bayesResults.bayesData = output.data;
bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld};
bayesResults.bestFitsMean = {bestFitMean_Ref, bestFitMean_Sld};
bayesResults.predlims = {predIntRef, predIntSld};
bayesResults.parConfInts = parConfInts;


end




