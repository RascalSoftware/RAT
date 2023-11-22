% Analysis of DSPC monolayers Data

% First make an instance of the project class
problem = projectClass('DSPC monolayers');


% Define the parameters:
Parameters = {
    %       Name                min     val     max     fit?
    {'Tails Thickness',         10,     20,     30,     true};
    {'Heads Thickness',          3,     11,     16,     true};
    {'Tails Roughness',          2,     5,      9,      true};
    {'Heads Roughness',          2,     5,      9,      true};
    {'Deuterated Tails SLD',    4e-6,   6e-6,   2e-5,   true};
    {'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,     true};
    {'Deuterated Heads SLD',    1e-6,   3e-6,   8e-6,   true};
    {'Hydrogenated Heads SLD',  0.1e-6,   1.4e-6, 3e-6,   true};
    {'Heads Hydration',         0,      0.3,   0.5,    true};
    };

% Group these into layers:
H_Heads = {'Hydrogenated Heads',...
    'Heads Thickness',...
    'Hydrogenated Heads SLD',...
    'Heads Roughness',...
    'Heads Hydration',...
    'bulk out' };

D_Heads = {'Deuterated Heads',...
    'Heads Thickness',...
    'Deuterated Heads SLD',...
    'Heads Roughness',...
    'Heads Hydration',...
    'bulk out' };

D_Tails = {'Deuterated Tails',...
    'Tails Thickness',...
    'Deuterated Tails SLD',...
    'Tails Roughness'};%,...
%'Tails Hydration',...
%'bulk in'};

H_Tails = {'Hydrogenated Tails',...
    'Tails Thickness',...
    'Hydrogenated Tails SLD',...
    'Tails Roughness'};%,...
%'Tails Hydration',...
%'bulk in'};

% Add the parameters and Layers to the project:
problem.addParameterGroup(Parameters);
problem.addLayerGroup({H_Heads; D_Heads; H_Tails; D_Tails});

% Increase the range for Substrate Roughness (param 1)
problem.setParameterLimits(1,2,13);

% Need two backgrounds - one for D2O and for H2O
% Change the name of the first and add a new one for the second
% Also need a new backsPar
problem.setBacksParName(1,'Backs value ACMW');
problem.setBacksParValue(1,5.5e-6);
problem.addBacksPar('Backs Value D2O',1e-8,2.8e-6,1e-5);

problem.addBackground('Background D2O','constant','Backs Value D2O');
problem.setBackground(1,'name','Background ACMW', 'value1', 'Backs Value ACMW');

% Also need an additional bulk out
problem.addBulkOut('SLD ACMW',-1e-6,0.0,1e-6,true);

% Add the data files
d13ACM = dlmread('d13acmw20.dat');
d70d2O = dlmread('d70d2o20.dat');
problem.addData('H-tail / D-head / ACMW', d13ACM);
problem.addData('D-tail / H-head / D2O', d70d2O);

% Add the contrasts
problem.addContrast('name','D-tail/H-Head/D2O',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...
    'nba', 'SLD air',...
    'data', 'D-tail / H-head / D2O');
problem.setContrastModel(1,{'Deuterated tails','Hydrogenated heads'});

problem.addContrast('name','H-tail/D-Head/ACMW',...
    'background','Background ACMW',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD ACMW',...
    'nba', 'SLD air',...
    'data', 'H-tail / D-head / ACMW');
problem.setContrastModel(2,{'hydrogenated tails','deuterated heads'});

% Set the fitting fitting flag on some parameters we need to fit
problem.setBacksPar(1,'fit',true);
problem.setBacksPar(2,'fit',true);
problem.setScalefactor(1,'fit',true);

% Display problem
problem

% Make the controls class...
controls = controlsClass();

[problem,results] = RAT(problem,controls);

figure(1); clf
plotRefSLD(problem,results)

save('twoContrastExample.mat','problem');
