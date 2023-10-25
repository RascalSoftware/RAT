function fval = NSIntraFun(data,p)


%data = {problemDef ; controls ; problemDefLimits ; problemDefCells};
%

problemDef = data{1};
controls = data{2};
problemDefLimits = data{3};
problemDefCells = data{4};

%problemDef.fitpars = cell2mat(p);
%problemDef.fitpars = [p{:}];

% Removed use of cells....
problemDef.fitpars = p;

problemDef = unpackparams(problemDef,controls);
[problemDef,result] = reflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);

fval = (-problemDef.calculations.sum_chi/2); %old way....
%fval = -log(exp(-problemDef.calculations.sum_chi/2));


end