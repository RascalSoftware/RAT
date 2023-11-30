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

[problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(customLayersProblem,controlsInput);

inputs.problemDefInput = customLayersProblem;
inputs.problemDef = problemDef;
inputs.problemDefCells = problemDefCells;
inputs.problemDefLimits = problemDefLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'customLayersInputs'],'inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);

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

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'customLayersOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = nonPolarisedTF.reflectivityCalculation(problemDef,problemDefCells,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams,chis,reflectivity,...
 simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = nonPolarisedTF.customLayers.single(problemDef,problemDefCells,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgroundParams = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'customLayersTFParams'],'TFParams');

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

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'customXYInputs'],'inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);

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

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'customXYOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = nonPolarisedTF.reflectivityCalculation(problemDef,problemDefCells,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,...
 resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = nonPolarisedTF.customXY.single(problemDef,problemDefCells,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgroundParams = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'customXYTFParams'],'TFParams');

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

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'standardLayersInputs'],'inputs');

% (b) Outputs
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);

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

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'standardLayersOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = nonPolarisedTF.reflectivityCalculation(problemDef,problemDefCells,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,...
 resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = nonPolarisedTF.standardLayers.single(problemDef,problemDefCells,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgroundParams = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'nonPolarisedTFReflectivityCalculation' filesep 'standardLayersTFParams'],'TFParams');

%% 4. Converting between RAT and RASCAL

thisProjectClass = r1ToProjectClass('DSPCBilayerStructInput.mat');
save('tests/testProjectConversion/DSPCBilayerProjectClass.mat', 'thisProjectClass');

thisProjectClass = r1ToProjectClass('monolayerVolumeModel.mat');
save('tests/testProjectConversion/monolayerVolumeModelProjectClass.mat', 'thisProjectClass');
