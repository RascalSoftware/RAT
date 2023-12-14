function Lik = DREAMWrapper(pars,ratInputs)

% Get the inputs for Reflectivity Calculation

problem = ratInputs.problemDef;
control = ratInputs.controls;
cells = ratInputs.problemDefCells;

% Put the current parameters into problem
problem.fitParams = pars;

% Distribute them to the right parts
problem = unpackParams(problem,control);

% Calculate....
[outProblem,~] = reflectivityCalculation(problem,cells,control);

% Function value is chi-squared....
chiSquared = outProblem.calculations.sumChi;

Lik = -chiSquared/2;

end
