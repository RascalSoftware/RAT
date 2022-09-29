function [problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls)


% Overloaded wrapper function for compile (i.e. we can't have the 'mex' 
% call in here of the compiler complains.

[problem,result] = reflectivity_calculation_mex(problemDef,problemDef_cells,problemDef_limits,controls);

end
