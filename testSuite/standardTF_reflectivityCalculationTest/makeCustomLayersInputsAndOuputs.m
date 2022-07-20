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

