clear; clear all; clear classes

% Male the problem;
orsoDSPCCustomLayers;

controls = controlsClass();

% Do an initial run with Matlab (because JIT)....
[problem,results] = RAT(problem,controls);

% Now run 200 interations of simplex...
controls.procedure = 'simplex';
controls.maxIter = 500;
controls.display = 'final';
[problem,results] = RAT(problem,controls);








%         ML     Py     Cpp
times = [1.95,  9.38,  1.83];


% DREAM 20000
times = [ 9.35, 53.89,   8.99];
