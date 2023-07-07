function [output,sRough] = callMatlabCustomFunctionDomains(params,contrast,funcName,path,bulkIn,bulkOut,nContrasts,domainNumber)

% Excecute a custom model function in the base Matlab workspace.

% This function uses feval to cause Matlab coder to pass excecution
% of the function named in 'fname' back to the base Matlab workspace,
% 'feval' generates an automatic coder.extrinsic call.

if coder.target('MATLAB')
    
    % For backwards compatability with Rascal1...
    bulkOuts = zeros(nContrasts,1);
    bulkOuts(contrast) = bulkOut;

    fileHandle = str2func(funcName);
    [output,sRough] = fileHandle(params,bulkIn,bulkOuts,contrast,domainNumber);
    
else
    
    % Use a coder.extrinsic call here, so Coder will 
    % pass the excecution of the function back to the calling Matlab 
    % session. There is no need to explicitly declare the extrinsic
    % as Coder automatically does this when it encounters 'feval'
    % https://uk.mathworks.com/help/simulink/ug/use-matlab-engine-to-execute-a-function-call-in-generated-code.html
    
    % Pre-define the outputs to keep the compiler happy
    % Need to define the size of the outputs with coder preprocessor
    % directives
    sRough = 3;
    coder.varsize('output');        % This maybe should be a 'coder.typeof' instead?

    % Because it is feval, coder sends this call to
    % the base Matlab workspace. The outputs of feval are mxArrays, 
    % so we need to do some work afterwards casting these to doubles (below)
    
    % For backwards compatability with Rascal1...
    bulkOuts = zeros(nContrasts,1);
    bulkOuts(contrast) = bulkOut;
    
    % Feval is automatic call to base Matlab workspace....
    [tempOut,tempRough] = feval(funcName,params,bulkIn,bulkOuts,contrast,domainNumber);
    
    % Tell coder n is doubles by defining it (otherwise 'size(n)' seems to return
    % [mxArray mxArray] not [double double]!), fill n with the size of the mxArray
    % 'tempOut', and use n to allocate the correct number of elements to 'output'
    % by filling output with zeros (i.e. output is an array of doubles)
    n = [0 0];
    n = size(tempOut);
    output = zeros(n);

    % Copy the mxArrays to our doubles arrays, which then makes coder cast
    % the mxArrays to double.
    sRough = tempRough;
    output = tempOut;

end