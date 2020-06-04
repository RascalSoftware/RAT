%Run Nested Sampler in RAT on D2O project
[problem,controls] = r1ToProblemDef('defaultProject_2D_bayesCompare.mat');

controls.procedure = 'NS';
controls.Nlive = 500;
controls.Nmcmc = 10;

[outProblem,results] = RAT(problem,controls);

%Processing of results still not done for NS..
%So grab the relevant bits straight from RAT.m

