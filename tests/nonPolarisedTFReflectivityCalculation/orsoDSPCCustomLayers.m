function project = orsoDSPCCustomLayers()

%% Custom Layers Example for Supported DSPC layer.
% 
% 
% Example of using Custom layers to model a DSPC supported bilayer.
% 
% 
% 
% Start by making the class and setting it to a custom layers type:

project = projectClass('Orso lipid example - custom layers');
project.setModelType('custom layers');
project.setGeometry('Substrate/liquid');
project.showPriors = true;

%%  
% We need to add the relevant parameters we are going to need to define the 
% model (note that Substrate Roughness' always exists as parameter 1..

Parameters = {
    %       Name                min         val         max     fit? 
        {'Oxide thick',         5,          20,         60,     true   };
        {'Oxide Hydration'      0,          0.2,        0.5,    true   };
        {'Lipid APM'            45          55          65      true   };
        {'Head Hydration'       0           0.2         0.5     true   };
        {'Bilayer Hydration'    0           0.1         0.2     true   };
        {'Bilayer Roughness'    2           4           8       true   };
        {'Water Thickness'      0           2           10      true   };
        };
    
 project.addParameterGroup(Parameters);
 project.setParameter(1,'min',1,'max',10);
 
%% 
% 
% 
% Need to add the relevant Bulk SLD's. Change the bulk in from air to silicon, 
% and add two additional water contrasts:

% Change bulk in from air to silicon....
project.setBulkIn(1,'name','Silicon','min',2.07e-6,'value',2.073e-6,'max',2.08e-6,'fit',false);

% Add two more values for bulk out....
project.addBulkOut('SLD SMW',1e-6,2.073e-6,3e-6,true);
project.addBulkOut('SLD H2O',-0.6e-6,-0.56e-6,-0.3e-6,true);

project.setBulkOut(1,'fit',true,'min',5e-6);

%% 
% Now add the datafiles.  We have three datasets we need to consider - the bilayer 
% against D2O, Silicon Matched water and H2O. Load these datafiles in and put 
% them in the data block....

% Read in the datafiles
D2O_data = dlmread('c_PLP0016596.dat');
SMW_data = dlmread('c_PLP0016601.dat');
H2O_data = dlmread('c_PLP0016607.dat');

% Add the data to the project
project.addData('Bilayer / D2O', D2O_data(:,1:3));
project.addData('Bilayer / SMW', SMW_data(:,1:3));
project.addData('Bilayer / H2O', H2O_data(:,1:3));

project.setData(2,'dataRange',[0.013 0.37]);
project.setData(3,'dataRange',[0.013 0.37]);
project.setData(4,'dataRange',[0.013 0.37]);

%% 
% 
% 
% Add the custom file to the project....

project.addCustomFile('DSPC Model','customBilayer.m','matlab','tests/nonPolarisedTFReflectivityCalculation/');
%% 
% 
% 
% Also, add the relevant background parameters - one each for each contrast:

% Change the name of the existing parameters to refer to D2O
project.setBackgroundParam(1,'name','Backs par D2O','fit',true,'min',1e-10,'max',1e-5,'val',1e-07);

% Add two new backs parameters for the other two..
project.addBackgroundParam('Backs par SMW',1e-10,1e-7,1e-5,true);
project.addBackgroundParam('Backs par H2O',1e-10,1e-7,1e-5,true);

% And add the two new constant backgrounds..
project.addBackground('Background SMW','constant','Backs par SMW');
project.addBackground('Background H2O','constant','Backs par H2O');

% And edit the other one....
project.setBackground(1,'name','Background D2O', 'source','Backs par D2O');

% Finally modify some of the other parameters to be more suitable values
% for a solid / liquid experiment.

% Set the scalefactor...
project.setScalefactor(1,'Value',1,'min',0.5,'max',2,'fit',true);

%% 
% 
% 
% Now add the three contrasts as before:

% D2O contrast..
project.addContrast('name','Bilayer / D2O',...
    'background','Background D2O',...
    'backgroundAction', actions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD D2O',...
    'data', 'Bilayer / D2O');

% SMW contrast..
project.addContrast('name','Bilayer / SMW',...
    'background','Background SMW',...
    'backgroundAction', actions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD SMW',...
    'data', 'Bilayer / SMW');

% SMW contrast..
project.addContrast('name','Bilayer / H2O',...
    'background','Background H2O',...
    'backgroundAction', actions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD H2O',...
    'data', 'Bilayer / H2O');
%% 
% 
% 
% And set the model for each..

project.setContrastModel(1,'DSPC Model');
project.setContrastModel(2,'DSPC Model');
project.setContrastModel(3,'DSPC Model');


end
