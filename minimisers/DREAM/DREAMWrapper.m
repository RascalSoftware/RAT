function Lik = DREAMWrapper(pars,ratInputs)

% Get the inputs for Reflectivity Calculation

problemStruct = ratInputs.problemStruct;
control = ratInputs.controls;
cells = ratInputs.problemCells;
limits = ratInputs.problemLimits;

% Put the current parameters into problem
problemStruct.fitParams = pars;

% Distribute them to the right parts
problemStruct = unpackParams(problemStruct,control);

% Calculate....
result = reflectivityCalculation(problemStruct,cells,limits,control);

% Function value is chi-squared....
chiSquared = result.calculationResults.sumChi;

Lik = -chiSquared/2;

end
