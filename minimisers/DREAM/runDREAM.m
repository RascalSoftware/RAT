function [outProblemDef,outProblem,result,bayesResults] = runDREAM(problemDef,problemDef_cells,problemDef_limits,controls,priors)

% Get the priors for the fitted parameters...
[problemDef,fitParamNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);
priorList = getFittedPriors(fitParamNames,priors,problemDef.fitconstr);

% Put all the RAT parameters together into one array...
ratInputs.problemDef = problemDef;
ratInputs.problemDef_cells = problemDef_cells;% 
ratInputs.problemDef_limits = problemDef_limits;
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
DREAMPar.parallel = 'no';
DREAMPar.CPU = 1;

% Jump probabilities...
DREAMPar.lambda = controls.lambda;
DREAMPar.p_unit_gamma = controls.p_unit_gamma;

% This will change...
% Initial sampling and parameter range
Par_info.prior = 'uniform';           

Par_info.min = problemDef.fitconstr(:,1)';
Par_info.max = problemDef.fitconstr(:,2)';
Par_info.boundhandling = controls.boundHandling;

%if dreamC.prior
    Par_info.mvnpdf = true;
%end

% Run the sampler....
%[chain,output,fx] = rat_DREAM(DREAMPar,Par_info,[],ratInputs);
%Func_name = @DREAMWrapper;
[chain,output,fx] = ratDREAM(DREAMPar,Par_info,[],ratInputs);

% Combine all chains....
nChains = DREAMPar.N;
lChains = DREAMPar.T;
nPars = DREAMPar.d;

allChains = [];
for i = 1:nChains
    thisChain = chain(:,1:nPars,i);
    allChains = [allChains ; thisChain];
end

output.chain = allChains;
output.s2chain = [];
output.sschain = [];
output.bestPars = mean(allChains,1);
output.results.mean = output.bestPars;

allProblem = cell(4,1);
allProblem{1} = problemDef;
allProblem{2} = controls;
allProblem{3} = problemDef_limits;
allProblem{4} = problemDef_cells;

[outProblemDef,outProblem,result,bayesResults] = processBayes_newMethod(output,allProblem);

end