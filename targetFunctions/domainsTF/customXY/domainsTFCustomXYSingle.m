function [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
    Simulation,shifted_data,layerSlds,domainSldProfiles,allLayers,...
    allRoughs] = domainsTFCustomXYSingle(problemDef,problemDefCells,...
    problemDefLimits,controls)


% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 ~,~,...        % Layers details N/A
 customFiles] = parseCells(problemDefCells);

% Extract individual parameters from problemDef struct
[numberOfContrasts, ~, cBacks, cShifts, cScales, cNbas, cNbss,...
cRes, backs, shifts, sf, nba, nbs, res, dataPresent, nParams, params,...
~, ~, backsType, cCustFiles] =  extractProblemParams(problemDef);      
            
%Pre-Allocation...
backgs = zeros(numberOfContrasts,1);
qshifts = zeros(numberOfContrasts,1);
sfs = zeros(numberOfContrasts,1);
nbas = zeros(numberOfContrasts,1);
nbss = zeros(numberOfContrasts,1);
resols = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);
outSsubs = zeros(numberOfContrasts,1);
chis =  zeros(numberOfContrasts,1);
allLayers = cell(numberOfContrasts,2); 
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
[domainSldProfiles,allRoughs] = customModelClass.processCustomXYDomains(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                                    shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params);

for i = 1:numberOfContrasts
    outSsubs(i) = allRoughs(i);
    [backgs(i),qshifts(i),sfs(i),nbas(i),nbss(i),resols(i)] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

    % Get the domain ratio for this contrast
    thisContrastDR = contrastDomainRatios(i);
    if isempty(thisContrastDR)
        thisContrastDR = 1;
    end
    domainRatio = allDomainRatios(thisContrastDR);

    % Resample the sld profiles
    thisSld1 = domainSldProfiles{1};
    thisSld2 = domainSldProfiles{2};
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

    shifted_dat =  shiftData(sfs(i),qshifts(i),dataPresent(i),allData{i},dataLimits{i},simLimits{i});
    shifted_data{i} = shifted_dat;
    
    reflectivityType = 'standardAbeles';
    [reflect1,Simul1] = callReflectivity(nbas(i),nbss(i),simLimits{i},repeatLayers{i},shifted_dat,layerSld1,allRoughs(i),resols(i),'single',reflectivityType,useImaginary);
    [reflect2,Simul2] = callReflectivity(nbas(i),nbss(i),simLimits{i},repeatLayers{i},shifted_dat,layerSld2,allRoughs(i),resols(i),'single',reflectivityType,useImaginary);

    [reflect1,Simul1,shifted_dat] = applyBackgroundCorrection(reflect1,Simul1,shifted_dat,backgs(i),backsType(i));
    [reflect2,Simul2,shifted_dat] = applyBackgroundCorrection(reflect2,Simul2,shifted_dat,backgs(i),backsType(i));

     % Calculate the average reflectivities....
    [totReflect,totSimul] = averageReflectivity(reflect1,reflect2,Simul1,Simul2,domainRatio);
    
    reflectivity{i} = totReflect;
    Simulation{i} = totSimul;
    
    if dataPresent(i)
        chis(i) = chiSquared(shifted_dat,totReflect,nParams);
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
