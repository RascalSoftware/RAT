a = load('testProblem.mat');
problem = a.problem;
problem = legacyChanges(problem);
setappdata(0,'problem',problem);

nC = problem.numberOfContrasts;
cBacks = problem.contrastBacks;
cShifts = problem.contrastShifts;
cScales = problem.contrastScales;
cNbas = problem.contrastNbas;
cNbss = problem.contrastNbss;
cRes = problem.contrastResolutions;

backs = problem.backs;
shifts = problem.shifts_horisontal;
sf = problem.scalefac;
nba = problem.nba;
nbs = problem.nbs;
res = problem.resolution;

[backgs,qshifts,sfs,nbas,nbss,resols] = backSort(cBacks(1),cShifts(1),cScales(1),cNbas(1),cNbss(1),cRes(1),backs,shifts,sf,nba,nbs,res);

problem.backgrounds = backgs;
problem.qshifts = qshifts;
problem.scalefactors = sfs;
problem.nbairs = nbas;
problem.nbsubs = nbss;



%problem = backsorts(problem);
