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

% For compilation, we have to preallocate memory for the output structs
numberOfContrasts = problemStruct.numberOfContrasts;
preAlloc = zeros(numberOfContrasts,1);

contrastParams = struct('ssubs',preAlloc, ...
                        'backgroundParams',preAlloc,...
                        'qzshifts',preAlloc,...
                        'scalefactors',preAlloc,...
                        'bulkIn',preAlloc,...
                        'bulkOut',preAlloc,...
                        'resolutionParams',preAlloc,...
                        'allSubRough',preAlloc,...
                        'resample',preAlloc);

calculationResults = struct('allChis',preAlloc,'sumChi',0);

% We also fill the results arrays to define their type and size.
reflectivity = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    reflectivity{i} = [1 1 ; 1 1];
end
coder.varsize('reflectivity{:}',[10000 2],[1 0]);

simulation = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    simulation{i} = [1 1 ; 1 1];
end
coder.varsize('simulation{:}',[10000 2],[1 0]);

shiftedData = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    shiftedData{i} = [1 1 1 ; 1 1 1];
end
coder.varsize('shiftedData{:}',[10000 3],[1 0]);

layerSlds = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    layerSlds{i} = [1 1 1 ; 1 1 1];
end
coder.varsize('layerSlds{:}',[10000 6],[1 1]);

domainLayerSlds = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainLayerSlds{i,1} = [1 1 1 ; 1 1 1];
    domainLayerSlds{i,2} = [1 1 1 ; 1 1 1];
end
coder.varsize('domainLayerSlds',[10000 2],[1 1]);
coder.varsize('domainLayerSlds{:}',[10000 6],[1 1]);

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i,1} = [1 1 ; 1 1];
end
coder.varsize('sldProfiles{:}',[10000 2],[1 0]);

domainSldProfiles = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainSldProfiles{i,1} = [1 1 ; 1 1];
    domainSldProfiles{i,2} = [1 1 ; 1 1];
end
coder.varsize('domainSldProfiles',[10000 2],[1 1]);
coder.varsize('domainSldProfiles{:}',[10000 Inf],[1 1]);

resampledLayers = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    resampledLayers{i} = [1 1 1; 1 1 1];
end
coder.varsize('resampledLayers{:}',[10000 3],[1 0]);

domainResampledLayers = cell(numberOfContrasts,2);
for i = 1:numberOfContrasts
    domainResampledLayers{i,1} = [1 1 1; 1 1 1];
    domainResampledLayers{i,2} = [1 1 1; 1 1 1];
end
coder.varsize('domainResampledLayers',[10000 2],[1 1]);
coder.varsize('domainResampledLayers{:}',[10000 3],[1 0]);

% Decide which target function we are calling and call the relevant routines
whichTF = problemStruct.TF;
switch whichTF
    case coderEnums.calculationTypes.NonPolarised
        [contrastParams,calculationResults,reflectivity,simulation,shiftedData,layerSlds,sldProfiles,resampledLayers] = nonPolarisedTF.reflectivityCalculation(problemStruct,problemCells,controls);
    %case coderEnums.calculationTypes.OilWater
        %contrastParams = oilWaterTFReflectivityCalculation(problemStruct,problemCells,controls);    
    %case coderEnums.calculationTypes.Magnetic
        %contrastParams = polarisedTFReflectivityCalculation(problemStruct,problemCells,controls);
    case coderEnums.calculationTypes.Domains
        [contrastParams,calculationResults,reflectivity,simulation,shiftedData,domainLayerSlds,domainSldProfiles,domainResampledLayers] = domainsTF.reflectivityCalculation(problemStruct,problemCells,controls);
%     otherwise
%         error('The calculation type "%s" is not supported', whichTF);

end

% Make the result struct
result.reflectivity = reflectivity;
result.simulation = simulation;
result.shiftedData = shiftedData;

% The size of this array now varies depending on TF
switch whichTF
    case coderEnums.calculationTypes.Domains

        result.layerSlds = domainLayerSlds;
        result.sldProfiles = domainSldProfiles;
        result.resampledLayers = domainResampledLayers;

    otherwise

        result.layerSlds = layerSlds;
        result.sldProfiles = sldProfiles;
        result.resampledLayers = resampledLayers;

end

% Complete the result struct
[~,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

result.calculationResults = calculationResults;
result.contrastParams = contrastParams;
result.bestFitPars = problemStruct.fitParams;
result.fitNames = fitNames;

end
