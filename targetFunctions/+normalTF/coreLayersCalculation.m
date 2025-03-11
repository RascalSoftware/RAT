function [reflectivity,simulation,shiftedData,layerSld,sldProfile,resampledLayers,chi] = ...
    coreLayersCalculation(layers,roughness,geometry,bulkIn,bulkOut,resample,...
    calcSld,shiftedData,simulationXData,dataIndices,repeatLayers,resolution,...
    background,backgroundAction,nParams,parallelPoints,resampleMinAngle,...
    resampleNPoints)

%   This is the main reflectivity calculation for all layers models in the 
%   normal target function.
%
%   The function first arranges the roughness' in the correct order
%   according to geometry. Then, if required it calculates the SLD profile
%   and if requested resamples this into a number of zero-roughness layers
%   (roughness resampling). It the applies any scalefactors and qz shifts
%   the data requires. This is done before calculating the reflectivity to
%   ensure that the reflectivity is calculated over the same range in qz as
%   the shifted datapoints. The main reflectivity calculation is then
%   called, including the resolution function. The calculation outputs two
%   profiles - 'reflect' which is the same range as the points, and
%   'simulation' which can be a different range to allow extrapolation.
%   The background correction is the applied, and finally chi-squared is 
%   calculated.

% Pre-definition for Coder
sldProfile = [0 0];
sldProfileIm = [0 0];
resampledLayers = [0 0 0 0];

% Build up the layers matrix for this contrast
[layerSld, ssubs] = groupLayersMod(layers,roughness,geometry);
layerSld = applyHydration(layerSld,bulkIn,bulkOut);

% Make the SLD profiles.
% If resampling is needed, then enforce the SLD calculation, so as to
% prevent the error of trying to resample a non-existent profile.
if calcSld || resample == 1

    % We process real and imaginary parts of the SLD separately
    ReSLDLayers = layerSld(:, [1:2,4:end]);
    ImSLDLayers = layerSld(:, [1,3:end]);

    % Note bulkIn and bulkOut = 0 since there is never any imaginary part
    % for the bulk phases.
    sldProfile = makeSLDProfiles(bulkIn,bulkOut,ReSLDLayers,ssubs,repeatLayers);
    sldProfileIm = makeSLDProfiles(0,0,ImSLDLayers,ssubs,repeatLayers);

end

% If required, then resample the SLD
if resample == 1
    resampledLayers = resampleLayers(sldProfile,sldProfileIm,resampleMinAngle,resampleNPoints);
    inputLayers = resampledLayers;
else
    inputLayers = layerSld;
end

% Calculate the reflectivity
reflectivityType = 'standardAbeles';
[reflectivity,simulation] = callReflectivity(bulkIn,bulkOut,simulationXData,dataIndices,repeatLayers,inputLayers,ssubs,resolution,parallelPoints,reflectivityType);

% Apply background correction
[reflectivity,simulation,shiftedData] = applyBackgroundCorrection(reflectivity,simulation,shiftedData,background,backgroundAction);

% Calculate chi squared
chi = chiSquared(shiftedData,reflectivity,nParams);

end
