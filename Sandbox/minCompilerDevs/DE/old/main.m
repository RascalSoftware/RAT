
addpath('/home/arwel/Documents/RascalDev/RAT'); %linux
addRatPaths


problem = load('testProblem_simplex_calcDef.mat');
problem = problem.calculation;
problem.fitpars = [problem.params, problem.backs, problem.shifts, problem.sf, problem.nba, problem.nbs, problem.res];

controls = load('testProblem_controlDef');
controls = controls.controls;

%problem = legacyChanges(problem);

if isfield(controls,'checks')
    checks = controls.checks;
else
    checks.params_fitYesNo = ones(length(problemDef.params),1);
    checks.backs_fitYesNo = ones(length(problemDef.backs),1);
    checks.shifts_fitYesNo = ones(length(problemDef.shifts),1);
    checks.scales_fitYesNo = ones(length(problemDef.sf),1);
    checks.nbairs_fitYesNo = ones(length(problemDef.nba),1);
    checks.nbsubs_fitYesNo = ones(length(problemDef.nbs),1);
    checks.resol_fitYesNo = ones(length(problemDef.res),1);
end

% tic
problemDef = unpackparams(problem,controls);
problem = rascal_DE_new_test(problem,controls)
% toc

%problem = rascal_DE_new_test(problem,contrls);


figure(1); clf; hold on;
for i = 1:problem.numberOfContrasts
    thisData = problem.shifted_data{i};
    mult = 10^(2*i);
    thisData(:,2) = thisData(:,2) / mult;
    thisData(:,3) = thisData(:,3) / mult;
    errorbar(thisData(:,1),thisData(:,2),thisData(:,3),'o');
    thisFit = problem.calculations.Simulation{i};
    thisFit(:,2) = thisFit(:,2) / mult;
    plot(thisFit(:,1),thisFit(:,2));
end
set(gca,'YScale','log','XScale','log','xlim',[0.05 0.4]);


figure(2); clf; hold on
for i = 1:problem.numberOfContrasts
    thisSld = problem.calculations.slds{i};
    plot(thisSld(:,1),thisSld(:,2));
end

%rmRatPaths





