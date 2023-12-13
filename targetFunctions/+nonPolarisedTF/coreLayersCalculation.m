function [sldProfile,reflect,simulation,shiftedData,theseLayers,resamLayers,chiSq,ssubs] = ...
    coreLayersCalculation(contrastLayers, rough, ...
    geometry, bulkIn, bulkOut, resample, calcSld, scalefactor, qzshift,...
    dataPresent, data, dataLimits, simLimits, repeatLayers,...
    background,resolution,contrastBackgroundsType,params,parallelPoints,resamPars,useImaginary)

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
%   'Simulation' which can be a different range to allow extrapolation.
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
%   contrastBackgroundsType       :
%   params          :
%   parallelPoints  :
%
% Outputs:
%
%
%
% ------------------------------------------------------------------------
%
%       (c) Arwel Hughes  -   12/1/21
%
%       Last Modified: 12/1/21 by Arwel Hughes.
%
% ------------------------------------------------------------------------

% Pre-definition for Coder
thisSldLaysIm = [0 0];
sldProfileIm = [0 0];
coder.varsize('thisSldLays',[10000 3],[1 1]);
coder.varsize('thisSldLaysIm',[10000 3],[1 1]);
coder.varsize('sldProfile',[10000 3],[1 1]);
coder.varsize('sldProfileIm',[10000 3],[1 1]);

% Bulid up the layers matrix for this contrast
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
    end
    
    sldProfile = makeSLDProfiles(bulkIn,bulkOut,thisSldLays,ssubs,repeatLayers);

    % If we have imaginary, we are also
    % going to need an SLD profile for the imaginary part
    if useImaginary
        % Note bulkIn and bulkOut = 0 since there is never any imaginary part for
        % the bulk phases..
        sldProfileIm = makeSLDProfiles(0,0,thisSldLaysIm,ssubs,repeatLayers);
    end

else
    sldProfile = [0 0];
end

% If required, then resample the SLD
if resample == 1
    if ~useImaginary
        layerSld = resampleLayers(sldProfile,resamPars);
    else
        layerSld = resampleLayersReIm(sldProfile,sldProfileIm,resamPars);
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

% Apply background correction, either to the simulation or the data
[reflect,simulation,shiftedData] = applyBackgroundCorrection(reflect,simulation,shiftedData,background,contrastBackgroundsType);

% Calculate chi squared.
chiSq = chiSquared(shiftedData,reflect,params);

end
