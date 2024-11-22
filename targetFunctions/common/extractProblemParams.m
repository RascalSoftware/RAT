function [numberOfContrasts, geometry, contrastBackgroundParams, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutionParams, contrastDomainRatios, backgroundParams, qzshifts, scalefactors, bulkIn, bulkOut, resolutionParams, domainRatio,...
dataPresent, nParams, params, numberOfLayers, resample, contrastBackgroundTypes, contrastBackgroundActions, contrastCustomFiles, useImaginary,...
repeatLayers, data, dataLimits, simLimits, contrastLayers, layersDetails, customFiles, domainContrastLayers] = extractProblemParams(problemStruct)

numberOfContrasts = problemStruct.numberOfContrasts;
geometry = problemStruct.geometry;
contrastBackgroundParams = problemStruct.contrastBackgroundParams;
contrastBackgroundTypes = problemStruct.contrastBackgroundTypes;
contrastBackgroundActions = problemStruct.contrastBackgroundActions;
contrastQzshifts = problemStruct.contrastQzshifts;
contrastScalefactors = problemStruct.contrastScalefactors;
contrastBulkIns = problemStruct.contrastBulkIns;
contrastBulkOuts = problemStruct.contrastBulkOuts;
contrastResolutionParams = problemStruct.contrastResolutionParams;
contrastDomainRatios = problemStruct.contrastDomainRatios;
contrastCustomFiles = problemStruct.contrastCustomFiles;
backgroundParams = problemStruct.backgroundParams;
qzshifts = problemStruct.qzshifts;
scalefactors = problemStruct.scalefactors;
bulkIn = problemStruct.bulkIn;
bulkOut = problemStruct.bulkOut;
resolutionParams = problemStruct.resolutionParams;
domainRatio = problemStruct.domainRatio;
dataPresent = problemStruct.dataPresent;
nParams = length(problemStruct.params);
params = problemStruct.params;
numberOfLayers = problemStruct.numberOfLayers;
resample = problemStruct.resample;
useImaginary = problemStruct.useImaginary;
repeatLayers = problemStruct.repeatLayers;
data = problemStruct.data;
dataLimits = problemStruct.dataLimits;
simLimits = problemStruct.simulationLimits;
contrastLayers = problemStruct.contrastLayers;
layersDetails = problemStruct.layersDetails;
customFiles = problemStruct.customFiles;
domainContrastLayers = problemStruct.domainContrastLayers;

end
