function [output,sRough] = callMatlabCustomFunction(params, contrast, funcName, bulkIn, bulkOut, nContrasts, domainNumber)
% Excecute a custom model function in the base Matlab workspace.

if coder.target('MATLAB')
    % For backwards compatability with Rascal1...
    bulkOuts = zeros(nContrasts,1);
    bulkOuts(contrast) = bulkOut;

    fileHandle = str2func(funcName);
    if (domainNumber < 1)
        [output,sRough] = fileHandle(params,bulkIn,bulkOuts,contrast);
    else
        [output,sRough] = fileHandle(params,bulkIn,bulkOuts,contrast,domainNumber);
    end
elseif coder.target('MEX')    
    bulkOuts = zeros(nContrasts,1);
    bulkOuts(contrast) = bulkOut;
    
    % 'feval' generates an automatic coder.extrinsic call.
    if (domainNumber < 1)
        [output,sRough] = feval(funcName, params, bulkIn, bulkOuts, contrast);
    else
        [output,sRough] = feval(funcName, params, bulkIn, bulkOuts, contrast, domainNumber);
    end
else
    % Calling matlab from other languages should be implemented in their wrapper
    sRough = 0;
    output = zeros([0 0]);
    error("This is not supported!");
end