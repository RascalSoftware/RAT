function [fval,result] = simplexIntrafun(x,problemStruct,controls,params)

% transform variables, then call original function
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemStruct.fitParams = xtrans;
problemStruct = unpackParams(problemStruct);

result = reflectivityCalculation(problemStruct,controls);

fval = result.calculationResults.sumChi;
end
