
problem = load('DSPCBilayerProjectClass.mat').thisProjectClass;

% Make a controls block
controls = controlsClass();
controls.parallel = parallelOptions.Points;
controls.procedure = procedures.Simplex;
controls.maxIter = 10;

figure(2); clf
eventManager.register(eventTypes.Plot, 'plotRefSLDHelper')
% eventManager.register(eventTypes.Message, 'disp')

[problem1, result1] = RAT(problem, controls);

plotRefSLD(problem1, result1);

eventManager.clear()
