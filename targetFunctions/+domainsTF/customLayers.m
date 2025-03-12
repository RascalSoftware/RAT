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
     contrastResolutionIndices, contrastDomainRatioIndices, backgroundParamValues,...
     qzshiftValues, scalefactorValues, bulkInValues, bulkOutValues, resolutionParamValues,...
     domainRatioValues, dataPresent, nParams, params, ~, resample,...
     contrastBackgroundTypes, contrastBackgroundActions, contrastResolutionTypes,...
     contrastCustomFiles, useImaginary, repeatLayers, data, dataLimits, simulationLimits,...
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
    
    contrastLayers1 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        contrastLayers1{i} = [1; 1];
    end
    
    contrastLayers2 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        contrastLayers2{i} = [1; 1];
    end

    % Process the custom models
    numberOfOutputColumns = 6;
    [contrastLayers,subRoughs] = domainsTF.processCustomFunction( ...
        contrastBulkInIndices,contrastBulkOutIndices,bulkInValues,bulkOutValues, ...
        contrastCustomFiles,numberOfContrasts,numberOfOutputColumns,customFiles,params,useImaginary);
    
    for i = 1:size(contrastLayers,1)
        contrastLayers1{i} = contrastLayers{i,1};
        contrastLayers2{i} = contrastLayers{i,2};
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
             backgroundParamValues,qzshiftValues,scalefactorValues,bulkInValues,...
             bulkOutValues,resolutionParamValues,domainRatioValues,dataPresent(i),...
             data{i},dataLimits{i},simulationLimits{i},repeatLayers{i},...
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,resample(i),geometry,...
             subRoughs(i),calcSld,contrastLayers1{i},contrastLayers2{i});
    
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
             backgroundParamValues,qzshiftValues,scalefactorValues,bulkInValues,...
             bulkOutValues,resolutionParamValues,domainRatioValues,dataPresent(i),...
             data{i},dataLimits{i},simulationLimits{i},repeatLayers{i},...
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,resample(i),geometry,...
             subRoughs(i),calcSld,contrastLayers1{i},contrastLayers2{i});

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


function [qzshift,scalefactor,bulkIn,bulkOut,chi,reflectivity,simulation,...
    shiftedData,background,resolution,layerSld,sldProfile,...
    resampledLayers] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    domainRatioIndex,backgroundParamValues,qzshiftValues,scalefactorValues,...
    bulkInValues,bulkOutValues,resolutionParamValues,domainRatioValues,...
    dataPresent,data,dataLimits,simulationLimits,repeatLayers,...
    backgroundType,backgroundAction,resolutionType,customFiles,nParams,...
    parallel,resampleMinAngle,resampleNPoints,resample,geometry,roughness,...
    calcSld,contrastLayers1,contrastLayers2)

    % Get the domain ratio for this contrast
    if isempty(domainRatioIndex)
        domainRatioIndex = 1;
    end
    domainRatio = domainRatioValues(domainRatioIndex);

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [qzshift,scalefactor,bulkIn,bulkOut] = backSort( ...
        qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,...
        qzshiftValues,scalefactorValues,bulkInValues,bulkOutValues);

    % Apply scale factors and q shifts to the data
    shiftedData = shiftData(scalefactor,qzshift,dataPresent,data,dataLimits,simulationLimits);
    [simulationXData, dataIndices] = makeSimulationRange(shiftedData, simulationLimits);

    background = constructBackground(backgroundType,backgroundParamIndex,...
        shiftedData,customFiles,backgroundParamValues,simulationXData,dataIndices);
    resolution = constructResolution(resolutionType,resolutionParamIndex,...
        shiftedData,customFiles,resolutionParamValues,simulationXData,dataIndices);

    % Call the core layers calculation - need to do this once for each
    % domain
    [reflectivity1,simulation1,~,layerSld1,sldProfile1,resampledLayers1] = normalTF.coreLayersCalculation(contrastLayers1,roughness,...
     geometry,bulkIn,bulkOut,resample,calcSld,shiftedData,simulationXData,dataIndices,repeatLayers,...
     resolution,background,backgroundAction,parallel,resampleMinAngle,resampleNPoints);

    [reflectivity2,simulation2,shiftedData,layerSld2,sldProfile2,resampledLayers2] = normalTF.coreLayersCalculation(contrastLayers2,roughness,...
     geometry,bulkIn,bulkOut,resample,calcSld,shiftedData,simulationXData,dataIndices,repeatLayers,...
     resolution,background,backgroundAction,parallel,resampleMinAngle,resampleNPoints);
    
    % Calculate the average reflectivities
    [reflectivity,simulation] = domainsTF.averageReflectivity(reflectivity1,reflectivity2,simulation1,simulation2,domainRatio);

    % Get an overall chi-squared for the new averaged curve
    chi = chiSquared(shiftedData,reflectivity,nParams);

    % Store returned values for this contrast in the output arrays
    sldProfile = {sldProfile1, sldProfile2};
    layerSld = {layerSld1, layerSld2};
    resampledLayers = {resampledLayers1, resampledLayers2};

end
