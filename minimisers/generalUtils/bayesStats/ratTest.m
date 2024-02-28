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

bestFitPars = bayesResults.bestPars;

problemCells = ratInputs.problemCells;
problemLimits = ratInputs.problemLimits;


problemStruct.fitParams = bestFitPars;
problemStruct = unpackParams(problemStruct,controls);
result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);

disp('debug');

% Calculate the prediction intervals
[best, intervals] = calcMCMCstatRefErrors(bayesResults,problemStruct,problemCells,problemLimits,controls);