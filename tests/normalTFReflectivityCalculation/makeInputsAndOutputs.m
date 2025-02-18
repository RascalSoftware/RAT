% This is a helper function to make the inputs and outputs for the Unit
% Tests. When changes are made to projectClass and controlsClass, it is
% necessary to run this function so that the changes (i.e. number of
% fields) are set in inputs and outputs to the tests.

%% 1. Custom Layers.
root = getappdata(0,'root');
customLayersProblem = orsoDSPCCustomLayers();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemStruct,problemLimits,controls] = parseClassToStructs(customLayersProblem,controlsInput);

inputs.project = customLayersProblem;
inputs.problemStruct = problemStruct;
inputs.problemLimits = problemLimits;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save([root filesep 'tests/normalTFReflectivityCalculation/customLayersInputs'],'inputs');

% (b) Outputs
resultStruct = reflectivityCalculation(problemStruct,controls);

outputs.resultStruct = resultStruct;

[problemStruct,resultStructMain,bayesResults] = RATMain(problemStruct,problemLimits,controls);

outputs.problemStruct = problemStruct;
outputs.resultStructMain = resultStructMain;
outputs.bayesResults = bayesResults;

[project, result] = RAT(customLayersProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save([root filesep 'tests/normalTFReflectivityCalculation/customLayersOutputs'],'outputs');

% (c) TF Parameters
[qzshifts,scalefactors,bulkIn,bulkOut,chis,reflectivity,simulation,...
 shiftedData,backgrounds,resolutions,layerSlds,sldProfiles,...
 resampledLayers,subRoughs] = normalTF.customLayers(problemStruct,controls);

TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.chis = chis;
TFParams.subRoughs = subRoughs;

TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.backgrounds = backgrounds;
TFParams.resolutions = resolutions;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.resampledLayers = resampledLayers;

save([root filesep 'tests/normalTFReflectivityCalculation/customLayersTFParams'],'TFParams');

%% 2. Custom XY.
% (a) Inputs
customXYProblem = DPPCCustomXYScript();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemStruct,problemLimits,controls] = parseClassToStructs(customXYProblem,controlsInput);

inputs.project = customXYProblem;
inputs.problemStruct = problemStruct;
inputs.problemLimits = problemLimits;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save([root filesep 'tests/normalTFReflectivityCalculation/customXYInputs'],'inputs');

% (b) Outputs
resultStruct = reflectivityCalculation(problemStruct,controls);

outputs.resultStruct = resultStruct;

[problemStruct,resultStructMain,bayesResults] = RATMain(problemStruct,problemLimits,controls);

outputs.problemStruct = problemStruct;
outputs.resultStructMain = resultStructMain;
outputs.bayesResults = bayesResults;

[project, result] = RAT(customXYProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save([root filesep 'tests/normalTFReflectivityCalculation/customXYOutputs'],'outputs');

% (c) TF Parameters
[qzshifts,scalefactors,bulkIn,bulkOut,chis,reflectivity,simulation,...
 shiftedData,backgrounds,resolutions,layerSlds,sldProfiles,...
 resampledLayers,subRoughs] = normalTF.customXY(problemStruct,controls);

TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.chis = chis;
TFParams.subRoughs = subRoughs;

TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.backgrounds = backgrounds;
TFParams.resolutions = resolutions;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.resampledLayers = resampledLayers;

save([root filesep 'tests/normalTFReflectivityCalculation/customXYTFParams'],'TFParams');

%% 3. Standard Layers
% (a) Inputs
standardProblem = DPPCStandardLayers();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemStruct,problemLimits,controls] = parseClassToStructs(standardProblem,controlsInput);

inputs.project = standardProblem;
inputs.problemStruct = problemStruct;
inputs.problemLimits = problemLimits;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save([root filesep 'tests/normalTFReflectivityCalculation/standardLayersInputs'],'inputs');

% (b) Outputs
resultStruct = reflectivityCalculation(problemStruct,controls);

outputs.resultStruct = resultStruct;

[problemStruct,resultStructMain,bayesResults] = RATMain(problemStruct,problemLimits,controls);

outputs.problemStruct = problemStruct;
outputs.resultStructMain = resultStructMain;
outputs.bayesResults = bayesResults;

[project, result] = RAT(standardProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save([root filesep 'tests/normalTFReflectivityCalculation/standardLayersOutputs'],'outputs');

% (c) TF Parameters
[qzshifts,scalefactors,bulkIn,bulkOut,chis,reflectivity,simulation,...
 shiftedData,backgrounds,resolutions,layerSlds,sldProfiles,...
 resampledLayers,subRoughs] = normalTF.standardLayers(problemStruct,controls);

TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.chis = chis;
TFParams.subRoughs = subRoughs;

TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.backgrounds = backgrounds;
TFParams.resolutions = resolutions;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.resampledLayers = resampledLayers;

save([root filesep 'tests/normalTFReflectivityCalculation/standardLayersTFParams'],'TFParams');

%% 4. Absorption
% (a) Inputs
absorptionProblem = DPPCAbsorption();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemStruct,problemLimits,controls] = parseClassToStructs(absorptionProblem,controlsInput);

inputs.project = absorptionProblem;
inputs.problemStruct = problemStruct;
inputs.problemLimits = problemLimits;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save([root filesep 'tests/normalTFReflectivityCalculation/absorptionInputs'],'inputs');

% (b) Outputs
resultStruct = reflectivityCalculation(problemStruct,controls);

outputs.resultStruct = resultStruct;

[problemStruct,resultStructMain,bayesResults] = RATMain(problemStruct,problemLimits,controls);

outputs.problemStruct = problemStruct;
outputs.resultStructMain = resultStructMain;
outputs.bayesResults = bayesResults;

[project, result] = RAT(absorptionProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save([root filesep 'tests/normalTFReflectivityCalculation/absorptionOutputs'],'outputs');

% (c) TF Parameters
[qzshifts,scalefactors,bulkIn,bulkOut,chis,reflectivity,simulation,...
 shiftedData,backgrounds,resolutions,layerSlds,sldProfiles,...
 resampledLayers,subRoughs] = normalTF.customLayers(problemStruct,controls);

TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.chis = chis;
TFParams.subRoughs = subRoughs;

TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.backgrounds = backgrounds;
TFParams.resolutions = resolutions;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.resampledLayers = resampledLayers;

save([root filesep 'tests/normalTFReflectivityCalculation/absorptionTFParams'],'TFParams');

%% 5. Converting between RAT and RASCAL

thisProjectClass = r1ToProjectClass([root filesep 'tests/testProjectConversion/DSPCBilayerStructInput.mat']);
save([root filesep 'tests/testProjectConversion/DSPCBilayerProjectClass.mat'], 'thisProjectClass');

thisProjectClass = r1ToProjectClass([root filesep 'tests/testProjectConversion/monolayerVolumeModel.mat']);
save([root filesep 'tests/testProjectConversion/monolayerVolumeModelProjectClass.mat'], 'thisProjectClass');
