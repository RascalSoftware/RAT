function Lik = DREAMWrapper(pars,ratInputs)

% Get the inputs for Reflectivity Calculation

problem = ratInputs.problemDef;
control = ratInputs.controls;
cells = ratInputs.problemDefCells;

% Put the current parameters into problem
problem.fitpars = pars;

% Distribute them to the right parts
problem = unpackparams(problem,control);

% Calculate....
[outProblem,~] = reflectivityCalculation(problem,cells,control);

% Function value is chi-squared....
chiSquared = outProblem.calculations.sum_chi;

Lik = -chiSquared/2;

end
