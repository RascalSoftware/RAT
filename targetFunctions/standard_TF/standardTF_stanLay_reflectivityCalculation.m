function [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_stanLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls)

%Pre-allocation
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

para = controls.para;

switch para
    case 'single'
            
          [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = standardTF_stanlay_single(problemDef,problemDef_cells,...
             problemDef_limits,controls);

     case 'points'

          [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = standardTF_stanlay_paraPoints(problemDef,problemDef_cells,...
             problemDef_limits,controls);


    case 'contrasts'
        
          [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = standardTF_stanlay_paraContrasts(problemDef,problemDef_cells,...
             problemDef_limits,controls);        
        
    case 'all'

          [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
             Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
             allRoughs] = standardTF_stanlay_paraAll(problemDef,problemDef_cells,...
             problemDef_limits,controls); 

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

end