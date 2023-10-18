function [problem,result] = reflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls)


% Overloaded wrapper function for compile (i.e. we can't have the 'mex' 
% call in here of the compiler complains.

[problem,result] = reflectivityCalculation_mex(problemDef,problemDefCells,problemDefLimits,controls);

end
