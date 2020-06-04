a = load('testProblem2.mat');
problem = a.problem;

fitYN = problem.fityesno;
fitPars = problem.fitpars;
otherPars = problem.otherpars;
backsYN = problem.backgrounds_fityesno;
scalesYN = problem.scalefac_fityesno;
shiftsYN = problem.shifts_fityesno;
nbairYN = problem.nbairs_fityesno;
nbsubYN = problem.nbsubs_fityesno;
resYN = problem.resolution_fityesno;

[params,backs,scalefac,shifts_horisontal,nba,nbs,resolution] = unpackPars(fitYN,fitPars,otherPars,backsYN, ...
    scalesYN,shiftsYN,nbairYN,nbsubYN,resYN);