%Load in the 'problem' and 'what' structures.
%Generated manually for now but these will
% be created by the GUI.


problem = load('testProblem_NS_calcDef.mat');
problem = problem.problem;
problem.limits.nba = [-1e-5 1e-5];

controls = load('testProblem_NS_controlDef');
controls = controls.controls;
% controls.checks.resol_fitYesNo = 0;

[roblem,result] = RAT(problem,controls);

disp('debug');


