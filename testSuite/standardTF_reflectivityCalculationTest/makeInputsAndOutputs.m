% This is a helper function to make the inputs and outputs for the Unit
% Tests. When changes are made to projectClass and controlsDef, it is
% necessary to run this function so that the changes (i.e. number of
% fields) are set in inputs and outputs to the tests.

% Paul Sharp 18/01/23 -- Fixed bugs in making test data and added new
% objects to the files. Changed class names to enable parameterised
% testing.

%%
% 1. Custom Layers.
ratRoot = getappdata(0,'ratRoot');
customLayersProblem = orsoDSPC_custLay_script();
controlsInput = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(customLayersProblem,controlsInput);

inputs.problemDefInput = customLayersProblem;
inputs.problemDef = problemDef;
inputs.problemDef_cells = problemDef_cells;
inputs.problemDef_limits = problemDef_limits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save('testSuite\standardTF_reflectivityCalculationTest\customLayersInputs','inputs');

% (b) Outputs
[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(customLayersProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save('testSuite\standardTF_reflectivityCalculationTest\customLayersOutputs','outputs');

%%
% 2. Custom XY.
% (a) Inputs
ratRoot = getappdata(0,'ratRoot');
customXYProblem = DPPC_custXY_script();
controlsInput = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(customXYProblem,controlsInput);

inputs.problemDefInput = customXYProblem;
inputs.problemDef = problemDef;
inputs.problemDef_cells = problemDef_cells;
inputs.problemDef_limits = problemDef_limits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save('testSuite\standardTF_reflectivityCalculationTest\customXYInputs','inputs');

% (b) Outputs
[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(customXYProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save('testSuite\standardTF_reflectivityCalculationTest\customXYOutputs','outputs');

%%
% 3. Standard Layers
% (a) Inputs
standardProblem = DPPC_standard_layers();
controlsInput = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(standardProblem,controlsInput);

inputs.problemDefInput = standardProblem;
inputs.problemDef = problemDef;
inputs.problemDef_cells = problemDef_cells;
inputs.problemDef_limits = problemDef_limits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save('testSuite\standardTF_reflectivityCalculationTest\standardLayersInputs','inputs');

% (b) Outputs
[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(standardProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save('testSuite\standardTF_reflectivityCalculationTest\standardLayersOutputs','outputs');