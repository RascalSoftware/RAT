function [reflectivity,simulation,shiftedData,backgrounds,resolutions,...
    sldProfiles,layers,resampledLayers,qzshifts,scalefactors,bulkIns,...
    bulkOuts,subRoughs,chis] = normalReflectivity(problemStruct,controls)
    % This is the main normal reflectivity calculation.
    % It extracts the required parameters for the contrasts
    % from the input arrays, then passes the main calculation to
    % the appropriate core calculation, which carries out the calculation
    % itself. The core layers calculation is common for both standard and
    % custom layers, with an additional core custom XY calculation.

    % Extract parameters from problemStruct
    [numberOfContrasts, geometry, contrastBackgroundIndices,...
     contrastResolutionIndices, backgroundParamValues, resolutionParamValues,...
     dataPresent, paramValues, resample, contrastBackgroundTypes,...
     contrastBackgroundActions, contrastResolutionTypes, contrastCustomFiles,...
     useImaginary, repeatLayers, data, dataLimits, simulationLimits,...
     contrastLayersIndices, layersDetails, customFiles, ~...
     ] = extractProblemParams(problemStruct);
    
    nParams = length(problemStruct.params);
    calcSld = controls.calcSLD;
    parallel = controls.parallel;
    numSimulationPoints = controls.numSimulationPoints;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;

    % Find the actual values from the indices given in each contrast
    scalefactors = problemStruct.scalefactors(problemStruct.contrastScalefactors)';
    bulkIns = problemStruct.bulkIns(problemStruct.contrastBulkIns)';
    bulkOuts = problemStruct.bulkOuts(problemStruct.contrastBulkOuts)';

    % qzshifts are not included as a parameter in RAT,
    % so we set up dummy values for the reflectivity calculation
    qzshifts = zeros(problemStruct.numberOfContrasts,1);
    
    % Allocate the memory for the output arrays before the main loop
    subRoughs = zeros(numberOfContrasts,1);
    chis = zeros(numberOfContrasts,1);
    
    reflectivity = cell(numberOfContrasts,1);  
    simulation = cell(numberOfContrasts,1);
    shiftedData = cell(numberOfContrasts,1);
    backgrounds = cell(numberOfContrasts,1);
    resolutions = cell(numberOfContrasts,1);
    sldProfiles = cell(numberOfContrasts,1);
    layers = cell(numberOfContrasts,1);
    resampledLayers = cell(numberOfContrasts,1);

    contrastLayers = cell(numberOfContrasts,1);
    contrastSlds = cell(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        shiftedData{i} = zeros(1,3);
        backgrounds{i} = zeros(1,3);
        resolutions{i} = zeros(1,2);
        contrastLayers{i} = zeros(1,6);
        contrastSlds{i} = zeros(1,3);
    end

%% Obtain model specific parameters

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
                    contrastLayersIndices{i}, layerValues);
    
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
            [contrastSlds,subRoughs] = normalTF.processCustomFunction(...
                bulkIns,bulkOuts,contrastCustomFiles,numberOfContrasts,...
                numberOfOutputColumns,customFiles,paramValues,useImaginary);

        otherwise
            
            coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', problemStruct.modelType);

    end

