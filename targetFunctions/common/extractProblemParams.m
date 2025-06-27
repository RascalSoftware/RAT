function [numberOfContrasts, geometry, contrastBackgroundParams,...
contrastResolutionParams, contrastDomainRatios, backgroundParams, resolutionParams, qzshifts, scalefactors, bulkIns, bulkOuts,...
domainRatios, dataPresent, nParams, params, resample, contrastBackgroundTypes, contrastBackgroundActions, contrastResolutionTypes,...
contrastCustomFiles, useImaginary, repeatLayers, data, dataLimits, simulationLimits, contrastLayers, layersDetails, customFiles, domainContrastLayers] = extractProblemParams(problemStruct)

numberOfContrasts = problemStruct.numberOfContrasts;
geometry = problemStruct.geometry;
contrastBackgroundParams = problemStruct.contrastBackgroundParams;
contrastBackgroundTypes = problemStruct.contrastBackgroundTypes;
contrastBackgroundActions = problemStruct.contrastBackgroundActions;
contrastResolutionParams = problemStruct.contrastResolutionParams;
contrastResolutionTypes = problemStruct.contrastResolutionTypes;
contrastDomainRatios = problemStruct.contrastDomainRatios;
contrastCustomFiles = problemStruct.contrastCustomFiles;
backgroundParams = problemStruct.backgroundParams;
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
qzshiftValues = 0.0;

contrastScalefactors = problemStruct.contrastScalefactors;
contrastBulkIns = problemStruct.contrastBulkIns;
contrastBulkOuts = problemStruct.contrastBulkOuts;

scalefactorValues = problemStruct.scalefactors;
bulkInValues = problemStruct.bulkIns;
bulkOutValues = problemStruct.bulkOuts;

% Find the actual values from the indices given in each contrast
qzshifts = qzshiftValues(contrastQzshifts)';
scalefactors = scalefactorValues(contrastScalefactors)';
bulkIns = bulkInValues(contrastBulkIns)';
bulkOuts = bulkOutValues(contrastBulkOuts)';

end
