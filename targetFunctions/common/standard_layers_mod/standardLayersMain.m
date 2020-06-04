a = load('testProblem.mat');
problem = a.problem;
problem = legacyChanges(problem);

params = problem.params;
%contrastLayers = problem.contrastLayers;
contrastLayers = problem.contrastLayers{1};
numberOfLayers = problem.numberOfLayers;
layersDetails = problem.layersDetails;
[layersList,sRoughs] = standard_layers_mod(params,contrastLayers,numberOfLayers,layersDetails);