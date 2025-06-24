

% Main file for working on the converter....

% 1. Make the project from a json file....
problem = jsonToProject('DSPC_standard_layers.json');

% Add the missing resolution (for this version...)
for i = 1:problem.contrasts.numberOfContrasts
    problem.setContrast(i,'Resolution','Resolution 1');
end

% % Also show the priors....
% problem.showPriors = false;

% Call the backwards conversion...
projectToJson(problem,'TestFile');

% 2. Convert from a normal project...
standardLayersDSPCScript;

% Call the conversion...
projectToJson(problem,'TestFile');



