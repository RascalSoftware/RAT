clc

% Load RAT results
testProb = load('testProb');
testProb = testProb.testProb;

ratInputs = load('ratInputs');
ratInputs = ratInputs.ratInputs;


problemDef = testProb.outProblemDef;
problem = testProb.problem;
results = testProb.results;
bayesResults = testProb.bayesResults;
controls = testProb.controls;

bestFitPars = bayesResults.bestPars;

problemDefCells = ratInputs.problemDefCells;
problemDefLimits = ratInputs.problemDefLimits;


problemDef.fitpars = bestFitPars;
problemDef = unpackparams(problemDef,controls);
[problem,result] = reflectivityCalculationWrapper(problemDef,problemDefCells,problemDefLimits,controls);

disp('debug');

% Calculate the prediction intervals
[best, intervals] = calcMCMCstatRefErrors(bayesResults,problemDef,problemDefCells,problemDefLimits,controls);