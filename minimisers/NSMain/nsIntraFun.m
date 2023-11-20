function fval = nsIntraFun(data,p)

    problemDef = data{1};
    controls = data{2};
    problemDefLimits = data{3};
    problemDefCells = data{4};

    % Removed use of cells....
    problemDef.fitpars = p;

    problemDef = unpackparams(problemDef,controls);
    [problemDef,result] = reflectivityCalculation(problemDef,problemDefCells,controls);

    fval = (-problemDef.calculations.sum_chi/2); 
end
