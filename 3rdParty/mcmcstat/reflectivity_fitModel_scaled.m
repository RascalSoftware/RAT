function ss = reflectivity_fitModel_scaled(theta,data,problem)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared.
% Scaled version so the parameters need to be unscaled before use.
                              
problemStruct = problem{1};
controls = problem{2};
problemLimits = problem{3};
problemCells = problem{4};

pars = theta;           % Current parameter values from mcmcstat
constr = problemStruct.fitLimits;
pars = unscalePars(pars,constr);

problemStruct.fitParams = pars;
problemStruct = unpackParams(problemStruct,controls);

[contrastParams,~] = reflectivityCalculation(problemStruct,problemCells,controls);

ss = contrastParams.calculations.sumChi;

end