%% Run the core calculation for each contrast
    
    if strcmpi(problemStruct.modelType, coderEnums.modelTypes.CustomXY)

        if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
        
            parfor i = 1:numberOfContrasts

                [backgrounds{i},resolutions{i},shiftedData{i},...
                 simulationXData,dataIndices...
                 ] = setupCoreReflectivityCalculation(...
                 contrastBackgroundIndices{i},contrastResolutionIndices{i},...
                 backgroundParamValues,resolutionParamValues, ...
                 contrastBackgroundTypes{i},contrastResolutionTypes{i},...
                 customFiles,qzshifts(i),scalefactors(i),dataPresent(i),...
                 data{i},dataLimits{i},simulationLimits{i},numSimulationPoints);
        
                [reflectivity{i},simulation{i},shiftedData{i},...
                 sldProfiles{i},layers{i},resampledLayers{i},chis(i)...
                 ] = coreCustomXYCalculation(bulkIns(i),bulkOuts(i),...
                 shiftedData{i},simulationXData,dataIndices,...
                 backgrounds{i},resolutions{i},contrastBackgroundActions{i},...
                 parallel,resampleMinAngle,resampleNPoints,subRoughs(i),contrastSlds{i},nParams);

            end
            
        else
        
            for i = 1:numberOfContrasts

                [backgrounds{i},resolutions{i},shiftedData{i},...
                 simulationXData,dataIndices...
                 ] = setupCoreReflectivityCalculation(...
                 contrastBackgroundIndices{i},contrastResolutionIndices{i},...
                 backgroundParamValues,resolutionParamValues,...
                 contrastBackgroundTypes{i},contrastResolutionTypes{i},...
                 customFiles,qzshifts(i),scalefactors(i),dataPresent(i),...
                 data{i},dataLimits{i},simulationLimits{i},numSimulationPoints);

                [reflectivity{i},simulation{i},shiftedData{i},...
                 sldProfiles{i},layers{i},resampledLayers{i},chis(i)...
                 ] = coreCustomXYCalculation(bulkIns(i),bulkOuts(i),...
                 shiftedData{i},simulationXData,dataIndices,...
                 backgrounds{i},resolutions{i},contrastBackgroundActions{i},...
                 parallel,resampleMinAngle,resampleNPoints,subRoughs(i),contrastSlds{i},nParams);
   
            end
        end

    else
    
        if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
        
            parfor i = 1:numberOfContrasts
        
                [backgrounds{i},resolutions{i},shiftedData{i},...
                 simulationXData,dataIndices...
                 ] = setupCoreReflectivityCalculation(...
                 contrastBackgroundIndices{i},contrastResolutionIndices{i},...
                 backgroundParamValues,resolutionParamValues,...
                 contrastBackgroundTypes{i},contrastResolutionTypes{i},...
                 customFiles,qzshifts(i),scalefactors(i),dataPresent(i),...
                 data{i},dataLimits{i},simulationLimits{i},numSimulationPoints);
                
                [reflectivity{i},simulation{i},shiftedData{i},...
                 sldProfiles{i},layers{i},resampledLayers{i},chis(i)...
                 ] = coreLayersCalculation(contrastLayers{i},...
                 subRoughs(i),geometry,bulkIns(i),bulkOuts(i),resample(i),...
                 calcSld,shiftedData{i},simulationXData,dataIndices,...
                 repeatLayers(i),backgrounds{i},resolutions{i},...
                 contrastBackgroundActions{i},parallel,...
                 resampleMinAngle,resampleNPoints,nParams);

            end
            
        else
        
            for i = 1:numberOfContrasts
                
                [backgrounds{i},resolutions{i},shiftedData{i},...
                 simulationXData,dataIndices...
                 ] = setupCoreReflectivityCalculation(...
                 contrastBackgroundIndices{i},contrastResolutionIndices{i},...
                 backgroundParamValues,resolutionParamValues,...
                 contrastBackgroundTypes{i},contrastResolutionTypes{i},...
                 customFiles,qzshifts(i),scalefactors(i),dataPresent(i),...
                 data{i},dataLimits{i},simulationLimits{i},numSimulationPoints);
                
                [reflectivity{i},simulation{i},shiftedData{i},...
                 sldProfiles{i},layers{i},resampledLayers{i},chis(i)...
                 ] = coreLayersCalculation(contrastLayers{i},...
                 subRoughs(i),geometry,bulkIns(i),bulkOuts(i),resample(i),...
                 calcSld,shiftedData{i},simulationXData,dataIndices,...
                 repeatLayers(i),backgrounds{i},resolutions{i},...
                 contrastBackgroundActions{i},parallel,...
                 resampleMinAngle,resampleNPoints,nParams);

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
