function fval = tempDEIntrafun(x,problemDef,problemDef_cells,controls)


%Unpck the params..
problemDef.fitpars = x;
problemDef = unpackparams(problemDef,controls);

problemDef = unpackparams(problemDef,controls);
[outProblem,result] = RAT(problemDef,controls);

fval = outProblem.calculations.sum_chi;