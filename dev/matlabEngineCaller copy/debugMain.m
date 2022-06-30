inputDebugVars = load('debugVars.mat');

debugVars = inputDebugVars.debugVars;

inputs = debugVars.inputs;

params = inputs.params;
contrast = inputs.contrast;
funcName = inputs.funcName;
funcPath = inputs.funcPath;
bulkIn = inputs.bulkIn;
bulkOut = inputs.bulkOut;

[output,sRough] = matlabEngineCaller_customLayers(params,contrast,funcName,funcPath,bulkIn,bulkOut);

disp(output);

% [output2,sRough2] = matlabEngineCaller_customLayers_mex(params,contrast,funcName,funcPath,bulkIn,bulkOut);
% 
% disp(output2);
