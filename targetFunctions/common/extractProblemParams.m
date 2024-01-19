function [numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParams, qzshifts, scalefactors, bulkIn, bulkOut, resolutionParams, dataPresent, nParams, params,...
numberOfLayers, resample, contrastBackgroundsType, contrastCustomFiles] =  extractProblemParams(problemStruct)

%Extract individual parameters from problem

numberOfContrasts = problemStruct.numberOfContrasts;
geometry = problemStruct.geometry;
contrastBackgrounds = problemStruct.contrastBackgrounds;
contrastBackgroundsType = problemStruct.contrastBackgroundsType;
contrastQzshifts = problemStruct.contrastQzshifts;
contrastScalefactors = problemStruct.contrastScalefactors;
contrastBulkIns = problemStruct.contrastBulkIns;
contrastBulkOuts = problemStruct.contrastBulkOuts;
contrastResolutions = problemStruct.contrastResolutions;
contrastCustomFiles = problemStruct.contrastCustomFiles;
backgroundParams = problemStruct.backgroundParams;
qzshifts = problemStruct.qzshifts;
scalefactors = problemStruct.scalefactors;
bulkIn = problemStruct.bulkIn;
bulkOut = problemStruct.bulkOut;
resolutionParams = problemStruct.resolutionParams;
dataPresent = problemStruct.dataPresent;
nParams = length(problemStruct.params);
params = problemStruct.params;
numberOfLayers = problemStruct.numberOfLayers;
resample = problemStruct.resample;

end
