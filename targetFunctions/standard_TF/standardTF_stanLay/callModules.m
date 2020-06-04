function [layersList,sRough] = callModules(params,whichContrast,contrastLayers,numberOfLayers,layersDetails,whichType,fileHandle,nbairs,nbsubs)


[layersList,sRough] = standard_layers_mod_mex(params,contrastLayers,numberOfLayers,layersDetails);

