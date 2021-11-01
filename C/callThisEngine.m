%

function output = callThisEngine()

    inputDebugVars = load('debugVars.mat');

    debugVars = inputDebugVars.debugVars;

    inputs = debugVars.inputs;

    params = inputs.params;
    contrast = inputs.contrast;
    funcName = inputs.funcName;
    funcPath = 'C:\Users\oba7931403\Documents\GitHub\RAT\C';
    bulkIn = inputs.bulkIn;
    bulkOut = inputs.bulkOut;

    % call the Matlab Class from MatlabEngine.m file
    % make an instance of the MatlabEngine class
    p = MatlabEngine();

    % start the Matlab Engine

    p.startEngine();

    % set the path to the Matlab Engine


    [output,sRough] = p.execute(params, contrast, funcName, funcPath, bulkIn, bulkOut);

    %[output,sRough] = matlabEngineCaller_customLayers(params,contrast,funcName,funcPath,bulkIn,bulkOut);

    disp(output);

    %[output2,sRough2] = matlabEngineCaller_customLayers_mex(params,contrast,funcName,funcPath,bulkIn,bulkOut);

    disp(sRough);

    
end