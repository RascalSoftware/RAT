function [problem,reflectivity,Simulation,shifted_data,layerSlds,domainSldProfiles,allLayers] = domainsTFCustomLayersReflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls)

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
backgs = zeros(numberOfContrasts,1);
qshifts = zeros(numberOfContrasts,1);
sfs = zeros(numberOfContrasts,1);
nbas = zeros(numberOfContrasts,1);
nbss = zeros(numberOfContrasts,1);
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

para = controls.para;

switch para
    case 'single'
            
          [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,domainSldProfiles,allLayers,...
             allRoughs] = domainsTFCustomLayersSingle(problemDef,problemDefCells,...
             problemDefLimits,controls);
        
    case 'points'
        
          [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,domainSldProfiles,allLayers,...
             allRoughs] = domainsTFCustomLayersParallelPoints(problemDef,problemDefCells,...
             problemDefLimits,controls);
         
    case 'contrasts'
        
          [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,domainSldProfiles,allLayers,...
             allRoughs] = domainsTFCustomLayersParallelContrasts(problemDef,problemDefCells,...
             problemDefLimits,controls);

end

problem.ssubs = outSsubs;
problem.backgrounds = backgs;
problem.qshifts = qshifts;
problem.scalefactors = sfs;
problem.nbairs = nbas;
problem.nbsubs = nbss;
problem.resolutions = resols;
problem.calculations.all_chis = chis;
problem.calculations.sum_chi = sum(chis);
problem.allSubRough = allRoughs;
problem.resample = problemDef.resample;

end