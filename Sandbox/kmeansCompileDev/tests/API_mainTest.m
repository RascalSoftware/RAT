%Load in the 'problem' and 'what' structures.
%Generated manually for now but these will
% be created by the GUI.


problem = load('testProblem_simplex_calcDef.mat');
problem = problem.calculation;


controls = load('testProblem_controlDef');
controls = controls.controls;

result = RAT(problem,controls);

disp('debug');


