function  [problemDef,bayesResults] = runDram_r1Mod(problemDef,problemDef_cells,problemDef_limits,priors,controls)

%#codegen

checks = controls.checks;
[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,checks);
%fitPriors = packPriors(priors,checks);

% Seed the Random Number Generator
rng(0);

lims = problemDef.fitconstr;

% Preallocate params array to keep the compiler happy
params = cell(length(fitNames),1);
for i = 1:length(params)
    params{i} = cell(1,6);
end

% We have a list of 'fitPars' which is created by packparams.m
% packparams doesn't do the same for our priors however. So we need 
% to do the same thing for our priors and extract the relevant ones
% so that we can build the params array for the algorithm


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
adaptint = 100;

% All the parameters are required for 'reflectivity_calculation', so group
% these together int a cell array for easy passing around
problem = {problemDef ; controls ; problemDef_limits ; problemDef_cells};

res = [];
output = runBayes_r1Mod(loop,nsimu,burnin,adaptint,params,problem);

bayesResults.res = output.results;
bayesResults.chain = output.chain;
bayesResults.s2chain = output.s2chain;
bayesResults.sschain = output.sschain;

% --------------------------------------------------------------
% 
%  Bayes ppst-processing
%
% ------------------------------------------------------


% % Calculate the 95% confidence intervals on the parameters
% parConfInts = iterShortest(output.chain,length(fitNames),[],0.95);
% bayesResults.parConfInts = parConfInts;
% 
% % Now use the R1 method for finding best pars as the max of the posteriors
% [bestPars_max,posteriors] = processPosterors(output);
% bayesResults.bestPars = bestPars_max;
% bayesResults.posteriors = posteriors;
% 
% problemDef.fitpars = bestPars_max;
% problemDef = unpackparams(problemDef,controls);
% [problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);
% 
% % result{1} = Simulation
% % result{2} = shifted_data;
% % result{5} = sld profiles
% 
% 
% % Calculate the best fits..
% 
% 
% 
% % Work out the 95% confidence intervals on the reflectivity and SLD




end




