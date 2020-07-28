clear 

addpath('r1Codes');

res = load('bayesResults.mat');
res = res.bayesResults;

outProb = res.outProb;
results = res.results;

[problem,controls] = r1ToProblemDef('monolayer_7_contrasts_stanLay');


[bestVals_max,posteriors] = makePosteriorPlotsR2(outProb,results);

[best, intervals] = calcMCMCstatRefErrorsR2(results,bestVals_max);