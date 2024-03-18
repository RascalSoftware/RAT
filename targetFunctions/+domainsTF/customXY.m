function [backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,domainLayerSlds,...
    domainSldProfiles,domainResampledLayers,allRoughs] = customXY(problemStruct,problemCells,controls)

    % Extract individual cell arrays
    [repeatLayers,...
     allData,...
     dataLimits,...
     simLimits,...
     ~,~,...        % Layers details N/A
     customFiles] = parseCells(problemCells);
    
    % Extract individual parameters from problemStruct
    [numberOfContrasts, ~, contrastBackgroundIndices, contrastQzshiftIndices,...
     contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
     contrastResolutionIndices, contrastDomainRatioIndices, backgroundParamArray,...
     qzshiftArray, scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray,...
     domainRatioArray, dataPresent, nParams, params, ~, ~, contrastBackgroundsType,...
     cCustFiles, useImaginary] = extractProblemParams(problemStruct);

    parallel = controls.parallel;
    resampleParams = controls.resampleParams;

    %Pre-Allocation...
    backgroundParams = zeros(numberOfContrasts,1);
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    resolutionParams = zeros(numberOfContrasts,1);
    allRoughs = zeros(numberOfContrasts,1);
    chis = zeros(numberOfContrasts,1);
    domainLayerSlds = cell(numberOfContrasts,2);
    shiftedData = cell(numberOfContrasts,1);
    
    reflectivity = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        reflectivity{i} = [1 1; 1 1];
    end
    
    simulation = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        simulation{i} = [1 1; 1 1];
    end
    
    domainResampledLayers = cell(numberOfContrasts,2);
    for i = 1:numberOfContrasts
        domainResampledLayers{i,1} = [1 1 1; 1 1 1];
        domainResampledLayers{i,2} = [1 1 1; 1 1 1];
    end
    
    domainSldProfiles = cell(numberOfContrasts,2);
    for i = 1:numberOfContrasts
        domainSldProfiles{i,1} = [1; 1];
        domainSldProfiles{i,2} = [1; 1];
    end
    
    inputSldProfiles1 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        inputSldProfiles1{i} = [1; 1];
    end
    
    inputSldProfiles2 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        inputSldProfiles2{i} = [1; 1];
    end
    
    sldProfiles = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        sldProfiles{i} = {[1 1; 1 1],[1 1; 1 1]};
    end
    
    resampledLayers = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        resampledLayers{i} = {[1 1 1; 1 1 1],[1 1 1; 1 1 1]};
    end
    
    layerSlds = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        layerSlds{i} = {[1 1 1; 1 1 1],[1 1 1; 1 1 1]};
    end

    [inputSldProfiles,allRoughs] = domainsTF.customXY.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params);
    
    for i = 1:size(inputSldProfiles,1)
        inputSldProfiles1{i} = inputSldProfiles{i,1};
        inputSldProfiles2{i} = inputSldProfiles{i,2};
    end
    
    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        parfor i = 1:numberOfContrasts
    
            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},layerSlds{i},sldProfiles{i},...
             resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices(i),...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionIndices(i),contrastDomainRatioIndices(i),...
             backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
             bulkOutArray,resolutionParamArray,domainRatioArray,dataPresent(i),...
             allData{i},dataLimits{i},simLimits{i},repeatLayers{i},...
             contrastBackgroundsType(i),nParams,parallel,resampleParams,...
             useImaginary,allRoughs(i),inputSldProfiles1{i},inputSldProfiles2{i});

        end
    
    else
        
        for i = 1:numberOfContrasts
            
            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},layerSlds{i},sldProfiles{i},...
             resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices(i),...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionIndices(i),contrastDomainRatioIndices(i),...
             backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
             bulkOutArray,resolutionParamArray,domainRatioArray,dataPresent(i),...
             allData{i},dataLimits{i},simLimits{i},repeatLayers{i},...
             contrastBackgroundsType(i),nParams,parallel,resampleParams,...
             useImaginary,allRoughs(i),inputSldProfiles1{i},inputSldProfiles2{i});

        end
    
    end
    
    for i = 1:numberOfContrasts

        contrastSLDProfiles = sldProfiles{i};
        domainSldProfiles{i,1} = contrastSLDProfiles{1};
        domainSldProfiles{i,2} = contrastSLDProfiles{2};
    
        contrastLayersSlds = layerSlds{i};
        domainLayerSlds{i,1} = contrastLayersSlds{1};
        domainLayerSlds{i,2} = contrastLayersSlds{2};
    
        contrastResampledLayers = resampledLayers{i};
        domainResampledLayers{i,1} = contrastResampledLayers{1};
        domainResampledLayers{i,2} = contrastResampledLayers{2};
    
    end

end


function [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,...
    bulkOutValue,resolutionParamValue,chi,reflectivity,simulation,shiftedData,...
    layerSld,sldProfile,resampledLayer] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    domainRatioIndex,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,domainRatios,dataPresent,allData,dataLimits,simLimits,...
    repeatLayers,contrastBackgroundsType,nParams,parallel,resampleParams,...
    useImaginary,roughness,sldProfile1,sldProfile2)

    % Get the domain ratio for this contrast
    if isempty(domainRatioIndex)
        domainRatioIndex = 1;
    end
    domainRatio = domainRatios(domainRatioIndex);

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue,...
     resolutionParamValue] = backSort(backgroundParamIndex,qzshiftIndex,...
     scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
     backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams);
     
    % Resample the sld profiles
    if ~useImaginary
        layerSld1 = resampleLayers(sldProfile1,resampleParams);
        layerSld2 = resampleLayers(sldProfile2,resampleParams);
    else
        reSLD1 = sldProfile1(:,1:2);
        imSLD1 = [sldProfile1(:,1),sldProfile1(:,3)];

        reSLD2 = sldProfile2(:,1:2);
        imSLD2 = [sldProfile2(:,1),sldProfile2(:,3)];

        layerSld1 = resampleLayersReIm(reSLD1,imSLD1,resampleParams);
        layerSld2 = resampleLayersReIm(reSLD2,imSLD2,resampleParams);
    end

    layerSld = {layerSld1, layerSld2};
    resampledLayer = {layerSld1, layerSld2};
    sldProfile = {sldProfile1, sldProfile2};

    shiftedDat = shiftData(scalefactorValue,qzshiftValue,dataPresent,allData,dataLimits,simLimits);
    shiftedData = shiftedDat;

    reflectivityType = 'standardAbeles';
    [reflect1,simul1] = callReflectivity(bulkInValue,bulkOutValue,simLimits,repeatLayers,shiftedDat,layerSld1,roughness,resolutionParamValue,parallel,reflectivityType,useImaginary);
    [reflect2,simul2] = callReflectivity(bulkInValue,bulkOutValue,simLimits,repeatLayers,shiftedDat,layerSld2,roughness,resolutionParamValue,parallel,reflectivityType,useImaginary);
    
    [reflect1,simul1,shiftedDat] = applyBackgroundCorrection(reflect1,simul1,shiftedDat,backgroundParamValue,contrastBackgroundsType);
    [reflect2,simul2,shiftedDat] = applyBackgroundCorrection(reflect2,simul2,shiftedDat,backgroundParamValue,contrastBackgroundsType);

     % Calculate the average reflectivities....
    [reflectivity,simulation] = domainsTF.averageReflectivity(reflect1,reflect2,simul1,simul2,domainRatio);

    if dataPresent
        chi = chiSquared(shiftedDat,reflectivity,nParams);
    else
        chi = 0;
    end

end
