global RAT_DEBUG DEBUGVARS

RAT_DEBUG = 0;
DEBUGVARS = 0;


%callParams = load('callParams.mat');

%callParams = load('newInputs_AL.mat');
%callParams = callParams.newInputs;
% callParams = load('newVars.mat');
% callParams = callParams.newVars;
callParams = load('callVars_latest.mat');
%callParams.callVars.problemDef.modelLanguage = 'matlab';
callParams = callParams.callVars;


% callParams = load('customVars.mat');
% callParams = callParams.customVars;


problemDef = callParams.problemDef;
problemDef_cells = callParams.problemDef_cells;
problemDef_limits = callParams.problemDef_limits;
controls = callParams.controls;
probleDef.modelFilename = ' ';

%controls.para = 'all';

[problem,result] = reflectivity_calculation_gpu(problemDef,problemDef_cells,problemDef_limits,controls);

disp('debug');

disp(problem.calculations.sum_chi)
