

% Main for custom bilayer
params = [3 20 0.2 55 0.2 0.1 4 2];

bulkIn = 2.073e-6;
bulkOut = [6.35e-6, 2.073e-6 -0.5e-6];

contrast = 1;

[output,sub_rough] = customBilayer(params,bulkIn,bulkOut,contrast);

