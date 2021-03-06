

params = [1, 2, 3, 4, 5, 6, 7, 8];
bulkIn = 2.073e-6;
bulkOut = 6.35e-6;

numberOfContrasts = 4;
params = {params ; params ; params; params};
in  = [bulkIn ; bulkIn ; bulkIn ; bulkIn];
out = [bulkOut ; bulkOut ; bulkOut ; bulkOut];

[allLayers, allRoughs] = loopCaller(params,in,out,numberOfContrasts);



