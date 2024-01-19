function ss = reflectivity_fitModel(theta,data,problem)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared

pars = theta;                                % Current parameter values from mcmcstat
problem = data.problem;                   % Struct needed for the calculation
%allProblem = data{1}.problem;
problemStruct = problem{1};
controls = problem{2};
problemLimits = problem{3};
problemCells = problem{4};


problemStruct.fitParams = pars;
problemStruct = unpackParams(problemStruct,controls);
%setappdata(0,'problem',problem);
%problem = reflectivityCalculation(problem);
[problemStruct,result] = reflectivityCalculation(problemStruct,problemCells,controls);

%problem = getappdata(0,'problem');
ss = problemStruct.calculations.sumChi;

end

