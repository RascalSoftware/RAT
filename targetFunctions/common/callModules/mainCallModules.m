a = load('volumeModel.mat');
%a = load('standardLayers.mat');

problem = a.problem;

problem = legacyChanges(problem);

params = problem.params;
numberOfContrasts = problem.numberOfContrasts;
contrastLayers = problem.contrastLayers_new;
numberOfLayers = problem.numberOfLayers;
layersDetails = problem.layersDetails;
whichType = problem.module.type;
fileHandle = problem.module.fileHandle;
nbairs = problem.nbairs;
nbsubs = problem.nbsubs;
[allLayers,allRoughs] = callModules(params,numberOfContrasts,contrastLayers,numberOfLayers,layersDetails,whichType,fileHandle,nbairs,nbsubs);
problem.allLayers = allLayers;
problem.allSubrough = allRoughs;