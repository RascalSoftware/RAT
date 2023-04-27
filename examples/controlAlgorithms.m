
problem = load('DSPCBilayerProjectClass.mat').thisProjectClass;

%% Make a controls block
controls = controlsClass();
controls.parallel = parallelOptions.Points;
[problem1, result1] = RAT(problem, controls);

%% Use simplex
controls.procedure = procedures.Simplex;
[problem2, result2] = RAT(problem, controls);

%% Use nested sampler
controls.procedure = procedures.NS;
controls.Nlive = 40;
[problem3, result3] = RAT(problem, controls);

%% Use differential evolution
controls.procedure = procedures.DE;
controls.populationSize = 10;
[problem4, result4] = RAT(problem, controls);

%% Use dream
controls.procedure = procedures.Dream;
controls.nSamples = 5000;
[problem5, result5] = RAT(problem, controls);

%% Plot the results....
figure(1); clf
plotRefSLD(problem1, result1);

figure(2); clf
plotRefSLD(problem2, result2);

figure(3); clf
plotRefSLD(problem3, result3);

figure(4); clf
plotRefSLD(problem4, result4);

figure(5); clf
plotRefSLD(problem5, result5);
