function  [problemStruct,result,bayesResults] = runNestedSampler(problemStruct,problemCells,problemLimits,controls,inPriors)

checks = controls.checks;
[problemStruct,fitNames] = packParams(problemStruct,problemCells,problemLimits,checks);

nestSamples = [0 0 ; 0 0];
coder.varsize('nest_samples');

postSamples = [0 0 ; 0 0];
coder.varsize('post_samples');

logZ = 0;
H = 0;

% Make an empty struct for bayesResults to hold the outputs of the
% calculation
numberOfContrasts = problemStruct.numberOfContrasts;
numberOfChains = 1;

if strcmpi(problemStruct.TF, coderEnums.calculationTypes.Domains)
    domains = true;
else
    domains = false;
end
bayesResults = makeEmptyBayesResultsStruct(numberOfContrasts, domains, numberOfChains);
      
%Deal with priors.
priorList = getFittedPriors(fitNames,inPriors,problemStruct.fitLimits);

%Tuning Parameters
model.ssfun = @nsIntraFun;
nLive = controls.nLive;
tolerance = controls.nsTolerance;
likelihood = @nsIntraFun;
nMCMC = controls.nMCMC;
data = {problemStruct ; controls ; problemLimits ; problemCells};

[logZ, nestSamples, postSamples, H] = nestedSampler(data, Nlive, Nmcmc, ...
    tolerance, likelihood, model, priorList, fitNames);

% Process the results...
nPars = length(fitNames);
% chain = nest_samples(:,1:end-1);
chain = postSamples(:,1:nPars);
bestPars = mean(chain,1);

bayesOutputs.bestPars = mean(chain);
bayesOutputs.chain = chain;
bayesOutputs.fitNames = fitNames;
bayesOutputs.s2chain = [];
bayesOutputs.sschain = [];
bayesOutputs.data = problemCells{2};

[problemStruct,result,nestResults] = processBayes(bayesOutputs,problemStruct,problemCells,problemLimits,controls);

bayesResults.predlims = nestResults.predlims;
bayesResults.bestFitsMean = nestResults.bestFitsMean;
bayesResults.parConfInts = nestResults.parConfInts;
bayesResults.bestPars = bestPars;
bayesResults.chain = chain;
bayesResults.nestOutput.LogZ = logZ;
bayesResults.nestOutput.nestSamples = nestSamples;
bayesResults.nestOutput.postSamples = postSamples;

end
