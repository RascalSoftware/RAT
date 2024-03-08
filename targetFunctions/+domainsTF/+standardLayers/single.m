function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,...
    domainSldProfiles,allLayers,allRoughs] = single(problemStruct,problemCells,controls)
% Single threaded version of the Standard Layers calculation 
% This is the main reflectivity calculation of the standard layers
% calculation type. It extracts the required parameters for the contrasts
% from the input arrays, then passes the main calculation to
% 'standardLayersCore', which carries out the calculation itself. 
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
[numberOfContrasts, geometry, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParam, qzshift, scalefactor, bulkIn, bulkOut, resolutionParam, dataPresent, nParams, params,...
~, resample, contrastBackgroundsType, ~] =  extractProblemParams(problemStruct);

calcSld = controls.calcSldDuringFit;   
useImaginary = problemStruct.useImaginary;
allDomainRatios = problemStruct.domainRatio;
contrastDomainRatios = problemStruct.contrastDomainRatios;

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

tempAllLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    tempAllLayers{i} = {[1 1 1;1 1 1],[1 1 1;1 1 1]};
end

tempLayerSlds = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    tempLayerSlds{i} = {[1 1 1;1 1 1],[1 1 1;1 1 1]};
end
% end memory allocation.

% First we need to allocate the absolute values of the input
% parameters to all the layers in the layers list. This only needs
% to be done once, and so is done outside the contrasts loop
outParameterisedLayers = allocateParamsToLayers(params, layersDetails);

% Resample params if requiired
resamPars = controls.resamPars;

% Substrate roughness is always first parameter for standard layers
thisRough = params(1);

% Loop over all the contrasts
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
    [thisBackground,thisQzshift,thisScalefactor,thisBulkIn,thisBulkOut,thisResol] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
    
    % Also need to determine which layers from the overall layers list
    % are required for this contrast, and put them in the correct order 
    % according to geometry. We run it twice, once for each domain...
    thisContrastLayers1 = allocateLayersForContrast(domainContrastLayers{1},outParameterisedLayers,useImaginary);
    thisContrastLayers2 = allocateLayersForContrast(domainContrastLayers{2},outParameterisedLayers,useImaginary);
    
    % For the other parameters, we extract the correct ones from the input
    % arrays
    thisRepeatLayers = repeatLayers{i};
    thisResample = resample(i);
    thisData = allData{i};
    thisDataPresent = dataPresent(i);
    thisDataLimits = dataLimits{i};
    thisSimLimits = simLimits{i};
    thisBacksType = contrastBackgroundsType(i);
    
    % Now call the core layers reflectivity calculation
    % In this case we are single cored, so we do not parallelise over
    % points
    parallelPoints = coderEnums.parallelOptions.Single;
    
    % Call the core layers calculation - need to do this once for each
    % domain
    [sldProfile1,reflect1,simul1,shiftedDat,layerSld1,resamLayers1,~,thisSsubs]= nonPolarisedTF.coreLayersCalculation(thisContrastLayers1, thisRough, ...
    geometry, thisBulkIn, thisBulkOut, thisResample, calcSld, thisScalefactor, thisQzshift,...
    thisDataPresent, thisData, thisDataLimits, thisSimLimits, thisRepeatLayers,...
    thisBackground,thisResol,thisBacksType,nParams,controls.parallel,resamPars,useImaginary);

    [sldProfile2,reflect2,simul2,~,layerSld2,resamLayers2,~,~] = nonPolarisedTF.coreLayersCalculation(thisContrastLayers2, thisRough, ...
    geometry, thisBulkIn, thisBulkOut, thisResample, calcSld, thisScalefactor, thisQzshift,...
    thisDataPresent, thisData, thisDataLimits, thisSimLimits, thisRepeatLayers,...
    thisBackground,thisResol,thisBacksType,nParams,controls.parallel,resamPars,useImaginary);

    % Calculate the average reflectivities....
    [totReflect,totSimul] = domainsTF.averageReflectivity(reflect1,reflect2,simul1,simul2,domainRatio);

    % Get an overall chi-squared for the new averaged curve..
    thisChiSquared = chiSquared(shiftedDat,totReflect,length(params));

    % Store returned values for this contrast in the output arrays.
    % As well as the calculated profiles, we also store a record of 
    % the other values (background, scalefactors etc) for each contrast
    % for future use.
    outSsubs(i) = thisSsubs;
    tempSldProfiles{i} = {sldProfile1, sldProfile2};
    reflectivity{i} = totReflect;
    simulation{i} = totSimul;
    shiftedData{i} = shiftedDat;
    tempLayerSlds{i} = {layerSld1, layerSld2};
    tempAllLayers{i} = {resamLayers1, resamLayers2};
    
    chis(i) = thisChiSquared;
    backgroundParams(i) = thisBackground;
    qzshifts(i) = thisQzshift;
    scalefactors(i) = thisScalefactor;
    bulkIns(i) = thisBulkIn;
    bulkOuts(i) = thisBulkOut;
    resolutionParams(i) = thisResol;
    allRoughs(i) = thisRough;
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
