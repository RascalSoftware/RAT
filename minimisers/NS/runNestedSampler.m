function  [problemStruct,result,bayesResults] = runNestedSampler(problemStruct,problemCells,problemLimits,controls,inPriors)

checks = controls.checks;
[problemStruct,fitNames] = packParams(problemStruct,problemCells,problemLimits,checks);

nest_samples = [0 0 ; 0 0];
coder.varsize('nest_samples');

post_samples = [0 0 ; 0 0];
coder.varsize('post_samples');

logZ = 0;
H = 0;

% Make an empty struct for bayesResults to hold the outputs of the
% calculation
nPars = 1e3;
numberOfContrasts = problemStruct.numberOfContrasts;
numberOfChains = 1;

if strcmpi(problemStruct.TF,'domains')
    domains = true;
else
    domains = false;
end
bayesResults = makeEmptyBayesResultsStruct(nPars, numberOfContrasts, domains, numberOfChains);
      
%Deal with priors.
priorList = getFittedPriors(fitNames,inPriors,problemStruct.fitLimits);

%Tuning Parameters
model.ssfun = @nsIntraFun;
Nlive = controls.Nlive;
tolerance = controls.nsTolerance;
likelihood = @nsIntraFun;
Nmcmc = controls.Nmcmc;
data = {problemStruct ; controls ; problemLimits ; problemCells};

[logZ, nest_samples, post_samples, H] = nestedSampler(data, Nlive, Nmcmc, ...
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
bayesOutputs.data = problemCells{2};

allProblem = cell(4,1);
allProblem{1} = problemStruct;
allProblem{2} = controls;
allProblem{3} = problemLimits;
allProblem{4} = problemCells;

[problemStruct,result,nestResults] = processBayes(bayesOutputs,allProblem);

bayesResults.predlims = nestResults.predlims;
bayesResults.bestFitsMean = nestResults.bestFitsMean;
bayesResults.parConfInts = nestResults.parConfInts;
bayesResults.bestPars = bestPars;
bayesResults.chain = chain;
bayesResults.bayesRes.nestOutput.LogZ = logZ;
bayesResults.bayesRes.nestOutput.nestSamples = nest_samples;
bayesResults.bayesRes.nestOutput.postSamples = post_samples;

end
