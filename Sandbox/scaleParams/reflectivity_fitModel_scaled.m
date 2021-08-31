function ss = reflectivity_fitModel_scaled(theta,data,problem)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared.
% Scaled version so the parameters need to be unscaled before use.
                              
problemDef = problem{1};
controls = problem{2};
problemDef_limits = problem{3};
problemDef_cells = problem{4};

pars = theta;           % Current parameter values from mcmcstat
constr = problemDef.fitconstr;
pars = unscalePars(pars,constr);

problemDef.fitpars = pars;
problemDef = unpackparams(problemDef,controls);
%setappdata(0,'problem',problem);
%problem = reflectivity_calculation(problem);
[problemDef,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

%problem = getappdata(0,'problem');
ss = problemDef.calculations.sum_chi;

end

