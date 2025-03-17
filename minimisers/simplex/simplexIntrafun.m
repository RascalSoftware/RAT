function [fval,result] = simplexIntrafun(x,problemStruct,controls,params)
% Produce a chi-squared fit value at a point for a given problem and controls.
%
% Used as the objective function for Nelder-Mead simplex.
%
% Parameters
% ----------
% x : vector
%     The point to evaluate.
% problemStruct : struct
%     The problem struct for calculation.
% controls : struct
%     The controls struct for the calculation.
% params : struct
%     A struct containing parameter fit information.
%
% Returns
% -------
% fval : float
%     The chi-squared value at ``x``.
% result : struct
%     The result struct from the reflectivity calculation.

% transform variables, then call original function
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemStruct.fitParams = xtrans';
problemStruct = unpackParams(problemStruct);

result = reflectivityCalculation(problemStruct,controls);

fval = result.calculationResults.sumChi;
end
