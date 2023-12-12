function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
    Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
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
layerSlds = cell(numberOfContrasts,1);
shifted_data = cell(numberOfContrasts,1);

reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end

Simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    Simulation{i} = [1 1 ; 1 1];
end

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 ; 1];
end

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i} = [1 ; 1];
end


% Resampling parameters
resamPars = controls.resamPars;
useImaginary = problemDef.useImaginary;

[sldProfiles,allRoughs] = nonPolarisedTF.customXY.processCustomFunction(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backgroundParam, ...
    qzshift,scalefactor,bulkIn,bulkOut,resolutionParam,cCustFiles,numberOfContrasts,customFiles,params);

for i = 1:numberOfContrasts
    [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);

    % Resample the layers
    thisSld = sldProfiles{i};
    if ~useImaginary
        layerSld = resampleLayers(thisSld,resamPars);
    else
        reSLD = thisSld(:,1:2);
        imSLD = [thisSld(:,1),thisSld(:,3)];
        layerSld = resampleLayersReIm(reSLD,imSLD,resamPars);
    end
    
    layerSlds{i} = layerSld;
    allLayers{i} = layerSld;

    shifted_dat =  shiftData(scalefactors(i),qzshifts(i),dataPresent(i),allData{i},dataLimits{i},simLimits{i});
    shifted_data{i} = shifted_dat;
    
    reflectivityType = 'standardAbeles';
    [reflect,Simul] = callReflectivity(bulkIns(i),bulkOuts(i),simLimits{i},repeatLayers{i},shifted_dat,layerSld,outSsubs(i),resolutionParams(i),'single',reflectivityType,useImaginary);
    
    [reflect,Simul,shifted_dat] = applyBackgroundCorrection(reflect,Simul,shifted_dat,backgroundParams(i),contrastBackgroundsType(i));
    
    reflectivity{i} = reflect;
    Simulation{i} = Simul;
    
    if dataPresent(i)
        chis(i) = chiSquared(shifted_dat,reflect,nParams);
    else
        chis(i) = 0;
    end
end
end
