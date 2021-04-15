function [output,sRough] = call_customLayers(params,contrast,file,callPath,bulkIn,bulkOut)

[output,layers] = matlabEngineCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);
sRough = params(1);

end



