function [qzshifts,scalefactors,bulkIns,bulkOuts,chis,reflectivity,...
    simulation,shiftedData,backgrounds,resolutions,domainLayerSlds,...
    domainSldProfiles,domainResampledLayers,subRoughs] = customXY(problemStruct,controls)
    
    % Extract parameters from problemStruct
    [numberOfContrasts, ~, contrastBackgroundIndices, contrastQzshiftIndices,...
     contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
     contrastResolutionIndices, contrastDomainRatioIndices, backgroundParamArray,...
     qzshiftArray, scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray,...
     domainRatioArray, dataPresent, nParams, params, ~, ~, contrastBackgroundTypes,...
     contrastBackgroundActions, contrastResolutionTypes, cCustFiles, useImaginary,...
     repeatLayers, data, dataLimits, simLimits, ~, ~, customFiles, ~] = extractProblemParams(problemStruct);

    parallel = controls.parallel;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;

    %Pre-Allocation...
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    chis = zeros(numberOfContrasts,1);
    
    reflectivity = cell(numberOfContrasts,1);   
    simulation = cell(numberOfContrasts,1);
    shiftedData = cell(numberOfContrasts,1);
    backgrounds = cell(numberOfContrasts,1);
    resolutions = cell(numberOfContrasts,1);
    domainLayerSlds = cell(numberOfContrasts,2);
    domainSldProfiles = cell(numberOfContrasts,2);    
    domainResampledLayers = cell(numberOfContrasts,2);   

    layerSlds = cell(numberOfContrasts,1);    
    sldProfiles = cell(numberOfContrasts,1);  
    resampledLayers = cell(numberOfContrasts,1);

    inputSldProfiles1 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        inputSldProfiles1{i} = [1; 1];
    end
    
    inputSldProfiles2 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        inputSldProfiles2{i} = [1; 1];
    end

    [inputSldProfiles,subRoughs] = domainsTF.customXY.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params);
    
    for i = 1:size(inputSldProfiles,1)
        inputSldProfiles1{i} = inputSldProfiles{i,1};
        inputSldProfiles2{i} = inputSldProfiles{i,2};
    end

    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        parfor i = 1:numberOfContrasts
    
            [qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),chis(i),...
             reflectivity{i},simulation{i},shiftedData{i},backgrounds{i},...
             resolutions{i},layerSlds{i},sldProfiles{i},resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionIndices{i},contrastDomainRatioIndices(i),...
             backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
             bulkOutArray,resolutionParamArray,domainRatioArray,dataPresent(i),...
             data{i},dataLimits{i},simLimits{i},repeatLayers{i},...
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel, ...
             resampleMinAngle,resampleNPoints,useImaginary,subRoughs(i),...
             inputSldProfiles1{i},inputSldProfiles2{i});

        end
    
    else
        
        for i = 1:numberOfContrasts
            
            [qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),chis(i),...
             reflectivity{i},simulation{i},shiftedData{i},backgrounds{i},...
             resolutions{i},layerSlds{i},sldProfiles{i},resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionIndices{i},contrastDomainRatioIndices(i),...
             backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
             bulkOutArray,resolutionParamArray,domainRatioArray,dataPresent(i),...
             data{i},dataLimits{i},simLimits{i},repeatLayers{i},...
             contrastBackgroundTypes,contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,useImaginary,subRoughs(i),...
             inputSldProfiles1{i},inputSldProfiles2{i});

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


function [qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue,chi,...
    reflectivity,simulation,shiftedData,background,resolution,layerSld,...
    sldProfile,resampledLayer] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    domainRatioIndex,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,domainRatios,dataPresent,data,dataLimits,simLimits,...
    repeatLayers,backgroundType,backgroundAction,resolutionType,customFiles,...
    nParams,parallel,resampleMinAngle,resampleNPoints,useImaginary,roughness,...
    sldProfile1,sldProfile2)

    % Get the domain ratio for this contrast
    if isempty(domainRatioIndex)
        domainRatioIndex = 1;
    end
    domainRatio = domainRatios(domainRatioIndex);

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue] = backSort(qzshiftIndex,...
     scalefactorIndex,bulkInIndex,bulkOutIndex,qzshifts,scalefactors,bulkIns,bulkOuts);
     
    % Resample the sld profiles
    if ~useImaginary
        layerSld1 = resampleLayers(sldProfile1,resampleMinAngle,resampleNPoints);
        layerSld2 = resampleLayers(sldProfile2,resampleMinAngle,resampleNPoints);
    else
        reSLD1 = sldProfile1(:,1:2);
        imSLD1 = [sldProfile1(:,1),sldProfile1(:,3)];

        reSLD2 = sldProfile2(:,1:2);
        imSLD2 = [sldProfile2(:,1),sldProfile2(:,3)];

        layerSld1 = resampleLayersReIm(reSLD1,imSLD1,resampleMinAngle,resampleNPoints);
        layerSld2 = resampleLayersReIm(reSLD2,imSLD2,resampleMinAngle,resampleNPoints);
    end

    layerSld = {layerSld1, layerSld2};
    resampledLayer = {layerSld1, layerSld2};
    sldProfile = {sldProfile1, sldProfile2};

    shiftedData = shiftData(scalefactorValue,qzshiftValue,dataPresent,data,dataLimits,simLimits);
    [simulationXData, dataIndices] = makeSimulationRange(shiftedData, simLimits);

    background = constructBackground(backgroundType,backgroundParamIndex,...
        shiftedData,customFiles,backgroundParams,simulationXData,dataIndices);
    resolution = constructResolution(resolutionType,resolutionParamIndex,...
        shiftedData,customFiles,resolutionParams,simulationXData,dataIndices);

    reflectivityType = 'standardAbeles';
    [reflect1,simul1] = callReflectivity(bulkInValue,bulkOutValue,simulationXData,dataIndices,repeatLayers,layerSld1,roughness,resolution,parallel,reflectivityType,useImaginary);
    [reflect2,simul2] = callReflectivity(bulkInValue,bulkOutValue,simulationXData,dataIndices,repeatLayers,layerSld2,roughness,resolution,parallel,reflectivityType,useImaginary);

    [reflect1,simul1,~] = applyBackgroundCorrection(reflect1,simul1,shiftedData,background,backgroundAction);
    [reflect2,simul2,shiftedData] = applyBackgroundCorrection(reflect2,simul2,shiftedData,background,backgroundAction);

     % Calculate the average reflectivities....
    [reflectivity,simulation] = domainsTF.averageReflectivity(reflect1,reflect2,simul1,simul2,domainRatio);

    if dataPresent
        chi = chiSquared(shiftedData,reflectivity,nParams);
    else
        chi = 0;
    end

end
