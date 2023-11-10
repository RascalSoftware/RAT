function [fitPars,fitNames,fitConstr] = getFitValues(inputProblem,controls)

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(inputProblem,controls);

[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);

fitPars = problemDef.fitpars;
fitConstr = problemDef.fitconstr;


end