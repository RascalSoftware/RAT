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

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = parseClassToStructs(customLayersProblem,controlsInput);

inputs.problemDefInput = customLayersProblem;
inputs.problemDef = problemDef;
inputs.problemDef_cells = problemDef_cells;
inputs.problemDef_limits = problemDef_limits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save('tests\standardTFReflectivityCalculation\customLayersInputs','inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RATMain(problemDef,problemDef_cells,problemDef_limits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(customLayersProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save('tests\standardTFReflectivityCalculation\customLayersOutputs','outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shifted_data;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
 Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
 allRoughs] = standardTF_custlay_single(problemDef,problemDef_cells,...
              problemDef_limits,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgs = backgs;
TFParams.qshifts = qshifts;
TFParams.sfs = sfs;
TFParams.nbas = nbas;
TFParams.nbss = nbss;
TFParams.resols = resols;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save('tests\standardTFReflectivityCalculation\customLayersTFParams','TFParams');

%%
% 2. Custom XY.
% (a) Inputs
ratRoot = getappdata(0,'ratRoot');
customXYProblem = DPPC_custXY_script();
controlsInput = controlsDef();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = parseClassToStructs(customXYProblem,controlsInput);

inputs.problemDefInput = customXYProblem;
inputs.problemDef = problemDef;
inputs.problemDef_cells = problemDef_cells;
inputs.problemDef_limits = problemDef_limits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save('tests\standardTFReflectivityCalculation\customXYInputs','inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RATMain(problemDef,problemDef_cells,problemDef_limits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(customXYProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save('tests\standardTFReflectivityCalculation\customXYOutputs','outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shifted_data;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
 Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
 allRoughs] = standardTF_custXY_single(problemDef,problemDef_cells,...
              problemDef_limits,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgs = backgs;
TFParams.qshifts = qshifts;
TFParams.sfs = sfs;
TFParams.nbas = nbas;
TFParams.nbss = nbss;
TFParams.resols = resols;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save('tests\standardTFReflectivityCalculation\customXYTFParams','TFParams');

%%
% 3. Standard Layers
% (a) Inputs
standardProblem = DPPC_standard_layers();
controlsInput = controlsDef();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = parseClassToStructs(standardProblem,controlsInput);

inputs.problemDefInput = standardProblem;
inputs.problemDef = problemDef;
inputs.problemDef_cells = problemDef_cells;
inputs.problemDef_limits = problemDef_limits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save('tests\standardTFReflectivityCalculation\standardLayersInputs','inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RATMain(problemDef,problemDef_cells,problemDef_limits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(standardProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save('tests\standardTFReflectivityCalculation\standardLayersOutputs','outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shifted_data;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
 Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
 allRoughs] = standardTF_stanlay_single(problemDef,problemDef_cells,...
              problemDef_limits,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgs = backgs;
TFParams.qshifts = qshifts;
TFParams.sfs = sfs;
TFParams.nbas = nbas;
TFParams.nbss = nbss;
TFParams.resols = resols;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save('tests\standardTFReflectivityCalculation\standardLayersTFParams','TFParams');