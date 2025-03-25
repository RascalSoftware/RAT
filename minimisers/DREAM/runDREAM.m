function [outProblemStruct,result,bayesResults] = runDREAM(problemStruct,controls)
% Run the DREAM algorithm for a given problem and controls.
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
% outProblemStruct : struct
%     the output project struct.
% result : struct
%     the calculation and optimisation results object.
% bayesResults : struct
%     Additional Bayesian results from the algorithm.

% Make an empty struct for bayesResults to hold the outputs of the
% calculation
numberOfContrasts = problemStruct.numberOfContrasts;
numberOfChains = controls.nChains;

if strcmpi(problemStruct.TF, coderEnums.calculationTypes.Domains)
    domains = true;
else
    domains = false;
end

bayesResults = makeEmptyBayesResultsStruct(numberOfContrasts, domains, numberOfChains);

% TODO remove when Jeffreys prior is implemented to DREAM 
% https://github.com/RascalSoftware/RAT/issues/353
if ismember(3, problemStruct.priorValues(:,1))
    coderException(coderEnums.errorCodes.invalidOption, 'Jeffreys priors are not available in DREAM.')
end

% Pre-allocation
checks = problemStruct.checks;
numberOfFitted = sum(checks.params) + ...
                 sum(checks.backgroundParams) + ...
                 sum(checks.scalefactors) + ...
                 sum(checks.bulkIns) + ...
                 sum(checks.bulkOuts) + ...
                 sum(checks.resolutionParams) + ...
                 sum(checks.domainRatios);

fitNames = cell(numberOfFitted,1);
for i = 1:numberOfFitted
    fitNames{i} = 'x';
end

fitNames = getFitNames(problemStruct);

% Get the priors for the fitted parameters...
priorList = getFittedPriors(fitNames, problemStruct.priorNames, ...
                            problemStruct.priorValues, problemStruct.fitLimits);

% Put all the RAT parameters together into one array...
ratInputs.problemStruct = problemStruct;
ratInputs.controls = controls;
ratInputs.priors = priorList;

% Get the parameters from the user
totalGen = controls.nSamples;                   % Total number of generations
nChains = controls.nChains;                     % Number of chains

% Set the relevant parameters for the DREAM sampler....
DREAMPar.nParams = length(fitNames);             % Dimension of the problem
DREAMPar.nChains = nChains;                           % Number of Markov Chains
DREAMPar.nGenerations = ceil(totalGen / nChains);          % Number of generations per chain
%DREAMPar.lik = 1;                              % Model output is likelihood

% Parallel or not...
DREAMPar.parallel = false;
DREAMPar.CPU = 1;

% Jump probabilities...
DREAMPar.jumpProbability = controls.jumpProbability;
DREAMPar.pUnitGamma = controls.pUnitGamma;
DREAMPar.adaptPCR = controls.adaptPCR;

% This will change...
% Initial sampling and parameter range
parInfo.prior = coderEnums.priorTypes.Uniform;
ParInfo.min = problemStruct.fitLimits(:,1)';
ParInfo.max = problemStruct.fitLimits(:,2)';
ParInfo.boundhandling = controls.boundHandling;
ParInfo.mvnpdf = true;


% Run the sampler....
[chain,dreamOutput,~] = ratDREAM(DREAMPar,ParInfo,ratInputs);

% Combine all chains....
nChains = DREAMPar.nChains;
nParams = DREAMPar.nParams;

collectChains = [];
for i = 1:nChains
    thisChain = chain(:,1:nParams,i);
    
    % Keep only the last 75% of the chain..
    nSamples = size(thisChain,1);
    cutoff = floor(nSamples * 0.25);
    thisChain = thisChain(cutoff:end,:);

    % Combine the parallel chains into one....
    collectChains = [collectChains ; thisChain];
end

bestParams = mean(collectChains);
output.results.outputDream = dreamOutput;
output.bestParams = bestParams;
output.chain = collectChains;

[outProblemStruct,result,dreamResults] = processBayes(output,problemStruct,controls);

% Populate the output struct
bayesResults.predictionIntervals = dreamResults.predictionIntervals;
bayesResults.confidenceIntervals = dreamResults.confidenceIntervals;
bayesResults.dreamParams = dreamOutput.DREAMPar;
bayesResults.dreamOutput.allChains = chain;

fieldNames = {'outlierChains','runtime','iteration','AR','R_stat','CR'};
for i = 1:length(fieldNames)
    thisFieldName = fieldNames{i};
    bayesResults.dreamOutput.(thisFieldName) = dreamOutput.(thisFieldName);
end

bayesResults.chain = collectChains;

end
