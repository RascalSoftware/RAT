function [numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, contrastDomainRatios, backgroundParams, qzshifts, scalefactors, bulkIn, bulkOut, resolutionParams, domainRatio,...
dataPresent, nParams, params, numberOfLayers, resample, contrastBackgroundActions, contrastCustomFiles, useImaginary] = extractProblemParams(problemStruct)

%Extract individual parameters from problem

numberOfContrasts = problemStruct.numberOfContrasts;
geometry = problemStruct.geometry;
contrastBackgrounds = problemStruct.contrastBackgrounds;
contrastBackgroundActions = problemStruct.contrastBackgroundActions;
contrastQzshifts = problemStruct.contrastQzshifts;
contrastScalefactors = problemStruct.contrastScalefactors;
contrastBulkIns = problemStruct.contrastBulkIns;
contrastBulkOuts = problemStruct.contrastBulkOuts;
contrastResolutions = problemStruct.contrastResolutions;
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

end
