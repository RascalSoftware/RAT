
[problem,controls] = r1ToProblemDef('original_dspc_bilayer.mat');

problem.qzshiftFitYesNo = 0;
problem.nbairFitYesNo = 0;

controls.procedure = 'NS';
controls.Nlive = 70;
controls.Nmcmc = 10;
controls.nsTolerance = 1;

[outProblem,results] = RAT(problem,controls);



%plotRefSLD(outProblem,results)