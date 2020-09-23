%function mlMain
clc

type = 'XY';
params = [1, 2, 3, 4, 5, 6, 7, 8];
fileName = 'debugMfileXY';
filePath  = pwd; %'/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src';
bulkIn = 2.073e-6;
bulkOut = 6.35e-6;
contrast = 1.0;

[layersList,sRoughs] = matlabEngineCaller_customLayers(params,contrast,fileName,filePath,bulkIn,bulkOut);

disp(layersList);


[layersList2,sRoughs] = matlabEngineCaller_customLayers_mex(params,contrast,fileName,filePath,bulkIn,bulkOut);
switch type
    case 'XY'
        layersList2 = layersList2(:,1:2);
end
disp(layersList2);