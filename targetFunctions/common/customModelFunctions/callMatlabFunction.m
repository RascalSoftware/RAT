function [output,subRough] = callMatlabFunction(funcName, params, bulkIn, bulkOut, contrast, domainNumber)
% Excecute a custom model function in the base Matlab workspace.

if coder.target('MATLAB')
    % For backwards compatability with Rascal1...
    fileHandle = str2func(funcName);
    if (domainNumber < 1)
        [output,subRough] = fileHandle(params,bulkIn,bulkOut,contrast);
    else
        [output,subRough] = fileHandle(params,bulkIn,bulkOut,contrast,domainNumber);
    end
elseif coder.target('MEX')        
    % 'feval' generates an automatic coder.extrinsic call.
    if (domainNumber < 1)
        [output,subRough] = feval(funcName, params, bulkIn, bulkOut, contrast);
    else
        [output,subRough] = feval(funcName, params, bulkIn, bulkOut, contrast, domainNumber);
    end
else
    % Calling matlab from other languages should be implemented in their wrapper
    subRough = 0;
    output = zeros([0 0]);
    coderException(coderEnums.errorCodes.unknown, 'This is not supported!');
end
