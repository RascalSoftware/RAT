function ss = reflectivity_fitModel_scaled(theta,data,problem)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared.
% Scaled version so the parameters need to be unscaled before use.
                              
problemDefStruct = problem{1};
controls = problem{2};
problemDefLimits = problem{3};
problemDefCells = problem{4};

pars = theta;           % Current parameter values from mcmcstat
constr = problemDefStruct.fitLimits;
pars = unscalePars(pars,constr);

problemDefStruct.fitParams = pars;
problemDefStruct = unpackParams(problemDefStruct,controls);
%setappdata(0,'problem',problem);
%problem = reflectivityCalculation(problem);
[problemDefStruct,result] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);

%problem = getappdata(0,'problem');
ss = problemDefStruct.calculations.sumChi;

end

