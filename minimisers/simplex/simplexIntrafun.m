function fval = simplexIntrafun(x,problemDef,problemDefCells,problemDefLimits,controls,params)


%problemDef,problemDefCells,problemDefLimits,controls,params,300



% transform variables, then call original function
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemDef.fitpars = xtrans;
problemDef = unpackparams(problemDef,controls);

[problemDef,~] = reflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

fval = problemDef.calculations.sum_chi;