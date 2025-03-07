function [qzshifts,scalefactors,bulkIns,bulkOuts,chis,reflectivity,...
    simulation,shiftedData,backgrounds,resolutions,domainLayerSlds,...
    domainSldProfiles,domainResampledLayers,subRoughs] = customLayers(problemStruct,controls)
    % The custom layers, domainsTF reflectivity calculation.
    % The function extracts the relevant parameters from the input arrays,
    % allocates these on a pre-contrast basis, then calls the 
    % 'coreLayersCalculation' (the core layers domainsTF calc is shared
    % between multiple calculation types).
    
    % Extract parameters from problemStruct
    [numberOfContrasts, geometry, contrastBackgroundIndices, contrastQzshiftIndices,...
     contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
     contrastResolutionIndices, contrastDomainRatioIndices, backgroundParamArray,...
     qzshiftArray, scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray,...
     domainRatioArray, dataPresent, nParams, params, ~, resample,...
     contrastBackgroundTypes, contrastBackgroundActions, contrastResolutionTypes,...
     cCustFiles, useImaginary, repeatLayers, data, dataLimits, simLimits,...
     ~, ~, customFiles, ~] = extractProblemParams(problemStruct);

    calcSld = controls.calcSldDuringFit;
    parallel = controls.parallel;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;
             
    % Pre-Allocation of output arrays...
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
    
    calcAllLayers1 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        calcAllLayers1{i} = [1; 1];
    end
    
    calcAllLayers2 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        calcAllLayers2{i} = [1; 1];
    end

    % Process the custom models....
    [calcAllLayers,subRoughs] = domainsTF.customLayers.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params,useImaginary);
    
    for i = 1:size(calcAllLayers,1)
        calcAllLayers1{i} = calcAllLayers{i,1};
        calcAllLayers2{i} = calcAllLayers{i,2};
    end

    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        % Parallel over all contrasts
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
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,useImaginary,resample(i),...
             geometry,subRoughs(i),calcSld,calcAllLayers1{i},calcAllLayers2{i});
    
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
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,useImaginary,resample(i),...
             geometry,subRoughs(i),calcSld,calcAllLayers1{i},calcAllLayers2{i});

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

    % Remove dummy imaginary column if present
    if ~useImaginary
        for i=1:numberOfContrasts
            domainLayerSlds{i,1}(:,3) = [];
            domainLayerSlds{i,2}(:,3) = [];
            domainResampledLayers{i,1}(:,3) = [];
            domainResampledLayers{i,2}(:,3) = [];
        end
    end

end


function [qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue,chi,...
    reflectivity,simulation,shiftedData,background,resolution,layerSld,...
    sldProfile,resampledLayer] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    domainRatioIndex,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,domainRatios,dataPresent,data,dataLimits,simLimits,...
    repeatLayers,backgroundType,backgroundAction,resolutionType,customFiles,...
    nParams,parallel,resampleMinAngle,resampleNPoints,useImaginary,resample,...
    geometry,roughness,calcSld,calcAllLayers1,calcAllLayers2)

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

    % Apply scale factors and q shifts to the data
    shiftedData = shiftData(scalefactorValue,qzshiftValue,dataPresent,data,dataLimits,simLimits);
    [simulationXData, dataIndices] = makeSimulationRange(shiftedData, simLimits);

    background = constructBackground(backgroundType,backgroundParamIndex,...
        shiftedData,customFiles,backgroundParams,simulationXData,dataIndices);
    resolution = constructResolution(resolutionType,resolutionParamIndex,...
        shiftedData,customFiles,resolutionParams,simulationXData,dataIndices);

    % Call the core layers calculation - need to do this once for each
    % domain
    [sldProfile1,reflect1,simul1,~,layerSld1,resampledLayer1,~] = normalTF.coreLayersCalculation(calcAllLayers1,roughness,...
     geometry,bulkInValue,bulkOutValue,resample,calcSld,shiftedData,simulationXData,dataIndices,repeatLayers,...
     resolution,background,backgroundAction,nParams,parallel,resampleMinAngle,resampleNPoints,useImaginary);

    [sldProfile2,reflect2,simul2,shiftedData,layerSld2,resampledLayer2,~] = normalTF.coreLayersCalculation(calcAllLayers2,roughness,...
     geometry,bulkInValue,bulkOutValue,resample,calcSld,shiftedData,simulationXData,dataIndices,repeatLayers,...
     resolution,background,backgroundAction,nParams,parallel,resampleMinAngle,resampleNPoints,useImaginary);
    
    % Calculate the average reflectivities....
    [reflectivity,simulation] = domainsTF.averageReflectivity(reflect1,reflect2,simul1,simul2,domainRatio);

    % Get an overall chi-squared for the new averaged curve..
    chi = chiSquared(shiftedData,reflectivity,nParams);

    % Store returned values for this contrast in the output arrays.
    sldProfile = {sldProfile1, sldProfile2};
    layerSld = {layerSld1, layerSld2};
    resampledLayer = {resampledLayer1, resampledLayer2};

end
