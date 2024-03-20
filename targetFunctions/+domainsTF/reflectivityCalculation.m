function [contrastParams,calculationResults,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,resampledLayers] = reflectivityCalculation(problemStruct,problemCells,controls)

% Main function for the domainsTF reflectivity calculation.
% This function decides what type of model is being analysed and branches
% to the correct one. The main options are:
%
% Standard Layers   - This is the equivalent of Standard Layers in RasCAL.
% Custom Layers     - This is also a layers calculation, but the
%                     specification of the layers is done using a user
%                     defined function.
% Custom XY         - This also has a model described by a user supplied
%                     function, but in this case the function generates an    
%                     SLD profile (i.e. XY function) rather than a list of
%                     layers.
%
% We then decide on parallelisation options before calling the relevant
% version of the main custom layers calculation. It is more efficient to
% have multiple versions of the core calculation, each dealing with a
% different scheme for parallelisation. These are:
%
% single            - single threaded reflectivity calculation.
% points            - parallelise over points.
% contrasts         - parallelise over contrasts.
%

% Find out the model type from the input structs
type = problemStruct.modelType;
numberOfContrasts = problemStruct.numberOfContrasts;

% Pre-allocation - It's necessary to pre-define the types for all the
% arrays for compilation, so do this in this block.
backgroundParams = zeros(numberOfContrasts,1);
qzshifts = zeros(numberOfContrasts,1);
scalefactors = zeros(numberOfContrasts,1);
bulkIns = zeros(numberOfContrasts,1);
bulkOuts = zeros(numberOfContrasts,1);
chis = zeros(numberOfContrasts,1);
resolutionParams = zeros(numberOfContrasts,1);
subRoughs = zeros(numberOfContrasts,1);

% Pre-allocate the output arrays.. this is necessary because otherwise the
% compiler complains with 'Output argument <....> is not assigned on some
% execution paths' error.
reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1; 1 1];
end

simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    simulation{i} = [1 1; 1 1];
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

sldProfiles = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    sldProfiles{i,1} = [1 1; 1 1];
    sldProfiles{i,2} = [1 1; 1 1];
end

resampledLayers = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    resampledLayers{i,1} = [1 1 1; 1 1 1];
    resampledLayers{i,2} = [1 1 1; 1 1 1];
end
           
switch lower(type)
    case coderEnums.modelTypes.StandardLayers

        [backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
         resolutionParams,chis,reflectivity,simulation,shiftedData,...
         layerSlds,sldProfiles,resampledLayers,...
         subRoughs] = domainsTF.standardLayers(problemStruct,problemCells,controls);        

    case coderEnums.modelTypes.CustomLayers

        [backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
         resolutionParams,chis,reflectivity,simulation,shiftedData,...
         layerSlds,sldProfiles,resampledLayers,...
         subRoughs] = domainsTF.customLayers(problemStruct,problemCells,controls);

    case coderEnums.modelTypes.CustomXY

        [backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
         resolutionParams,chis,reflectivity,simulation,shiftedData,...
         layerSlds,sldProfiles,resampledLayers,...
         subRoughs] = domainsTF.customXY(problemStruct,problemCells,controls);

end

% Package everything into one array for tidy output
contrastParams.backgroundParams = backgroundParams;
contrastParams.qzshifts = qzshifts;
contrastParams.scalefactors = scalefactors;
contrastParams.bulkIn = bulkIns;
contrastParams.bulkOut = bulkOuts;
contrastParams.resolutionParams = resolutionParams;
contrastParams.subRoughs = subRoughs;
contrastParams.resample = problemStruct.resample;

calculationResults.chiValues = chis;
calculationResults.sumChi = sum(chis);

end
