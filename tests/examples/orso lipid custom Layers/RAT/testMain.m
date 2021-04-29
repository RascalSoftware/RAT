
params = [3 20 0.2 55 0.2 0.1 4 2];
bulkIn = 2e-6;
bulkOut = 6e-6;
contrast = 1;

out = callMatlabCustomLayers('customBilayer.m',params,bulkIn,bulkOut,contrast);

