
function [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
    Simulation,shifted_data,layerSlds,domainSldProfiles,allLayers,...
    allRoughs] = domainsTFStandardLayersParallelPoints(problemDef,problemDefCells,...
    problemDefLimits,controls)
% Single theraded version of the Standard Layers calculation 
% This is the main reflectivity calculation of the standard layers
% calculation type. It extracts the required paramters for the contrasts
% from the input arrays, then passes the main calculation to
% 'standardLayersCore', which carries out the calculation iteslf. 
% The core calculation is common for both standard and custom layers.


% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,~,...
 layersDetails,~] = parseCells(problemDefCells);

% Additionally extract the additional domain layers details
domainContrastLayers = problemDefCells{19};

% Extract individual parameters from problemDef struct
[numberOfContrasts, geometry, cBacks, cShifts, cScales, cNbas, cNbss,...
cRes, backs, shifts, sf, nba, nbs, res, dataPresent, nParams, params,...
numberOfLayers, resample, backsType, ~] =  extractProblemParams(problemDef);

calcSld = controls.calcSld;   
useImaginary = problemDef.useImaginary;
allDomainRatios = problemDef.domainRatio;
contrastDomainRatios = problemDef.contrastDomainRatios;

domainRatio = 1;    % Default for compile.

% Allocate the memory for the output arrays before the main loop
backgs = zeros(numberOfContrasts,1);
qshifts = zeros(numberOfContrasts,1);
sfs = zeros(numberOfContrasts,1);
nbas = zeros(numberOfContrasts,1);
nbss = zeros(numberOfContrasts,1);
resols = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);
outSsubs = zeros(numberOfContrasts,1);
chis =  zeros(numberOfContrasts,1);
layerSlds = cell(numberOfContrasts,2);
domainSldProfiles = cell(numberOfContrasts,2);
shifted_data = cell(numberOfContrasts,1);

reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end

Simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    Simulation{i} = [1 1 ; 1 1];
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

% Loop over all the contrasts
for i = 1:numberOfContrasts

    % Get the domain ratio for theis contrast
    thisContrastDR = contrastDomainRatios(i);
    if isempty(thisContrastDR)
        thisContrastDR = 1;
    end
    domainRatio = allDomainRatios(thisContrastDR);

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [thisBackground,thisQshift,thisSf,thisNba,thisNbs,thisResol] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);
    
    % Also need to determine which layers from the overall layers list
    % are required for this contrast, and put them in the correct order 
    % according to geometry. We run it twice, once for each domain...
    thisContrastLayers1 = allocateLayersForContrast(domainContrastLayers{1},outParameterisedLayers,useImaginary);
    thisContrastLayers2 = allocateLayersForContrast(domainContrastLayers{2},outParameterisedLayers,useImaginary);
    
    % For the other parameters, we extract the correct ones from the input
    % arrays
    thisRough = params(1);      % Substrate roughness is always first parameter for standard layers
    thisRepeatLayers = repeatLayers{i};
    thisResample = resample(i);
    thisCalcSld = calcSld;
    thisData = allData{i};
    thisDataPresent = dataPresent(i);
    thisDataLimits = dataLimits{i};
    thisSimLimits = simLimits{i};
    thisBacksType = backsType(i);
    
    % Now call the core standardTF_stanlay reflectivity calculation
    % In this case we are single cored, so we do not parallelise over
    % points
    parallelPoints = 'points';
    
    % Call the core layers calculation - need to do this once for each
    % domain
    [sldProfile1,reflect1,Simul1,shifted_dat,layerSld1,resamLayers1,~,thisSsubs]= standardTFLayersCore(thisContrastLayers1, thisRough, ...
    geometry, thisNba, thisNbs, thisResample, thisCalcSld, thisSf, thisQshift,...
    thisDataPresent, thisData, thisDataLimits, thisSimLimits, thisRepeatLayers,...
    thisBackground,thisResol,thisBacksType,nParams,parallelPoints,resamPars,useImaginary);

    [sldProfile2,reflect2,Simul2,~,layerSld2,resamLayers2,~,~] = standardTFLayersCore(thisContrastLayers2, thisRough, ...
    geometry, thisNba, thisNbs, thisResample, thisCalcSld, thisSf, thisQshift,...
    thisDataPresent, thisData, thisDataLimits, thisSimLimits, thisRepeatLayers,...
    thisBackground,thisResol,thisBacksType,nParams,parallelPoints,resamPars,useImaginary);

    % Calculate the average reflectivities....
    [totReflect,totSimul] = averageReflectivity(reflect1,reflect2,Simul1,Simul2,domainRatio);

    % Get an overall chi-squared for the new averaged curve..
    thisChiSquared = chiSquared(shifted_dat,totReflect,length(params));

    % Store returned values for this contrast in the output arrays.
    % As well as the calculated profiles, we also store a record of 
    % the other values (background, scalefactors etc) for each contrast
    % for future use.
    outSsubs(i) = thisSsubs;
    tempSldProfiles{i} = {sldProfile1, sldProfile2};
    reflectivity{i} = totReflect;
    Simulation{i} = totSimul;
    shifted_data{i} = shifted_dat;
    tempLayerSlds{i} = {layerSld1, layerSld2};
    tempAllLayers{i} = {resamLayers1, resamLayers2};
    
    chis(i) = thisChiSquared;
    backgs(i) = thisBackground;
    qshifts(i) = thisQshift;
    sfs(i) = thisSf;
    nbas(i) = thisNba;
    nbss(i) = thisNbs;
    resols(i) = thisResol;
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


