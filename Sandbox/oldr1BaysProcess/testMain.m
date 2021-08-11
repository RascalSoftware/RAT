% Test of using the old R1 post processing.
clear

% Load some input pars
inputPars = load('inputPars.mat');
inputPars = inputPars.inputPars;

problemDef = inputPars.problemDef;
problemDef_cells = inputPars.problemDef_cells;
problemDef_limits = inputPars.problemDef_limits;
priors = inputPars.priors;
controls = inputPars.controls;

% Run the main RAT Bayes routine....
[outProblemDef,bayesResults] = runDram_r1Mod(problemDef,problemDef_cells,problemDef_limits,priors,controls);

% Calculate the Bayes statistics....
[best, intervals, posteriors] = calcMCMCstatRefErrors(bayesResults,outProblemDef,problemDef_cells,problemDef_limits,controls);
bayesResults.best = best;
bayesResults.posteriors = posteriors;
bayesResults.intervals = intervals;