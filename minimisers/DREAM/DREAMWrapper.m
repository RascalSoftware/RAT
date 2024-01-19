function Lik = DREAMWrapper(pars,ratInputs)

% Get the inputs for Reflectivity Calculation

problemDefStruct = ratInputs.problemDefStruct;
control = ratInputs.controls;
cells = ratInputs.problemDefCells;

% Put the current parameters into problem
problemDefStruct.fitParams = pars;

% Distribute them to the right parts
problemDefStruct = unpackParams(problemDefStruct,control);

% Calculate....
[contrastParams,~] = reflectivityCalculation(problemDefStruct,cells,control);

% Function value is chi-squared....
chiSquared = contrastParams.calculations.sumChi;

Lik = -chiSquared/2;

end
