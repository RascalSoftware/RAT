function [problem,result] = reflectivityCalculationTestingWrapper(problemDef,problemDef_cells,problemDef_limits,controls,useCompiled,whichParallel)

% This is a wrapper function for testing 'reflectivityCalculation'. It can
% be made to go down all three calculation types - 'standard layers',
% 'custom layers' or 'custom XY' depending on the four first inputs.
%
% For each calculation type, there are three possible parallelisations -
% single cored, over contrasts (outer loop) or over points (inner loop), 
% so there are 9 possible routes through the calculation in all. The 
% parallelisations are chosen externally to this wrapper by setting the 
% 'parallel' input to either 'single', 'contrasts' or 'points'.
%
% Additionally, it is necessary to check both the compiled (mex) and
% uncompiled (matlab) functions. The results should be the same for each
% calculation type regardless of the parallelisation or compilation chosen.

% 1. Select the parallelisation type - this is done by setting
% controls.para to the value of the 'parallel' input...
controls.para = whichParallel;   % 'contrasts', 'points', 'single'

% 2. Choose whether to use the compiled or uncompiled code. The useComiled
% input is a boolean flag, so just use it directly.
% We also need ro catch any generated errors, so we put the whole thing in
% a try/catch block..


if useCompiled
    [problem,result] = reflectivityCalculation_mex(problemDef,problemDef_cells,problemDef_limits,controls);
else
    [problem,result] = reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
end



end
