global RAT_DEBUG DEBUGVARS

RAT_DEBUG = 0;
DEBUGVARS = 0;


%callParams = load('callParams.mat');

%callParams = load('newInputs_AL.mat');
%callParams = callParams.newInputs;
% callParams = load('newVars.mat');
% callParams = callParams.newVars;
%callParams = load('callVars_latest.mat');
callParams = load('callVars_14_4.mat');
%callParams.callVars.problemDef.modelLanguage = 'matlab';
%callParams = callParams.callVars;
callParams = callParams.callVars;


% callParams = load('customVars.mat');
% callParams = callParams.customVars;


problemDef = callParams.problemDef;
problemDef_cells = callParams.problemDef_cells;
problemDef_limits = callParams.problemDef_limits;
controls = callParams.problemDef_controls;
probleDef.modelFilename = ' ';

%controls.para = 'all';

[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

disp('debug');

disp(problem.calculations.sum_chi)
