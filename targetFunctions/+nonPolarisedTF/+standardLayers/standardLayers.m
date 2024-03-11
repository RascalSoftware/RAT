function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,...
    sldProfiles,allLayers,allRoughs] = standardLayers(problemStruct,problemCells,controls)
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
 layersDetails,~] = parseCells(problemCells);

% Extract individual parameters from problemStruct
[numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParam, qzshift, scalefactor, bulkIn, bulkOut, resolutionParam, dataPresent, nParams, params,...
~, resample, contrastBackgroundsType, ~] =  extractProblemParams(problemStruct);

calcSld = controls.calcSldDuringFit;
parallel = controls.parallel;
useImaginary = problemStruct.useImaginary;

% Allocate the memory for the output arrays before the main loop
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
    allLayers{i} = [1 1 1; 1 1 1];
end
% end memory allocation.


% First we need to allocate the absolute values of the input
% parameters to all the layers in the layers list. This only needs
% to be done once, and so is done outside the contrasts loop
outParameterisedLayers = allocateParamsToLayers(params, layersDetails);

% Resample parameters if required
resamPars = controls.resamPars;

% Substrate roughness is always first parameter for standard layers
subRough = params(1);

if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)

    % Loop over all the contrasts
    parfor i = 1:numberOfContrasts
        
        % Extract the relevant parameter values for this contrast
        % from the input arrays.
        % First need to decide which values of the backgrounds, scalefactors
        % data shifts and bulk contrasts are associated with this contrast
        [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
        
        % Also need to determine which layers from the overall layers list
        % are required for this contrast, and put them in the correct order 
        % according to geometry
        thisContrastLayers = allocateLayersForContrast(contrastLayers{i},outParameterisedLayers,useImaginary);
        
        % Call the core layers calculation
        [sldProfiles{i},reflectivity{i},simulation{i},shiftedData{i},layerSlds{i},allLayers{i},...
            chis(i),outSsubs(i)] = nonPolarisedTF.coreLayersCalculation(thisContrastLayers, subRough, ...
        geometry, bulkIns(i), bulkOuts(i), resample(i), calcSld, scalefactors(i), qzshifts(i),...
        dataPresent(i), allData{i}, dataLimits{i}, simLimits{i}, repeatLayers{i},...
        backgroundParams(i),resolutionParams(i),contrastBackgroundsType(i),nParams,parallel,resamPars,useImaginary);
        
        allRoughs(i) = subRough;

    end
    
else

    % Loop over all the contrasts
    for i = 1:numberOfContrasts
        
        % Extract the relevant parameter values for this contrast
        % from the input arrays.
        % First need to decide which values of the backgrounds, scalefactors
        % data shifts and bulk contrasts are associated with this contrast
        [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
        
        % Also need to determine which layers from the overall layers list
        % are required for this contrast, and put them in the correct order 
        % according to geometry
        thisContrastLayers = allocateLayersForContrast(contrastLayers{i},outParameterisedLayers,useImaginary);
        
        % Call the core layers calculation
        [sldProfiles{i},reflectivity{i},simulation{i},shiftedData{i},layerSlds{i},allLayers{i},...
            chis(i),outSsubs(i)] = nonPolarisedTF.coreLayersCalculation(thisContrastLayers, subRough, ...
        geometry, bulkIns(i), bulkOuts(i), resample(i), calcSld, scalefactors(i), qzshifts(i),...
        dataPresent(i), allData{i}, dataLimits{i}, simLimits{i}, repeatLayers{i},...
        backgroundParams(i),resolutionParams(i),contrastBackgroundsType(i),nParams,parallel,resamPars,useImaginary);

        allRoughs(i) = subRough;

    end

end
