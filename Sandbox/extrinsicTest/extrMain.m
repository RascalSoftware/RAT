% Test of coder extrinsic

params = [1 2 3 4];
bulkIn = 2e-6;
bulkOut = 4e-6;
contrast = 1;

testFun = 'myTestFun';

[out,sr] = callTestFun_mex(testFun,params,bulkIn,bulkOut,contrast);



