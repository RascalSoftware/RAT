function [output,sRough] = call_customLayers(params,contrast,thisCustomFile,bulkIn,bulkOut)

% Split up the custom file array
fName = thisCustomFile{1};
lang = thisCustomFile{2};
path = thisCustomFile{3};

% switch lang
%     case 'matlab'
        [output,sRough] = callMatlabCustomLayers(params,contrast,fName,path,bulkIn,bulkOut);
    %case 'octave'
    %    [output,layers] = octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
    %case 'python'
    %    [output,layers] = pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
%end

end



