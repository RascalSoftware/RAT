function [fval,result] = simplexIntrafun(x,problemStruct,problemLimits,controls,params)

% transform variables, then call original function
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemStruct.fitParams = xtrans;
problemStruct = unpackParams(problemStruct,controls.checks);

result = reflectivityCalculation(problemStruct,problemLimits,controls);

fval = result.calculationResults.sumChi;
end
