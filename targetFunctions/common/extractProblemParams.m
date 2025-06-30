function [numberOfContrasts, geometry, contrastBackgroundParams,...
contrastResolutionParams, backgroundParams, resolutionParams, qzshifts,...
scalefactors, bulkIns, bulkOuts, domainRatios, dataPresent, nParams, params,...
resample, contrastBackgroundTypes, contrastBackgroundActions, contrastResolutionTypes,...
contrastCustomFiles, useImaginary, repeatLayers, data, dataLimits, simulationLimits,...
contrastLayers, layersDetails, customFiles, domainContrastLayers...
] = extractProblemParams(problemStruct)

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
nParams = length(problemStruct.params);
params = problemStruct.params;
contrastLayers = problemStruct.contrastLayers;
customFiles = problemStruct.customFiles;
contrastCustomFiles = problemStruct.contrastCustomFiles;
layersDetails = problemStruct.layersDetails;
domainContrastLayers = problemStruct.domainContrastLayers;


% qzshifts are not included as a parameter in RAT, so we set up dummy
% values for the reflectivity calculation
contrastQzshifts = ones(1,problemStruct.numberOfContrasts);
qzshiftValues = 0.0;

contrastScalefactors = problemStruct.contrastScalefactors;
contrastBulkIns = problemStruct.contrastBulkIns;
contrastBulkOuts = problemStruct.contrastBulkOuts;
contrastDomainRatios = problemStruct.contrastDomainRatios;

scalefactorValues = problemStruct.scalefactors;
bulkInValues = problemStruct.bulkIns;
bulkOutValues = problemStruct.bulkOuts;
domainRatioValues = problemStruct.domainRatios;

% Find the actual values from the indices given in each contrast
qzshifts = qzshiftValues(contrastQzshifts)';
scalefactors = scalefactorValues(contrastScalefactors)';
bulkIns = bulkInValues(contrastBulkIns)';
bulkOuts = bulkOutValues(contrastBulkOuts)';
domainRatios = domainRatioValues(contrastDomainRatios)';

end
