testPars = load('testParams.mat');

testPars = testPars.testParams;

problemDef = testPars{1};
problemDef_cells = testPars{2};
problemDef_limits = testPars{3};
controls = testPars{4};

[outLayers, allRoughs] = callParaMatalbCustlay_mex(problemDef,problemDef_cells,...
    problemDef_limits,controls);