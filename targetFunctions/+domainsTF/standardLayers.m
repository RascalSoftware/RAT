function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,domainLayerSlds,...
    domainSldProfiles,domainAllLayers,allRoughs] = standardLayers(problemStruct,problemCells,controls)
    % This is the main reflectivity calculation of the standard layers
    % calculation type. It extracts the required parameters for the contrasts
    % from the input arrays, then passes the main calculation to
    % 'coreLayersCalculation', which carries out the calculation itself. 
    % The core calculation is common for both standard and custom layers.
    
    % Extract individual cell arrays
    [repeatLayers,...
     allData,...
     dataLimits,...
     simLimits,~,...
     layersDetails,~] = parseCells(problemCells);
    
    % Additionally extract the additional domain layers details
    domainContrastLayers = problemCells{19};
    
    % Extract individual parameters from problemStruct
    [numberOfContrasts, geometry, contrastBackgroundIndices, contrastQzshiftIndices, contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
    contrastResolutionIndices, contrastDomainRatioIndices, backgroundParamArray, qzshiftArray, scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray, domainRatioArray,...
    dataPresent, nParams, params, ~, resample, contrastBackgroundsType, ~, useImaginary] = extractProblemParams(problemStruct);
    
    calcSld = controls.calcSldDuringFit;
    parallel = controls.parallel;
    resamPars = controls.resamPars;
    
    domainRatio = 1;    % Default for compile.
    
    % Allocate the memory for the output arrays before the main loop
    backgroundParams = zeros(numberOfContrasts,1);
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    resolutionParams = zeros(numberOfContrasts,1);
    allRoughs = zeros(numberOfContrasts,1);
    outSsubs = zeros(numberOfContrasts,1);
    chis = zeros(numberOfContrasts,1);
    domainLayerSlds = cell(numberOfContrasts,2);
    domainSldProfiles = cell(numberOfContrasts,2);
    shiftedData = cell(numberOfContrasts,1);
    
    reflectivity = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        reflectivity{i} = [1 1 ; 1 1];
    end
    
    simulation = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        simulation{i} = [1 1 ; 1 1];
    end
    
    domainAllLayers = cell(numberOfContrasts,2);
    for i = 1:numberOfContrasts
        domainAllLayers{i,1} = [1 1 1; 1 1 1];
        domainAllLayers{i,2} = [1 1 1; 1 1 1];
    end

    domainContrastLayers1 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        domainContrastLayers1{i} = [1 ; 1];
    end
    
    domainContrastLayers2 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        domainContrastLayers2{i} = [1 ; 1];
    end
    
    sldProfiles = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        sldProfiles{i} = {[1 1 ; 1 1],[1 1 ; 1 1]};
    end
    
    allLayers = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        allLayers{i} = {[1 1 1;1 1 1],[1 1 1;1 1 1]};
    end
    
    layerSlds = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        layerSlds{i} = {[1 1 1;1 1 1],[1 1 1;1 1 1]};
    end
    % end memory allocation.
    
    % First we need to allocate the absolute values of the input
    % parameters to all the layers in the layers list. This only needs
    % to be done once, and so is done outside the contrasts loop
    outParameterisedLayers = allocateParamsToLayers(params, layersDetails);
    
    % Substrate roughness is always first parameter for standard layers
    for i = 1:numberOfContrasts
        allRoughs(i) = params(1);
    end

    for i = 1:size(domainContrastLayers1,1)
        domainContrastLayers1{i} = domainContrastLayers{i,1};
        domainContrastLayers2{i} = domainContrastLayers{i,2};
    end

    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        % Loop over all the contrasts
        parfor i = 1:numberOfContrasts
        
            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),reflectivity{i},simulation{i},...
             shiftedData{i},layerSlds{i},sldProfiles{i},allLayers{i},chis(i),...
             outSsubs(i)] = contrastCalculation(contrastBackgroundIndices(i),...
            contrastQzshiftIndices(i),contrastScalefactorIndices(i),contrastBulkInIndices(i),...
            contrastBulkOutIndices(i),contrastResolutionIndices(i),contrastDomainRatioIndices(i),...
            backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
            bulkOutArray,resolutionParamArray,domainRatioArray,dataPresent(i),allData{i},...
            dataLimits{i},simLimits{i},repeatLayers{i},contrastBackgroundsType(i),...
            nParams,parallel,resamPars,useImaginary,resample(i),geometry,...
            allRoughs(i),calcSld,domainContrastLayers1{i},domainContrastLayers2{i},...
            outParameterisedLayers);
    
        end
    
    else
    
        % Loop over all the contrasts
        for i = 1:numberOfContrasts

            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),reflectivity{i},simulation{i},...
             shiftedData{i},layerSlds{i},sldProfiles{i},allLayers{i},chis(i),...
             outSsubs(i)] = contrastCalculation(contrastBackgroundIndices(i),...
            contrastQzshiftIndices(i),contrastScalefactorIndices(i),contrastBulkInIndices(i),...
            contrastBulkOutIndices(i),contrastResolutionIndices(i),contrastDomainRatioIndices(i),...
            backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
            bulkOutArray,resolutionParamArray,domainRatioArray,dataPresent(i),allData{i},...
            dataLimits{i},simLimits{i},repeatLayers{i},contrastBackgroundsType(i),...
            nParams,parallel,resamPars,useImaginary,resample(i),geometry,...
            allRoughs(i),calcSld,domainContrastLayers1{i},domainContrastLayers2{i},...
            outParameterisedLayers);
    
        end
    
    end
    
    for i = 1:numberOfContrasts
    
        contrastSldProfiles = sldProfiles{i};
        domainSldProfiles{i,1} = contrastSldProfiles{1};
        domainSldProfiles{i,2} = contrastSldProfiles{2};
    
        contrastLayerSlds = layerSlds{i};
        domainLayerSlds{i,1} = contrastLayerSlds{1};
        domainLayerSlds{i,2} = contrastLayerSlds{2};
    
        contrastAllLayers = allLayers{i};
        domainAllLayers{i,1} = contrastAllLayers{1};
        domainAllLayers{i,2} = contrastAllLayers{2};
    
    end

