function layerValues = allocateParamsToLayers(paramValues, layersDetails)
% Allocates parameters from the parameter array to the correct layers
%
% This function takes the list of all layers in 'layersDetails', 
% then loops over all the layers, putting in the correct
% parameter value from the parameters array into each layer in
% the 'layerValues' cell array

    numberOfLayers = length(layersDetails);
    layerValues = cell(1,numberOfLayers);

    for i = 1:numberOfLayers
        layer = layersDetails{i};
        layerLength = length(layer);
        outputLayer = zeros(1,6);

        % Find thickness, roughness and SLD
        % Input layer contains either 5 (real SLD) or 6 (complex SLD)
        % values. If SLD is real, the imaginary column is set to zero
        for j = 1:(layerLength-3)
            outputLayer(j) = paramValues(layer(j));
        end

        % Layer Thickness
        outputLayer(4) = paramValues(layer(layerLength-2));

        % Get hydration value, which may be NaN
        if ~isnan(layer(layerLength-1))
            outputLayer(5) = paramValues(layer(layerLength-1));
        else
            outputLayer(5) = NaN;
        end

        % Fill in hydrate with value
        outputLayer(6) = layer(end);

        layerValues{i} = outputLayer;
    end

end