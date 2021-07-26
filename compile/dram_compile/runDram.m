function  [problemDef,problem,result,bayesResults] = runDram(problemDef,problemDef_cells,problemDef_limits,priors,controls)

%#codegen
%coder.varsize('problemDef.contrastBacks',[1 Inf],[0 1]);


checks = controls.checks;
[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,checks);
%fitPriors = packPriors(priors,checks);

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

%params = params(:);

%prior = prior';plot(roughness,grid);

% %Tuning Parameters - fixed for now
% model.ssfun = @MCMC_Intrafun;
% 
% %prior = prior';
% %Tuning Parameters - fixed for now
% model.ssfun = @MCMC_Intrafun;
% %options.nsimu = 500;
%options.adaptInt = 100;
%options.method = 'dram';
%options.updatesigma = 0;
%options.burnInTime = 100;

loop = controls.repeats;
nsimu =  controls.nsimu;
burnin = controls.burnin;
adaptint = 100;%controls.adaptint;

problem = {problemDef ; controls ; problemDef_limits ; problemDef_cells};

res = [];
output = runBayes(loop,nsimu,burnin,adaptint,params,problem);

bayesResults.res = output.results;
bayesResults.chain = output.chain;
bayesResults.s2chain = output.s2chain;
bayesResults.sschain = output.sschain;
bayesResults.bestPars = output.bestPars;
bayesResults.bayesData = output.data;
bayesResults.bestFits = output.bestFits;
bayesResults.predlims = output.predlims;
parConfInts = iterShortest(output.chain,length(fitNames),[],0.95);
bayesResults.parConfInts = parConfInts;


problemDef.fitpars = output.bestPars;
problemDef = unpackparams(problemDef,controls);
[problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

end




