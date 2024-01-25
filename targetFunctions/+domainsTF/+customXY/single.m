function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
    simulation,shiftedData,layerSlds,domainSldProfiles,allLayers,...
    allRoughs] = single(problemDef,problemDefCells,controls)


% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 ~,~,...        % Layers details N/A
 customFiles] = parseCells(problemDefCells);

% Extract individual parameters from problemDef struct
[numberOfContrasts, ~, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParam, qzshift, scalefactor, bulkIn, bulkOut, resolutionParam, dataPresent, nParams, params,...
~, ~, contrastBackgroundsType, cCustFiles] =  extractProblemParams(problemDef);      
            
%Pre-Allocation...
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

for i = 1:numberOfContrasts
    domainSldProfiles{i,1} = [1 1 ; 1 1];
    domainSldProfiles{i,2} = [1 1 ; 1 1];
end

tempSldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    tempSldProfiles{i} = {[1 1 ; 1 1],[1 1 ; 1 1]};
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
useImaginary = problemDef.useImaginary;
allDomainRatios = problemDef.domainRatio;
contrastDomainRatios = problemDef.contrastDomainRatios;

domainRatio = 1;    % Default for compile.

domainSldProfiles = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainSldProfiles{i,1} = [1 1 ; 1 1];
    domainSldProfiles{i,2} = [1 1 ; 1 1];
end
[domainSldProfiles,allRoughs] = domainsTF.customXY.processCustomFunction(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backgroundParam, ...
    qzshift,scalefactor,bulkIn,bulkOut,resolutionParam,cCustFiles,numberOfContrasts,customFiles,params);

for i = 1:numberOfContrasts
    outSsubs(i) = allRoughs(i);
    [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);

    % Get the domain ratio for this contrast
    thisContrastDR = contrastDomainRatios(i);
    if isempty(thisContrastDR)
        thisContrastDR = 1;
    end
    domainRatio = allDomainRatios(thisContrastDR);

    % Resample the sld profiles
    thisSld1 = domainSldProfiles{i,1};
    thisSld2 = domainSldProfiles{i,2};
    if ~useImaginary
        layerSld1 = resampleLayers(thisSld1,resamPars);
        layerSld2 = resampleLayers(thisSld2,resamPars);
    else
        reSLD1 = thisSld1(:,1:2);
        imSLD1 = [thisSld1(:,1),thisSld1(:,3)];

        reSLD2 = thisSld2(:,1:2);
        imSLD2 = [thisSld2(:,1),thisSld2(:,3)];

        layerSld1 = resampleLayersReIm(reSLD1,imSLD1,resamPars);
        layerSld2 = resampleLayersReIm(reSLD2,imSLD2,resamPars);
    end
    
    tempLayerSlds{i} = {layerSld1, layerSld2};
    tempAllLayers{i} = {layerSld1, layerSld2};
    tempSldProfiles{i} = {thisSld1, thisSld2};

    shiftedDat =  shiftData(scalefactors(i),qzshifts(i),dataPresent(i),allData{i},dataLimits{i},simLimits{i});
    shiftedData{i} = shiftedDat;
    
    reflectivityType = 'standardAbeles';
    [reflect1,simul1] = callReflectivity(bulkIns(i),bulkOuts(i),simLimits{i},repeatLayers{i},shiftedDat,layerSld1,allRoughs(i),resolutionParams(i),'single',reflectivityType,useImaginary);
    [reflect2,simul2] = callReflectivity(bulkIns(i),bulkOuts(i),simLimits{i},repeatLayers{i},shiftedDat,layerSld2,allRoughs(i),resolutionParams(i),'single',reflectivityType,useImaginary);

    [reflect1,simul1,shiftedDat] = applyBackgroundCorrection(reflect1,simul1,shiftedDat,backgroundParams(i),contrastBackgroundsType(i));
    [reflect2,simul2,shiftedDat] = applyBackgroundCorrection(reflect2,simul2,shiftedDat,backgroundParams(i),contrastBackgroundsType(i));

     % Calculate the average reflectivities....
    [totReflect,totSimul] = domainsTF.averageReflectivity(reflect1,reflect2,simul1,simul2,domainRatio);
    
    reflectivity{i} = totReflect;
    simulation{i} = totSimul;
    
    if dataPresent(i)
        chis(i) = chiSquared(shiftedDat,totReflect,nParams);
    else
        chis(i) = 0;
    end
end

for i = 1:numberOfContrasts
    theseDomainSLDs = tempSldProfiles{i};
    domainSldProfiles{i,1} = theseDomainSLDs{1};
    domainSldProfiles{i,2} = theseDomainSLDs{2};

    theseAllLayers = tempAllLayers{i};
    allLayers{i,1} = theseAllLayers{1};
    allLayers{i,2} = theseAllLayers{2};

    theseLayerSlds = tempLayerSlds{i};
    layerSlds{i,1} = theseLayerSlds{1};
    layerSlds{i,2} = theseLayerSlds{2};
end
end
