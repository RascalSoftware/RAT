
% Test custom function languages....
clear; clear all; clear classes
[path, ~, ~] = fileparts(mfilename("fullpath"));

% Male the problem;
orsoDSPCCustomLayers;

controls = controlsClass();

%% Matlab
[problem,results] = RAT(problem,controls);
figure(1); clf
plotRefSLD(problem,results);


%% Python
problem.setCustomFile(1,'filename', 'customBilayer.py', 'path', path);
problem.setCustomFile(1,'language','python');

[problem,results] = RAT(problem,controls);
figure(2); clf
plotRefSLD(problem,results);

%% Cpp
problem.setCustomFile(1,'filename', 'customBilayer.dll', 'path', path);
problem.setCustomFile(1,'language','cpp');

[problem,results] = RAT(problem,controls);
figure(3); clf
plotRefSLD(problem,results);
