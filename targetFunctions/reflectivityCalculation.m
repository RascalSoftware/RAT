function result = reflectivityCalculation(problemStruct,controls)
% Compute the reflectivity and SLD curves for a given model using the Abeles matrix formalism.
%
% Main entry point into the reflectivity calculation for the toolbox.
% This is the main function that is called by any of the minimisers or
% analysis tools from the rest of the toolbox. 
%
% The main job of this function is to decide which type of calculation
% (i.e. 'Target function') is required, and call the relevant routines.
% Different model types are specified in sub functions.
% The types of available target functions are:
%
% * normal    - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples.
%
% * domains   - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
%
% Parameters
% ----------
% problemStruct : struct
%     The project class as a struct (generated via parseClassToStructs)
% controls : struct
%     The controls struct (generated via parseClassToStructs)
%
% Returns
% -------
% result : struct
%     The results of the calculation.

% Decide which target function we are calling and call the relevant routines
switch problemStruct.TF
    
    case coderEnums.calculationTypes.Normal      
        
        [reflectivity,simulation,shiftedData,backgrounds,resolutions,...
         sldProfiles,layers,resampledLayers,~,scalefactors,bulkIns,...
         bulkOuts,subRoughs,chis...
         ] = normalTF.normalReflectivity(problemStruct,controls);

    case coderEnums.calculationTypes.Domains
     
        [reflectivity,simulation,shiftedData,backgrounds,resolutions,...
         sldProfiles,layers,resampledLayers,~,scalefactors,bulkIns,...
         bulkOuts,subRoughs,chis...
         ] = domainsTF.domainsReflectivity(problemStruct,controls);

    otherwise
        coderException(coderEnums.errorCodes.invalidOption, 'The calculation type "%s" is not supported', problemStruct.TF);
end

% Make the result struct
calculationResults.chiValues = chis;
calculationResults.sumChi = sum(chis);

contrastParams.scalefactors = scalefactors;
contrastParams.bulkIn = bulkIns;
contrastParams.bulkOut = bulkOuts;
contrastParams.subRoughs = subRoughs;
contrastParams.resample = problemStruct.resample;

result.reflectivity = reflectivity;
result.simulation = simulation;
result.shiftedData = shiftedData;
result.backgrounds = backgrounds;
result.resolutions = resolutions;
result.sldProfiles = sldProfiles;
result.layers = layers;
result.resampledLayers = resampledLayers;

result.calculationResults = calculationResults;
result.contrastParams = contrastParams;

result.fitParams = problemStruct.fitParams;
result.fitNames = getFitNames(problemStruct);

end
