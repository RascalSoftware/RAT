% This is a helper function to make the inputs and outputs for the Unit
% Tests. When changes are made to projectClass and controlsDef, it is
% necessary to run this function fo that the changes (i.e. number of
% fields) are set in inputs and outputs to the tests.


% 1. Custom Layers.
ratRoot = getappdata(0,'ratRoot');
customProblem = orsoDSPC_custLay_script();
controls = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(problemDefInput,controls);

customLayersInputs.problemDef = problemDef;
customLayersInputs.problemDef_cells = problemDef_cells;
customLayersInputs.problemDef_limits = problemDef_limits;
customLayersInputs.controls = controls;

save('customLayersInputs','customLayersInputs');

% 2. Custom XY.
% (a) Inputs
ratRoot = getappdata(0,'ratRoot');
customProblem = DPPC_custXY_script();
controls = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(customProblem,controls);

customXYInputs.problemDef = problemDef;
customXYInputs.problemDef_cells = problemDef_cells;
customXYInputs.problemDef_limits = problemDef_limits;
customXYInputs.controls = controls;

save('customXYInputs','customXYInputs');

% (b) Outputs
[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

customXYOutput.problem = problem;
customXYOutput.result = result;

save('customXYOutput','customXYOutput');

% 3. Standard Layers
% (a) Inputs
standardProblem = DPPC_standard_layers();
controls = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(customProblem,controls);

standardLayersInputs.problemDef = problemDef;
standardLayersInputs.problemDef_cells = problemDef_cells;
standardLayersInputs.problemDef_limits = problemDef_limits;
standardLayersInputs.controls = controls;

save('standardLayersInputs','standardLayersInputs');

% (b) Outputs
[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

standardLayersOutput.problem = problem;
standardLayersOutput.result = result;

save('standardLayersOutput','standardLayersOutput');





