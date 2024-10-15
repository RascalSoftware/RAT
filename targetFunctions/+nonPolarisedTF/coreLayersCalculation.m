function [sldProfile,reflect,simulation,shiftedData,theseLayers,resamLayers,chiSq] = ...
    coreLayersCalculation(contrastLayers, rough, ...
    geometry, bulkIn, bulkOut, resample, calcSld, scalefactor, qzshift,...
    dataPresent, data, dataLimits, simLimits, repeatLayers,...
    backgroundParams,resolution,backgroundParamIndex,backgroundParamArray,customFiles,contrastBackgroundActions,params,parallelPoints,resampleMinAngle,resampleNPoints,useImaginary)

%   This is the main reflectivity calculation for all Layers models in the 
%   non polarised target function. 
%
%   The function first arranges the 
%   roughness' in the correct order according
%   to geometry. Then, if required it calculates the SLD profile and if
%   requested resamples this into a number of zero-roughness layers
%   (roughness resampling). It the applies any scalefactors and qz shifts
%   the data requires. This is done before calculating the reflectivity to
%   ensure that the reflectivity is calculated over the same range in qz as
%   the shifted datapoints. The main reflectivity calculation is then
%   called, including the resolution function. The calculation outputs two
%   profiles - 'reflect' which is the same range as the points, and
%   'simulation' which can be a different range to allow extrapolation.
%   The background correction is the applied, and finally chi-squared is 
%   calculated.
%
% Inputs:
%   contrastLayers  :
%   rough           :
%   geometry        :
%   bulkIn          :
%   bulkOut         :
%   resample        :
%   calcSld         :
%   scalefactor     :
%   qzshift         :
%   dataPresent     :
%   data            :
%   dataLimits      :
%   simLimits       :
%   repeatLayers    :
%   background      :
%   resol           :
%   contrastBackgroundActions       :
%   params          :
%   parallelPoints  :
%
% Outputs:
%
%
%

% Pre-definition for Coder
sldProfile = [0 0];
sldProfileIm = [0 0];

% Build up the layers matrix for this contrast
if ~useImaginary
    [theseLayers, ssubs] = groupLayersMod(contrastLayers,rough,geometry,bulkIn,bulkOut);
else
    [theseLayers, ssubs] = groupLayersModImaginary(contrastLayers,rough,geometry,bulkIn,bulkOut);
end

% Make the SLD profiles.
% If resampling is needed, then enforce the calcSLD flag, so as to catch
% the error af trying to resample a non-existent profile.
if (resample == 1 && ~calcSld)
    calcSld = true;
end

% If calc SLD flag is set, then calculate the SLD profile
if calcSld

    % If we need them both, we process real and imaginary parts of the SLD
    % seperately...
    if useImaginary
        thisSldLays = [theseLayers(:,1:2) theseLayers(:,4:end)];
        thisSldLaysIm = [theseLayers(:,1) theseLayers(:,3:end)];
    else
        thisSldLays = theseLayers;
        thisSldLaysIm = [0 0]; % Dummy value for coder
    end
    
    sldProfile = makeSLDProfiles(bulkIn,bulkOut,thisSldLays,ssubs,repeatLayers);

    % If we have imaginary, we are also
    % going to need an SLD profile for the imaginary part
    if useImaginary
        % Note bulkIn and bulkOut = 0 since there is never any imaginary part for
        % the bulk phases..
        sldProfileIm = makeSLDProfiles(0,0,thisSldLaysIm,ssubs,repeatLayers);
    end
end

% If required, then resample the SLD
if resample == 1
    if ~useImaginary
        layerSld = resampleLayers(sldProfile,resampleMinAngle,resampleNPoints);
    else
        layerSld = resampleLayersReIm(sldProfile,sldProfileIm,resampleMinAngle,resampleNPoints);
    end
    resamLayers = layerSld;
else
    layerSld = theseLayers;
    resamLayers = [0 0 0];
end

% Apply scale factors and q shifts to the data
shiftedData = shiftData(scalefactor,qzshift,dataPresent,data,dataLimits,simLimits);

% Calculate the reflectivity
reflectivityType = 'standardAbeles';
[reflect,simulation] = callReflectivity(bulkIn,bulkOut,simLimits,repeatLayers,shiftedData,layerSld,ssubs,resolution,parallelPoints,reflectivityType,useImaginary);

% Apply background correction
background = constructBackground(backgroundParamIndex,shiftedData,customFiles,backgroundParamArray,simulation);
[reflect,simulation,shiftedData] = applyBackgroundCorrection(reflect,simulation,shiftedData,backgroundParams,background,contrastBackgroundActions);

% Calculate chi squared.
chiSq = chiSquared(shiftedData,reflect,params);

end
