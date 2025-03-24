function fval = nsIntraFun(data,p)
% Calculate the log-likelihood of a data point during nested sampling.
% 
% Parameters
% ----------
% data : array
%     The problem struct and controls.
% p : array
%     The point in parameter space to calculate likelihood for.

    problemStruct = data{1};
    controls = data{2};

    % Removed use of cells....
    problemStruct.fitParams = p;

    problemStruct = unpackParams(problemStruct);
    result = reflectivityCalculation(problemStruct,controls);

    fval = (-result.calculationResults.sumChi/2);
    
end
