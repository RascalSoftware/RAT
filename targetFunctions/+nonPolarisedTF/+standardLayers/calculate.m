function [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = calculate(problemDef,problemDefCells,controls)

% Standard layers reflectivity calculation for nonPolarisedTF
% This function decides on parallelisation options before calling the
% relevant version ofthe main standard layers calculation. Parallelisation 
% is either over the outer loop ('contrasts'), or the inner loop
% ('points'). The easiest way to do this is to have multiple versions of 
% the same core calculation, rather than trying to make the parallel
% for loops conditional (although that would be much neater) There are:
% points    - parallelise over points in the reflectivity calculation
% contrasts - parallelise over contrasts (outer for loop)


% Pre-allocation - It's necessary to
% pre-define the types for all the arrays
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
% ------- End type definitions -------------


switch controls.parallel
    case 'single'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.standardLayers.single(problemDef,problemDefCells,controls);
     case 'points'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.standardLayers.parallelPoints(problemDef,problemDefCells,controls);
    case 'contrasts'
          [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = nonPolarisedTF.standardLayers.parallelContrasts(problemDef,problemDefCells,controls);        
end

% Package everything into one array for tidy output
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
