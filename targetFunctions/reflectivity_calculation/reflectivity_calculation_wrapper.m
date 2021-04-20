function [problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls)


% This is just a wrapper function for choosing between
% the Matlab and Mex version of reflectivity_calculation.
% This is for development and will be removed for the 
% eventual fully compiled toolbox

% The outputs are as follows..
% problem.ssubs         = [nContrasts x 1 double]
% problem.backgrounds   = [nContrasts x 1 double]
% problem.qshifts       = [nContrasts x 1 double]
% problem.scalefactots  = [nContrasts x 1 double]
% problem.nbairs        = [nContrasts x 1 double]
% problem.nbsubs        = [nContrasts x 1 double]
% problem.resolutions   = [nContrasts x 1 double]
% problem.allSubRough   = [nContrasts x 1 double] - Appears to be the same
%                                                   as ssubs and needs to be removed
% problem.calculations.all_chis = [nContrasts x 1 double]
% problem.calculations.sum_chi  = [1 x 1 double];

% result{1} = reflectivity{}
% result{2} = simulations{}
% result{3} = shifted_data{}
% result{4} = layerSlds{}
% result{5} = sldProfiles{}
% result{6} = currently empty - will be allLayers (i.e. resampled)

type = 'mex';

 switch type
     case 'mex'
        [problem,result] = reflectivity_calculation_mex(problemDef,problemDef_cells,problemDef_limits,controls);
     otherwise
        [problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);
end

end