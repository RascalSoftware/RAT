clc

% Load RAT results
testProb = load('testProb');
testProb = testProb.testProb;

ratInputs = load('ratInputs');
ratInputs = ratInputs.ratInputs;


problemDefStruct = testProb.outProblemDef;
problem = testProb.problem;
results = testProb.results;
bayesResults = testProb.bayesResults;
controls = testProb.controls;

bestFitPars = bayesResults.bestPars;

problemDefCells = ratInputs.problemDefCells;
problemDefLimits = ratInputs.problemDefLimits;


problemDefStruct.fitParams = bestFitPars;
problemDefStruct = unpackParams(problemDefStruct,controls);
[problem,result] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);

disp('debug');

% Calculate the prediction intervals
[best, intervals] = calcMCMCstatRefErrors(bayesResults,problemDefStruct,problemDefCells,problemDefLimits,controls);