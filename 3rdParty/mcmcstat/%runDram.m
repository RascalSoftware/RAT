function  [problemStruct,problem,result,bayesResults] = runDram(problemStruct,problemLimits,priors,controls)

[problemStruct,fitNames] = packParams(problemStruct,problemLimits);
%fitPriors = packPriors(priors);

% Seed the Random Number Generator
rng(0);


%fitPriors = packPriors(priors);

%First deal with priors.
%Make uniform priors from the
%min/max limits for now.
lims = problemStruct.fitLimits;
% Get the li

for i = 1:length(fitNames)
    name = fitNames{i};
    value = problemStruct.fitParams(i);
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

problem = {problemStruct ; controls ; problemLimits};

output = runBayes(loop,nsimu,burnin,adaptint,params,problem);

bayesResults.res = output.results;
bayesResults.chain = output.chain;
bayesResults.s2chain = output.s2chain;
bayesResults.sschain = output.sschain;
bayesResults.bayesData = output.data;
bayesResults.bestFits = output.bestFits;
bayesResults.predictionIntervals = output.predictionIntervals;

problemStruct.fitParams = output.bestParams;
problemStruct = unpackParams(problemStruct);
result = reflectivityCalculation(problemStruct,controls);

% Pre-processor directives for Matlab Coder.
coder.varsize('problem.ssubs',[Inf 1],[1 0]);
coder.varsize('problem.backgroundParams',[Inf 1],[1 0]);
coder.varsize('problem.scalefactors',[Inf 1],[1 0]);
coder.varsize('problem.bulkIn',[Inf 1],[1 0]);
coder.varsize('problem.bulkOut',[Inf 1],[1 0]);
coder.varsize('problem.resolutionParams',[Inf 1],[1 0]);
coder.varsize('problem.ssubs',[Inf 1],[1 0]);
coder.varsize('problem.calculations.chiValues',[Inf 1],[1 0]);
coder.varsize('problem.calculations.sumChi',[1 1],[0 0]);
coder.varsize('problem.subRoughs',[Inf 1],[1 0]);

end
