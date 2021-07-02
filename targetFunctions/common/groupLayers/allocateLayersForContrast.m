function     thisContrastLayers = allocateLayersForContrast(contrastLayers,outParameterisedLayers)

% Decide which layers are needed for a particular contrast
% This function takes the master array of all layers
% and extracts which parameters are requires for 
% a particular contrast. 
% outParameterisedLayers - List of all the available layers
% thisContrastLayers     - Array detailing which layers are required 
%                          for this contrast


thisContrastLayers = zeros(length(contrastLayers),5);

for i = 1:length(contrastLayers)
    thisLayer = outParameterisedLayers{contrastLayers(i)};
    thisContrastLayers(i,:) = thisLayer;
end

end