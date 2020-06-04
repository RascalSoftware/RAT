%% Solid Liquid Fit Example
% 
% 
% First get the problemDefs etc by using an existing RasCAL1 project as usual 
% (use original_DSPC_bilayer from the Rascal demo's folder).
% 
% First initialise RAT....

addRatPaths()
%% 
% Rather than populate the input classes manually, we build them from an 
% existing Rascal project....

[problem,controls] = r1ToProblemDef('original_dspc_bilayer.mat')
%% 
% 
% 
% Set up for running simplex...

controls.procedure = 'NS';
controls.Nlive = 70;
controls.Nmcmc = 0;
controls.nsTolerance = 1;

%% 
% Run the fit...

[outProblem,results] = RAT(problem,controls)

%% 
% Plot out the results....

plotRefSLD(outProblem,results)