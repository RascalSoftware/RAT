% First make an instance of the project class
problem = project(name='DSPC custom layers', model='custom layers');


%% 
% 

% Define the parameters:
Parameters = {
    %       Name                min       val      max       fit? 
    {'Area per molecule',        45,      45,      65,       true};
    {'Head Hydration',           0,       0.01,    0.5,      true};
    {'Head Roughness',           0,       5,       7,        true};
    {'Tail Roughness',           0,       5,       7,        true};
    {'Tail thickness',           15,      20,      25,       true};
    };


% Add the parameters and Layers to the project:
problem.addParameterGroup(Parameters);

% Increase the constr range for Substrate Roughness (param 1)
problem.setParameterConstraint(1,2,13);

% Add the custom layers file
problem.addCustomFile('DSPC Model','customDSPCMonolayer.m','matlab','pwd');
%% 
% 

% Need two backgrounds - one for D2O and for H2O
% Change the name of the first and add a new one for the second
% Also need a new backsPar
problem.setBacksParName(1,'Backs value ACMW');
problem.setBacksParValue(1,5.5e-6);
problem.addBacksPar('Backs Value D2O',1e-8,2.8e-6,1e-5);

problem.addBackground('Background D2O','constant','Backs Value D2O');
problem.setBackground(1,'name','Background ACMW', 'value1', 'Backs Value ACMW');

%% 
% 

% Also need an additional bulk out
problem.addBulkOut('SLD ACMW',-1e-6,0.0,1e-6,true);

% Add the data files
d13ACM = dlmread('d13acmw20.dat');
d70d2O = dlmread('d70d2o20.dat');
problem.addData('H-tail / D-head / ACMW', d13ACM);
problem.addData('D-tail / H-head / D2O', d70d2O);
%% 
% 

% Add the contrasts
problem.addContrast('name','D-tail/H-Head/D2O',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...
    'nba', 'SLD air',...
    'data', 'D-tail / H-head / D2O');
problem.setContrastModel(1,'DSPC Model');

problem.addContrast('name','H-tail/D-Head/ACMW',...
    'background','Background ACMW',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD ACMW',...
    'nba', 'SLD air',...
    'data', 'H-tail / D-head / ACMW');
problem.setContrastModel(2,'DSPC Model');

%% 
% 

% Set the fitting fitting flag on some parameters we need to fit
problem.setBacksPar(1,'fit',true);
problem.setBacksPar(2,'fit',true);
problem.setScalefactor(1,'fit',true);
problem.setBulkOut(1,'fit',false);
problem.setBulkOut(2,'fit',false);


%%

% Make the controls class...
controls = controlsClass();
controls.parallel = 'points';
controls.calcSldDuringFit = true;

[problem,results] = RAT(problem,controls);

%%
figure(10); clf
plotRefSLD(problem, results);
