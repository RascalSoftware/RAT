function [outProblemStruct,result,bayesResults] = runDREAM(problemStruct,problemCells,problemLimits,controls,priors)


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

% Pre-allocation
checks = controls.checks;
numberOfFitted = sum(checks.fitParam) + ...
                 sum(checks.fitBackgroundParam) + ...
                 sum(checks.fitScalefactor) + ...
                 sum(checks.fitQzshift) + ...
                 sum(checks.fitBulkIn) + ...
                 sum(checks.fitBulkOut) + ...
                 sum(checks.fitResolutionParam) + ...
                 sum(checks.fitDomainRatio);

fitParamNames = cell(numberOfFitted,1);
for i = 1:numberOfFitted
    fitParamNames{i} = 'x';
end

[problemStruct,fitParamNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

% Get the priors for the fitted parameters...
priorList = getFittedPriors(fitParamNames,priors,problemStruct.fitLimits);

% Put all the RAT parameters together into one array...
ratInputs.problemStruct = problemStruct;
ratInputs.problemCells = problemCells;
ratInputs.problemLimits = problemLimits;
ratInputs.controls = controls;
ratInputs.priors = priorList;

% Get the parameters from the user
totalGen = controls.nSamples;                   % Total number of generations
nChains = controls.nChains;                     % Number of chains

% Set the relevant parameters for the DREAM sampler....
DREAMPar.d = length(fitParamNames);             % Dimension of the problem
DREAMPar.N = nChains;                           % Number of Markov Chains
DREAMPar.T = ceil(totalGen / nChains);          % Number of generations per chain
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
Par_info.prior = coderEnums.priorTypes.Uniform;
ParInfo.min = problemStruct.fitLimits(:,1)';
ParInfo.max = problemStruct.fitLimits(:,2)';
ParInfo.boundhandling = controls.boundHandling;
ParInfo.mvnpdf = true;


% Run the sampler....
Meas_info = struct('Y',0,'N',0);
[chain,dreamOutput,~] = ratDREAM(DREAMPar,ParInfo,Meas_info,ratInputs);

% Combine all chains....
nChains = DREAMPar.N;
nPars = DREAMPar.d;

collectChains = [];
for i = 1:nChains
    thisChain = chain(:,1:nPars,i);
    
    % Keep only the last 75% of the chain..
    nSamples = size(thisChain,1);
    cutoff = floor(nSamples * 0.25);
    thisChain = thisChain(cutoff:end,:);

    % Combine the parallel chains into one....
    collectChains = [collectChains ; thisChain];
end

bestPars = mean(collectChains);
output.results.outputDream = dreamOutput;
output.bestPars = bestPars;
output.chain = collectChains;

[outProblemStruct,result,dreamResults] = processBayes(output,problemStruct,problemCells,problemLimits,controls);

% Populate the output struct
bayesResults.bestFitsMean = dreamResults.bestFitsMean;
bayesResults.predlims = dreamResults.predlims;
bayesResults.parConfInts = dreamResults.parConfInts;
bayesResults.bestPars = bestPars;
bayesResults.allChains = chain;
bayesResults.dreamParams = dreamOutput.DREAMPar;

fieldNames = {'outlier','RunTime','iteration','iloc','fx','AR','R_stat','CR'};
for i = 1:length(fieldNames)
    thisFieldName = fieldNames{i};
    bayesResults.dreamOutput.(thisFieldName) = dreamOutput.(thisFieldName);
end

bayesResults.chain = collectChains;

end
