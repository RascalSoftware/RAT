function [numberOfContrasts, geometry, cBacks, cShifts, cScales, cNbas, cNbss,...
cRes, backs, shifts, sf, nba, nbs, res, dataPresent, nParams, params,...
numberOfLayers, resample, backsType] =  extractProblemParams(problemDef)

%Extract individual parameters from problemDef

numberOfContrasts = problemDef.numberOfContrasts;
geometry = problemDef.geometry;
cBacks = problemDef.contrastBacks;
cShifts = problemDef.contrastShifts;
cScales = problemDef.contrastScales;
cNbas = problemDef.contrastNbas;
cNbss = problemDef.contrastNbss;
cRes = problemDef.contrastRes;
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
backsType = problemDef.contrastBacksType;


end


