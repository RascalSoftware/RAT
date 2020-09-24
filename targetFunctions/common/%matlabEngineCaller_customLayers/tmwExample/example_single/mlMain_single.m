

params = [1, 2, 3, 4, 5, 6, 7, 8];
fileName = 'debugMfile';
filePath  = '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/';
bulkIn = 2.073e-6;
bulkOut = 6.35e-6;
contrast = 1.0;

[layersList,sRoughs] = matlabEngineCaller_customLayers(params,contrast,fileName,filePath,bulkIn,bulkOut);

layersList

%To close the engine, run this line....
%[layersList,sRoughs] = matlabEngineCaller_customLayers(params,-2,fileName,filePath,bulkIn,bulkOut);



