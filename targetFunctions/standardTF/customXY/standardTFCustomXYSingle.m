function [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
    Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
    allRoughs] = standardTFCustomXYSingle(problemDef,problemDef_cells,...
    problemDef_limits,controls)


% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 contrastLayers,...
 layersDetails,...
 customFiles] = parseCells(problemDef_cells);

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

Simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    Simulation{i} = [1 1 ; 1 1];
end

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 ; 1];
end
sldProf = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProf{i} = [1 ; 1];
end

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i} = [1 ; 1];
end


% Resampling parameters
resamPars = controls.resamPars;

% Process the custom models. These can either be as a Matlab script, or a
% user generated DLL
lang = customFiles{1}{2}; 
switch lang 
case 'matlab'
    % Call the Matlab parallel loop to process the custom models.....
    [sldProf, allRoughs] = loopMatalbCustlayWrapper_XYSingle(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
    shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params);

case 'cpp'
    [sldProf,allRoughs] = loopCppCustlayWrapper_XYSingle(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
    shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params);
end


for i = 1:numberOfContrasts
    [backgs(i),qshifts(i),sfs(i),nbas(i),nbss(i),resols(i)] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);
    
    sldProfiles{i} = sldProf{i};

    layerSld = resampleLayers(sldProfiles{i},resamPars);
    layerSlds{i} = layerSld;
    allLayers{i} = layerSld;

    shifted_dat =  shiftData(sfs(i),qshifts(i),dataPresent(i),allData{i},dataLimits{i},simLimits{i});
    shifted_data{i} = shifted_dat;
    
    reflectivityType = 'standardAbeles_realOnly';
    [reflect,Simul] = callReflectivity(nbas(i),nbss(i),simLimits{i},repeatLayers{i},shifted_dat,layerSld,outSsubs(i),resols(i),'single',reflectivityType);
    
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
