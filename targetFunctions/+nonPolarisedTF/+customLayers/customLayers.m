function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,...
    sldProfiles,allLayers,allRoughs] = customLayers(problemStruct,problemCells,controls)
% The custom layers, nonPolarisedTF reflectivity calculation.
% The function extracts the relevant parameters from the input arrays,
% allocates these on a pre-contrast basis, then calls the 'core' 
% calculation (the core layers nonPolarisedTF calc is shared between
% multiple calculation types).

% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 ~,~,customFiles] = parseCells(problemCells);

% Extract individual parameters from problemStruct
[numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParam, qzshift, scalefactor, bulkIn, bulkOut, resolutionParam, dataPresent, nParams, params,...
~, resample, contrastBackgroundsType, cCustFiles] =  extractProblemParams(problemStruct);

calcSld = controls.calcSldDuringFit;
parallel = controls.parallel;
useImaginary = problemStruct.useImaginary;
                     
% Pre-Allocation of output arrays...
backgroundParams = zeros(numberOfContrasts,1);
qzshifts = zeros(numberOfContrasts,1);
scalefactors = zeros(numberOfContrasts,1);
bulkIns = zeros(numberOfContrasts,1);
bulkOuts = zeros(numberOfContrasts,1);
resolutionParams = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);
outSsubs = zeros(numberOfContrasts,1);
chis = zeros(numberOfContrasts,1);
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
[allLayers,allRoughs] = nonPolarisedTF.customLayers.processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkIn,bulkOut,cCustFiles,numberOfContrasts,customFiles,params,useImaginary);

if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)

    % Multi cored over all contrasts
    parfor i = 1:numberOfContrasts
        
        % Extract the relevant parameter values for this contrast
        % from the input arrays.
        % First need to decide which values of the backgrounds, scalefactors
        % data shifts and bulk contrasts are associated with this contrast
        [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
        
        % Call the reflectivity calculation
        [sldProfiles{i},reflectivity{i},simulation{i},shiftedData{i},layerSlds{i},allLayers{i},chis(i),outSsubs(i)] = ...
        nonPolarisedTF.coreLayersCalculation...
        (allLayers{i}, allRoughs(i), ...
        geometry, bulkIns(i), bulkOuts(i), resample(i), calcSld, scalefactors(i), qzshifts(i),...
        dataPresent(i), allData{i}, dataLimits{i}, simLimits{i}, repeatLayers{i},...
        backgroundParams(i),resolutionParams(i),contrastBackgroundsType(i),nParams,parallel,resamPars,useImaginary);
    
    end

else

    % Single cored over all contrasts
    for i = 1:numberOfContrasts
        
        % Extract the relevant parameter values for this contrast
        % from the input arrays.
        % First need to decide which values of the backgrounds, scalefactors
        % data shifts and bulk contrasts are associated with this contrast
        [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
           
        % Call the reflectivity calculation
        [sldProfiles{i},reflectivity{i},simulation{i},shiftedData{i},layerSlds{i},allLayers{i},chis(i),outSsubs(i)] = ...
        nonPolarisedTF.coreLayersCalculation...
        (allLayers{i}, allRoughs(i), ...
        geometry, bulkIns(i), bulkOuts(i), resample(i), calcSld, scalefactors(i), qzshifts(i),...
        dataPresent(i), allData{i}, dataLimits{i}, simLimits{i}, repeatLayers{i},...
        backgroundParams(i),resolutionParams(i),contrastBackgroundsType(i),nParams,parallel,resamPars,useImaginary);

    end

end
