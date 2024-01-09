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


problemDef.fitParams = bestFitPars;
problemDef = unpackParams(problemDef,controls);
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);

disp('debug');

% Calculate the prediction intervals
[best, intervals] = calcMCMCstatRefErrors(bayesResults,problemDef,problemDefCells,problemDefLimits,controls);