function [sldProfile,reflect,Simul,shifted_dat,theseLayers,resamLayers,chiSq,ssubs] = ...
    standardTF_layers_core(contrastLayers, rough, ...
    geometry, nba, nbs, resample, calcSld, sf, qshift,...
    dataPresent, data, dataLimits, simLimits, repeatLayers,...
    background,resol,backsType,params,paralellPoints,resamPars)

%   This is the main reflectivity calculation for all Layers models in the 
%   standard target function. 
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
%   nba             :
%   nbs             :
%   resample        :
%   calcSld         :
%   sf              :
%   qshift          :
%   dataPresent     :
%   data            :
%   dataLimits      :
%   simLimits       :
%   repeatLayers    :
%   background      :
%   resol           :
%   backsType       :
%   params          :
%   paralellPoints  :
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

% Bulid up the layers matrix for this contrast
[theseLayers, ssubs] = groupLayers_Mod(contrastLayers,rough,geometry,nba,nbs);

% Make the SLD profiles.
% If resampling is needed, then enforce the calcSLD flag, so as to catch
% the error af trying to resample a non-existent profile.
if (resample == 1 && calcSld == 0)
    calcSld = 1;
end

% If calc SLD flag is set, then calculate the SLD profile
if calcSld == 1
    sldProfile = makeSLDProfiles(nba,nbs,theseLayers,ssubs,repeatLayers);
else
    sldProfile = [0 0];
end

% If required, then resample the SLD
if resample == 1
    layerSld = resampleLayers(sldProfile,resamPars);
    resamLayers = layerSld;
else
    layerSld = theseLayers;
    resamLayers = [0 0 0];
end

% Apply scale factors and q shifts to the data
shifted_dat = shiftdata(sf,qshift,dataPresent,data,dataLimits,simLimits);

% Calculate the reflectivity
reflectivityType = 'standardAbeles_realOnly';
[reflect,Simul] = callReflectivity(nba,nbs,simLimits,repeatLayers,shifted_dat,layerSld,ssubs,resol,paralellPoints,reflectivityType);

% Apply background correction, either to the simulation or the data
[reflect,Simul,shifted_dat] = applyBackgroundCorrection(reflect,Simul,shifted_dat,background,backsType);

% Calculate chi squared.
chiSq = chiSquared(shifted_dat,reflect,params);

end