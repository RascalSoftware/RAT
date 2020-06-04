%Load in the 'problem' and 'what' structures.
%Generated manually for now but these will
% be created by the GUI.


problem = load('testProblem_simplex_calcDef.mat');
problem = problem.calculation;
problem.limits.nba = [-1e-5 1e-5];

controls = load('testProblem_simplex_controlDef');
controls = controls.controls;


%controls.proc = 'DE';
[roblem,result] = RAT(problem,controls);

disp('debug');

figure(1)
clf; hold on
for i = 1:7
    thisFit = result.reflectivity{i};
    plot(thisFit(:,1),thisFit(:,2),'-');
    thisData = result.shifted_data{i};
    errorbar(thisData(:,1),thisData(:,2),thisData(:,3),'o');
end
set(gca,'YScale','log');

