function [qzshifts,scalefactors,bulkIns,bulkOuts,chis,reflectivity,...
    simulation,shiftedData,backgrounds,resolutions,domainSldProfiles,...
    domainLayers,domainResampledLayers,subRoughs] = customXY(problemStruct,controls)
    
    % Extract parameters from problemStruct
    [numberOfContrasts, ~, contrastBackgroundIndices, contrastQzshiftIndices,...
     contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
     contrastResolutionIndices, contrastDomainRatioIndices, backgroundParamValues,...
     qzshiftValues, scalefactorValues, bulkInValues, bulkOutValues, resolutionParamValues,...
     domainRatioValues, dataPresent, nParams, params, ~, ~, contrastBackgroundTypes,...
     contrastBackgroundActions, contrastResolutionTypes, contrastCustomFiles, useImaginary,...
     ~, data, dataLimits, simulationLimits, ~, ~, customFiles, ~] = extractProblemParams(problemStruct);

    parallel = controls.parallel;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;

    %Pre-Allocation
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
    domainSldProfiles = cell(numberOfContrasts,2);
    domainLayers = cell(numberOfContrasts,2);
    domainResampledLayers = cell(numberOfContrasts,2);   

    sldProfiles = cell(numberOfContrasts,1);
    layers = cell(numberOfContrasts,1);
    resampledLayers = cell(numberOfContrasts,1);

    slds1 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        slds1{i} = [1; 1];
    end
    
    slds2 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        slds2{i} = [1; 1];
    end

    numberOfOutputColumns = 3;
    [slds,subRoughs] = domainsTF.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInValues,bulkOutValues,contrastCustomFiles,numberOfContrasts,numberOfOutputColumns,customFiles,params,useImaginary);
    
    for i = 1:size(slds,1)
        slds1{i} = slds{i,1};
        slds2{i} = slds{i,2};
    end

    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        parfor i = 1:numberOfContrasts
    
            [qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),chis(i),...
             reflectivity{i},simulation{i},shiftedData{i},backgrounds{i},...
             resolutions{i},sldProfiles{i},layers{i},resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionIndices{i},contrastDomainRatioIndices(i),...
             backgroundParamValues,qzshiftValues,scalefactorValues,bulkInValues,...
             bulkOutValues,resolutionParamValues,domainRatioValues,dataPresent(i),...
             data{i},dataLimits{i},simulationLimits{i},...
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,subRoughs(i),slds1{i},slds2{i});

        end
    
    else
        
        for i = 1:numberOfContrasts
            
            [qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),chis(i),...
             reflectivity{i},simulation{i},shiftedData{i},backgrounds{i},...
             resolutions{i},sldProfiles{i},layers{i},resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionIndices{i},contrastDomainRatioIndices(i),...
             backgroundParamValues,qzshiftValues,scalefactorValues,bulkInValues,...
             bulkOutValues,resolutionParamValues,domainRatioValues,dataPresent(i),...
             data{i},dataLimits{i},simulationLimits{i},...
             contrastBackgroundTypes,contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,subRoughs(i),slds1{i},slds2{i});

        end
    
    end
    
    for i = 1:numberOfContrasts

        contrastSLDProfiles = sldProfiles{i};
        domainSldProfiles{i,1} = contrastSLDProfiles{1};
        domainSldProfiles{i,2} = contrastSLDProfiles{2};
    
        contrastLayersValues = layers{i};
        domainLayers{i,1} = contrastLayersValues{1};
        domainLayers{i,2} = contrastLayersValues{2};
    
        contrastResampledLayers = resampledLayers{i};
        domainResampledLayers{i,1} = contrastResampledLayers{1};
        domainResampledLayers{i,2} = contrastResampledLayers{2};
    
    end

    % Remove dummy imaginary column if present
    if ~useImaginary
        for i=1:numberOfContrasts
            domainSldProfiles{i,1}(:,3) = [];
            domainSldProfiles{i,2}(:,3) = [];
            domainLayers{i,1}(:,3) = [];
            domainLayers{i,2}(:,3) = [];
            domainResampledLayers{i,1}(:,3) = [];
            domainResampledLayers{i,2}(:,3) = [];
        end
    end

end


function [qzshift,scalefactor,bulkIn,bulkOut,chi,reflectivity,simulation,...
    shiftedData,background,resolution,sldProfile,layers,...
    resampledLayers] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    domainRatioIndex,backgroundParamValues,qzshiftValues,scalefactorValues,...
    bulkInValues,bulkOutValues,resolutionParamValues,domainRatioValues,...
    dataPresent,data,dataLimits,simulationLimits,backgroundType,...
    backgroundAction,resolutionType,customFiles,nParams,parallel,...
    resampleMinAngle,resampleNPoints,roughness,sldProfile1,sldProfile2)

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
        qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex, ...
        qzshiftValues,scalefactorValues,bulkInValues,bulkOutValues);
     
    % Resample the sld profiles
    reSLD1 = sldProfile1(:,[1,2]);
    imSLD1 = sldProfile1(:,[1,3]);

    reSLD2 = sldProfile2(:,[1,2]);
    imSLD2 = sldProfile2(:,[1,3]);

    layers1 = resampleLayers(reSLD1,imSLD1,resampleMinAngle,resampleNPoints);
    layers2 = resampleLayers(reSLD2,imSLD2,resampleMinAngle,resampleNPoints);

    layers = {layers1, layers2};
    resampledLayers = {layers1, layers2};
    sldProfile = {sldProfile1, sldProfile2};

    shiftedData = shiftData(scalefactor,qzshift,dataPresent,data,dataLimits,simulationLimits);
    [simulationXData, dataIndices] = makeSimulationRange(shiftedData, simulationLimits);

    background = constructBackground(backgroundType,backgroundParamIndex,...
        shiftedData,customFiles,backgroundParamValues,simulationXData,dataIndices);
    resolution = constructResolution(resolutionType,resolutionParamIndex,...
        shiftedData,customFiles,resolutionParamValues,simulationXData,dataIndices);

    reflectivityType = 'standardAbeles';
    [reflectivity1,simulation1] = callReflectivity(bulkIn,bulkOut,simulationXData, ...
        dataIndices,1,layers1,roughness,resolution,parallel,reflectivityType);
    [reflectivity2,simulation2] = callReflectivity(bulkIn,bulkOut,simulationXData, ...
        dataIndices,1,layers2,roughness,resolution,parallel,reflectivityType);

    [reflectivity1,simulation1,~] = applyBackgroundCorrection(reflectivity1,simulation1,shiftedData,background,backgroundAction);
    [reflectivity2,simulation2,shiftedData] = applyBackgroundCorrection(reflectivity2,simulation2,shiftedData,background,backgroundAction);

     % Calculate the average reflectivities
    [reflectivity,simulation] = domainsTF.averageReflectivity(reflectivity1,reflectivity2,simulation1,simulation2,domainRatio);

    chi = chiSquared(shiftedData,reflectivity,nParams);

end
