function [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
    Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
    allRoughs] = parallelPoints(problemDef,problemDefCells,controls)
% Multi threaded version of the custom layers over reflectivity poimnts
% for standardTF reflectivity calculation. 
% The function extracts the relevant parameters from the input
% arrays, allocates these on a pre-contrast basis, then calls the 'core' 
% calculation (the core layers standardTf calc is shared between multiple
% calculation types).

% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 ~,~,customFiles] = parseCells(problemDefCells);

% Extract individual parameters from problemDef struct
[numberOfContrasts, geometry, cBacks, cShifts, cScales, cNbas, cNbss,...
cRes, backs, shifts, sf, nba, nbs, res, dataPresent, nParams, params,...
~, resample, backsType, cCustFiles] =  extractProblemParams(problemDef);

calcSld = controls.calcSldDuringFit;
useImaginary = problemDef.useImaginary;
                     
% Pre-Allocation of output arrays...
backgs = zeros(numberOfContrasts,1);
qshifts = zeros(numberOfContrasts,1);
sfs = zeros(numberOfContrasts,1);
nbas = zeros(numberOfContrasts,1);
nbss = zeros(numberOfContrasts,1);
resols = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);
outSsubs = zeros(numberOfContrasts,1);
chis =  zeros(numberOfContrasts,1);
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

%   --- End Memory Allocation ---

% Resampling parameters
resamPars = controls.resamPars;

% Process the custom models....
[allLayers,allRoughs] = customModelClass.processCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                                    shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,useImaginary);

% Single cored over all contrasts
for i = 1:numberOfContrasts
    
    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [thisBackground,thisQshift,thisSf,thisNba,thisNbs,thisResol] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);
    
    % Get the custom layers output for this contrast
    thisContrastLayers = allLayers{i};

    % For the other parameters, we extract the correct ones from the input
    % arrays
    thisRough = allRoughs(i);      
    thisRepeatLayers = repeatLayers{i};
    thisResample = resample(i);
    thisData = allData{i};
    thisDataPresent = dataPresent(i);
    thisDataLimits = dataLimits{i};
    thisSimLimits = simLimits{i};
    thisBacksType = backsType(i);
    
    % Now call the core standardTF_stanlay reflectivity calculation
    % In this case we are single cored, so we do not parallelise over
    % points
    parallelPoints = 'points';
    
    % Call the reflectivity calculation
    [sldProfile,reflect,Simul,shifted_dat,layerSld,resamLayers,thisChiSquared,thisSsubs] = ...
    standardTF.coreLayersCalculation...
    (thisContrastLayers, thisRough, ...
    geometry, thisNba, thisNbs, thisResample, calcSld, thisSf, thisQshift,...
    thisDataPresent, thisData, thisDataLimits, thisSimLimits, thisRepeatLayers,...
    thisBackground,thisResol,thisBacksType,nParams,parallelPoints,resamPars,useImaginary);
   
    % Store returned values for this contrast in the output arrays.
    % As well as the calculated profiles, we also store a record of 
    % the other values (background, scalefactors etc) for each contrast
    % for future use.
    outSsubs(i) = thisSsubs;
    sldProfiles{i} = sldProfile;
    reflectivity{i} = reflect;
    Simulation{i} = Simul;
    shifted_data{i} = shifted_dat;
    layerSlds{i} = layerSld;
    allLayers{i} = resamLayers;
    
    chis(i) = thisChiSquared;
    backgs(i) = thisBackground;
    qshifts(i) = thisQshift;
    sfs(i) = thisSf;
    nbas(i) = thisNba;
    nbss(i) = thisNbs;
    resols(i) = thisResol;
    allRoughs(i) = thisRough;

end
end
