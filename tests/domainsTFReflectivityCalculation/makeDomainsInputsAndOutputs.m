% This is a helper function to make the inputs and outputs for the Unit
% Tests. When changes are made to projectClass and controlsClass, it is
% necessary to run this function so that the changes (i.e. number of
% fields) are set in inputs and outputs to the tests.

%% 1. Standard Layers
% (a) Inputs
standardProblem = domainsStandardLayers();
controlsInput = controlsClass();

% Supress printing of RAT output for testing
controlsInput.display = 'off';

[problemStruct,problemCells,problemLimits,priors,controls] = parseClassToStructs(standardProblem,controlsInput);

inputs.project = standardProblem;
inputs.problemStruct = problemStruct;
inputs.problemCells = problemCells;
inputs.problemLimits = problemLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsStandardLayersInputs'],'inputs');

% (b) Outputs
[contrastParams,resultCells] = reflectivityCalculation(problemStruct,problemCells,controls);

outputs.contrastParams = contrastParams;
outputs.resultCells = resultCells;

[problemStruct,contrastParamsMain,resultCellsMain,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors);

outputs.problemStruct = problemStruct;
outputs.contrastParamsMain = contrastParamsMain;
outputs.resultCellsMain = resultCellsMain;
outputs.bayesResults = bayesResults;

resultStruct = parseResultToStruct(contrastParams,resultCells);

outputs.resultStruct = resultStruct;

[project, result] = RAT(standardProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsStandardLayersOutputs'],'outputs');

% (c) TF Parameters
[contrastParams,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = domainsTF.reflectivityCalculation(problemStruct,problemCells,controls);

TFParams.contrastParams = contrastParams;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,...
 resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = domainsTF.standardLayers.single(problemStruct,problemCells,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgroundParams = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsStandardLayersTFParams'],'TFParams');

%% 2. Custom XY.
% (a) Inputs
customXYProblem = domainsCustomXY();
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

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomXYInputs'],'inputs');

% (b) Outputs
[contrastParams,resultCells] = reflectivityCalculation(problemStruct,problemCells,controls);

outputs.contrastParams = contrastParams;
outputs.resultCells = resultCells;

[problemStruct,contrastParamsMain,resultCellsMain,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors);

outputs.problemStruct = problemStruct;
outputs.contrastParamsMain = contrastParamsMain;
outputs.resultCellsMain = resultCellsMain;
outputs.bayesResults = bayesResults;

resultStruct = parseResultToStruct(contrastParams,resultCells);

outputs.resultStruct = resultStruct;

[project, result] = RAT(customXYProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomXYOutputs'],'outputs');

% (c) TF Parameters
[contrastParams,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = domainsTF.reflectivityCalculation(problemStruct,problemCells,controls);

TFParams.contrastParams = contrastParams;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,...
 resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = domainsTF.customXY.single(problemStruct,problemCells,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgroundParams = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomXYTFParams'],'TFParams');

%% 3. Custom Layers.
root = getappdata(0,'root');
customLayersProblem = domainsCustomLayers();
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

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomLayersInputs'],'inputs');

% (b) Outputs
[contrastParams,resultCells] = reflectivityCalculation(problemStruct,problemCells,controls);

outputs.contrastParams = contrastParams;
outputs.resultCells = resultCells;

[problemStruct,contrastParamsMain,resultCellsMain,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors);

outputs.problemStruct = problemStruct;
outputs.contrastParamsMain = contrastParamsMain;
outputs.resultCellsMain = resultCellsMain;
outputs.bayesResults = bayesResults;

resultStruct = parseResultToStruct(contrastParams,resultCells);

outputs.resultStruct = resultStruct;

[project, result] = RAT(customLayersProblem,controlsInput);

outputs.project = project;
outputs.result = result;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomLayersOutputs'],'outputs');

% (c) TF Parameters
[contrastParams,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = domainsTF.reflectivityCalculation(problemStruct,problemCells,controls);

TFParams.contrastParams = contrastParams;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,...
 resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = domainsTF.customLayers.single(problemStruct,problemCells,controls);

TFParams.outSsubs = outSsubs;
TFParams.backgrounds = backgroundParams;
TFParams.qzshifts = qzshifts;
TFParams.scalefactors = scalefactors;
TFParams.bulkIn = bulkIn;
TFParams.bulkOut = bulkOut;
TFParams.resolutionParams = resolutionParams;
TFParams.chis = chis;
TFParams.allRoughs = allRoughs;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomLayersTFParams'],'TFParams');
