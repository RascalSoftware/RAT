function [problem,reflectivity,simulation,shiftedData,layerSlds,domainSldProfiles,allLayers] = reflectivityCalculation(problemDefStruct,problemDefCells,controls)

% Main function for the domainsTF reflectivity calculation
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
type = problemDefStruct.modelType;
numberOfContrasts = problemDefStruct.numberOfContrasts;

% Pre-allocate the output arrays.. this is necessary because otherwise
% the compiler complains with 'Output argument <....> is not assigned on 
% some execution paths' error.
preAlloc = zeros(numberOfContrasts,1);
problem = struct('ssubs',preAlloc,...
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

layerSlds = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    layerSlds{i,1} = [1 1 1 ; 1 1 1];
    layerSlds{i,2} = [1 1 1 ; 1 1 1];
end

domainSldProfiles = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainSldProfiles{i,1} = [1 1 ; 1 1];
    domainSldProfiles{i,2} = [1 1 ; 1 1];
end

allLayers = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    allLayers{i,1} = [1 1 1 ; 1 1 1];
    allLayers{i,2} = [1 1 1 ; 1 1 1];
end
           
switch lower(type)
    case 'standard layers'
        % Standard layers calculation
        [problem,reflectivity,simulation,...
         shiftedData,layerSlds,domainSldProfiles,...
         allLayers]= domainsTF.standardLayers.calculate(problemDefStruct,problemDefCells,controls);
    case 'custom layers'
        % Custom layers with user supplied custom model file
        [problem,reflectivity,simulation,...
            shiftedData,layerSlds,domainSldProfiles,...
            allLayers] = domainsTF.customLayers.calculate(problemDefStruct,problemDefCells,controls);
    case 'custom xy'
        % Custom SLD profile with user defined model file
        [problem,reflectivity,simulation,...
           shiftedData,layerSlds,domainSldProfiles,...
           allLayers] = domainsTF.customXY.calculate(problemDefStruct,problemDefCells,controls);
end
end