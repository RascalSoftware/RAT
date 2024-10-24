function [contrastParams,calculationResults,reflectivity,simulation,shiftedData,backgrounds,layerSlds,sldProfiles,resampledLayers] = reflectivityCalculation(problemStruct,problemCells,controls)

% Main function for the nonPolarisedTF reflectivity calculation.
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
           
switch lower(type)
    case coderEnums.modelTypes.StandardLayers

        [qzshifts,scalefactors,bulkIns,bulkOuts,...
         resolutionParams,chis,reflectivity,simulation,shiftedData,...
         backgrounds,layerSlds,sldProfiles,resampledLayers,...
         subRoughs] = nonPolarisedTF.standardLayers(problemStruct,problemCells,controls);

    case coderEnums.modelTypes.CustomLayers

        [qzshifts,scalefactors,bulkIns,bulkOuts,...
         resolutionParams,chis,reflectivity,simulation,shiftedData,...
         backgrounds,layerSlds,sldProfiles,resampledLayers,...
         subRoughs] = nonPolarisedTF.customLayers(problemStruct,problemCells,controls);

    case coderEnums.modelTypes.CustomXY
        
        [qzshifts,scalefactors,bulkIns,bulkOuts,...
         resolutionParams,chis,reflectivity,simulation,shiftedData,...
         backgrounds,layerSlds,sldProfiles,resampledLayers,...
         subRoughs] = nonPolarisedTF.customXY(problemStruct,problemCells,controls);
    otherwise
        error('The model type "%s" is not supported', type);
end

% Package everything into structs for tidy output
contrastParams.scalefactors = scalefactors;
contrastParams.bulkIn = bulkIns;
contrastParams.bulkOut = bulkOuts;
contrastParams.resolutionParams = resolutionParams;
contrastParams.subRoughs = subRoughs;
contrastParams.resample = problemStruct.resample;

calculationResults.chiValues = chis;
calculationResults.sumChi = sum(chis);

end
