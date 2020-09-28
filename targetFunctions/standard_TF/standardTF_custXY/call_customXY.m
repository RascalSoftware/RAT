function [output,sRough] = call_customXY(params,contrast,file,callPath,bulkIn,bulkOut)

[out,layers] = matlabEngineCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut);

points = size(out,1);
output = zeros(points,2);   

if size(out,2) == 3
    output = out(:,1:2);
else
    output = out;
end

sRough = params(1);

end



