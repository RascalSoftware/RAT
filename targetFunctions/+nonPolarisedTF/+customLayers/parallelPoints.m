function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
    simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
    allRoughs] = parallelPoints(problemDef,problemDefCells,controls)
% Multi threaded version of the custom layers over reflectivity poimnts
% for nonPolarisedTF reflectivity calculation. 
% The function extracts the relevant parameters from the input
% arrays, allocates these on a pre-contrast basis, then calls the 'core' 
% calculation (the core layers nonPolarisedTF calc is shared between
% multiple calculation types).

% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 ~,~,customFiles] = parseCells(problemDefCells);

% Extract individual parameters from problemDef struct
[numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParam, qzshift, scalefactor, bulkIn, bulkOut, resolutionParam, dataPresent, nParams, params,...
~, resample, contrastBackgroundsType, cCustFiles] =  extractProblemParams(problemDef);

calcSld = controls.calcSldDuringFit;
useImaginary = problemDef.useImaginary;
                     
% Pre-Allocation of output arrays...
backgroundParams = zeros(numberOfContrasts,1);
qzshifts = zeros(numberOfContrasts,1);
scalefactors = zeros(numberOfContrasts,1);
bulkIns = zeros(numberOfContrasts,1);
bulkOuts = zeros(numberOfContrasts,1);
resolutionParams = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);
outSsubs = zeros(numberOfContrasts,1);
chis =  zeros(numberOfContrasts,1);
layerSlds = cell(numberOfContrasts,1);
sldProfiles = cell(numberOfContrasts,1);
shiftedData = cell(numberOfContrasts,1);

reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end

simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    simulation{i} = [1 1 ; 1 1];
end

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 ; 1];
end

%   --- End Memory Allocation ---

% Resampling parameters
resamPars = controls.resamPars;

% Process the custom models....
[allLayers,allRoughs] = nonPolarisedTF.customLayers.processCustomFunction(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backgroundParam, ...
    qzshift,scalefactor,bulkIn,bulkOut,resolutionParam,cCustFiles,numberOfContrasts,customFiles,params,useImaginary);

% Single cored over all contrasts
for i = 1:numberOfContrasts
    
    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [thisBackground,thisQzshift,thisScalefactor,thisBulkIn,thisBulkOut,thisResol] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
    
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
    thisBacksType = contrastBackgroundsType(i);
    
    % Now call the core layers reflectivity calculation
    % In this case we are single cored, so we do not parallelise over
    % points
    parallelPoints = 'points';
    
    % Call the reflectivity calculation
    [sldProfile,reflect,simul,shiftedDat,layerSld,resamLayers,thisChiSquared,thisSsubs] = ...
    nonPolarisedTF.coreLayersCalculation...
    (thisContrastLayers, thisRough, ...
    geometry, thisBulkIn, thisBulkOut, thisResample, calcSld, thisScalefactor, thisQzshift,...
    thisDataPresent, thisData, thisDataLimits, thisSimLimits, thisRepeatLayers,...
    thisBackground,thisResol,thisBacksType,nParams,parallelPoints,resamPars,useImaginary);
   
    % Store returned values for this contrast in the output arrays.
    % As well as the calculated profiles, we also store a record of 
    % the other values (background, scalefactors etc) for each contrast
    % for future use.
    outSsubs(i) = thisSsubs;
    sldProfiles{i} = sldProfile;
    reflectivity{i} = reflect;
    simulation{i} = simul;
    shiftedData{i} = shiftedDat;
    layerSlds{i} = layerSld;
    allLayers{i} = resamLayers;
    
    chis(i) = thisChiSquared;
    backgroundParams(i) = thisBackground;
    qzshifts(i) = thisQzshift;
    scalefactors(i) = thisScalefactor;
    bulkIns(i) = thisBulkIn;
    bulkOuts(i) = thisBulkOut;
    resolutionParams(i) = thisResol;
    allRoughs(i) = thisRough;

end
end
