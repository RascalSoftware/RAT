function [contrastParams,calculationResults,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = calculate(problemStruct,problemCells,controls)

% Custom XP profile reflectivity calculation for nonPolarisedTF

% This function decides on parallelisation options before calling the
% relevant version of the main custom XY calculation. It is more
% efficient to have multiple versions of the core calculation, each dealing
% with a different scheme for parallelisation. These are:
% single    - single threaded reflectivity calculation
% points    - parallelise over points in the reflectivity calculation
% contrasts - parallelise over contrasts.


% Pre-allocation - It's necessary to
% pre-allocate the memory for all the arrays
% for compilation, so do this in this block.

numberOfContrasts = problemStruct.numberOfContrasts;
outSsubs = zeros(numberOfContrasts,1);
backgroundParams = zeros(numberOfContrasts,1);
qzshifts = zeros(numberOfContrasts,1);
scalefactors = zeros(numberOfContrasts,1);
bulkIns = zeros(numberOfContrasts,1);
bulkOuts = zeros(numberOfContrasts,1);
chis = zeros(numberOfContrasts,1);
resolutionParams = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);

reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end

simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    simulation{i} = [1 1 ; 1 1];
end

shiftedData = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    shiftedData{i} = [1 1 1; 1 1 1];
end

layerSlds = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    layerSlds{i} = [1 1 1; 1 1 1];
end

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i} = [1 1; 1 1];
end

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 ; 1];
end

switch controls.parallel
    case 'single'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
             simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.customXY.single(problemStruct,problemCells,controls);
    case 'points'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
             simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.customXY.parallelPoints(problemStruct,problemCells,controls);
    case 'contrasts'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
             simulation,shiftedData,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.customXY.parallelContrasts(problemStruct,problemCells,controls);
end

contrastParams.ssubs = outSsubs;
contrastParams.backgroundParams = backgroundParams;
contrastParams.qzshifts = qzshifts;
contrastParams.scalefactors = scalefactors;
contrastParams.bulkIn = bulkIns;
contrastParams.bulkOut = bulkOuts;
contrastParams.resolutionParams = resolutionParams;
contrastParams.allSubRough = allRoughs;
contrastParams.resample = ones(1,length(allRoughs));

calculationResults.allChis = chis;
calculationResults.sumChi = sum(chis);

end
