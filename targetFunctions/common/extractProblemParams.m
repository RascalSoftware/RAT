function [numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backs, shifts, scalefactor, bulkIn, bulkOut, res, dataPresent, nParams, params,...
numberOfLayers, resample, backsType, contrastCustomFiles] =  extractProblemParams(problemDef)

%Extract individual parameters from problemDef

numberOfContrasts = problemDef.numberOfContrasts;
geometry = problemDef.geometry;
contrastBackgrounds = problemDef.contrastBackgrounds;
contrastQzshifts = problemDef.contrastQzshifts;
contrastScalefactors = problemDef.contrastScalefactors;
contrastBulkIns = problemDef.contrastBulkIns;
contrastBulkOuts = problemDef.contrastBulkOuts;
contrastResolutions = problemDef.contrastResolutions;
backs = problemDef.backgroundParams;
shifts = problemDef.qzshifts;
scalefactor = problemDef.scalefactors;
bulkIn = problemDef.bulkIn;
bulkOut = problemDef.bulkOut;
res = problemDef.resolutionParams;
dataPresent = problemDef.dataPresent;
nParams = length(problemDef.params);
params = problemDef.params;
numberOfLayers = problemDef.numberOfLayers;
resample = problemDef.resample;
backsType = problemDef.contrastBackgroundsType;
contrastCustomFiles = problemDef.contrastCustomFiles;


end


