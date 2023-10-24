function  [problemDef,outProblem,result,bayesResults] = runNestedSampler(problemDef,problemDefCells,problemDefLimits,controls,inPriors)

checks = controls.checks;
[problemDef,fitNames] = packparams(problemDef,problemDefCells,problemDefLimits,checks);

% Make an empty struct for bayesResults to hold the outputs of the
% calculation
nPars = 1e3;
numberOfContrasts = problemDef.numberOfContrasts;
numberOfChains = 1;

if strcmpi(problemDef.TF,'domains')
    domains = true;
else
    domains = false;
end
bayesResults = makeEmptyBayesResultsStruct(nPars, numberOfContrasts, domains, numberOfChains);
      
%Deal with priors.
priorList = getFittedPriors(fitNames,inPriors,problemDef.fitconstr);

%Tuning Parameters
model.ssfun = @NSIntraFun;
Nlive = controls.Nlive;
tolerance = controls.nsTolerance;
likelihood = @NSIntraFun;
Nmcmc = controls.nmcmc;
data = {problemDef ; controls ; problemDefLimits ; problemDefCells};

[logZ, nest_samples, post_samples, H] = nested_sampler(data, Nlive, Nmcmc, ...
    tolerance, likelihood, model, priorList, fitNames);

% Process the results...
nPars = length(fitNames);
% chain = nest_samples(:,1:end-1);
chain = post_samples(:,1:nPars);
bestPars = mean(chain,1);

bayesOutputs.bestPars = mean(chain);
bayesOutputs.chain = chain;
bayesOutputs.fitNames = fitNames;
bayesOutputs.s2chain = [];
bayesOutputs.sschain = [];
bayesOutputs.data = problemDefCells{2};

allProblem = cell(4,1);
allProblem{1} = problemDef;
allProblem{2} = controls;
allProblem{3} = problemDefLimits;
allProblem{4} = problemDefCells;

[problemDef,outProblem,result,nestResults] = processBayes(bayesOutputs,allProblem);

bayesResults.predlims = nestResults.predlims;
bayesResults.bestFitsMean = nestResults.bestFitsMean;
bayesResults.parConfInts = nestResults.parConfInts;
bayesResults.bestPars = bestPars;
bayesResults.chain = chain;
bayesResults.bayesRes.nestOutput.LogZ = logZ;
bayesResults.bayesRes.nestOutput.nestSamples = nest_samples;
bayesResults.bayesRes.nestOutput.postSamples = post_samples;

end
