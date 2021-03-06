function [output,sRough] = call_customLayers(params,contrast,file,callPath,bulkIn,bulkOut,lang)


%switch lang
%    case 'matlab'
        [output,layers] = matlabEngineCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
        sRough = params(1);
    %case 'octave'
    %    [output,layers] = octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
    %case 'python'
    %    [output,layers] = pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
%end


end



