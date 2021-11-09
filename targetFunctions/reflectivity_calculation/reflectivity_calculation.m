function [problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls)

% Main entry point into the reflectivity calculation for the toolbox.
% This is the main function that is called by any of the minimisers or
% analysis tools from the rest of the toolbox. The main job of this
% function is to decide which type of calculation (i.e. 'Target function'
% is required, and call the relevant routines. The types of available 
% target functions are:
%
% 1. standardTF       - The main basic target function type, for non polarised 
%                       neutrons (or x-rays) with non-absorbing samples.
%                       Different model types are specified in sub functions
%                       from here.
%
% 2. standardTFAbs    - Identical to standardTF, but includes imaginary refractive 
%                       index terms.
%
% 3. oilWaterTF       - Target function for oil-water samples
%
% 4. domainsTF        - Target function for samples consisting of domains 
%                       which are larger than the beam lateral coherence length.
%
% 5. polarisedTF      - Target function for cases for polarised neutrons
%                       with polarisation analysis


% for compilation, we have to preallocate memory for the output arrays
% Setting these parameters in the struct defines them as doubles



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
problem.resample = 0;

% MATLAB ENGINE STUFF

% open the engines in a loop with unique names to each 

% we open engines based on our req by comparing with no of open currently

% if there are not enough engines open, open them up but if there are more than required, close them

% engine.startEngine(); here aling with logic
% set up the engine pointers based on number of engines 


persistent noOfOpenEngines;


if isempty(noOfOpenEngines)
    noOfOpenEngines = 0;
end


numberOfEnginesNeeded = controls.numberOfEngines;



numberOfEngines = controls.numberOfEngines;

for i = 1:numberOfEngines
    engineName = ['p',num2str(i)];
    eval([engineName,' = MatlabEngine();']);
    eval(['engines(i) = ',engineName,';']);

end

controls.engines = engines;

if noOfOpenEngines < numberOfEnginesNeeded
    newEnginesRequired = numberOfEnginesNeeded - noOfOpenEngines;
    for i = 1:newEnginesRequired
        engines(i).startEngine();
        noOfOpenEngines = noOfOpenEngines + 1;


    end
    
    

elseif noOfOpenEngines > numberOfEnginesNeeded
    EnginesToDestroy = noOfOpenEngines - numberOfEngines;
    for i = 1:EnginesToDestroy
        engines(i).closeEngine();
        noOfOpenEngines = noOfOpenEngines - 1;
    end
  
end



% We also foll the results arrays to define their
% type and size. (NOTE: at the moment we have a 'coder.varsize'
% pre-processor directives for the compiler here and at the 
% end for the results block. We are unlikely to need both
% TODO: Find out which is necessary and tidy this up.

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
    allLayers{i} = [1 1 1; 1 1 1];
end
coder.varsize('allLayers{:}',[10000 3],[1 0]);



%Decide which target function we are calling ans call the relevant routines
whichTF = problemDef.TF;
switch whichTF
    case 'standardTF'
        [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
    %case 'standardTFAbs'
        %[problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTFAbs_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
    %case 'oilWaterTF'
        %problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);    
    %case 'polarisedTF'
        %problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
    %case 'domainsTF'
        %problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
end

result = cell(1,6);

cell1 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell1{i} = reflectivity{i};
end
result{1} = cell1;

cell2 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell2{i} = Simulation{i};
end
result{2} = cell2;

cell3 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell3{i} = shifted_data{i}; 
end
result{3} = cell3;
 
cell4 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell4{i} = layerSlds{i};
end
result{4} = cell4;
 
cell5 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell5{i} = sldProfiles{i}; 
end
result{5} = cell5;
 
cell6 = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    cell6{i} = allLayers{i}; 
end
result{6} = cell6;

% Pre-processor directives for Matlab Coder
% to define the size of the output array
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

%Result coder definitions....
coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity
coder.varsize('result{1}{:}',[Inf 2],[1 0]);

coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin
coder.varsize('result{2}{:}',[Inf 2],[1 0]);

coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data
coder.varsize('result{3}{:}',[Inf 3],[1 0]);

coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds
coder.varsize('result{4}{:}',[Inf 3],[1 0]);

coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles
coder.varsize('results{5}{:}',[Inf 2],[1 0]);

coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers (resampled)
coder.varsize('result{6}{:}',[Inf 3],[1 0]);

end

