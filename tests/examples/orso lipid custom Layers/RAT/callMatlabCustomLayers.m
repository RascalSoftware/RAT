function [output,sRough] = callMatlabCustomLayers(params,contrast,funcName,path,bulkIn,bulkOut);

persistent fileHandle


if coder.target('MATLAB')

    % Set the path and function handle on first run through
    if isempty(fileHandle)
        
        dotM = strfind(funcName,'.m');
        if ~isempty(dotM)
            funcName = funcName(1:dotM-1);
        end
        
        % Need to add the path of the function to the Matlab path
        addpath(path);
        
        fileHandle = str2func(funcName);
    end
    
    % Call the custom function 
    [output,sRough] = fileHandle(params,bulkIn,bulkOut,contrast);
else

    % Use a coder.extrinsic call here.







end