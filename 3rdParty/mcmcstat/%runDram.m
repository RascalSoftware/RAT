function  [problemDef,problem,result,bayesResults] = runDram(problemDef,problemDefCells,problemDefLimits,priors,controls)
debug = 0;

checks = controls.checks;
[problemDef,fitNames] = packParams(problemDef,problemDefCells,problemDefLimits,checks);
%fitPriors = packPriors(priors,checks);

% Seed the Random Number Generator
rng(0);


%fitPriors = packPriors(priors,checks);

%First deal with priors.
%Make uniform priors from the
%min/max limits for now.
prior = {};
lims = problemDef.fitconstr;
% Get the li

for i = 1:length(fitNames)
    name = fitNames{i};
    value = problemDef.fitpars(i);
    min = lims(i,1);
    max = lims(i,2);
    mu = 0;
    sigma = Inf;
    thisGroup = {name, value, min, max, mu, sigma};
    params{i} = thisGroup;
end

params = params(:);

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

problem = {problemDef ; controls ; problemDefLimits ; problemDefCells};

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

problemDef.fitpars = output.bestPars;
problemDef = unpackParams(problemDef,controls);
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);

% Pre-processor directives for Matlab Coder.
coder.varsize('problem.ssubs',[Inf 1],[1 0]);
coder.varsize('problem.backgroundParams',[Inf 1],[1 0]);
coder.varsize('problem.qzshifts',[Inf 1],[1 0]);
coder.varsize('problem.scalefactors',[Inf 1],[1 0]);
coder.varsize('problem.bulkIn',[Inf 1],[1 0]);
coder.varsize('problem.bulkOut',[Inf 1],[1 0]);
coder.varsize('problem.resolutionParams',[Inf 1],[1 0]);
coder.varsize('problem.ssubs',[Inf 1],[1 0]);
coder.varsize('problem.calculations.allChis',[Inf 1],[1 0]);
coder.varsize('problem.calculations.sumChi',[1 1],[0 0]);
coder.varsize('problem.allSubRough',[Inf 1],[1 0]);

%Result coder definitions....
coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity
coder.varsize('result{1}{:}',[Inf 2],[1 0]);

coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin
coder.varsize('result{2}{:}',[Inf 2],[1 0]);

coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data
coder.varsize('result{3}{:}',[Inf 3],[1 0]);

coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds
coder.varsize('result{4}{:}',[Inf 3],[1 0]);

coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles
coder.varsize('result{5}{:}',[Inf 2],[1 0]);

coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers
coder.varsize('result{6}{:}',[Inf 1],[1 0]);


end




