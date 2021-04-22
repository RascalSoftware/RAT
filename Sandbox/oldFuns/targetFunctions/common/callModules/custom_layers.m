function [layersList,sRoughs] = custom_layers(params,whichContrast,fileHandle,nbairs,nbsubs);

fileHandle = str2func(fileHandle);
[layersList,sRoughs] = fileHandle(params,nbairs,nbsubs,whichContrast);













