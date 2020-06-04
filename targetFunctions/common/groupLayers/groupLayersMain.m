problem = load('groupLayers_problem');
problem = problem.problem;

%problem = groupLayers(problem);

allLayers = problem.allLayers;
allRoughs = problem.allSubrough;
numberOfContrasts = problem.numberOfContrasts;
geometry = problem.module.experiment_type;
nbairs = problem.nbairs;
nbsubs = problem.nbsubs;
allRoughs = cell2mat(allRoughs);

i = 1;
[outLayers, outSsubs] = groupLayers_Mod(allLayers{i},allRoughs(i),geometry,nbairs(i),nbsubs(i));


problem.layers = outLayers;
problem.ssubs = outSsubs;