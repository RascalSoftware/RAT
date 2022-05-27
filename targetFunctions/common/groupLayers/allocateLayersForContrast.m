function     thisContrastLayers = allocateLayersForContrast(contrastLayers,outParameterisedLayers)
% Decide which layers are needed for a particular contrast.
% This function takes the master array of all layers
% and extracts which parameters are required for 
% a particular contrast. 
%
% INPUTS:
%     outParameterisedLayers - List of all the available layers
%     thisContrastLayers     - Array detailing which layers are required for this contrast


thisContrastLayers = zeros(length(contrastLayers),5);

for i = 1:length(contrastLayers)
    if (contrastLayers(i) ~= 0)
        thisLayer = outParameterisedLayers{contrastLayers(i)};
        thisContrastLayers(i,:) = thisLayer;
    else
        thisContrastLayers(1,:) = [];
    end
end

end