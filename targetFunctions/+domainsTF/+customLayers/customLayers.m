function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,...
    domainSldProfiles,allLayers,allRoughs] = customLayers(problemStruct,problemCells,controls)
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
[numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParam, qzshift, scalefactor, bulkIn, bulkOut, resolutionParam, dataPresent, nParams, params,...
~, resample, contrastBackgroundsType, cCustFiles] = extractProblemParams(problemStruct);

calcSld = controls.calcSldDuringFit;
parallel = controls.parallel;
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
layerSlds = cell(numberOfContrasts,2);
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

allLayers = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    allLayers{i,1} = [1 1 1; 1 1 1];
    allLayers{i,2} = [1 1 1; 1 1 1];
end

tempSldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    tempSldProfiles{i} = {[1 1 ; 1 1],[1 1 ; 1 1]};
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

tempAllLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    tempAllLayers{i} = {[1 1 1;1 1 1],[1 1 1;1 1 1]};
end

tempLayerSlds = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    tempLayerSlds{i} = {[1 1 1;1 1 1],[1 1 1;1 1 1]};
end

% Resampling parameters
resamPars = controls.resamPars;

% Process the custom models....
[calcAllLayers,allRoughs] = domainsTF.customLayers.processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkIn,bulkOut,cCustFiles,numberOfContrasts,customFiles,params,useImaginary);

for i = 1:size(calcAllLayers,1)
    calcAllLayers1{i} = calcAllLayers{i,1};
    calcAllLayers2{i} = calcAllLayers{i,2};
end

if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)

    % Parallel over all contrasts
    parfor i = 1:numberOfContrasts
    
        % Get the domain ratio for this contrast
        thisContrastDR = contrastDomainRatios(i);
        if isempty(thisContrastDR)
            thisContrastDR = 1;
        end
        domainRatio = allDomainRatios(thisContrastDR);
    
        % Extract the relevant parameter values for this contrast
        % from the input arrays.
        % First need to decide which values of the backgrounds, scalefactors
        % data shifts and bulk contrasts are associated with this contrast
        [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
           
        % Call the reflectivity calculation for each domain
        % Domain 1
        [sldProfile1,reflect1,simul1,shiftedDat,layerSld1,resamLayers1,~,outSsubs(i)] = ...
        nonPolarisedTF.coreLayersCalculation...
        (calcAllLayers1{i}, allRoughs(i), ...
        geometry, bulkIns(i), bulkOuts(i), resample(i), calcSld, scalefactors(i), qzshifts(i),...
        dataPresent(i), allData{i}, dataLimits{i}, simLimits{i}, repeatLayers{i},...
        backgroundParams(i),resolutionParams(i),contrastBackgroundsType(i),nParams,parallel,resamPars,useImaginary);
    
        % Domain 2
        [sldProfile2,reflect2,simul2,~,layerSld2,resamLayers2,~,~] = ...
        nonPolarisedTF.coreLayersCalculation...
        (calcAllLayers2{i}, allRoughs(i), ...
        geometry, bulkIns(i), bulkOuts(i), resample(i), calcSld, scalefactors(i), qzshifts(i),...
        dataPresent(i), allData{i}, dataLimits{i}, simLimits{i}, repeatLayers{i},...
        backgroundParams(i),resolutionParams(i),contrastBackgroundsType(i),nParams,parallel,resamPars,useImaginary);
    
        % Calculate the average reflectivities....
        [reflectivity{i},simulation{i}] = domainsTF.averageReflectivity(reflect1,reflect2,simul1,simul2,domainRatio);
    
        % Get an overall chi-squared for the new averaged curve..
        chis(i) = chiSquared(shiftedDat,reflectivity{i},length(params));
       
        % Store returned values for this contrast in the output arrays.
        tempSldProfiles{i} = {sldProfile1, sldProfile2};
        tempLayerSlds{i} = {layerSld1, layerSld2};
        tempAllLayers{i} = {resamLayers1, resamLayers2};

        shiftedData{i} = shiftedDat;

    end

else

    for i = 1:numberOfContrasts
    
        % Get the domain ratio for this contrast
        thisContrastDR = contrastDomainRatios(i);
        if isempty(thisContrastDR)
            thisContrastDR = 1;
        end
        domainRatio = allDomainRatios(thisContrastDR);
    
        % Extract the relevant parameter values for this contrast
        % from the input arrays.
        % First need to decide which values of the backgrounds, scalefactors
        % data shifts and bulk contrasts are associated with this contrast
        [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);

        % For the other parameters, we extract the correct ones from the input
        % arrays      
        thisRepeatLayers = repeatLayers{i};
        thisResample = resample(i);
        thisData = allData{i};
        thisDataPresent = dataPresent(i);
        thisDataLimits = dataLimits{i};
        thisSimLimits = simLimits{i};
        thisBacksType = contrastBackgroundsType(i);
    
        % Call the reflectivity calculation for each domain
        % Domain 1
        [sldProfile1,reflect1,simul1,shiftedDat,layerSld1,resamLayers1,~,outSsubs(i)] = ...
        nonPolarisedTF.coreLayersCalculation...
        (calcAllLayers1{i}, allRoughs(i), ...
        geometry, bulkIns(i), bulkOuts(i), thisResample, calcSld, scalefactors(i), qzshifts(i),...
        thisDataPresent, thisData, thisDataLimits, thisSimLimits, thisRepeatLayers,...
        backgroundParams(i),resolutionParams(i),thisBacksType,nParams,parallel,resamPars,useImaginary);
    
        % Domain 2
        [sldProfile2,reflect2,simul2,~,layerSld2,resamLayers2,~,~] = ...
        nonPolarisedTF.coreLayersCalculation...
        (calcAllLayers2{i}, allRoughs(i), ...
        geometry, bulkIns(i), bulkOuts(i), thisResample, calcSld, scalefactors(i), qzshifts(i),...
        thisDataPresent, thisData, thisDataLimits, thisSimLimits, thisRepeatLayers,...
        backgroundParams(i),resolutionParams(i),thisBacksType,nParams,parallel,resamPars,useImaginary);
    
        % Calculate the average reflectivities....
        [reflectivity{i},simulation{i}] = domainsTF.averageReflectivity(reflect1,reflect2,simul1,simul2,domainRatio);
    
        % Get an overall chi-squared for the new averaged curve..
        chis(i) = chiSquared(shiftedDat,reflectivity{i},length(params));
       
        % Store returned values for this contrast in the output arrays.
        tempSldProfiles{i} = {sldProfile1, sldProfile2};
        tempLayerSlds{i} = {layerSld1, layerSld2};
        tempAllLayers{i} = {resamLayers1, resamLayers2};

        shiftedData{i} = shiftedDat;

    end

end

for i = 1:numberOfContrasts

    contrastDomainSLDProfiles = tempSldProfiles{i};
    domainSldProfiles{i,1} = contrastDomainSLDProfiles{1};
    domainSldProfiles{i,2} = contrastDomainSLDProfiles{2};

    contrastLayersSlds = tempLayerSlds{i};
    layerSlds{i,1} = contrastLayersSlds{1};
    layerSlds{i,2} = contrastLayersSlds{2};

    contrastAllLayers = tempAllLayers{i};
    allLayers{i,1} = contrastAllLayers{1};
    allLayers{i,2} = contrastAllLayers{2};

end

end
