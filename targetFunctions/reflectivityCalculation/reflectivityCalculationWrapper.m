function [problem,result] = reflectivityCalculationWrapper(problemDef,problemDef_cells,problemDef_limits,controls)

% Dummy reflectivityCalculationWrapper for compiles

% This is just a wrapper function for choosing between
% the Matlab and Mex version of reflectivityCalculation.
% This is for development and will be removed for the 
% eventual fully compiled toolbox

type = 'mex';

 switch type
     case 'mex'
        [problem,result] = reflectivityCalculation_mex(problemDef,problemDef_cells,problemDef_limits,controls);
     otherwise
        [problem,result] = reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
end