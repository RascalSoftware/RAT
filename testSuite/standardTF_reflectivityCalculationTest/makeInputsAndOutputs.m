% This is a helper function to make the inputs and outputs for the Unit
% Tests. When changes are made to projectClass and controlsDef, it is
% necessary to run this function so that the changes (i.e. number of
% fields) are set in inputs and outputs to the tests.

% Paul Sharp 17/01/23 -- Fixed bugs in making test data and added new
% objects to the files

%%
% 1. Custom Layers.
ratRoot = getappdata(0,'ratRoot');
customLayersProblem = orsoDSPC_custLay_script();
controlsInput = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(customLayersProblem,controlsInput);

customLayersInputs.ProblemDefInput = customLayersProblem;
customLayersInputs.problemDef = problemDef;
customLayersInputs.problemDef_cells = problemDef_cells;
customLayersInputs.problemDef_limits = problemDef_limits;
customLayersInputs.priors = priors;
customLayersInputs.controlsInput = controlsInput;
customLayersInputs.controls = controls;

save('customLayersInputs','customLayersInputs');

% (b) Outputs
[problem, result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

customLayersOutputs.problem = problem;
customLayersOutputs.result = result;

[problemOut, resultOut] = RAT(customLayersProblem,controlsInput);

customLayersOutputs.problemOut = problemOut;
customLayersOutputs.resultOut = resultOut;

save('customLayersOutputs','customLayersOutputs');

%%
% 2. Custom XY.
% (a) Inputs
ratRoot = getappdata(0,'ratRoot');
customXYProblem = DPPC_custXY_script();
controlsInput = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(customXYProblem,controlsInput);

customXYInputs.problemDefInput = customXYProblem;
customXYInputs.problemDef = problemDef;
customXYInputs.problemDef_cells = problemDef_cells;
customXYInputs.problemDef_limits = problemDef_limits;
customXYInputs.priors = priors;
customXYInputs.controlsInput = controlsInput;
customXYInputs.controls = controls;

save('customXYInputs','customXYInputs');

% (b) Outputs
[problem, result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

customXYOutputs.problem = problem;
customXYOutputs.result = result;

[problemOut, resultOut] = RAT(customXYProblem,controlsInput);

customXYOutputs.problemOut = problemOut;
customXYOutputs.resultOut = resultOut;

save('customXYOutputs','customXYOutputs');

%%
% 3. Standard Layers
% (a) Inputs
standardProblem = DPPC_standard_layers();
controlsInput = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(standardProblem,controlsInput);

standardLayersInputs.problemDefInput = standardProblem;
standardLayersInputs.problemDef = problemDef;
standardLayersInputs.problemDef_cells = problemDef_cells;
standardLayersInputs.problemDef_limits = problemDef_limits;
standardLayersInputs.priors = priors;
standardLayersInputs.controlsInput = controlsInput;
standardLayersInputs.controls = controls;

save('standardLayersInputs','standardLayersInputs');

% (b) Outputs
[problem, result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

standardLayersOutputs.problem = problem;
standardLayersOutputs.result = result;

[problemOut, resultOut] = RAT(standardProblem,controlsInput);

standardLayersOutputs.problemOut = problemOut;
standardLayersOutputs.resultOut = resultOut;

save('standardLayersOutputs','standardLayersOutputs');