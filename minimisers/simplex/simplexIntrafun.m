function [fval,problemStruct,result] = simplexIntrafun(x,problemStruct,problemCells,controls,params)

% transform variables, then call original function
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemStruct.fitParams = xtrans;
problemStruct = unpackParams(problemStruct,controls);

[problemStruct,result] = reflectivityCalculation(problemStruct,problemCells,controls);

fval = problemStruct.calculations.sumChi;
end
