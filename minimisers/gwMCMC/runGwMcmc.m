
function [outProblemDef,outProblem,result,bayesResults] = runGwMcmc(problemDef,problemDef_cells,problemDef_limits,controls,priors)

% Run the Goodman and Weare MCMC Sampler.

% Re-set the random number generator for repeatability
rng('default');

% Get the relevant priors from the full list of priors..
[~,paramNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);
priorList = getFittedPriors(paramNames,priors,problemDef.fitconstr);

% Initialise the walkers..
fitPars = problemDef.fitpars;
initval = zeros(length(fitPars),(length(fitPars)*2 + 1));
initVal(:,1) = fitPars(:);
for i = 1:length(fitPars)*2
    shakeVal = randn(1,length(fitPars))./100;
    nextLine = fitPars + (shakeVal.*fitPars);
    initVal = [initVal , nextLine(:)];
end

% Group the inputs into a simple array...
extras{1}= problemDef;
extras{2} = problemDef_cells;% 
extras{3} = problemDef_limits;
extras{4} = controls;
extras{5} = priorList;

% Get the relevant values from 'controls' and put them into one array...
p.BurnIn = controls.gwBurnin;
p.Parallel = 0; %controls.parallel;
p.ProgressBar = 1;
p.StepSize = controls.StepSize;
p.ThinChain = controls.ThinChain;
nSteps = controls.nSteps;

% Run the sampler..
allSamples = gwmcmc_compile(initVal,nSteps,p,extras);

% Collapse the samples from all the walkers into a single chain
chain = allSamples(:,:)';

% Collect everything into the right format...
% output.results = results;
% output.chain = chain;
% output.s2chain = s2chain;
% output.sschain = sschain;
% output.bestPars = results.mean;
% output.data = data;

output.chain = chain;
output.s2chain = [];
output.sschain = [];
output.bestPars = mean(chain,1);
output.results.mean = output.bestPars;

% DEBUG - plot the chain....
ecornerplot(allSamples,'names',paramNames);

allProblem = cell(4,1);
allProblem{1} = problemDef;
allProblem{2} = controls;
allProblem{3} = problemDef_limits;
allProblem{4} = problemDef_cells;

[outProblemDef,outProblem,result,bayesResults] = processBayes_newMethod(output,allProblem);

end