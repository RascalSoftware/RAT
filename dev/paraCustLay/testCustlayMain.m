testPars = load('testParams.mat');

testPars = testPars.testParams;

problemDef = testPars{1};
problemDef_cells = testPars{2};
problemDef_limits = testPars{3};
controls = testPars{4};

tic
[outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
    Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
    allRoughs] = dev_custlay_paraContrasts(problemDef,problemDef_cells,...
    problemDef_limits,controls);
toc

tic
[MXoutSsubs,MXbackgs,MXqshifts,MXsfs,MXnbas,MXnbss,MXresols,MXchis,MXreflectivity,...
    MXSimulation,MXshifted_data,MXlayerSlds,MXsldProfiles,MXallLayers,...
    MXallRoughs] = dev_custlay_paraContrasts_mex(problemDef,problemDef_cells,...
    problemDef_limits,controls);
toc
