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

% For compilation, we fill the results arrays to define their type and size
numberOfContrasts = problemStruct.numberOfContrasts;
shiftedData = cell(numberOfContrasts,1);

% Decide which target function we are calling and call the relevant routines
whichTF = problemStruct.TF;
switch whichTF
    case coderEnums.calculationTypes.NonPolarised
        [contrastParams,calculationResults,reflectivity,simulation,fullShiftedData,backgrounds,layerSlds,sldProfiles,resampledLayers] = nonPolarisedTF.reflectivityCalculation(problemStruct,problemCells,controls);
    %case coderEnums.calculationTypes.OilWater
        %contrastParams = oilWaterTFReflectivityCalculation(problemStruct,problemCells,controls);    
    %case coderEnums.calculationTypes.Magnetic
        %contrastParams = polarisedTFReflectivityCalculation(problemStruct,problemCells,controls);
    case coderEnums.calculationTypes.Domains
        [contrastParams,calculationResults,reflectivity,simulation,fullShiftedData,backgrounds,layerSlds,sldProfiles,resampledLayers] = domainsTF.reflectivityCalculation(problemStruct,problemCells,controls);
    otherwise
        error('The calculation type "%s" is not supported', whichTF);
end

% Reduce data to original three columns
for i = 1:length(shiftedData)
    shiftedData{i} = fullShiftedData{i}(:,1:3);
end

% Make the result struct
result.reflectivity = reflectivity;
result.simulation = simulation;
result.shiftedData = shiftedData;
result.backgrounds = backgrounds;
result.layerSlds = layerSlds;
result.sldProfiles = sldProfiles;
result.resampledLayers = resampledLayers;

% Complete the result struct
[~,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

result.calculationResults = calculationResults;
result.contrastParams = contrastParams;
result.fitParams = problemStruct.fitParams;
result.fitNames = fitNames;

end
