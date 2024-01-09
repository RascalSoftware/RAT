function [fval, problemDef,result] = simplexIntrafun(x,problemDef,problemDefCells,controls,params)

% transform variables, then call original function
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemDef.fitParams = xtrans;
problemDef = unpackParams(problemDef,controls);

[problemDef,result] = reflectivityCalculation(problemDef,problemDefCells,controls);

fval = problemDef.calculations.sumChi;
end
