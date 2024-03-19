function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,...
    sldProfiles,allLayers,allRoughs] = customXY(problemStruct,problemCells,controls)

    % Extract individual cell arrays
    [repeatLayers,...
     allData,...
     dataLimits,...
     simLimits,...
     ~,~,...        % Layers details N/A
     customFiles] = parseCells(problemCells);
    
    % Extract individual parameters from problemStruct
    [numberOfContrasts, ~, contrastBackgroundIndices, contrastQzshiftIndices, contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
    contrastResolutionIndices, ~, backgroundParamArray, qzshiftArray, scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray, ~,...
    dataPresent, nParams, params, ~, ~, contrastBackgroundsType, cCustFiles, useImaginary] = extractProblemParams(problemStruct);

    parallel = controls.parallel;
    resamPars = controls.resamPars;
                
    %Pre-Allocation...
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
    
    sldProfiles = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        sldProfiles{i} = [1 ; 1];
    end

    % Process the custom models
    [sldProfiles,allRoughs] = nonPolarisedTF.customXY.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params);
    
    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        parfor i = 1:numberOfContrasts

            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},layerSlds{i},sldProfiles{i},...
             allLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices(i),...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionIndices(i),backgroundParamArray,qzshiftArray,...
             scalefactorArray,bulkInArray,bulkOutArray,resolutionParamArray,...
             dataPresent(i),allData{i},dataLimits{i},simLimits{i},...
             repeatLayers{i},contrastBackgroundsType(i),nParams,parallel,...
             resamPars,useImaginary,allRoughs(i),sldProfiles{i});
        end
    
    else
    
        for i = 1:numberOfContrasts

            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},layerSlds{i},sldProfiles{i},...
             allLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices(i),...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionIndices(i),backgroundParamArray,qzshiftArray,...
             scalefactorArray,bulkInArray,bulkOutArray,resolutionParamArray,...
             dataPresent(i),allData{i},dataLimits{i},simLimits{i},...
             repeatLayers{i},contrastBackgroundsType(i),nParams,parallel,...
             resamPars,useImaginary,allRoughs(i),sldProfiles{i});

        end
    
    end

end


function [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,...
    bulkOutValue,resolutionParamValue,chi,reflectivity,simulation,shiftedData,...
    layerSld,sldProfile,allLayer] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,...
    dataPresent,allData,dataLimits,simLimits,repeatLayers,contrastBackgroundsType,...
    nParams,parallel,resamPars,useImaginary,roughness,sldProfile)

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue,...
     resolutionParamValue] = backSort(backgroundParamIndex,qzshiftIndex,...
     scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
     backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams);
     
    % Resample the layers
    if ~useImaginary
        layerSld = resampleLayers(sldProfile,resamPars);
    else
        reSLD = sldProfile(:,1:2);
        imSLD = [sldProfile(:,1),sldProfile(:,3)];
        layerSld = resampleLayersReIm(reSLD,imSLD,resamPars);
    end
    
    allLayer = layerSld;

    shiftedDat = shiftData(scalefactorValue,qzshiftValue,dataPresent,allData,dataLimits,simLimits);
    shiftedData = shiftedDat;

    reflectivityType = 'standardAbeles';
    [reflect,simul] = callReflectivity(bulkInValue,bulkOutValue,simLimits,repeatLayers,shiftedDat,layerSld,roughness,resolutionParamValue,parallel,reflectivityType,useImaginary);
    
    [reflectivity,simulation,shiftedDat] = applyBackgroundCorrection(reflect,simul,shiftedDat,backgroundParamValue,contrastBackgroundsType);
    
    if dataPresent
        chi = chiSquared(shiftedDat,reflectivity,nParams);
    else
        chi = 0;
    end

end
