function fval = nsIntraFun(data,p)

    problemStruct = data{1};
    controls = data{2};

    % Removed use of cells....
    problemStruct.fitParams = p;

    problemStruct = unpackParams(problemStruct,controls.checks);
    result = reflectivityCalculation(problemStruct,controls);

    fval = (-result.calculationResults.sumChi/2); 
end
