function [output,sRough] = pythonCustomFunctionWrapper(funcName,params,bulkIn,bulkOut,contrast,nContrasts)

% Excecute a python custom model function in the base Matlab workspace.

% This function uses feval to cause Matlab coder to execute
% 'callPythonFunction' in the base Matlab workspace.
% 'feval' generates an automatic coder.extrinsic call...

if coder.target('MATLAB')
    
    [output,sRough] = callPythonFunction(funcName,params,bulkIn,bulkOut,contrast);
    
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
    
    [tempOut,tempRough] = feval('callPythonFunction',funcName,params,bulkIn,bulkOut,contrast);
    
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