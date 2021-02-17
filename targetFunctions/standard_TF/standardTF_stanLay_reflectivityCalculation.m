function [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_stanLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls)


[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 contrastLayers,...
 layersDetails] = RAT_parse_cells(problemDef_cells);


%Extract individual parameters from problemDef
res = problemDef.resample;
numberOfContrasts = problemDef.numberOfContrasts;
geometry = problemDef.geometry;
%nbairs = problemDef.nbairs;
%nbsubs = problemDef.nbsubs;
%repeats = problemDef.repeatLayers;
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
%allData = problemDef.allData;
%dataLimits = problemDef.dataLimits;
%simLimits = problemDef.simLimits;
%repeatLayers = problemDef.repeatLayers;
nParams = length(problemDef.params);
params = problemDef.params;
%contrastLayers = problemDef.contrastLayers;
numberOfLayers = problemDef.numberOfLayers;
%layersDetails = problemDef.layersDetails;
resample = problemDef.resample;
backsType = problemDef.contrastBacksType;
calcSld = controls.calcSld;


%Pre-allocation
outSsubs = params(1);
backgs = zeros(numberOfContrasts,1);
qshifts = zeros(numberOfContrasts,1);
sfs = zeros(numberOfContrasts,1);
nbas = zeros(numberOfContrasts,1);
nbss = zeros(numberOfContrasts,1);
chis = zeros(numberOfContrasts,1);
resols = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);

reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end

Simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    Simulation{i} = [1 1 ; 1 1];
end

shifted_data = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    shifted_data{i} = [1 1 1; 1 1 1];
end

layerSlds = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    layerSlds{i} = [1 1 1; 1 1 1];
end

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i} = [1 1; 1 1];
end

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 ; 1];
end

para = controls.para;

switch para
    case 'single'
        
        [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
            Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
            allRoughs]...
            = standardTF_stanlay_single...
            (resample, ...
            numberOfContrasts,geometry,repeatLayers,cBacks,cShifts, ...
            cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res,dataPresent , ...
            allData ,dataLimits ,simLimits ,nParams ,params ,contrastLayers, ...
            numberOfLayers ,layersDetails,problemDef_limits,backsType,calcSld);
        
     case 'points'
         
        [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
            Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
            allRoughs]...
            = standardTF_stanlay_paraPoints...
            (resample, ...
            numberOfContrasts,geometry,repeatLayers,cBacks,cShifts, ...
            cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res,dataPresent , ...
            allData ,dataLimits ,simLimits ,nParams ,params ,contrastLayers, ...
            numberOfLayers ,layersDetails,problemDef_limits,backsType,calcSld);
        
    case 'contrasts'
        
        [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
            Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
            allRoughs]...
            = standardTF_stanlay_paraContrasts...
            (resample, ...
            numberOfContrasts,geometry,repeatLayers,cBacks,cShifts, ...
            cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res,dataPresent , ...
            allData ,dataLimits ,simLimits ,nParams ,params ,contrastLayers, ...
            numberOfLayers,layersDetails,problemDef_limits,backsType,calcSld);      
end

problem.ssubs = outSsubs;
problem.backgrounds = backgs;
problem.qshifts = qshifts;
problem.scalefactors = sfs;
problem.nbairs = nbas;
problem.nbsubs = nbss;
problem.resolutions = resols;
problem.calculations.all_chis = chis;
problem.calculations.sum_chi = sum(chis);
problem.allSubRough = allRoughs;

end