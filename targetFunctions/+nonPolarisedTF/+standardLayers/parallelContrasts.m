
function [outSsubs,backgs,qshifts,scalefactors,nbas,nbss,resols,chis,reflectivity,...
    Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
    allRoughs] = parallelContrasts(problemDef,problemDefCells,controls)
% Standard Layers calculation paralelised over the outer loop
% This is the main reflectivity calculation of the standard layers
% calculation type. It extracts the required parameters for the contrasts
% from the input arrays, then passes the main calculation to
% 'standardLayersCore', which carries out the calculation iteself. 
% The core calculation is common for both standard and custom layers.

% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 contrastLayers,...
 layersDetails,~] = parseCells(problemDefCells);

% Extract individual parameters from problemDef struct
[numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backs, shifts, scalefactor, nba, nbs, res, dataPresent, nParams, params,...
~, resample, backsType, ~] =  extractProblemParams(problemDef);

calcSld = controls.calcSldDuringFit;   
useImaginary = problemDef.useImaginary;

% Allocate the memory for the output arrays before the main loop
backgs = zeros(numberOfContrasts,1);
qshifts = zeros(numberOfContrasts,1);
scalefactors = zeros(numberOfContrasts,1);
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
    allLayers{i} = [1 1 1; 1 1 1];
end
% end memory allocation.


% First we need to allocate the absolute values of the input
% parameters to all the layers in the layers list. This only needs
% to be done once, and so is done outside the contrasts loop
outParameterisedLayers = allocateParamsToLayers(params, layersDetails);

% Resample parameters if required
resamPars = controls.resamPars;

% Loop over all the contrasts
parfor i = 1:numberOfContrasts
    
    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [thisBackground,thisQshift,thisScalefactor,thisNba,thisNbs,thisResol] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backs,shifts,scalefactor,nba,nbs,res);
    
    % Also need to determine which layers from the overall layers list
    % are required for this contrast, and put them in the correct order 
    % according to geometry
    thisContrastLayers = allocateLayersForContrast(contrastLayers{i},outParameterisedLayers,useImaginary);
    
    % For the other parameters, we extract the correct ones from the input
    % arrays
    thisRough = params(1);      % Substrate roughness is always first parameter for standard layers
    thisRepeatLayers = repeatLayers{i};
    thisResample = resample(i);
    thisData = allData{i};
    thisDataPresent = dataPresent(i);
    thisDataLimits = dataLimits{i};
    thisSimLimits = simLimits{i};
    thisBacksType = backsType(i);
    
    % Now call the core layers reflectivity calculation
    % In this case we are single cored, so we do not parallelise over
    % points
    parallelPoints = 'single';
    
    % Call the core layers calculation
    [sldProfile,reflect,Simul,shifted_dat,layerSld,resampledLayers,...
        thisChiSquared,thisSsubs] = nonPolarisedTF.coreLayersCalculation(thisContrastLayers, thisRough, ...
    geometry, thisNba, thisNbs, thisResample, calcSld, thisScalefactor, thisQshift,...
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
    chis(i) = thisChiSquared;
    backgs(i) = thisBackground;
    qshifts(i) = thisQshift;
    scalefactors(i) = thisScalefactor;
    nbas(i) = thisNba;
    nbss(i) = thisNbs;
    resols(i) = thisResol;
    allRoughs(i) = thisRough;
    allLayers{i} = resampledLayers;
end
end
