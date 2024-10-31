function result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls)
% Main entry point into the reflectivity calculation for the toolbox.
% This is the main function that is called by any of the minimisers or
% analysis tools from the rest of the toolbox. 
%
% *The main job of this function is to decide which type of calculation
% (i.e. 'Target function' is required, and call the relevant routines.
% The types of available target functions are:*
%
% * non polarised  - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples. Different model types are specified in sub functions from here.
%
% * oil water      - Target function for oil-water samples
%
% * domains        - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
%
% * magnetic       - Target function for cases for polarised neutrons with polarisation analysis.
%                       

% Decide which target function we are calling and call the relevant routines
targetFunction = problemStruct.TF;
modelType = problemStruct.modelType;

switch targetFunction
    case coderEnums.calculationTypes.NonPolarised      
           
        switch lower(modelType)

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
                error('The model type "%s" is not supported', modelType);
        end

    %case coderEnums.calculationTypes.OilWater
        %contrastParams = oilWaterTFReflectivityCalculation(problemStruct,problemCells,controls);    
    %case coderEnums.calculationTypes.Magnetic
        %contrastParams = polarisedTFReflectivityCalculation(problemStruct,problemCells,controls);

    case coderEnums.calculationTypes.Domains

        switch lower(modelType)

            case coderEnums.modelTypes.StandardLayers
        
                [qzshifts,scalefactors,bulkIns,bulkOuts,...
                 resolutionParams,chis,reflectivity,simulation,shiftedData,...
                 backgrounds,layerSlds,sldProfiles,resampledLayers,...
                 subRoughs] = domainsTF.standardLayers(problemStruct,problemCells,controls);        
        
            case coderEnums.modelTypes.CustomLayers
        
                [qzshifts,scalefactors,bulkIns,bulkOuts,...
                 resolutionParams,chis,reflectivity,simulation,shiftedData,...
                 backgrounds,layerSlds,sldProfiles,resampledLayers,...
                 subRoughs] = domainsTF.customLayers(problemStruct,problemCells,controls);
        
            case coderEnums.modelTypes.CustomXY
        
                [qzshifts,scalefactors,bulkIns,bulkOuts,...
                 resolutionParams,chis,reflectivity,simulation,shiftedData,...
                 backgrounds,layerSlds,sldProfiles,resampledLayers,...
                 subRoughs] = domainsTF.customXY(problemStruct,problemCells,controls);

            otherwise
                error('The model type "%s" is not supported', modelType);
        end

    otherwise
        error('The calculation type "%s" is not supported', targetFunction);
end

% Make the result struct
calculationResults.chiValues = chis;
calculationResults.sumChi = sum(chis);

contrastParams.scalefactors = scalefactors;
contrastParams.bulkIn = bulkIns;
contrastParams.bulkOut = bulkOuts;
contrastParams.resolutionParams = resolutionParams;
contrastParams.subRoughs = subRoughs;
contrastParams.resample = problemStruct.resample;

result.reflectivity = reflectivity;
result.simulation = simulation;
result.shiftedData = shiftedData;
result.backgrounds = backgrounds;
result.layerSlds = layerSlds;
result.sldProfiles = sldProfiles;
result.resampledLayers = resampledLayers;

result.calculationResults = calculationResults;
result.contrastParams = contrastParams;

result.fitParams = problemStruct.fitParams;

[~,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);
result.fitNames = fitNames;

end
