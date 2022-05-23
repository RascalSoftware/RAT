function mlMain

params = [1, 2, 3, 4, 5, 6, 7, 8];
fileName = 'debugMfile';
filePath  = '/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src';
bulkIn = 2.073e-6;
bulkOut = 6.35e-6;
contrast = 1.0;



[layersList,sRoughs] = matlabEngineCaller_customLayers_mex(params,contrast,fileName,filePath,bulkIn,bulkOut);

%[a,b] = matlabEngineCaller_customLayers_mex(1,-1,'test','test',1,1);

disp('debug');



end








% function [layersList,sRoughs] = custom_layers(params,whichContrast,fileHandle,nbairs,nbsubs);
% 
% fileHandle = str2func(fileHandle);
% [layersList,sRoughs] = fileHandle(params,nbairs,nbsubs,whichContrast);