function fval = nsIntraFun(data,p)

    problemDef = data{1};
    controls = data{2};
    problemDefCells = data{4};

    % Removed use of cells....
    problemDef.fitpars = p;

    problemDef = unpackParams(problemDef,controls);
    [problemDef,~] = reflectivityCalculation(problemDef,problemDefCells,controls);

    fval = (-problemDef.calculations.sumChi/2); 
end
