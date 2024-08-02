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

[problemStruct,problemCells,problemLimits,priors,controls] = parseClassToStructs(customLayersProblem,controlsInput);

inputs.project = customLayersProblem;
inputs.problemStruct = problemStruct;
inputs.problemCells = problemCells;
inputs.problemLimits = problemLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/customLayersInputs'],'inputs');

% (b) Outputs
resultStruct = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);

outputs.resultStruct = resultStruct;

[problemStruct,resultStructMain,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors);

outputs.problemStruct = problemStruct;
outputs.resultStructMain = resultStructMain;
outputs.bayesResults = bayesResults;

[project, result] = RAT(customLayersProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/customLayersOutputs'],'outputs');

% (c) TF Parameters
[contrastParams,calculationResults,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,resampledLayers] = nonPolarisedTF.reflectivityCalculation(problemStruct,problemCells,controls);

TFParams.contrastParams = contrastParams;
TFParams.calculationResults = calculationResults;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.resampledLayers = resampledLayers;

[backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,...
 chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,...
 resampledLayers,subRoughs] = nonPolarisedTF.customLayers(problemStruct,problemCells,controls);

TFParams.backgroundParams = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.subRoughs = subRoughs;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/customLayersTFParams'],'TFParams');

%% 2. Custom XY.
% (a) Inputs
customXYProblem = DPPCCustomXYScript();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemStruct,problemCells,problemLimits,priors,controls] = parseClassToStructs(customXYProblem,controlsInput);

inputs.project = customXYProblem;
inputs.problemStruct = problemStruct;
inputs.problemCells = problemCells;
inputs.problemLimits = problemLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/customXYInputs'],'inputs');

% (b) Outputs
resultStruct = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);

outputs.resultStruct = resultStruct;

[problemStruct,resultStructMain,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors);

outputs.problemStruct = problemStruct;
outputs.resultStructMain = resultStructMain;
outputs.bayesResults = bayesResults;

[project, result] = RAT(customXYProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/customXYOutputs'],'outputs');

% (c) TF Parameters
[contrastParams,calculationResults,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,resampledLayers] = nonPolarisedTF.reflectivityCalculation(problemStruct,problemCells,controls);

TFParams.contrastParams = contrastParams;
TFParams.calculationResults = calculationResults;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.resampledLayers = resampledLayers;

[backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,...
 chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,...
 resampledLayers, subRoughs] = nonPolarisedTF.customXY(problemStruct,problemCells,controls);

TFParams.backgroundParams = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.subRoughs = subRoughs;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/customXYTFParams'],'TFParams');

%% 3. Standard Layers
% (a) Inputs
standardProblem = DPPCStandardLayers();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemStruct,problemCells,problemLimits,priors,controls] = parseClassToStructs(standardProblem,controlsInput);
[problemStruct,~] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

inputs.project = standardProblem;
inputs.problemStruct = problemStruct;
inputs.problemCells = problemCells;
inputs.problemLimits = problemLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/standardLayersInputs'],'inputs');

% (b) Outputs
resultStruct = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);

outputs.resultStruct = resultStruct;

[problemStruct,resultStructMain,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors);

outputs.problemStruct = problemStruct;
outputs.resultStructMain = resultStructMain;
outputs.bayesResults = bayesResults;

[project, result] = RAT(standardProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/standardLayersOutputs'],'outputs');

% (c) TF Parameters
[contrastParams,calculationResults,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,resampledLayers] = nonPolarisedTF.reflectivityCalculation(problemStruct,problemCells,controls);

TFParams.contrastParams = contrastParams;
TFParams.calculationResults = calculationResults;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.resampledLayers = resampledLayers;

[backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,...
 chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,...
 resampledLayers,subRoughs] = nonPolarisedTF.standardLayers(problemStruct,problemCells,controls);

TFParams.backgroundParams = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.subRoughs = subRoughs;

save([root filesep 'tests/nonPolarisedTFReflectivityCalculation/standardLayersTFParams'],'TFParams');

%% 4. Converting between RAT and RASCAL

thisProjectClass = r1ToProjectClass([root filesep 'tests/testProjectConversion/DSPCBilayerStructInput.mat']);
save([root filesep 'tests/testProjectConversion/DSPCBilayerProjectClass.mat'], 'thisProjectClass');

thisProjectClass = r1ToProjectClass([root filesep 'tests/testProjectConversion/monolayerVolumeModel.mat']);
save([root filesep 'tests/testProjectConversion/monolayerVolumeModelProjectClass.mat'], 'thisProjectClass');
