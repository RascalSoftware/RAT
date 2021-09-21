function [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
    Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
    allRoughs] = standardTF_custXY_paraPoints(problemDef,problemDef_cells,...
    problemDef_limits,controls)

% Multi threaded version of the custom XY profile over reflectivity points
% for standardTF reflectivity calculation. 


% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 contrastLayers,...
 layersDetails,...
 customFiles] = RAT_parse_cells(problemDef_cells);

% Extract individual parameters from problemDef struct
[numberOfContrasts, geometry, cBacks, cShifts, cScales, cNbas, cNbss,...
cRes, backs, shifts, sf, nba, nbs, res, dataPresent, nParams, params,...
numberOfLayers, resample, backsType, cCustFiles] =  extractProblemParams(problemDef);      
            
%Pre-Allocation...
backgs = zeros(numberOfContrasts,1);
qshifts = zeros(numberOfContrasts,1);
sfs = zeros(numberOfContrasts,1);
nbas = zeros(numberOfContrasts,1);
nbss = zeros(numberOfContrasts,1);
resols = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);
outSsubs = zeros(numberOfContrasts,1);
chis =  zeros(numberOfContrasts,1);
allLayers = cell(numberOfContrasts,1); 
layerSlds = cell(numberOfContrasts,1);
sldProfiles = cell(numberOfContrasts,1);
shifted_data = cell(numberOfContrasts,1);

reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end
%coder.varsize('reflectivity{:}',[10000 2],[1 0]);

Simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    Simulation{i} = [1 1 ; 1 1];
end
%coder.varsize('Simulation{:}',[10000 2],[1 0]);

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 ; 1];
end
%coder.varsize('allLayers{:}',[10000 3],[1 1]);


for i = 1:numberOfContrasts
    [backgs(i),qshifts(i),sfs(i),nbas(i),nbss(i),resols(i)] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);
    
    thisCustomFile = customFiles{cCustFiles(i)};
    [sldProfile,allRoughs(i)] = call_customLayers(params,i,thisCustomFile,nbas,nbss(i),numberOfContrasts);
    
    sldProfiles{i} = sldProfile;

    resamPars = controls.resamPars;
    layerSld = resampleLayers(sldProfile,resamPars);
    layerSlds{i} = layerSld;
    allLayers{i} = layerSld;

    shifted_dat =  shiftdata(sfs(i),qshifts(i),dataPresent(i),allData{i},dataLimits{i},simLimits{i});
    shifted_data{i} = shifted_dat;
    
    reflectivityType = 'standardAbeles_realOnly';
    [reflect,Simul] = callReflectivity(nbas(i),nbss(i),simLimits{i},repeatLayers{i},shifted_dat,layerSld,outSsubs(i),resols(i),'points',reflectivityType);
    
    [reflect,Simul,shifted_dat] = applyBackgroundCorrection(reflect,Simul,shifted_dat,backgs(i),backsType(i));
    
    reflectivity{i} = reflect;
    Simulation{i} = Simul;
    
    if dataPresent(i)
        chis(i) = chiSquared(shifted_dat,reflect,nParams);
    else
        chis(i) = 0;
    end
end


end