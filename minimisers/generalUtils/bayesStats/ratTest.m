clc

% Load RAT results
testProb = load('testProb');
testProb = testProb.testProb;

ratInputs = load('ratInputs');
ratInputs = ratInputs.ratInputs;


problemStruct = testProb.outProblemDef;
problem = testProb.problem;
results = testProb.results;
bayesResults = testProb.bayesResults;
controls = testProb.controls;

fitParams = results.bestParams;

problemCells = ratInputs.problemCells;
problemLimits = ratInputs.problemLimits;


problemStruct.fitParams = fitParams;
problemStruct = unpackParams(problemStruct,controls.checks);
result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);

disp('debug');

% Calculate the prediction intervals
[best, intervals] = calcMCMCstatRefErrors(bayesResults,problemStruct,problemCells,problemLimits,controls);