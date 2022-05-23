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

problemDef_cells = ratInputs.problemDef_cells;
problemDef_limits = ratInputs.problemDef_limits;


problemDef.fitpars = bestFitPars;
problemDef = unpackparams(problemDef,controls);
[problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

disp('debug');

% Calculate the prediction intervals
[best, intervals] = calcMCMCstatRefErrors(bayesResults,problemDef,problemDef_cells,problemDef_limits,controls);