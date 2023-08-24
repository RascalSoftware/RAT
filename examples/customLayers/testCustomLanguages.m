
% Test custom function languages....
clear; clear all; clear classes

% Male the problem;
orsoDSPCCustomLayers;

controls = controlsClass();

%% Matlab
[problem,results] = RAT(problem,controls);
figure(1); clf
plotRefSLD(problem,results);


%% Python
wrapper = pythonWrapper('customBilayer.py', 'customBilayer');
problem.setCustomFile(1,'filename', wrapper.getHandle());
problem.setCustomFile(1,'language','matlab');

[problem,results] = RAT(problem,controls);
figure(2); clf
plotRefSLD(problem,results);

%% Cpp
wrapper = dyLibWrapper('customBilayer.dll', 'customBilayer');
problem.setCustomFile(1,'filename', wrapper.getHandle());
problem.setCustomFile(1,'language','cpp');

[problem,results] = RAT(problem,controls);
figure(3); clf
plotRefSLD(problem,results);