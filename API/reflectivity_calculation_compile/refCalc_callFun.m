% global RAT_DEBUG DEBUGVARS
% 
% RAT_DEBUG = 0;
% DEBUGVARS = 0;


callParams = load('callVars.mat');
callParams = callParams.callVars;


problemDef = callParams.problemDef;
problemDef_cells = callParams.problemDef_cells;
problemDef_limits = callParams.problemDef_limits;
controls = callParams.controls;

probleDef.modelFilename = ' ';
[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);
