function [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = calculate(problemDef,problemDefCells,controls)

% Custom layers reflectivity calculation for nonPolarisedTF

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
resols = zeros(numberOfContrasts,1);
allRoughs = zeros(numberOfContrasts,1);

reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end

Simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    Simulation{i} = [1 1 ; 1 1];
end

shifted_data = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    shifted_data{i} = [1 1 1; 1 1 1];
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
    allLayers{i} = [1 1 1; 1 1 1];
end
% End pre-allocation

switch controls.parallel
    case 'single'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.customLayers.single(problemDef,problemDefCells,controls);
    case 'points'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.customLayers.parallelPoints(problemDef,problemDefCells,controls);
    case 'contrasts'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.customLayers.parallelContrasts(problemDef,problemDefCells,controls);
end

problem.ssubs = outSsubs;
problem.backgroundParams = backgroundParams;
problem.qzshifts = qzshifts;
problem.scalefactors = scalefactors;
problem.bulkIn = bulkIns;
problem.bulkOut = bulkOuts;
problem.resolutionParams = resols;
problem.calculations.all_chis = chis;
problem.calculations.sum_chi = sum(chis);
problem.allSubRough = allRoughs;
problem.resample = problemDef.resample;
end
