function ss = reflectivity_fitModel(theta,data,problem)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared

pars = theta;                                % Current parameter values from mcmcstat
problem = data.problem;                   % Struct needed for the calculation
%allProblem = data{1}.problem;
problemDefStruct = problem{1};
controls = problem{2};
problemDefLimits = problem{3};
problemDefCells = problem{4};


problemDefStruct.fitParams = pars;
problemDefStruct = unpackParams(problemDefStruct,controls);
%setappdata(0,'problem',problem);
%problem = reflectivityCalculation(problem);
[problemDefStruct,result] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);

%problem = getappdata(0,'problem');
ss = problemDefStruct.calculations.sumChi;

end

