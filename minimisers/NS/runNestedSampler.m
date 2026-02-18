function  [problemStruct,result,bayesResults] = runNestedSampler(problemStruct,controls)
% Run the nested sampling algorithm for a given problem and controls.
%
% Parameters
% ----------
% problemStruct : struct
%     the Project struct.
% controls : struct
%     the Controls struct.
%
% Returns
% -------
% problemStruct : struct
%     the output project struct.
% result : struct
%     the calculation and optimisation results object.
% bayesResults : struct
%     Additional Bayesian results from the algorithm.
%

fitNames = getFitNames(problemStruct);
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
      
% Deal with priors.
priorList = getFittedPriors(fitNames, problemStruct.priorNames, ...
                            problemStruct.priorValues, problemStruct.fitLimits);

% Tuning Parameters
model.ssfun = @nsIntraFun;
nLive = controls.nLive;
tolerance = controls.nsTolerance;
likelihood = @nsIntraFun;
nMCMC = controls.nMCMC;
data = {problemStruct; controls};

[logZ, nestSamples, postSamples, H] = nestedSampler(data, nLive, nMCMC,...
    tolerance, likelihood, model, priorList, fitNames);

% Process the results...
nParams = length(fitNames);
% chain = nest_samples(:,1:end-1);
chain = postSamples(:,1:nParams);

bayesOutputs.bestParams = mean(chain, 1);
bayesOutputs.chain = chain;
bayesOutputs.fitNames = fitNames;
bayesOutputs.s2chain = [];
bayesOutputs.sschain = [];
bayesOutputs.data = problemStruct.data;

[problemStruct,result,nestResults] = processBayes(bayesOutputs,problemStruct,controls);

bayesResults.predictionIntervals = nestResults.predictionIntervals;
bayesResults.confidenceIntervals = nestResults.confidenceIntervals;
bayesResults.chain = chain;
bayesResults.nestedSamplerOutput.logZ = logZ;
bayesResults.nestedSamplerOutput.logZErr = sqrt(H / nLive);
bayesResults.nestedSamplerOutput.nestSamples = nestSamples;
bayesResults.nestedSamplerOutput.postSamples = postSamples;

end
