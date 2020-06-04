function     thisContrastLayers = allocateLayersForContrast(contrastLayers,outParameterisedLayers);

% Take the layers list for a contrast and build an
% array of real valued layers 


thisContrastLayers = zeros(length(contrastLayers),5);

for i = 1:length(contrastLayers)
    thisLayer = outParameterisedLayers{contrastLayers(i)};
    thisContrastLayers(i,:) = thisLayer;
end

end