function fval = nsIntraFun(data,p)

    problemStruct = data{1};
    controls = data{2};
    problemCells = data{4};

    % Removed use of cells....
    problemStruct.fitParams = p;

    problemStruct = unpackParams(problemStruct,controls);
    [problemStruct,~] = reflectivityCalculation(problemStruct,problemCells,controls);

    fval = (-problemStruct.calculations.sumChi/2); 
end
