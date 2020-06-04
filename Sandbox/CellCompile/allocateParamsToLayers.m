function outLayers = allocateParamsToLayers(params, layersDetails);

%This function takes the list of all layers (in terms of parameter
%numbers) in layersDetails, and loops through putting in the correct
%parameter value from the parameter array in each layer. 

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
    thisOutLayer(n+1) = thisLayer(end);
    outLayers{i} = thisOutLayer;
end

end