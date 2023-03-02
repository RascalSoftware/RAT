function Lik = DREAMWrapper(pars,ratInputs)

% Get the inputs for Reflectivity Calculation

problem = ratInputs.problemDef;
control = ratInputs.controls;
cells = ratInputs.problemDef_cells;
limits = ratInputs.problemDef_limits;

% Put the current parameters into problem
problem.fitpars = pars;

% Distribute them to the right parts
problem = unpackparams(problem,control);

% Calculate....
[outProblem,results] = reflectivityCalculationWrapper(problem,cells,limits,control);

% Function value is chi-squared....
chiSquared = outProblem.calculations.sum_chi;

Lik = exp(-chiSquared/2);

end





