function fval = simplexIntrafun(x,problemDef,problemDef_cells,problemDef_limits,controls,params,maxEval)


%problemDef,problemDef_cells,problemDef_limits,controls,params,300



% transform variables, then call original function
a = 'debug';
% transform
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemDef.fitpars = xtrans;
problemDef = unpackparams(problemDef,controls);

[problemDef,result] = reflectivityCalculationWrapper(problemDef,problemDef_cells,problemDef_limits,controls);

fval = problemDef.calculations.sum_chi;