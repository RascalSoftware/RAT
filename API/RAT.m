function [project,result] = RAT(project,controls)
% Runs RAT calculation for the given project and controls inputs.
%
% Parameters
% ----------
% project : projectClass
%    An instance of the ``projectClass``.
% controls : controlsClass
%    An instance of the ``controlsClass``.   
%
% Returns
% -------
% project : projectClass
%    An instance of the ``projectClass`` with updated fit values from the calculation.
% result : struct
%    The results of the calculation such as simulated reflectivities, SLD profiles etc.
%
% Notes
% -----
% For a non-Bayesian procedure, the result struct has the following fields below where nDomains, 
% nContrasts and nParams are the the number of domains, contrasts and params respectively  
%  
% ================== ============================ ===============
% Field              Type                         Description
% ================== ============================ ===============
% reflectivity       [nContrasts x 1] cell        calculated reflectivity values
% simulation         [nContrasts x 1] cell        simulated reflectivity values
% shiftedData        [nContrasts x 1] cell        Data shifted using given scale factor
% backgrounds        [nContrasts x 1] cell        background values for each contrast
% resolutions        [nContrasts x 1] cell        resolution values for each contrast 
% layerSlds          [nContrasts x nDomains] cell layers parameter values for each contrast
% sldProfiles        [nContrasts x nDomains] cell SLD profiles
% resampledLayers    [nContrasts x nDomains] cell resampled layer values for each contrast 
%                                                 if resample is true otherwise an array of zeros
% calculationResults [1 x 1] struct               Chi-squared goodness of fit results. The fields 
%                                                 are ``chiValues`` and ``sumChi``  
% contrastParams     [1 x 1] struct               Parameter values for each contrast. The fields are 
%                                                 ``scalefactors``, ``bulkIn``, ``bulkOut``, ``subRoughs``, 
%                                                 and ``resample``
% fitParams          [1 x nParams] double         fitted parameter values
% fitNames           [nParams x 1] cell           name of fitted parameters
% ================== ============================ ===============
%
% For a Bayesian procedure, the result struct will also contain the following fields in 
% addition to the ones above  
%  
% =================== ==================== ===============
% Field               Type                 Description
% =================== ==================== ===============
% predictionIntervals [1 x 1] struct       Mean, 65% and 95% confidence intervals, and chi squared 
%                                          goodness of fit values for the reflectivity and SLD. The fields 
%                                          are ``reflectivity``, ``sld``, and ``sampleChi``
% confidenceIntervals [1 x 1] struct       Confidence intervals for the Markov chain. The fields are 
%                                          ``percentile95``, ``percentile65``, and ``mean``.
% dreamParams         [1 x 1] struct       Parameters used to configure dream. 
% dreamOutput         [1 x 1] struct       Diagnostic output information from a DREAM run. The fields 
%                                          are ``allChains``, ``outlierChains``, ``runtime``, 
%                                          ``iteration``, ``modelOutput``, ``AR``, ``R_stat``, and ``CR``
% nestedSamplerOutput [1 x 1] struct       Output from a nested sampler run. The fields are ``LogZ``, 
%                                          ``LogZErr``, ``nestSamples``, and ``postSamples``
% chain               [M x nParams] double MCMC chains where M is the length of each chain
% =================== ==================== ===============

[problemStruct,problemLimits,controls] = parseClassToStructs(project,controls);

% Set controls.calcSLD to 1 if we are doing customXY
switch lower(problemStruct.modelType)
    case modelTypes.CustomXY.value
        controls.calcSldDuringFit = true;
end

% Call the main RAT routine...
display = ~strcmpi(controls.display, displayOptions.Off.value);
textProgressBar(0, 0, display);
% If display is not silent print a line confirming RAT is starting
if display
    fprintf('Starting RAT ________________________________________________________________________________________________\n\n');
end

tic
[problemStruct,result,bayesResults] = RATMain_mex(problemStruct,problemLimits,controls);

if display
    toc
end
textProgressBar(0, 0, true);
if any(strcmpi(controls.procedure, {procedures.NS.value, procedures.Dream.value}))
    result = mergeStructs(result, bayesResults);
end

project = parseOutToProjectClass(project,problemStruct);

if ~strcmpi(controls.display, displayOptions.Off.value)
   fprintf('\nFinished RAT ______________________________________________________________________________________________ \n\n');
end

end
