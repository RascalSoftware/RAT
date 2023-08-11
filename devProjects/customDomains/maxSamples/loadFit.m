
fit1 = load('fit1.mat');
fit1 = fit1.fit1;

problem = fit1.problem;
results = fit1.results;

problem.setContrast(1,'resample',false)

[problem,results] = RAT(problem,controls);

clf; plotRefSLD(problem,results);

