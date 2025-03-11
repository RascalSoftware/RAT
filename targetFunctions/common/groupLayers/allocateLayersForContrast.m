function layers = allocateLayersForContrast(layerIndices,layerValues)
% Decide which layers are needed for a particular contrast.
% This function takes the master array of all layers
% and extracts which parameters are required for 
% a particular contrast. 
%
% INPUTS:
%     layerValues      - List of all the available layers
%     layerIndices     - Array detailing which layers are required for this contrast

layers = zeros(length(layerIndices), 6);
for i = 1:length(layerIndices)
    layers(i,:) = layerValues{layerIndices(i)};
end

end
