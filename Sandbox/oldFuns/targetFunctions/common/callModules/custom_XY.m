function [layersList,sRoughs] = custom_XY(params,whichContrast,fileHandle,nbairs,nbsubs)


fileHandle = str2func(fileHandle);
layersList = fileHandle(params,nbairs,nbsubs,whichContrast);
sRoughs = 1;

end













