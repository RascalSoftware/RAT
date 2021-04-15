a = load('testProblem.mat');
problem = a.problem;
problem = legacyChanges(problem);

scalefac = problem.scalefactors;
horshift = problem.qshifts;
nC = problem.numberOfContrasts;
dataPresent = problem.dataPresent;
allData = problem.data;
dataLimits = problem.dataLimits;

%shifted_data{i} = shiftdata(sfs(i),qshifts(i),dataPresent(i),allData{i},dataLimits{i});
shifted_data = shiftdata(scalefac(1),horshift(1),dataPresent(1),allData{1},dataLimits{1});