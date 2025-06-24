

% Main file for working on the converter....
% 
% % 1. Make the project from a json file....
% problem = jsonToProject('DSPC_custom_layers.json');
% 
% % Call the backwards conversion...
% projectToJson(problem,'TestFile');

% 2. Convert from a normal project...
customLayersDSPCScript;

% Call the conversion...
projectToJson(problem,'TestFile');



