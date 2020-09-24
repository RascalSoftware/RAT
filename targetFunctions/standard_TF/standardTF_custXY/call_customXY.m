function [output,sRough] = call_customXY(params,contrast,file,callPath,bulkIn,bulkOut)

[output,layers] = matlabEngineCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);

if size(output) == 3
    output = output(:,1:2);
end

sRough = params(1);

end



