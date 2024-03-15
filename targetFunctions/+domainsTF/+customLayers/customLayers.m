function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,domainLayerSlds,...
    domainSldProfiles,domainAllLayers,allRoughs] = customLayers(problemStruct,problemCells,controls)
    % The custom layers, domainsTF reflectivity calculation.
    % The function extracts the relevant parameters from the input arrays,
    % allocates these on a pre-contrast basis, then calls the 
    % 'coreLayersCalculation' (the core layers domainsTF calc is shared
    % between multiple calculation types).
    
    % Extract individual cell arrays
    [repeatLayers,...
     allData,...
     dataLimits,...
     simLimits,...
     ~,~,customFiles] = parseCells(problemCells);
    
    % Extract individual parameters from problemStruct
    [numberOfContrasts, geometry, contrastBackgroundIndices, contrastQzshiftIndices, contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
    contrastResolutionIndices, backgroundParamArray, qzshiftArray, scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray, dataPresent, nParams, params,...
    ~, resample, contrastBackgroundsType, cCustFiles] =  extractProblemParams(problemStruct);
    
    calcSld = controls.calcSldDuringFit;
    parallel = controls.parallel;
    resamPars = controls.resamPars;
    useImaginary = problemStruct.useImaginary;
    allDomainRatios = problemStruct.domainRatio;
    contrastDomainRatios = problemStruct.contrastDomainRatios;
    
    domainRatio = 1;    % Default for compile.
             
    % Pre-Allocation of output arrays...
    backgroundParams = zeros(numberOfContrasts,1);
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    resolutionParams = zeros(numberOfContrasts,1);
    allRoughs = zeros(numberOfContrasts,1);
    outSsubs = zeros(numberOfContrasts,1);
    chis =  zeros(numberOfContrasts,1);
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
    
    sldProfiles = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        sldProfiles{i} = {[1 1 ; 1 1],[1 1 ; 1 1]};
    end
    
    calcAllLayers = cell(numberOfContrasts,2);
    for i = 1:numberOfContrasts
        calcAllLayers{i,1} = [1 ; 1];
        calcAllLayers{i,2} = [1 ; 1];
    end
    
    calcAllLayers1 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        calcAllLayers1{i} = [1 ; 1];
    end
    
    calcAllLayers2 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        calcAllLayers2{i} = [1 ; 1];
    end
    
    allLayers = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        allLayers{i} = {[1 1 1;1 1 1],[1 1 1;1 1 1]};
    end
    
    layerSlds = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        layerSlds{i} = {[1 1 1;1 1 1],[1 1 1;1 1 1]};
    end
    
    % Process the custom models....
    [calcAllLayers,allRoughs] = domainsTF.customLayers.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params,useImaginary);
    
    for i = 1:size(calcAllLayers,1)
        calcAllLayers1{i} = calcAllLayers{i,1};
        calcAllLayers2{i} = calcAllLayers{i,2};
    end
    
    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        % Parallel over all contrasts
        parfor i = 1:numberOfContrasts
        
            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),reflectivity{i},simulation{i},...
             shiftedData{i},layerSlds{i},sldProfiles{i},allLayers{i},chis(i),...
             outSsubs(i)] = contrastCalculation(contrastBackgroundIndices(i),...
            contrastQzshiftIndices(i),contrastScalefactorIndices(i),contrastBulkInIndices(i),...
            contrastBulkOutIndices(i),contrastResolutionIndices(i),...
            backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
            bulkOutArray,resolutionParamArray,dataPresent(i),allData{i},...
            dataLimits{i},simLimits{i},repeatLayers{i},contrastBackgroundsType(i),...
            nParams,parallel,resamPars,useImaginary,resample(i),geometry,...
            allRoughs(i),calcSld,calcAllLayers1{i},calcAllLayers2{i},...
            contrastDomainRatios(i),allDomainRatios);
    
        end
    
    else
    
        for i = 1:numberOfContrasts
        
            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),reflectivity{i},simulation{i},...
             shiftedData{i},layerSlds{i},sldProfiles{i},allLayers{i},chis(i),...
             outSsubs(i)] = contrastCalculation(contrastBackgroundIndices(i),...
            contrastQzshiftIndices(i),contrastScalefactorIndices(i),contrastBulkInIndices(i),...
            contrastBulkOutIndices(i),contrastResolutionIndices(i),...
            backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
            bulkOutArray,resolutionParamArray,dataPresent(i),allData{i},...
            dataLimits{i},simLimits{i},repeatLayers{i},contrastBackgroundsType(i),...
            nParams,parallel,resamPars,useImaginary,resample(i),geometry,...
            allRoughs(i),calcSld,calcAllLayers1{i},calcAllLayers2{i},...
            contrastDomainRatios(i),allDomainRatios);
    
        end
    
    end
    
    for i = 1:numberOfContrasts
    
        contrastDomainSLDProfiles = sldProfiles{i};
        domainSldProfiles{i,1} = contrastDomainSLDProfiles{1};
        domainSldProfiles{i,2} = contrastDomainSLDProfiles{2};
    
        contrastLayersSlds = layerSlds{i};
        domainLayerSlds{i,1} = contrastLayersSlds{1};
        domainLayerSlds{i,2} = contrastLayersSlds{2};
    
        contrastAllLayers = allLayers{i};
        domainAllLayers{i,1} = contrastAllLayers{1};
        domainAllLayers{i,2} = contrastAllLayers{2};
    
    end

end


function [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,...
    bulkOutValue,resolutionParamValue,reflectivity,simulation,shiftedData,...
    layerSld,sldProfile,allLayer,chi,ssub] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,...
    dataPresent,allData,dataLimits,simLimits,repeatLayers,contrastBackgroundsType,...
    nParams,parallel,resamPars,useImaginary,resample,geometry,roughness,...
    calcSld,calcAllLayers1,calcAllLayers2,contrastDomainRatio,allDomainRatios)

    % Get the domain ratio for this contrast
    if isempty(contrastDomainRatio)
        contrastDomainRatio = 1;
    end
    domainRatio = allDomainRatios(contrastDomainRatio);

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue,...
     resolutionParamValue] = backSort(backgroundParamIndex,qzshiftIndex,...
     scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
     backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams);

    % Call the core layers calculation - need to do this once for each
    % domain
    [sldProfile1,reflect1,simul1,shiftedData,layerSld1,resamLayers1,~,ssub] = nonPolarisedTF.coreLayersCalculation(calcAllLayers1,roughness,...
     geometry,bulkInValue,bulkOutValue,resample,calcSld,scalefactorValue,qzshiftValue,...
     dataPresent,allData,dataLimits,simLimits,repeatLayers,backgroundParamValue,...
     resolutionParamValue,contrastBackgroundsType,nParams,parallel,resamPars,useImaginary);

    [sldProfile2,reflect2,simul2,~,layerSld2,resamLayers2,~,~] = nonPolarisedTF.coreLayersCalculation(calcAllLayers2,roughness,...
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
