a = load('testProblem2.mat');
problem = a.problem;
%problem = legacyChanges(problem);

nbairs = problem.nbairs;
nbsubs = problem.nbsubs;
simLimits = problem.simLimits;
repeatLayers = problem.repeatLayers;
allData = problem.shifted_data;
layers = problem.layers;
ssubs = problem.ssubs;
numberOfContrasts = problem.numberOfContrasts;
backs = problem.backgrounds;
res = problem.resolutions;
nParams = length(problem.params);
fits = problem.calculations.reflectivity;

chis = chiSquared(allData{1},fits{1},nParams);
%chis = chiSquared(allData,fits,nParams,numberOfContrasts);






