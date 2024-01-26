function [contrastParams,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,allLayers] = reflectivityCalculation(problemStruct,problemCells,controls)

% Main function for the nonPolarisedTF reflectivity calculation
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
type = problemStruct.modelType;
numberOfContrasts = problemStruct.numberOfContrasts;

% Pre-allocate the output arrays.. this is necessary because otherwise
% the compiler complains with 'Output argument <....> is not assigned on 
% some execution paths' error.
preAlloc = zeros(numberOfContrasts,1);
contrastParams = struct('ssubs',preAlloc,...
                        'backgroundParams',preAlloc,...
                        'qzshifts',preAlloc,...
                        'scalefactors',preAlloc,...
                        'bulkIn',preAlloc,...
                        'bulkOut',preAlloc,...
                        'resolutionParams',preAlloc,...
                        'calculations',struct('allChis',preAlloc,'sumChi',0),...
                        'allSubRough',preAlloc,...
                        'resample',preAlloc');

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
    shiftedData{i} = [1 1 1 ; 1 1 1];
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
    case 'standard layers'
        % Standard layers calculation
        [contrastParams,reflectivity,simulation,...
         shiftedData,layerSlds,sldProfiles,...
         allLayers]= nonPolarisedTF.standardLayers.calculate(problemStruct,problemCells,controls);
    case 'custom layers'
        % Custom layers with user supplied custom model file
        [contrastParams,reflectivity,simulation,...
            shiftedData,layerSlds,sldProfiles,...
            allLayers] = nonPolarisedTF.customLayers.calculate(problemStruct,problemCells,controls);
    case 'custom xy'
        % Custom SLD profile with user defined model file
        [contrastParams,reflectivity,simulation,...
           shiftedData,layerSlds,sldProfiles,...
           allLayers] = nonPolarisedTF.customXY.calculate(problemStruct,problemCells,controls);
end

end
