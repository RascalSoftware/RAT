function [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls)

% Main function for the standardTF reflectivity calculation
% This function decides what type of model is being analysed and barnches
% to the correct one. The main options are:
% layers            - This is the equivalent of Standard Layers in RasCAL
% Custom Layers     - This is also a layers calculation, but the
%                   specification of the layers is dne using a user defined
%                   function.
% Custom XY         - This also has a model described by a user supplied
%                   function, but in this case the function generates an    
%                   SLD profile (i.e. XY function) rather than a list of
%                   layers.


% Find out the model type from the input structs
type = problemDef.modelType;
numberOfContrasts = problemDef.numberOfContrasts;

% Pre-allocate the output arrays.. this is necessary because otherwise
% the compiler complains with 'Output argument <....> is not assigned on 
% some execution paths' error.
preAlloc = zeros(numberOfContrasts,1);
problem = struct('ssubs',preAlloc,...
                 'backgrounds',preAlloc,...
                 'qshifts',preAlloc,...
                 'scalefactors',preAlloc,...
                 'nbairs',preAlloc,...
                 'nbsubs',preAlloc,...
                 'resolutions',preAlloc,...
                 'calculations',struct('all_chis',preAlloc,'sum_chi',0),...
                 'allSubRough',preAlloc,...
                 'resample',preAlloc);

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
    shifted_data{i} = [1 1 1 ; 1 1 1];
end

layerSlds = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    layerSlds{i} = [1 1 1 ; 1 1 1];
end

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i} = [1 1 ; 1 1];
end

allLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    allLayers{i} = [1 1 1 ; 1 1 1];
end
           
switch lower(type)
    case 'layers'
        % Standard layers calculation
        [problem,reflectivity,Simulation,...
         shifted_data,layerSlds,sldProfiles,...
         allLayers]= standardTF_stanLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'custom layers'
        % Custom layers with user supplied custom model file
        [problem,reflectivity,Simulation,...
            shifted_data,layerSlds,sldProfiles,...
            allLayers] = standardTF_custLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'custom xy'
        % Custom SLD profile with user defined model file
        [problem,reflectivity,Simulation,...
           shifted_data,layerSlds,sldProfiles,...
           allLayers] = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
end

end