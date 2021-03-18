function [problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls)


% This is just a wrapper function for choosing between
% the Matlab and Mex version of reflectivity_calculation.
% This is for development and will be removed for the 
% eventual fully compiled toolbox

type = 'matlab';

 switch type
     case 'mex'
        [problem,result] = reflectivity_calculation_mex(problemDef,problemDef_cells,problemDef_limits,controls);
     otherwise
        [problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);
end

end