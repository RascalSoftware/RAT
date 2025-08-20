function [reflectivity,simulation,shiftedData,sldProfile,layers,resampledLayers,chi] = ...
    coreLayersCalculation(contrastLayers,roughness,geometry,bulkIn,bulkOut,resample,...
    calcSld,shiftedData,simulationXData,dataIndices,repeatLayers,...
    background,resolution,backgroundAction,parallelPoints,resampleMinAngle,...
    resampleNPoints,nParams)

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
%   Finally, the background correction is applied.

% Pre-definition for Coder
sldProfile = [0 0];
sldProfileIm = [0 0];
resampledLayers = [0 0 0 0];

% Build up the layers matrix for this contrast
[layers, ssubs] = groupLayersMod(contrastLayers,roughness,geometry);
layers = applyHydration(layers,bulkIn,bulkOut);

% Make the SLD profiles.
% If resampling is needed, then enforce the SLD calculation, so as to
% prevent the error of trying to resample a non-existent profile.
if calcSld || resample == 1

    % We process real and imaginary parts of the SLD separately
    ReSLDLayers = layers(:, [1:2,4:end]);
    sldProfile = makeSLDProfile(bulkIn,bulkOut,ReSLDLayers,ssubs,repeatLayers);

end

% If required, then resample the SLD
if resample == 1

    % Here, we need the imaginary part of the SLD
    % Note bulkIn and bulkOut = 0 since there is never any imaginary part
    % for the bulk phases.
    ImSLDLayers = layers(:, [1,3:end]);
    sldProfileIm = makeSLDProfile(0,0,ImSLDLayers,ssubs,repeatLayers);

    resampledLayers = resampleLayers(sldProfile,sldProfileIm,resampleMinAngle,resampleNPoints);
    inputLayers = resampledLayers;
    repeatLayers = 1;

else

    inputLayers = layers;

end

% Calculate the reflectivity
reflectivityType = 'standardAbeles';
[reflectivity,simulation] = callReflectivity(bulkIn,bulkOut,simulationXData,dataIndices,repeatLayers,inputLayers,ssubs,resolution,parallelPoints,reflectivityType);

% Apply background correction
[reflectivity,simulation,shiftedData] = applyBackgroundCorrection(reflectivity,simulation,shiftedData,background,backgroundAction);

chi = chiSquared(shiftedData,reflectivity,nParams);

end
