function [qzshifts,scalefactors,bulkIns,bulkOuts,chis,reflectivity,...
    simulation,shiftedData,backgrounds,resolutions,domainSldProfiles,...
    domainLayers,domainResampledLayers,subRoughs] = standardLayers(problemStruct,controls)
    % This is the main reflectivity calculation of the standard layers
    % calculation type. It extracts the required parameters for the contrasts
    % from the input arrays, then passes the main calculation to
    % 'coreLayersCalculation', which carries out the calculation itself. 
    % The core calculation is common for both standard and custom layers.
    
    % Extract parameters from problemStruct
    [numberOfContrasts, geometry, contrastBackgroundIndices, contrastQzshiftIndices,...
     contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
     contrastResolutionIndices, contrastDomainRatioIndices, backgroundParamValues,...
     qzshiftValues, scalefactorValues, bulkInValues, bulkOutValues,...
     resolutionParamValues, domainRatioValues, dataPresent, nParams, paramValues,...
     ~, resample, contrastBackgroundTypes, contrastBackgroundActions,...
     contrastResolutionTypes, contrastCustomFiles, useImaginary,...
     repeatLayers, data, dataLimits, simulationLimits, inputContrastLayers,...
     layersDetails, customFiles, domainContrastLayers...
     ] = extractProblemParams(problemStruct);
    
    calcSld = controls.calcSldDuringFit;
    parallel = controls.parallel;
    numSimulationPoints = controls.numSimulationPoints;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;
    
    % Allocate the memory for the output arrays before the main loop
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    domainRatios = zeros(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);
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
    
    contrastLayers1 = cell(numberOfContrasts,1);   
    contrastLayers2 = cell(numberOfContrasts,1);

    % Extract the relevant parameter values for this contrast from the
    % input arrays. We need to determine which values of the data shifts,
    % scalefactors, and bulk contrasts are associated with this contrast.
    for i = 1:numberOfContrasts

        [qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i)] = backSort( ...
         contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
         contrastBulkInIndices(i),contrastBulkOutIndices(i),...
         qzshiftValues,scalefactorValues,bulkInValues,bulkOutValues);

        % Get the domain ratio for this contrast
        if isempty(contrastDomainRatioIndices(i))
            contrastDomainRatioIndices(i) = 1;
        end
        domainRatios(i) = domainRatioValues(contrastDomainRatioIndices(i));

    end


    switch lower(problemStruct.modelType)
        
        case coderEnums.modelTypes.StandardLayers

            % First we need to allocate the absolute values of the input
            % parameters to all the layers in the layers list. This only needs
            % to be done once, and so is done outside the contrasts loop
            layerValues = allocateParamsToLayers(paramValues, layersDetails);

            for i = 1:numberOfContrasts

                % Substrate roughness is always first parameter for standard layers
                subRoughs(i) = paramValues(1);
    
                % Also need to determine which layers from the overall layers list
                % are required for this contrast, and put them in the correct order 
                % according to geometry. We run it twice, once for each domain
                contrastLayers1{i} = allocateLayersForContrast(domainContrastLayers{inputContrastLayers{i}(1)},layerValues);
                contrastLayers2{i} = allocateLayersForContrast(domainContrastLayers{inputContrastLayers{i}(2)},layerValues);

            end

        case coderEnums.modelTypes.CustomLayers

            numberOfOutputColumns = 6;
            [contrastLayers,subRoughs] = domainsTF.processCustomFunction( ...
             contrastBulkInIndices,contrastBulkOutIndices,bulkInValues,bulkOutValues, ...
             contrastCustomFiles,numberOfContrasts,numberOfOutputColumns,customFiles,paramValues,useImaginary);

            for i = 1:size(contrastLayers,1)
                contrastLayers1{i} = contrastLayers{i,1};
                contrastLayers2{i} = contrastLayers{i,2};
            end

    end



    


    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        % Loop over all the contrasts
        parfor i = 1:numberOfContrasts
        
            [chis(i),...
             reflectivity{i},simulation{i},shiftedData{i},backgrounds{i},...
             resolutions{i},sldProfiles{i},layers{i},resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastResolutionIndices{i},backgroundParamValues,...
             resolutionParamValues,...
             qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),domainRatios(i),...
             dataPresent(i),data{i},dataLimits{i},simulationLimits{i},repeatLayers(i),...
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             numSimulationPoints,resampleMinAngle,resampleNPoints,resample(i),...
             geometry,subRoughs(i),calcSld,contrastLayers1{i},contrastLayers2{i});
    
        end
    
    else
    
        % Loop over all the contrasts
        for i = 1:numberOfContrasts

            [chis(i),...
             reflectivity{i},simulation{i},shiftedData{i},backgrounds{i},...
             resolutions{i},sldProfiles{i},layers{i},resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastResolutionIndices{i},backgroundParamValues,...
             resolutionParamValues,...
             qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),domainRatios(i),...
             dataPresent(i),data{i},dataLimits{i},simulationLimits{i},repeatLayers(i),...
             contrastBackgroundTypes{i},contrastBackgroundActions{i},...
             contrastResolutionTypes{i},customFiles,nParams,parallel,...
             numSimulationPoints,resampleMinAngle,resampleNPoints,resample(i),...
             geometry,subRoughs(i),calcSld,contrastLayers1{i},contrastLayers2{i});

        end
    
    end
    
    for i = 1:numberOfContrasts
    
        contrastSldProfiles = sldProfiles{i};
        domainSldProfiles{i,1} = contrastSldProfiles{1};
        domainSldProfiles{i,2} = contrastSldProfiles{2};
    
        contrastLayerValues = layers{i};
        domainLayers{i,1} = contrastLayerValues{1};
        domainLayers{i,2} = contrastLayerValues{2};
    
        contrastResampledLayers = resampledLayers{i};
        domainResampledLayers{i,1} = contrastResampledLayers{1};
        domainResampledLayers{i,2} = contrastResampledLayers{2};
    
    end

    % Remove dummy imaginary column if present
    if ~useImaginary
        for i=1:numberOfContrasts
            domainLayers{i,1}(:,3) = [];
            domainLayers{i,2}(:,3) = [];
            domainResampledLayers{i,1}(:,3) = [];
            domainResampledLayers{i,2}(:,3) = [];
        end
    end

