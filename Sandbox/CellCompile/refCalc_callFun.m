callParams = load('callParams.mat');
callParams = callParams.callParams;

problemDef = callParams.problemDef;
problemDef_cells = callParams.problemDef_cells;
problemDef_limits = callParams.problemDef_limits;
controls = callParams.controls;

[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);
