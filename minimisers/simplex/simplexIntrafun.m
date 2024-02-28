function [fval,result] = simplexIntrafun(x,problemStruct,problemCells,problemLimits,controls,params)

% transform variables, then call original function
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemStruct.fitParams = xtrans;
problemStruct = unpackParams(problemStruct,controls);

result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);

fval = result.calculationResults.sumChi;
end
