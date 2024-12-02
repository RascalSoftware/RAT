function ss = reflectivity_fitModel(theta,data,problem)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared

pars = theta;                                % Current parameter values from mcmcstat
problem = data.problem;                   % Struct needed for the calculation
%allProblem = data{1}.problem;
problemStruct = problem{1};
controls = problem{2};

problemStruct.fitParams = pars;
problemStruct = unpackParams(problemStruct,controls.checks);
result = reflectivityCalculation(problemStruct,controls);

ss = result.calculationResults.sumChi;

end
