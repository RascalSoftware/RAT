function     thisContrastLayers = allocateLayersForContrast(contrastLayers,outParameterisedLayers,useImaginary)
% Decide which layers are needed for a particular contrast.
% This function takes the master array of all layers
% and extracts which parameters are required for 
% a particular contrast. 
%
% INPUTS:
%     outParameterisedLayers - List of all the available layers
%     thisContrastLayers     - Array detailing which layers are required for this contrast

coder.varsize('thisContrastLayers',[1000 6],[1 1]);

if useImaginary
    thisContrastLayers = zeros(length(contrastLayers),6);
else
    thisContrastLayers = zeros(length(contrastLayers),5);
end

for i = 1:length(contrastLayers)
    if (contrastLayers(i) ~= 0)
        thisContrastLayers(i,:) = outParameterisedLayers{contrastLayers(i)};
    else
        thisContrastLayers(i,:) = [];
    end
end

end
