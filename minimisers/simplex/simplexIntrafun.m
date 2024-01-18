function [fval,problemDefStruct,result] = simplexIntrafun(x,problemDefStruct,problemDefCells,controls,params)

% transform variables, then call original function
xtrans = simplexXTransform(x,params);

%Unpck the params..
problemDefStruct.fitParams = xtrans;
problemDefStruct = unpackParams(problemDefStruct,controls);

[problemDefStruct,result] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);

fval = problemDefStruct.calculations.sumChi;
end
