function [numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backs, shifts, sf, nba, nbs, res, dataPresent, nParams, params,...
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
backs = problemDef.backs;
shifts = problemDef.shifts;
sf = problemDef.sf;
nba = problemDef.nba;
nbs = problemDef.nbs;
res = problemDef.res;
dataPresent = problemDef.dataPresent;
nParams = length(problemDef.params);
params = problemDef.params;
numberOfLayers = problemDef.numberOfLayers;
resample = problemDef.resample;
backsType = problemDef.contrastBackgroundsType;
contrastCustomFiles = problemDef.contrastCustomFiles;


end


