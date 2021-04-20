
function [problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls)


%Preallocatin of outputs
problem.ssubs = 0;
problem.backgrounds = 0;
problem.qshifts = 0;
problem.scalefactors = 0;
problem.nbairs = 0;
problem.nbsubs = 0;
problem.resolutions = 0;
problem.calculations.all_chis = 0;
problem.calculations.sum_chi = 0;
problem.allSubRough = 0;


numberOfContrasts = problemDef.numberOfContrasts;
reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end
coder.varsize('reflectivity{:}',[10000 2],[1 0]);

Simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    Simulation{i} = [1 1 ; 1 1];
end
coder.varsize('Simulation{:}',[10000 2],[1 0]);

shifted_data = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    shifted_data{i} = [1 1 1 ; 1 1 1];
end
coder.varsize('shifted_data{:}',[10000 3],[1 0]);

layerSlds = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    layerSlds{i} = [1 1 1 ; 1 1 1];
end
coder.varsize('layerSlds{:}',[10000 3],[1 0]);

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i} = [1 1 ; 1 1];
end
coder.varsize('sldProfiles{:}',[10000 2],[1 0]);

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 ; 1];
end
coder.varsize('allLayers{:}',[10000 1],[1 0]);

%Decide which target function we are calling
whichTF = problemDef.TF;
switch whichTF
    case 'standardTF'
        [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
    %case 'oilWaterTF'
        %problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);    
    %case 'polarisedTF'
        %problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
    %case 'domainsTF'
        %problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
end


result = cell(1,6);
%cell1Length = numberOfContrasts;
cell1 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell1{i} = reflectivity{i};
end
result{1} = cell1;

% cell2Length = 7;
cell2 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell2{i} = Simulation{i};
end
result{2} = cell2;
% 
% cell3Length = 7;
cell3 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell3{i} = shifted_data{i}; 
end
result{3} = cell3;
% 
% cell4Length = 7;
cell4 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell4{i} = layerSlds{i};
end
result{4} = cell4;
% 
% cell5Length = 7;
cell5 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell5{i} = sldProfiles{i}; 
end
result{5} = cell5;
% 
% cell6Length = 7;
cell6 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell6{i} = allLayers{i}; 
end
result{6} = cell6;


coder.varsize('problem.ssubs',[Inf 1],[1 0]);
coder.varsize('problem.backgrounds',[Inf 1],[1 0]);
coder.varsize('problem.qshifts',[Inf 1],[1 0]);
coder.varsize('problem.scalefactors',[Inf 1],[1 0]);
coder.varsize('problem.nbairs',[Inf 1],[1 0]);
coder.varsize('problem.nbsubs',[Inf 1],[1 0]);
coder.varsize('problem.resolutions',[Inf 1],[1 0]);
coder.varsize('problem.ssubs',[Inf 1],[1 0]);
coder.varsize('problem.calculations.all_chis',[Inf 1],[1 0]);
coder.varsize('problem.calculations.sum_chi',[1 1],[0 0]);
coder.varsize('problem.allSubRough',[Inf 1],[1 0]);

end