% THIS FILE IS GENERATED FROM RAT VIA THE "WRITESCRIPT" ROUTINE. IT IS NOT PART OF THE RAT CODE.

project = createProject(name='', calcType='non polarised', model='standard layers', geometry='air/substrate', absorption=false);

project.setParameterValue(1, 20);
project.setParameterLimits(1, 1, 5);
project.setParameterFit(1, true);
project.setParameterPrior(1, 'uniform', 0, Inf);


project.removeBulkIn(1);
project.addBulkIn('SLD Air', 0, 0, 0, false, 'uniform', 0, Inf);

project.removeBulkOut(1);
project.addBulkOut('SLD D2O', 6.2e-06, 6.35e-06, 6.35e-06, false, 'uniform', 0, Inf);

project.removeScalefactor(1);
project.addScalefactor('Scalefactor 1', 0.02, 0.23, 0.25, false, 'uniform', 0, Inf);

project.removeQzshift(1);
project.addQzshift('Qz shift 1', -0.0001, 0, 0.0001, false, 'uniform', 0, Inf);

project.removeBackgroundParam(1);
project.addBackgroundParam('Background Param 1', 1e-07, 1e-06, 1e-05, false, 'uniform', 0, Inf);

project.removeResolutionParam(1);
project.addResolutionParam('Resolution par 1', 0.01, 0.03, 0.05, false, 'uniform', 0, Inf);

project.removeBackground(1);
project.removeResolution(1);

project.addBackground('Background 1', 'constant', 'Background Param 1', '', '', '', '');

project.addResolution('Resolution 1', 'constant', 'Resolution par 1', '', '', '', '');

project.removeData(1);
project.addData('Simulation');
project.setData(1, 'simRange', [0.005 0.7]);

