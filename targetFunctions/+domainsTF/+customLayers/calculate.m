function [problem,reflectivity,simulation,shiftedData,layerSlds,domainSldProfiles,allLayers] = calculate(problemDef,problemDefCells,controls)

% Custom layers reflectivity calculation for domainsTF

% This function decides on parallelisation options before calling the
% relevant version of the main custom layers calculation. It is more
% efficient to have multiple versions of the core calculation, each dealing
% with a different scheme for parallelisation. These are:
% single    - single threaded reflectivity calculation
% points    - parallelise over points in the reflectivity calculation
% contrasts - parallelise over contrasts.


% Pre-allocation - It's necessary to
% pre-allocate the memory for all the arrays
% for compilation, so do this in this block.
numberOfContrasts = problemDef.numberOfContrasts;
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

layerSlds = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    layerSlds{i,1} = [1 1 1; 1 1 1];
    layerSlds{i,2} = [1 1 1; 1 1 1];
end

domainSldProfiles = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainSldProfiles{i,1} = [1 1; 1 1];
    domainSldProfiles{i,2} = [1 1; 1 1];
end

allLayers = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    allLayers{i,1} = [1 1 1; 1 1 1];
    allLayers{i,2} = [1 1 1; 1 1 1];
end
coder.varsize('allLayers',[10000 2],[1 1]);

% End pre-allocation

switch controls.parallel
    case 'single'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
             simulation,shiftedData,layerSlds,domainSldProfiles,allLayers,...
             allRoughs] = domainsTF.customLayers.single(problemDef,problemDefCells,controls);
    case 'points'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
             simulation,shiftedData,layerSlds,domainSldProfiles,allLayers,...
             allRoughs] = domainsTF.customLayers.parallelPoints(problemDef,problemDefCells,controls);    
    case 'contrasts'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,chis,reflectivity,...
             simulation,shiftedData,layerSlds,domainSldProfiles,allLayers,...
             allRoughs] = domainsTF.customLayers.parallelContrasts(problemDef,problemDefCells,controls);
end

problem.ssubs = outSsubs;
problem.backgroundParams = backgroundParams;
problem.qzshifts = qzshifts;
problem.scalefactors = scalefactors;
problem.bulkIn = bulkIns;
problem.bulkOut = bulkOuts;
problem.resolutionParams = resolutionParams;
problem.calculations.allChis = chis;
problem.calculations.sumChi = sum(chis);
problem.allSubRough = allRoughs;
problem.resample = problemDef.resample;
end
