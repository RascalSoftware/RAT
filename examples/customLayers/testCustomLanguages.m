
% Test custom function languages....
clear; clear all; clear classes

% Male the problem;
orsoDSPCCustomLayers;

controls = controlsClass();

%% Matlab
[problem,results] = RAT(problem,controls);


%% Python
problem.setCustomFile(1,'filename','customBilayer.py');
problem.setCustomFile(1,'language','python');

[problem,results] = RAT(problem,controls);

%% Cpp
