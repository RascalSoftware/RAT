function [layersList,sRough] = call_StandardLayers(params,whichContrast,contrastLayers,numberOfLayers,layersDetails,whichType,nbairs,nbsubs)

%(params,i,contrastLayers{i},numberOfLayers,layersDetails,geometry,nbairs,nbsubs);
%(params,i,contrastLayers{i},numberOfLayers,layersDetails,geometry,nbairs,nbsubs);

[layersList,sRough] = standard_layers_mod(params,contrastLayers,numberOfLayers,layersDetails);

