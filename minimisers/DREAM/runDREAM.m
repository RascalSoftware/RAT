function [outProblemDefStruct,contrastParams,result,bayesResults] = runDREAM(problemDefStruct,problemDefCells,problemDefLimits,controls,priors)


% Make an empty struct for bayesResults to hold the outputs of the
% calculation
nPars = 1e3;
numberOfContrasts = problemDefStruct.numberOfContrasts;
numberOfChains = controls.nChains;

if strcmpi(problemDefStruct.TF,'domains')
    domains = true;
else
    domains = false;
end

bayesResults = makeEmptyBayesResultsStruct(nPars, numberOfContrasts, domains, numberOfChains);

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

[problemDefStruct,fitParamNames] = packParams(problemDefStruct,problemDefCells,problemDefLimits,controls.checks);

% Get the priors for the fitted parameters...
priorList = getFittedPriors(fitParamNames,priors,problemDefStruct.fitLimits);

% Put all the RAT parameters together into one array...
ratInputs.problemDefStruct = problemDefStruct;
ratInputs.problemDefCells = problemDefCells;
ratInputs.problemDefLimits = problemDefLimits;
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
DREAMPar.lambda = controls.jumpProbability;
DREAMPar.pUnitGamma = controls.pUnitGamma;
DREAMPar.adaptPCR = controls.adaptPCR;

% This will change...
% Initial sampling and parameter range
Par_info.prior = 'uniform';           

Par_info.min = problemDefStruct.fitLimits(:,1)';
Par_info.max = problemDefStruct.fitLimits(:,2)';
Par_info.boundhandling = controls.boundHandling;

%if dreamC.prior
    Par_info.mvnpdf = true;
%end

% Run the sampler....
%[chain,output,fx] = rat_DREAM(DREAMPar,Par_info,[],ratInputs);
%Func_name = @DREAMWrapper;
Meas_info = struct('Y',0,'N',0);
[chain,dreamOutput,~] = ratDREAM(DREAMPar,Par_info,Meas_info,ratInputs);

% Combine all chains....
nChains = DREAMPar.N;
lChains = DREAMPar.T;
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

allProblem = cell(4,1);
allProblem{1} = problemDefStruct;
allProblem{2} = controls;
allProblem{3} = problemDefLimits;
allProblem{4} = problemDefCells;

bestPars = mean(collectChains);
output.results.outputDream = dreamOutput;
output.bestPars = bestPars;
output.chain = collectChains;

[outProblemDefStruct,contrastParams,result,dreamResults] = processBayes(output,allProblem);

% Populate the output struct
bayesResults.bayesRes.allChains = chain;
bayesResults.bayesRes.dreamOutput = dreamOutput;
bayesResults.chain = collectChains;
bayesResults.bestPars = bestPars;
bayesResults.chain = collectChains;
% bayesResults.bayesRes.allChains = chain;
bayesResults.predlims = dreamResults.predlims;
bayesResults.parConfInts = dreamResults.parConfInts;
bayesResults.bestFitsMean = dreamResults.bestFitsMean;

% These are not defined in makeEmptyBayesResultsStruct

% bayesResults.bayesRes.DREAMPar = DREAMPar;
% bayesResults.bayesRes.Meas_info = Meas_info;
% bayesResults.bayesRes.dreamOutput = output;

end
