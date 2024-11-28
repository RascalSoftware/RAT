function [qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,backgrounds,...
    layerSlds,sldProfiles,resampledLayers,subRoughs] = standardLayers(problemStruct,controls)
    % This is the main reflectivity calculation of the standard layers
    % calculation type. It extracts the required parameters for the contrasts
    % from the input arrays, then passes the main calculation to
    % 'coreLayersCalculation', which carries out the calculation itself. 
    % The core calculation is common for both standard and custom layers.

    % Extract parameters from problemStruct
    [numberOfContrasts, geometry, contrastBackgroundIndices, contrastQzshiftIndices,...
     contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
     contrastResolutionParamIndices, ~, backgroundParamArray, qzshiftArray,...
     scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray, ~,...
     dataPresent, nParams, params, ~, resample, contrastBackgroundTypes,...
     contrastBackgroundActions, ~, useImaginary, repeatLayers, data,...
     dataLimits, simLimits, contrastLayers, layersDetails, customFiles, ~] = extractProblemParams(problemStruct);
    
    calcSld = controls.calcSldDuringFit;
    parallel = controls.parallel;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;
    
    % Allocate the memory for the output arrays before the main loop
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    resolutionParams = zeros(numberOfContrasts,1);
    chis = zeros(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);
    
    reflectivity = cell(numberOfContrasts,1);  
    simulation = cell(numberOfContrasts,1);
    shiftedData = cell(numberOfContrasts,1);
    backgrounds = cell(numberOfContrasts,1);
    layerSlds = cell(numberOfContrasts,1);
    sldProfiles = cell(numberOfContrasts,1);
    resampledLayers = cell(numberOfContrasts,1);
    
    % First we need to allocate the absolute values of the input
    % parameters to all the layers in the layers list. This only needs
    % to be done once, and so is done outside the contrasts loop
    outParameterisedLayers = allocateParamsToLayers(params, layersDetails);   
    
    % Substrate roughness is always first parameter for standard layers
    for i = 1:numberOfContrasts
        subRoughs(i) = params(1);
    end
    
    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        % Loop over all the contrasts
        parfor i = 1:numberOfContrasts
    
            [qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},backgrounds{i},layerSlds{i},...
             sldProfiles{i},resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionParamIndices(i),backgroundParamArray,qzshiftArray,...
             scalefactorArray,bulkInArray,bulkOutArray,resolutionParamArray,...
             dataPresent(i),data{i},dataLimits{i},simLimits{i},repeatLayers{i},...
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             customFiles,nParams,parallel,resampleMinAngle,resampleNPoints,...
             useImaginary,resample(i),geometry,subRoughs(i),calcSld,...
             contrastLayers{i},outParameterisedLayers);
    
        end
        
    else
    
        % Loop over all the contrasts
        for i = 1:numberOfContrasts
            
            [qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},backgrounds{i},layerSlds{i},...
             sldProfiles{i},resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionParamIndices(i),backgroundParamArray,qzshiftArray, ...
             scalefactorArray,bulkInArray,bulkOutArray,resolutionParamArray,...
             dataPresent(i),data{i},dataLimits{i},simLimits{i},repeatLayers{i},...
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             customFiles,nParams,parallel,resampleMinAngle,resampleNPoints,...
             useImaginary,resample(i),geometry,subRoughs(i),calcSld,...
             contrastLayers{i},outParameterisedLayers);

        end
    end
end


function [qzshiftValue,scalefactorValue,bulkInValue,...
    bulkOutValue,resolutionParamValue,chi,reflectivity,simulation,shiftedData,background,...
    layerSld,sldProfile,resampledLayer] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,...
    dataPresent,data,dataLimits,simLimits,repeatLayers,backgroundType,backgroundAction,...
    customFiles,nParams,parallel,resampleMinAngle,resampleNPoints,useImaginary,resample,geometry,roughness,...
    calcSld,contrastLayers,outParameterisedLayers)

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue,...
     resolutionParamValue] = backSort(qzshiftIndex,...
     scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
     qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams);
    
    % Also need to determine which layers from the overall layers list
    % are required for this contrast, and put them in the correct order 
    % according to geometry
    thisContrastLayers = allocateLayersForContrast(contrastLayers,outParameterisedLayers,useImaginary);

    % Apply scale factors and q shifts to the data
    shiftedData = shiftData(scalefactorValue,qzshiftValue,dataPresent,data,dataLimits,simLimits);
    background = constructBackground(backgroundType,backgroundParamIndex,shiftedData,customFiles,backgroundParams,simLimits);

    % Call the core layers calculation
    [sldProfile,reflectivity,simulation,shiftedData,layerSld,resampledLayer,...
     chi] = normalTF.coreLayersCalculation(thisContrastLayers,roughness,...
     geometry,bulkInValue,bulkOutValue,resample,calcSld,shiftedData,simLimits,repeatLayers,...
     resolutionParamValue,background,backgroundAction,nParams,parallel,resampleMinAngle,resampleNPoints,useImaginary);

end