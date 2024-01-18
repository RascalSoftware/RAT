function [numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParams, qzshifts, scalefactors, bulkIn, bulkOut, resolutionParams, dataPresent, nParams, params,...
numberOfLayers, resample, contrastBackgroundsType, contrastCustomFiles] =  extractProblemParams(problemDefStruct)

%Extract individual parameters from problemDef

numberOfContrasts = problemDefStruct.numberOfContrasts;
geometry = problemDefStruct.geometry;
contrastBackgrounds = problemDefStruct.contrastBackgrounds;
contrastBackgroundsType = problemDefStruct.contrastBackgroundsType;
contrastQzshifts = problemDefStruct.contrastQzshifts;
contrastScalefactors = problemDefStruct.contrastScalefactors;
contrastBulkIns = problemDefStruct.contrastBulkIns;
contrastBulkOuts = problemDefStruct.contrastBulkOuts;
contrastResolutions = problemDefStruct.contrastResolutions;
contrastCustomFiles = problemDefStruct.contrastCustomFiles;
backgroundParams = problemDefStruct.backgroundParams;
qzshifts = problemDefStruct.qzshifts;
scalefactors = problemDefStruct.scalefactors;
bulkIn = problemDefStruct.bulkIn;
bulkOut = problemDefStruct.bulkOut;
resolutionParams = problemDefStruct.resolutionParams;
dataPresent = problemDefStruct.dataPresent;
nParams = length(problemDefStruct.params);
params = problemDefStruct.params;
numberOfLayers = problemDefStruct.numberOfLayers;
resample = problemDefStruct.resample;

end
