function [output,sRough] = call_customLayers(params,contrast,thisCustomFile,bulkIn,bulkOut)

% Call a custom layers function
% This function calls a custom model, which can be in Matlab, Python or
% Octave. The custom function is called 'custom layers', but the same
% routines are required for layers or XY, so the same function is used.
% For Matlab, the gererated C++ passes excecution back to the base Matlab
% workspace. For Octave, an embedded Octave interpreter is used. An
% embedded interpreter is also used for Python.


% TODO: Add the Octave and Python functionality.


% Split up the custom file array into name, language and path...
fName = thisCustomFile{1};
lang = thisCustomFile{2};
path = thisCustomFile{3};

% Call the relevant routines depending on the language required
% switch lang
%     case 'matlab'
        [output,sRough] = callMatlabCustomLayers(params,contrast,fName,path,bulkIn,bulkOut);
    %case 'octave'
    %    [output,layers] = octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
    %case 'python'
    %    [output,layers] = pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
%end

end



