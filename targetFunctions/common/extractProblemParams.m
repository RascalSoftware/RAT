function [numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParams, qzshifts, scalefactors, bulkIn, bulkOut, resolutionParams, dataPresent, nParams, params,...
numberOfLayers, resample, contrastBackgroundsType, contrastCustomFiles] =  extractProblemParams(problemDef)

%Extract individual parameters from problemDef

numberOfContrasts = problemDef.numberOfContrasts;
geometry = problemDef.geometry;
contrastBackgrounds = problemDef.contrastBackgrounds;
contrastBackgroundsType = problemDef.contrastBackgroundsType;
contrastQzshifts = problemDef.contrastQzshifts;
contrastScalefactors = problemDef.contrastScalefactors;
contrastBulkIns = problemDef.contrastBulkIns;
contrastBulkOuts = problemDef.contrastBulkOuts;
contrastResolutions = problemDef.contrastResolutions;
contrastCustomFiles = problemDef.contrastCustomFiles;
backgroundParams = problemDef.backgroundParams;
qzshifts = problemDef.qzshifts;
scalefactors = problemDef.scalefactors;
bulkIn = problemDef.bulkIn;
bulkOut = problemDef.bulkOut;
resolutionParams = problemDef.resolutionParams;
dataPresent = problemDef.dataPresent;
nParams = length(problemDef.params);
params = problemDef.params;
numberOfLayers = problemDef.numberOfLayers;
resample = problemDef.resample;

end
