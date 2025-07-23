function [numberOfContrasts, geometry, contrastBackgroundParams,...
contrastResolutionParams, backgroundParams, resolutionParams, dataPresent,...
params, resample, contrastBackgroundTypes, contrastBackgroundActions,...
contrastResolutionTypes, contrastCustomFiles, useImaginary, repeatLayers,...
data, dataLimits, simulationLimits, contrastLayers, layersDetails, customFiles,...
domainContrastLayers] = extractProblemParams(problemStruct)

resample = problemStruct.resample;
data = problemStruct.data;
dataPresent = problemStruct.dataPresent;
dataLimits = problemStruct.dataLimits;
simulationLimits = problemStruct.simulationLimits;
numberOfContrasts = problemStruct.numberOfContrasts;
geometry = problemStruct.geometry;
useImaginary = problemStruct.useImaginary;
repeatLayers = problemStruct.repeatLayers;
contrastBackgroundParams = problemStruct.contrastBackgroundParams;
contrastBackgroundTypes = problemStruct.contrastBackgroundTypes;
contrastBackgroundActions = problemStruct.contrastBackgroundActions;
contrastResolutionParams = problemStruct.contrastResolutionParams;
contrastResolutionTypes = problemStruct.contrastResolutionTypes;
backgroundParams = problemStruct.backgroundParams;
resolutionParams = problemStruct.resolutionParams;
params = problemStruct.params;
contrastLayers = problemStruct.contrastLayers;
layersDetails = problemStruct.layersDetails;
customFiles = problemStruct.customFiles;
contrastCustomFiles = problemStruct.contrastCustomFiles;
domainContrastLayers = problemStruct.domainContrastLayers;

end
