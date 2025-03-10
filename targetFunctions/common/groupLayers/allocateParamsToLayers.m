function outLayers = allocateParamsToLayers(params, layersDetails)
% Allocates parameters from the parameter array to the correct layers
%
% This function takes the list of all layers in 'layersDetails', 
% then loops over all the layers, putting in the correct
% parameter value from the parameters array into each layer in
% the 'outLayers' cell array

    numberOfLayers = length(layersDetails);
    outLayers = cell(1,numberOfLayers);

    for i = 1:numberOfLayers
        thisLayer = layersDetails{i};
        layerLength = length(thisLayer);
        thisOutLayer = zeros(1,6);

        % Find thickness, roughness and SLD
        % Input layer contains either 5 (real SLD) or 6 (complex SLD)
        % values. If SLD is real, the imaginary column is set to zero
        for n = 1:(layerLength-3)
            thisVal = thisLayer(n);
            thisOutLayer(n) = params(thisVal);
        end

        % Layer Thickness
        thisOutLayer(4) = params(thisLayer(layerLength-2));

        % Get hydration value, which may be NaN
        if ~isnan(thisLayer(layerLength-1))
            thisOutLayer(5) = params(thisLayer(layerLength-1));
        else
            thisOutLayer(5) = NaN;
        end

        % Fill in hydrate with value
        thisOutLayer(6) = thisLayer(end);

        outLayers{i} = thisOutLayer;
    end

end