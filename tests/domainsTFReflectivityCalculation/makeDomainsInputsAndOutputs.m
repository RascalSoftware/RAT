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

[problemDefStruct,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(standardProblem,controlsInput);

inputs.problemDefInput = standardProblem;
inputs.problemDefStruct = problemDefStruct;
inputs.problemDefCells = problemDefCells;
inputs.problemDefLimits = problemDefLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsStandardLayersInputs'],'inputs');

% (b) Outputs
[problem,resultCells] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);

outputs.problem = problem;
outputs.resultCells = resultCells;

[problemDefStruct,problemMain,resultCellsMain,bayesResults] = RATMain(problemDefStruct,problemDefCells,problemDefLimits,controls,priors);

outputs.problemDefStruct = problemDefStruct;
outputs.problemMain = problemMain;
outputs.resultCellsMain = resultCellsMain;
outputs.bayesResults = bayesResults;

resultStruct = parseResultToStruct(problem,resultCells);

outputs.resultStruct = resultStruct;

[problemDefOutput, result] = RAT(standardProblem,controlsInput);

outputs.problemDefOutput = problemDefOutput;
outputs.result = result;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsStandardLayersOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = domainsTF.reflectivityCalculation(problemDefStruct,problemDefCells,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,...
 resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = domainsTF.standardLayers.single(problemDefStruct,problemDefCells,controls);

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

[problemDefStruct,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(customXYProblem,controlsInput);

inputs.problemDefInput = customXYProblem;
inputs.problemDefStruct = problemDefStruct;
inputs.problemDefCells = problemDefCells;
inputs.problemDefLimits = problemDefLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomXYInputs'],'inputs');

% (b) Outputs
[problem,resultCells] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);

outputs.problem = problem;
outputs.resultCells = resultCells;

[problemDefStruct,problemMain,resultCellsMain,bayesResults] = RATMain(problemDefStruct,problemDefCells,problemDefLimits,controls,priors);

outputs.problemDefStruct = problemDefStruct;
outputs.problemMain = problemMain;
outputs.resultCellsMain = resultCellsMain;
outputs.bayesResults = bayesResults;

resultStruct = parseResultToStruct(problem,resultCells);

outputs.resultStruct = resultStruct;

[problemDefOutput, result] = RAT(customXYProblem,controlsInput);

outputs.problemDefOutput = problemDefOutput;
outputs.result = result;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomXYOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = domainsTF.reflectivityCalculation(problemDefStruct,problemDefCells,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,...
 resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = domainsTF.customXY.single(problemDefStruct,problemDefCells,controls);

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

[problemDefStruct,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(customLayersProblem,controlsInput);

inputs.problemDefInput = customLayersProblem;
inputs.problemDefStruct = problemDefStruct;
inputs.problemDefCells = problemDefCells;
inputs.problemDefLimits = problemDefLimits;
inputs.priors = priors;
inputs.controlsInput = controlsInput;
inputs.controls = controls;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomLayersInputs'],'inputs');

% (b) Outputs
[problem,resultCells] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);

outputs.problem = problem;
outputs.resultCells = resultCells;

[problemDefStruct,problemMain,resultCellsMain,bayesResults] = RATMain(problemDefStruct,problemDefCells,problemDefLimits,controls,priors);

outputs.problemDefStruct = problemDefStruct;
outputs.problemMain = problemMain;
outputs.resultCellsMain = resultCellsMain;
outputs.bayesResults = bayesResults;

resultStruct = parseResultToStruct(problem,resultCells);

outputs.resultStruct = resultStruct;

[problemDefOutput, result] = RAT(customLayersProblem,controlsInput);

outputs.problemDefOutput = problemDefOutput;
outputs.result = result;

save(['tests' filesep 'domainsTFReflectivityCalculation' filesep 'domainsCustomLayersOutputs'],'outputs');

% (c) TF Parameters
[problem,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = domainsTF.reflectivityCalculation(problemDefStruct,problemDefCells,controls);

TFParams.problem = problem;
TFParams.reflectivity = reflectivity;
TFParams.simulation = simulation;
TFParams.shiftedData = shiftedData;
TFParams.layerSlds = layerSlds;
TFParams.sldProfiles = sldProfiles;
TFParams.allLayers = allLayers;

[outSsubs,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,...
 resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
 allRoughs] = domainsTF.customLayers.single(problemDefStruct,problemDefCells,controls);

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
