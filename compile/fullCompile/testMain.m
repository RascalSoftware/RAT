
testPars = load('testPars');
testPars = testPars.testPars;

problemDef = testPars{1};
problemDefCells = testPars{2};
problemDefLimits = testPars{3};
controls = testPars{4};
priors = testPars{5};

[outProblemDef,problem,results,bayesResults] = RATMain_mex(problemDef,problemDefCells,...
                                                       problemDefLimits,controls,priors);
