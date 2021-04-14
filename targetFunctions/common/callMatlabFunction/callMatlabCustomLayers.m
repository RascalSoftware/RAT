function [output,sRough] = callMatlabCustomLayers(params,contrast,funcName,path,bulkIn,bulkOut)

persistent fileHandle


if coder.target('MATLAB')

    if isempty(fileHandle)
        
        dotM = strfind(funcName,'.m');
        if ~isempty(dotM)
            funcName = funcName(1:dotM-1);
        end
        
        fullFunc = [path funcName];
        fileHandle = str2func(fullFunc);
    end
    [output,sRough] = fileHandle(params,bulkIn,bulkOut,contrast);
else

    % Use a coder.extrinsic call here.







end