function asd()
%CALLCLASS  Constructor for the class handle.

    
    inputDebugVars = load('debugVars.mat');

    debugVars = inputDebugVars.debugVars;

    inputs = debugVars.inputs;

    params = inputs.params;
    contrast = inputs.contrast;
    funcName = inputs.funcName;
    funcPath = 'C:\Users\oba7931403\Documents\GitHub\RAT\Sandbox';
    bulkIn = inputs.bulkIn;
    bulkOut = inputs.bulkOut;

    p = MatlabEngine();

    %     p.startEngine();
    p.startEngine();
    [output,sRough]=p.execute(params,contrast,funcName,funcPath,bulkIn,bulkOut);

    % wait for 10 seconds
    
    p.closeEngine();
    
    


    %[output,sRough] = matlabEngineCaller_customLayers(params,contrast,funcName,funcPath,bulkIn,bulkOut);

    disp(output);

    %[output2,sRough2] = matlabEngineCaller_customLayers_mex(params,contrast,funcName,funcPath,bulkIn,bulkOut);

    disp(sRough);
end
