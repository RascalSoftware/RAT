function [qzshifts,scalefactors,bulkIns,bulkOuts,chis,reflectivity,...
    simulation,shiftedData,backgrounds,resolutions,sldProfiles,layers,...
    resampledLayers,subRoughs] = normalReflectivity(problemStruct,controls)
    % This is the main normal reflectivity calculation.
    % It extracts the required parameters for the contrasts
    % from the input arrays, then passes the main calculation to
    % the appropriate core calculation, which carries out the calculation
    % itself. The core layers calculation is common for both standard and
    % custom layers, with an additional core custom XY calculation.

    % Extract parameters from problemStruct
    [numberOfContrasts, geometry, contrastBackgroundIndices,...
     contrastResolutionIndices, ~, backgroundParamValues, resolutionParamValues,...
     qzshifts, scalefactors, bulkIns, bulkOuts, ~, dataPresent, nParams,... 
     paramValues, resample, contrastBackgroundTypes, contrastBackgroundActions,...
     contrastResolutionTypes, contrastCustomFiles, useImaginary, repeatLayers,...
     data, dataLimits, simulationLimits, contrastLayersIndices, layersDetails,...
     customFiles, ~] = extractProblemParams(problemStruct);
    
    calcSld = controls.calcSldDuringFit;
    parallel = controls.parallel;
    numSimulationPoints = controls.numSimulationPoints;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;
    
    % Allocate the memory for the output arrays before the main loop
    chis = zeros(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);
    
    reflectivity = cell(numberOfContrasts,1);  
    simulation = cell(numberOfContrasts,1);
    shiftedData = cell(numberOfContrasts,1);
    backgrounds = cell(numberOfContrasts,1);
    resolutions = cell(numberOfContrasts,1);
    sldProfiles = cell(numberOfContrasts,1);
    layers = cell(numberOfContrasts,1);
    resampledLayers = cell(numberOfContrasts,1);

    contrastLayers = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        contrastLayers{i} = zeros(1, 6);
    end

    slds = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        slds{i} = zeros(1, 3);
    end

    switch lower(problemStruct.modelType)
        
        case coderEnums.modelTypes.StandardLayers

            % First we need to allocate the absolute values of the input
            % parameters to all the layers in the layers list. This only
            % needs to be done once, and so is done outside the contrasts
            % loop
            layerValues = allocateParamsToLayers(paramValues, layersDetails);

            for i = 1:numberOfContrasts
    
                % Substrate roughness is always first parameter for
                % standard layers.
                subRoughs(i) = paramValues(1);
    
                % Also need to determine which layers from the overall
                % layers list are required for this contrast, and put them
                % in the correct order according to geometry. 
                contrastLayers{i} = allocateLayersForContrast( ...
                    contrastLayersIndices{i},layerValues);
    
            end

        case coderEnums.modelTypes.CustomLayers

            % Process the custom models
            numberOfOutputColumns = 6;
            [contrastLayers,subRoughs] = normalTF.processCustomFunction(...
                bulkIns,bulkOuts,contrastCustomFiles,numberOfContrasts,...
                numberOfOutputColumns,customFiles,paramValues,useImaginary);

        case coderEnums.modelTypes.CustomXY

            % Process the custom models
            numberOfOutputColumns = 3;
            [slds,subRoughs] = normalTF.processCustomFunction(...
                bulkIns,bulkOuts,contrastCustomFiles,numberOfContrasts,...
                numberOfOutputColumns,customFiles,paramValues,useImaginary);

        otherwise
            
            coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', problemStruct.modelType);

    end
    
    if strcmpi(problemStruct.modelType, coderEnums.modelTypes.CustomXY)

        if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
        
            parfor i = 1:numberOfContrasts

                [inputBackground,inputResolution,inputShiftedData,...
                 simulationXData,dataIndices...
                 ] = setupCoreReflectivityCalculation(...
                 contrastBackgroundIndices{i},contrastResolutionIndices{i},...
                 backgroundParamValues,resolutionParamValues,qzshifts(i),...
                 scalefactors(i),dataPresent(i),data{i},dataLimits{i},...
                 simulationLimits{i},contrastBackgroundTypes{i},...
                 contrastResolutionTypes{i},customFiles,numSimulationPoints);
        
                [outputReflectivity,simulation{i},outputShiftedData,...
                 sldProfiles{i},layers{i},resampledLayers{i}...
                 ] = normalTF.coreCustomXYCalculation(bulkIns(i),bulkOuts(i),...
                 inputShiftedData,simulationXData,dataIndices,...
                 inputResolution,inputBackground,contrastBackgroundActions{i},...
                 parallel,resampleMinAngle,resampleNPoints,subRoughs(i),slds{i});

                backgrounds{i} = inputBackground;
                resolutions{i} = inputResolution;

                chis(i) = chiSquared(outputShiftedData,outputReflectivity,nParams);

                shiftedData{i} = outputShiftedData;
                reflectivity{i} = outputReflectivity;


            end
            
        else
        
            for i = 1:numberOfContrasts

                [inputBackground,inputResolution,inputShiftedData,...
                 simulationXData,dataIndices...
                 ] = setupCoreReflectivityCalculation(...
                 contrastBackgroundIndices{i},contrastResolutionIndices{i},...
                 backgroundParamValues,resolutionParamValues,qzshifts(i),...
                 scalefactors(i),dataPresent(i),data{i},dataLimits{i},...
                 simulationLimits{i},contrastBackgroundTypes{i},...
                 contrastResolutionTypes{i},customFiles,numSimulationPoints);

                [outputReflectivity,simulation{i},outputShiftedData,...
                 sldProfiles{i},layers{i},resampledLayers{i}...
                 ] = normalTF.coreCustomXYCalculation(bulkIns(i),bulkOuts(i),...
                 inputShiftedData,simulationXData,dataIndices,...
                 inputResolution,inputBackground,contrastBackgroundActions{i},...
                 parallel,resampleMinAngle,resampleNPoints,subRoughs(i),slds{i});

                backgrounds{i} = inputBackground;
                resolutions{i} = inputResolution;

                chis(i) = chiSquared(outputShiftedData,outputReflectivity,nParams);

                shiftedData{i} = outputShiftedData;
                reflectivity{i} = outputReflectivity;
   
            end
        end

    else
    
        if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
        
            parfor i = 1:numberOfContrasts
        
                [inputBackground,inputResolution,inputShiftedData,...
                 simulationXData,dataIndices...
                 ] = setupCoreReflectivityCalculation(...
                 contrastBackgroundIndices{i},contrastResolutionIndices{i},...
                 backgroundParamValues,resolutionParamValues,qzshifts(i),...
                 scalefactors(i),dataPresent(i),data{i},dataLimits{i},...
                 simulationLimits{i},contrastBackgroundTypes{i},...
                 contrastResolutionTypes{i},customFiles,numSimulationPoints);
                
                [outputReflectivity,simulation{i},outputShiftedData,...
                 sldProfiles{i},layers{i},resampledLayers{i}...
                 ] = normalTF.coreLayersCalculation(contrastLayers{i},...
                 subRoughs(i),geometry,bulkIns(i),bulkOuts(i),resample(i),...
                 calcSld,inputShiftedData,simulationXData,dataIndices,...
                 repeatLayers(i),inputResolution,inputBackground,...
                 contrastBackgroundActions{i},parallel,...
                 resampleMinAngle,resampleNPoints);

                backgrounds{i} = inputBackground;
                resolutions{i} = inputResolution;

                chis(i) = chiSquared(outputShiftedData,outputReflectivity,nParams);

                shiftedData{i} = outputShiftedData;
                reflectivity{i} = outputReflectivity;

            end
            
        else
        
            for i = 1:numberOfContrasts
                
                [inputBackground,inputResolution,inputShiftedData,...
                 simulationXData,dataIndices...
                 ] = setupCoreReflectivityCalculation(...
                 contrastBackgroundIndices{i},contrastResolutionIndices{i},...
                 backgroundParamValues,resolutionParamValues,qzshifts(i),...
                 scalefactors(i),dataPresent(i),data{i},dataLimits{i},...
                 simulationLimits{i},contrastBackgroundTypes{i},...
                 contrastResolutionTypes{i},customFiles,numSimulationPoints);
                
                [outputReflectivity,simulation{i},outputShiftedData,...
                 sldProfiles{i},layers{i},resampledLayers{i}...
                 ] = normalTF.coreLayersCalculation(contrastLayers{i},...
                 subRoughs(i),geometry,bulkIns(i),bulkOuts(i),resample(i),...
                 calcSld,inputShiftedData,simulationXData,dataIndices,...
                 repeatLayers(i),inputResolution,inputBackground,...
                 contrastBackgroundActions{i},parallel,...
                 resampleMinAngle,resampleNPoints);

                backgrounds{i} = inputBackground;
                resolutions{i} = inputResolution;

                chis(i) = chiSquared(outputShiftedData,outputReflectivity,nParams);

                shiftedData{i} = outputShiftedData;
                reflectivity{i} = outputReflectivity;

            end
        end
    end

    % Remove dummy imaginary column if present
    if ~useImaginary
        for i=1:numberOfContrasts
            layers{i}(:,3) = [];
            resampledLayers{i}(:,3) = [];
        end
    end

end

function [reflectivity,simulation,shiftedData,sldProfile,layers,...
    resampledLayers,chi] = customXYContrastCalculation(bulkIn,bulkOut,...
    shiftedData,simulationXData,dataIndices,resolution,background,...
    backgroundAction,nParams,parallel,resampleMinAngle,resampleNPoints,...
    roughness,sld)

    % Resample the layers
    sldProfile = sld(:,[1,2]);
    sldProfileIm = sld(:,[1,3]);
    resampledLayers = resampleLayers(sldProfile,sldProfileIm,...
        resampleMinAngle,resampleNPoints);
    
    layers = resampledLayers;

    reflectivityType = 'standardAbeles';
    [reflectivity,simulation] = callReflectivity(bulkIn,bulkOut,...
     simulationXData,dataIndices,1,layers,roughness,resolution,parallel,...
     reflectivityType);

    [reflectivity,simulation,shiftedData] = applyBackgroundCorrection(...
        reflectivity,simulation,shiftedData,background,backgroundAction);
    
    chi = chiSquared(shiftedData,reflectivity,nParams);

end
