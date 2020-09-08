function [output,sRough] = call_customXY(params,contrast,file,callPath,bulkIn,bulkOut)

[output,layers] = matlabEngineCaller_customXY(params,contrast,file,callPath,bulkIn,bulkOut);
sRough = params(1);

end



