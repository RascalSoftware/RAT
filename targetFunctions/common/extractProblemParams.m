function [numberOfContrasts, geometry, contrastBackgroundParams, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutionParams, contrastDomainRatios, backgroundParams, qzshifts, scalefactors, bulkIns, bulkOuts, resolutionParams,...
domainRatios, dataPresent, nParams, params, resample, contrastBackgroundTypes, contrastBackgroundActions, contrastResolutionTypes,...
contrastCustomFiles, useImaginary, repeatLayers, data, dataLimits, simulationLimits, contrastLayers, layersDetails, customFiles, domainContrastLayers] = extractProblemParams(problemStruct)

numberOfContrasts = problemStruct.numberOfContrasts;
geometry = problemStruct.geometry;
contrastBackgroundParams = problemStruct.contrastBackgroundParams;
contrastBackgroundTypes = problemStruct.contrastBackgroundTypes;
contrastBackgroundActions = problemStruct.contrastBackgroundActions;
contrastScalefactors = problemStruct.contrastScalefactors;
contrastBulkIns = problemStruct.contrastBulkIns;
contrastBulkOuts = problemStruct.contrastBulkOuts;
contrastResolutionParams = problemStruct.contrastResolutionParams;
contrastResolutionTypes = problemStruct.contrastResolutionTypes;
contrastDomainRatios = problemStruct.contrastDomainRatios;
contrastCustomFiles = problemStruct.contrastCustomFiles;
backgroundParams = problemStruct.backgroundParams;
scalefactors = problemStruct.scalefactors;
bulkIns = problemStruct.bulkIns;
bulkOuts = problemStruct.bulkOuts;
resolutionParams = problemStruct.resolutionParams;
domainRatios = problemStruct.domainRatios;
dataPresent = problemStruct.dataPresent;
nParams = length(problemStruct.params);
params = problemStruct.params;
resample = problemStruct.resample;
useImaginary = problemStruct.useImaginary;
repeatLayers = problemStruct.repeatLayers;
data = problemStruct.data;
dataLimits = problemStruct.dataLimits;
simulationLimits = problemStruct.simulationLimits;
contrastLayers = problemStruct.contrastLayers;
layersDetails = problemStruct.layersDetails;
customFiles = problemStruct.customFiles;
domainContrastLayers = problemStruct.domainContrastLayers;

% qzshifts are not included as a parameter in RAT, so we set up dummy
% values for the reflectivity calculation
contrastQzshifts = ones(1,problemStruct.numberOfContrasts);
qzshifts = 0.0;

end
