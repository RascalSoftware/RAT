function [numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParams, qzshifts, scalefactor, bulkIn, bulkOut, res, dataPresent, nParams, params,...
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
scalefactor = problemDef.scalefactors;
bulkIn = problemDef.bulkIn;
bulkOut = problemDef.bulkOut;
res = problemDef.resolutionParams;
dataPresent = problemDef.dataPresent;
nParams = length(problemDef.params);
params = problemDef.params;
numberOfLayers = problemDef.numberOfLayers;
resample = problemDef.resample;

end
