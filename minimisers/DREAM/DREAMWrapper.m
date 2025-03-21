function Lik = DREAMWrapper(pars,ratInputs)
% Calculate the log-likelihood for a set of parameters.
%
% Parameters
% ----------
% pars : vector
%     The current parameter values.
% ratInputs : struct
%     The problem and controls to calculate log-likelihood from.
%
% Returns
% -------
% Lik : float
%     The (natural) log-likelihood value for the given parameter values.
%

% Get the inputs for Reflectivity Calculation
problemStruct = ratInputs.problemStruct;
controls = ratInputs.controls;

% Put the current parameters into problem
problemStruct.fitParams = pars;

% Distribute them to the right parts
problemStruct = unpackParams(problemStruct);

% Calculate....
result = reflectivityCalculation(problemStruct,controls);

% Function value is chi-squared....
chiSquared = result.calculationResults.sumChi;

Lik = -chiSquared/2;

end
