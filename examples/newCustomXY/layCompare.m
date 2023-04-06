
% Load Layers results
lays = load('lays');
lays = lays.lays;
layProb = lays{1};
layRes = lays{2};

orsoDSPCCustomXY;
controls = controlsClass();
[problem,results] = RAT(problem,controls);

figure(1); clf; hold on
plotRefSLD(problem,results);
plotRefSLD(layProb,layRes);
