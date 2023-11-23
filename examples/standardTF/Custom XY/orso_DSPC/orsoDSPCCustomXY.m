%function problem = orsoDSPCCustomLayers()

%% Custom Layers Example for Supported DSPC layer.
% 
% 
% Example of using Custom layers to model a DSPC supportd bilayer.
% 
% 
% 
% Start by making the class and setting it to a custom layers type:

problem = createProject(name='Orso lipid example - custom layers', model='custom XY');
problem.setGeometry('Substrate/liquid');
problem.setUsePriors(true);

%% 
% 
% 
% We need to add the relevant parameters we are going to need to define the 
% model (note that Substrate Roughness' always exists as parameter 1..

Parameters = {
    %       Name                min          val         max     fit? 
        {'Oxide thick',          1,          10,         30,     true   };
        {'Oxide Hydration'       0,          0,       0.5,     true   };
        {'Water Thick'          1,           0,         20,     true   };
        {'Head Thick'            8           7,         15,     true   };
        {'Head SLD'            1.4e-6,      1.7e-6,     1.9e-6,  true   };
        {'Tails Thick'          15,          15,         20,     true   };
        {'Tails SLD'           -0.5e-6,    -0.4e-6,    -0.1e-6,  true   };
        {'Methyl Thick'          3,           3,          7,     true   };
        {'Bilayer Rough'         3,           3,          7,     true   };
        {'Head Hydration'       0.1,         0.1,        0.4,    true   };
        {'Bilayer Coverage'     0.8,         1,        1.0,    true   };
        };
    
 problem.addParameterGroup(Parameters);
 problem.setParameter(1,'min',1,'max',10);
 
%% 
% 
% 
% Need to add the relevant Bulk SLD's. Change the bulk in from air to silicon, 
% and add two additional water contrasts:

% Change bulk in from air to silicon....
problem.setBulkIn(1,'name','Silicon','min',2.07e-6,'value',2.073e-6,'max',2.08e-6,'fit',false);

% Add two more values for bulk out....
problem.addBulkOut('SLD SMW',1e-6,2.073e-6,3e-6,true);
problem.addBulkOut('SLD H2O',-0.6e-6,-0.56e-6,-0.3e-6,true);

problem.setBulkOut(1,'fit',true,'min',5e-6,'value',6.1e-6);

%% 
% Now add the datafiles.  We have three datasets we need to consider - the bilayer 
% against D2O, Silicon Matched water and H2O. Load these datafiles in and put 
% them in the data block....

% Read in the datafiles
D2O_data = dlmread('c_PLP0016596.dat');
SMW_data = dlmread('c_PLP0016601.dat');
H2O_data = dlmread('c_PLP0016607.dat');

% Add the data to the project
problem.addData('Bilayer / D2O', D2O_data(:,1:3));
problem.addData('Bilayer / SMW', SMW_data(:,1:3));
problem.addData('Bilayer / H2O', H2O_data(:,1:3));

problem.setData(2,'dataRange',[0.013 0.37]);
problem.setData(3,'dataRange',[0.013 0.37]);
problem.setData(4,'dataRange',[0.013 0.37]);

%% 
% 
% 
% Add the custom file to the project....

problem.addCustomFile('DSPC Model','DSPCCustomXY.m','matlab',pwd);
%% 
% 
% 
% Also, add the relevant background parameters - one each for each contrast:

% Change the name of the existing parameters to refer to D2O
problem.setBackgroundParam(1,'name','Backs par D2O','fit',true,'min',1e-10,'max',1e-5,'val',1e-07);

% Add two new backs parameters for the other two..
problem.addBackgroundParam('Backs par SMW',1e-10,1e-7,1e-5,true);
problem.addBackgroundParam('Backs par H2O',1e-10,1e-7,1e-5,true);

% And add the two new constant backgrounds..
problem.addBackground('Background SMW','constant','Backs par SMW');
problem.addBackground('Background H2O','constant','Backs par H2O');

% And edit the other one....
problem.setBackground(1,'name','Background D2O', 'value1','Backs par D2O');

% Finally modify some of the other parameters to be more suitable values
% for a solid / liquid experiment.

% Set the scalefactor...
problem.setScalefactor(1,'Value',1,'min',0.5,'max',2,'fit',true);

%% 
% 
% 
% Now add the three contrasts as before:

% D2O contrast..
problem.addContrast('name','Bilayer / D2O',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...        % This is bulk out ('Nb Subs')
    'nba', 'Silicon',...        % This is bulk in ('Nb Air')
    'data', 'Bilayer / D2O');

% SMW contrast..
problem.addContrast('name','Bilayer / SMW',...
    'background','Background SMW',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD SMW',...        % This is bulk out
    'nba', 'Silicon',...        % This is bulk in
    'data', 'Bilayer / SMW');

% SMW contrast..
problem.addContrast('name','Bilayer / H2O',...
    'background','Background H2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD H2O',...        % This is bulk out
    'nba', 'Silicon',...        % This is bulk in
    'data', 'Bilayer / H2O');
%% 
% 
% 
% And set the model for each..

problem.setContrastModel(1,'DSPC Model');
problem.setContrastModel(2,'DSPC Model');
problem.setContrastModel(3,'DSPC Model');



problem


%end



