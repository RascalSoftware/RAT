%function mlMain

params = [1, 2, 3, 4, 5, 6, 7, 8];
fileName = 'debugMfileXY';
filePath  = '/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src';
bulkIn = 2.073e-6;
bulkOut = 6.35e-6;
contrast = 1.0;

[layersList,sRoughs] = matlabEngineCaller_customXY(params,contrast,fileName,filePath,bulkIn,bulkOut);

disp(layersList);


%[layersList,sRoughs] = matlabEngineCaller_customXY_mex(params,contrast,fileName,filePath,bulkIn,bulkOut);

disp(layersList);