function ss = reflectivity_fitModel(theta,data,problem)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared

pars = theta;                                % Current parameter values from mcmcstat
problem = data.problem;                   % Struct needed for the calculation
%allProblem = data{1}.problem;
problemDef = problem{1};
controls = problem{2};
problemDef_limits = problem{3};
problemDef_cells = problem{4};


problemDef.fitpars = pars;
problemDef = unpackparams(problemDef,controls);
%setappdata(0,'problem',problem);
%problem = reflectivityCalculation(problem);
[problemDef,result] = reflectivityCalculationWrapper(problemDef,problemDef_cells,problemDef_limits,controls);

%problem = getappdata(0,'problem');
ss = problemDef.calculations.sum_chi;

end

