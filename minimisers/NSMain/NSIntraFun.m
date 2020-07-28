function fval = NSIntraFun(data,problrmDef_cells,parNames,p)


%data = {problemDef ; controls ; problemDef_limits ; problemDef_cells};
%

problemDef = data{1};
controls = data{2};
problemDef_limits = data{3};
problemDef_cells = data{4};

problemDef.fitpars = cell2mat(p);

problemDef = unpackparams(problemDef,controls);
[problemDef,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

fval = (-problemDef.calculations.sum_chi/2); %old way....
%fval = -log(exp(-problemDef.calculations.sum_chi/2));


end