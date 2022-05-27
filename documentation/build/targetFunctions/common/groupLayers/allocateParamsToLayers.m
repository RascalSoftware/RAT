function outLayers = allocateParamsToLayers(params, layersDetails)
% Allocates parameters from the parameter array to the correct layers
%
% This function takes the list of all layers in 'layersDetails', 
% then loops over all the layers, putting in the correct
% parameter value from the parameters array into each layer in
% the 'outLayers' cell array

    numberOfLayers = length(layersDetails);
    thisOutLayer = zeros(1,5);
    outLayers = cell(1,numberOfLayers);

    for i = 1:numberOfLayers
        thisLayer = layersDetails{i};
        for n = 1:(length(thisLayer)-1)
            thisVal = thisLayer(n);
            if ~isnan(thisVal)
                thisOutLayer(n) = params(thisVal);
            else
                thisOutLayer(n) = NaN;
            end
        end
        thisOutLayer(length(thisLayer)) = thisLayer(end);
        outLayers{i} = thisOutLayer;
    end

end