function fval = nsIntraFun(data,p)

    problemDefStruct = data{1};
    controls = data{2};
    problemDefCells = data{4};

    % Removed use of cells....
    problemDefStruct.fitParams = p;

    problemDefStruct = unpackParams(problemDefStruct,controls);
    [problemDefStruct,~] = reflectivityCalculation(problemDefStruct,problemDefCells,controls);

    fval = (-problemDefStruct.calculations.sumChi/2); 
end
