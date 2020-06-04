function [layersList,sRough] = callModules(params,whichContrast,contrastLayers,numberOfLayers,layersDetails,whichType,fileHandle,nbairs,nbsubs)


switch whichType
    case 1  %Standard Layers
        [layersList,sRough] = standard_layers_mod(params,contrastLayers,numberOfLayers,layersDetails);
    case 2  %Custom layers model
        [layersList,sRough] = custom_layers(params,whichContrast,fileHandle,nbairs,nbsubs);
    case 3  %Custom XY profile
        [layersList,sRough] = custom_XY(params,whichContrast,fileHandle,nbairs,nbsubs);
        sRough = 1;
end

