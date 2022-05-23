function [problem,result] = singleCalculation(problemDef,problemDef_cells,problemDef_limits,controls)

%Just call the reflectivity calculation.
%Any additional argument checking etc will go in here...
[problem,result]  = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

end
