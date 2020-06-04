[problem,control] = r1ToProblemDef('20nM_data.mat');

problem.qzshiftFitYesNo = 0;
problem.nbairFitYesNo = 0;

control.procedure = 'NS';

control.nsTolerance = 1e-2;
control.Nlive = 100;
control.Nmcmc = 20;

[outProblem,result] = RAT(problem,control);