end


function [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,...
    bulkOutValue,resolutionParamValue,reflectivity,simulation,shiftedData,...
    layerSld,sldProfile,allLayer,chi,ssub] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    domainRatioIndex,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,domainRatios,...
    dataPresent,allData,dataLimits,simLimits,repeatLayers,contrastBackgroundsType,...
    nParams,parallel,resamPars,useImaginary,resample,geometry,roughness,...
    calcSld,domainContrastLayers1,domainContrastLayers2,outParameterisedLayers)

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

    % Also need to determine which layers from the overall layers list
    % are required for this contrast, and put them in the correct order 
    % according to geometry. We run it twice, once for each domain...
    thisContrastLayers1 = allocateLayersForContrast(domainContrastLayers1,outParameterisedLayers,useImaginary);
    thisContrastLayers2 = allocateLayersForContrast(domainContrastLayers2,outParameterisedLayers,useImaginary);
       
    % Call the core layers calculation - need to do this once for each
    % domain
    [sldProfile1,reflect1,simul1,shiftedData,layerSld1,resamLayers1,~,ssub] = nonPolarisedTF.coreLayersCalculation(thisContrastLayers1,roughness,...
     geometry,bulkInValue,bulkOutValue,resample,calcSld,scalefactorValue,qzshiftValue,...
     dataPresent,allData,dataLimits,simLimits,repeatLayers,backgroundParamValue,...
     resolutionParamValue,contrastBackgroundsType,nParams,parallel,resamPars,useImaginary);

    [sldProfile2,reflect2,simul2,~,layerSld2,resamLayers2,~,~] = nonPolarisedTF.coreLayersCalculation(thisContrastLayers2,roughness,...
     geometry,bulkInValue,bulkOutValue,resample,calcSld,scalefactorValue,qzshiftValue,...
     dataPresent,allData,dataLimits,simLimits,repeatLayers,backgroundParamValue,...
     resolutionParamValue,contrastBackgroundsType,nParams,parallel,resamPars,useImaginary);
    
    % Calculate the average reflectivities....
    [reflectivity,simulation] = domainsTF.averageReflectivity(reflect1,reflect2,simul1,simul2,domainRatio);

    % Get an overall chi-squared for the new averaged curve..
    chi = chiSquared(shiftedData,reflectivity,nParams);

    % Store returned values for this contrast in the output arrays.
    sldProfile = {sldProfile1, sldProfile2};
    layerSld = {layerSld1, layerSld2};
    allLayer = {resamLayers1, resamLayers2};

end
