%% Development of new background functions.
% 
% 
% Develop them in here first, then we'll have to think about how to change 
% problemDef to accommodate the different versions.
% 
% First get the problemDefs etc by using an existing RasCAL1 project as usual 
% (use original_DSPC_bilayer from the Rascal demo's folder.

addRatPaths()
[problem,controls] = r1ToProblemDef('original_dspc_bilayer.mat')
%% 
% 
% 
% ..test this out in RAT just in case there is something untoward....

controls.proc = 'simplex';
controls.algArgs.maxFunEvals = 500;

problem.backgroundConstr{1} = [1e-8 1e-5];
problem.backgroundConstr{1} = [1e-8 1e-5];

[out1,results] = RAT(problem,controls)

plotRefSLD(out1,results)