function [layersOutput,sRoughOutput] = standard_layers_mod(params,contrastLayers,numberOfLayers,layersDetails)



sRoughOutput = params(1);
if numberOfLayers == 0
    sub_rough = params(1);
    layersList = [];
else
    layersValues = zeros(numberOfLayers,5);
    for n = 1:numberOfLayers
        thisLayer = layersDetails{n};
        for m = 1:4
            thisItem = thisLayer(m);
            if ~isnan(thisItem)
                layersValues(n,m) = params(thisItem);
            else
                layersValues(n,m) = NaN;
            end
        end
        whichBulk = thisLayer(5);
        if whichBulk == 2
            layersValues(n,5) = 1;
        else
            layersValues(n,5) = 0;
        end
    end
    
    
    if ~isempty(contrastLayers)
        layersList = zeros(length(contrastLayers),5);
        for n = 1:length(contrastLayers)
            thisRow = contrastLayers(n);
            layersList(n,:) = layersValues(thisRow,:);
        end
    else
        layersList = [];
    end
end
sub_rough = params(1);
layersOutput = layersList;
sRoughOutput = sub_rough;


end