end


function [chi,reflectivity,simulation,...
    shiftedData,background,resolution,sldProfile,layers,...
    resampledLayers] = contrastCalculation(backgroundParamIndex,...
    resolutionParamIndex,backgroundParamValues,resolutionParamValues,...
    qzshift,scalefactor,bulkIn,bulkOut,domainRatio,...
    dataPresent,data,dataLimits,simulationLimits,repeatLayers,...
    backgroundType,backgroundAction,resolutionType,customFiles,nParams,...
    parallel,numSimulationPoints,resampleMinAngle,resampleNPoints,resample,...
    geometry,roughness,calcSld,contrastLayers1,contrastLayers2)
    
    % Apply scale factors and q shifts to the data
    shiftedData = shiftData(scalefactor,qzshift,dataPresent,data,dataLimits,simulationLimits,numSimulationPoints);
    [simulationXData, dataIndices] = makeSimulationRange(shiftedData, simulationLimits);

    background = constructBackground(backgroundType,backgroundParamIndex,...
        shiftedData,customFiles,backgroundParamValues,simulationXData,dataIndices);
    resolution = constructResolution(resolutionType,resolutionParamIndex,...
        shiftedData,customFiles,resolutionParamValues,simulationXData,dataIndices);
      
    % Call the core layers calculation - need to do this once for each
    % domain
    [reflectivity1,simulation1,~,sldProfile1,layers1,resampledLayers1] = normalTF.coreLayersCalculation( ...
        contrastLayers1,roughness,geometry,bulkIn,bulkOut,resample,calcSld,shiftedData, ...
        simulationXData,dataIndices,repeatLayers,resolution,background, ...
        backgroundAction,parallel,resampleMinAngle,resampleNPoints);

    [reflectivity2,simulation2,shiftedData,sldProfile2,layers2,resampledLayers2] = normalTF.coreLayersCalculation( ...
        contrastLayers2,roughness,geometry,bulkIn,bulkOut,resample,calcSld,shiftedData, ...
        simulationXData,dataIndices,repeatLayers,resolution,background, ...
        backgroundAction,parallel,resampleMinAngle,resampleNPoints);
    
    % Calculate the average reflectivities
    [reflectivity,simulation] = domainsTF.averageReflectivity(reflectivity1,reflectivity2,simulation1,simulation2,domainRatio);

    % Get an overall chi-squared for the new averaged curve
    chi = chiSquared(shiftedData,reflectivity,nParams);

    % Store returned values for this contrast in the output arrays
    sldProfile = {sldProfile1, sldProfile2};
    layers = {layers1, layers2};
    resampledLayers = {resampledLayers1, resampledLayers2};

end
