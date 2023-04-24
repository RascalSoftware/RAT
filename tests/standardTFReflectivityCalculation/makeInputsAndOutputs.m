% This is a helper function to make the inputs and outputs for the Unit
% Tests. When changes are made to projectClass and controlsClass, it is
% necessary to run this function so that the changes (i.e. number of
% fields) are set in inputs and outputs to the tests.

% Paul Sharp 18/01/23 -- Fixed bugs in making test data and added new
% objects to the files. Changed class names to enable parameterised
% testing.
% Paul Sharp 12/04/23 -- Added code to update the test data for converting
% between RAT and RASCAL

%% 1. Custom Layers.
root = getappdata(0,'root');
customLayersProblem = orsoDSPCCustomLayers();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(customLayersProblem,controlsInput);

inputs.problemDefInput = customLayersProblem;
inputs.problemDef = problemDef;
inputs.problemDefCells = problemDefCells;
inputs.problemDefLimits = problemDefLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'customLayersInputs'],'inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RATMain(problemDef,problemDefCells,problemDefLimits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(customLayersProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'customLayersOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTFReflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shifted_data;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
 Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
 allRoughs] = standardTFCustomLayersSingle(problemDef,problemDefCells,...
              problemDefLimits,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgs = backgs;
TFParams.qshifts = qshifts;
TFParams.sfs = sfs;
TFParams.nbas = nbas;
TFParams.nbss = nbss;
TFParams.resols = resols;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'customLayersTFParams'],'TFParams');

%% 2. Custom XY.
% (a) Inputs
customXYProblem = DPPCCustomXYScript();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(customXYProblem,controlsInput);

inputs.problemDefInput = customXYProblem;
inputs.problemDef = problemDef;
inputs.problemDefCells = problemDefCells;
inputs.problemDefLimits = problemDefLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'customXYInputs'],'inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RATMain(problemDef,problemDefCells,problemDefLimits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(customXYProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'customXYOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTFReflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shifted_data;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
 Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
 allRoughs] = standardTFCustomXYSingle(problemDef,problemDefCells,...
              problemDefLimits,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgs = backgs;
TFParams.qshifts = qshifts;
TFParams.sfs = sfs;
TFParams.nbas = nbas;
TFParams.nbss = nbss;
TFParams.resols = resols;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'customXYTFParams'],'TFParams');

%% 3. Standard Layers
% (a) Inputs
standardProblem = DPPCStandardLayers();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(standardProblem,controlsInput);

inputs.problemDefInput = standardProblem;
inputs.problemDef = problemDef;
inputs.problemDefCells = problemDefCells;
inputs.problemDefLimits = problemDefLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'standardLayersInputs'],'inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

outputs.problem = problem;
outputs.result = result;

[problemOutStruct,~,~,bayesResults] = RATMain(problemDef,problemDefCells,problemDefLimits,controls,priors);

outputs.problemOutStruct = problemOutStruct;
outputs.bayesResults = bayesResults;

resultOutStruct = parseResultToStruct(problem,result);

outputs.resultOutStruct = resultOutStruct;

[problemOut, resultOut] = RAT(standardProblem,controlsInput);

outputs.problemOut = problemOut;
outputs.resultOut = resultOut;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'standardLayersOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTFReflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shifted_data;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
 Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
 allRoughs] = standardTFStandardLayersSingle(problemDef,problemDefCells,...
              problemDefLimits,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgs = backgs;
TFParams.qshifts = qshifts;
TFParams.sfs = sfs;
TFParams.nbas = nbas;
TFParams.nbss = nbss;
TFParams.resols = resols;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'standardTFReflectivityCalculation' filesep 'standardLayersTFParams'],'TFParams');

%% 4. Converting betwwen RAT and RASCAL

thisProjectClass = r1ToProjectClass('originalDSPCBilayerStructInput.mat');
save('tests/testProjectConversion/originalDSPCBilayerProjectClass.mat', 'thisProjectClass')

thisProjectClass = r1ToProjectClass('monolayerVolumeModel.mat');
save('tests/testProjectConversion/monolayerVolumeModelProjectClass.mat', 'thisProjectClass')
