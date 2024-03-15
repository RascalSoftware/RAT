function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,domainLayerSlds,...
    domainSldProfiles,domainAllLayers,allRoughs] = customXY(problemStruct,problemCells,controls)

    % Extract individual cell arrays
    [repeatLayers,...
     allData,...
     dataLimits,...
     simLimits,...
     ~,~,...        % Layers details N/A
     customFiles] = parseCells(problemCells);
    
    % Extract individual parameters from problemStruct
    [numberOfContrasts, ~, contrastBackgroundIndices, contrastQzshiftIndices, contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
    contrastResolutionIndices, contrastDomainRatioIndices, backgroundParamArray, qzshiftArray, scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray, domainRatioArray,...
    dataPresent, nParams, params, ~, ~, contrastBackgroundsType, cCustFiles, useImaginary] = extractProblemParams(problemStruct);

    parallel = controls.parallel;
    resamPars = controls.resamPars;

    %Pre-Allocation...
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
    
    domainSldProfiles = cell(numberOfContrasts,2);
    for i = 1:numberOfContrasts
        domainSldProfiles{i,1} = [1 ; 1];
        domainSldProfiles{i,2} = [1 ; 1];
    end
    
    inputSldProfiles1 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        inputSldProfiles1{i} = [1 ; 1];
    end
    
    inputSldProfiles2 = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        inputSldProfiles2{i} = [1 ; 1];
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
        
    domainRatio = 1;    % Default for compile.
    
    [inputSldProfiles,allRoughs] = domainsTF.customXY.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params);
    
    for i = 1:size(inputSldProfiles,1)
        inputSldProfiles1{i} = inputSldProfiles{i,1};
        inputSldProfiles2{i} = inputSldProfiles{i,2};
    end
    
    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        parfor i = 1:numberOfContrasts
    
            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),reflectivity{i},simulation{i},...
             shiftedData{i},layerSlds{i},sldProfiles{i},allLayers{i},...
             chis(i)] = contrastCalculation(contrastBackgroundIndices(i),...
            contrastQzshiftIndices(i),contrastScalefactorIndices(i),contrastBulkInIndices(i),...
            contrastBulkOutIndices(i),contrastResolutionIndices(i),contrastDomainRatioIndices(i),...
            backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray, ...
            bulkOutArray,resolutionParamArray,domainRatioArray,dataPresent(i),allData{i},...
            dataLimits{i},simLimits{i},repeatLayers{i},contrastBackgroundsType(i),...
            nParams,parallel,resamPars,useImaginary,allRoughs(i),inputSldProfiles1{i},...
            inputSldProfiles2{i},outSsubs(i));

        end
    
    else
        
        for i = 1:numberOfContrasts
            
            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),reflectivity{i},simulation{i},...
             shiftedData{i},layerSlds{i},sldProfiles{i},allLayers{i},...
             chis(i)] = contrastCalculation(contrastBackgroundIndices(i),...
            contrastQzshiftIndices(i),contrastScalefactorIndices(i),contrastBulkInIndices(i),...
            contrastBulkOutIndices(i),contrastResolutionIndices(i),contrastDomainRatioIndices(i),...
            backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray, ...
            bulkOutArray,resolutionParamArray,domainRatioArray,dataPresent(i),allData{i},...
            dataLimits{i},simLimits{i},repeatLayers{i},contrastBackgroundsType(i),...
            nParams,parallel,resamPars,useImaginary,allRoughs(i),inputSldProfiles1{i},...
            inputSldProfiles2{i},outSsubs(i));

        end
    
    end
    
    for i = 1:numberOfContrasts

        outSsubs(i) = allRoughs(i);
    
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
    layerSld,sldProfile,allLayer,chi] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,domainRatioIndex,...
    backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,domainRatios,...
    dataPresent,allData,dataLimits,simLimits,repeatLayers,contrastBackgroundsType,...
    nParams,parallel,resamPars,useImaginary,roughness,sldProfile1,sldProfile2,ssub)

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
        layerSld1 = resampleLayers(sldProfile1,resamPars);
        layerSld2 = resampleLayers(sldProfile2,resamPars);
    else
        reSLD1 = sldProfile1(:,1:2);
        imSLD1 = [sldProfile1(:,1),sldProfile1(:,3)];

        reSLD2 = sldProfile2(:,1:2);
        imSLD2 = [sldProfile2(:,1),sldProfile2(:,3)];

        layerSld1 = resampleLayersReIm(reSLD1,imSLD1,resamPars);
        layerSld2 = resampleLayersReIm(reSLD2,imSLD2,resamPars);
    end

    layerSld = {layerSld1, layerSld2};
    allLayer = {layerSld1, layerSld2};
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
