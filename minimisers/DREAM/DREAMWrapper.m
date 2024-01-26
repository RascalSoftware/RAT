function Lik = DREAMWrapper(pars,ratInputs)

% Get the inputs for Reflectivity Calculation

problemStruct = ratInputs.problemStruct;
control = ratInputs.controls;
cells = ratInputs.problemCells;

% Put the current parameters into problem
problemStruct.fitParams = pars;

% Distribute them to the right parts
problemStruct = unpackParams(problemStruct,control);

% Calculate....
[contrastParams,~] = reflectivityCalculation(problemStruct,cells,control);

% Function value is chi-squared....
chiSquared = contrastParams.calculations.sumChi;

Lik = -chiSquared/2;

end
