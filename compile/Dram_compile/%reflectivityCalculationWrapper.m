function [problem,result] = reflectivityCalculationWrapper(problemDef,problemDef_cells,problemDef_limits,controls)


% Overloaded wrapper function for compile (i.e. we can't have the 'mex' 
% call in here of the compiler complains.

[problem,result] = reflectivityCalculation_mex(problemDef,problemDef_cells,problemDef_limits,controls);

end
