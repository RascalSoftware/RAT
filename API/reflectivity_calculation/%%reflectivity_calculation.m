function [problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls)


% This is just a wrapper function to allow calling the 
%mex version of reflectivity calculation. The actual
% 'reflectivity_calculation' is '%reflectivity_calculation'


[problem,result] = reflectivity_calculation_mex(problemDef,problemDef_cells,problemDef_limits,controls);





end
