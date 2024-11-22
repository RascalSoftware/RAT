function fval = nsIntraFun(data,p)

    problemStruct = data{1};
    controls = data{2};
    problemLimits = data{3};
    problemCells = data{4};

    % Removed use of cells....
    problemStruct.fitParams = p;

    problemStruct = unpackParams(problemStruct,controls.checks);
    result = reflectivityCalculation(problemStruct,problemCells,problemLimits,controls);

    fval = (-result.calculationResults.sumChi/2); 
end
