function project = DPPCStandardLayers() 

%% ORSO Lipid Example 1 - DSPC Bilayer Analysed Using a Standard Layers Model.
% 
% 
% Start by making an empty instance of the project definition class:

project = projectClass('Orso lipid example');

%% 
% In this example, we will use a standard layers model. This defines layers 
% in terms of thickness, SLD, roughness and hydration. These are then grouped 
% into layers and the allocated to contrasts in the normal RasCAl way. For this 
% sample, we have a DSPC bilayer on a Silicon substrate, which will  be coated 
% by an oxide layer. Usually there is a hydration layer between the substrate 
% and the lipid, although this depends on the exact conditions of the measurement. 
% Start by defining the parameters for the oxide layer. We need a thickness, SLD 
% and hydration. The roughness is assumed to be the bulk substrate roughness.

Parameters = {
    %       Name                min         val         max     fit? 
        {'Oxide thick',         5,         20,         60,     true   };
        {'Oxide SLD',           3e-6,       3.41e-6,    4e-6,   false  };
        {'Oxide Hydration'      0,          20,         30,     true   }};
    
%% 
% Add these parameters to the project class, and group them into a layer to 
% demonstrate how this is done:

    project.addParameterGroup(Parameters);
    % Now make the oxide layer
    Oxide = {'Oxide Layer',...           % Name of the layer
             'Oxide thick',...           % Layer thickness
             'Oxide SLD',...             % Layer SLD
             'Substrate Roughness',...   % Layer roughness
             'Oxide Hydration',...       % Oxide hydration (precent)
             'bulk out' };               % Which bulk phase is hydrating the layer
            
    % Add this to the project...
    project.addLayer(Oxide);
%% 
% Now we'll build the layers for the lipid, The bilayer is symmetrical, so we 
% can have mostly the same values for the inner and outer tails and heads. We 
% have to be a bit careful with roughness' however, since we want to have a slightly 
% different roughness for the head/water interface and the head/alkyl interface, 
% and for layer model in this geometry the roughness for each layer refers to the 
% next interface. So we'll make separate layers for inner and outer lipids, but 
% all sharing the same parameters, and just differing in the roughness order.
% 
% Define the parameters we will need:

% Bilayer parameters:
bilParams = {
        {'Bilayer heads thick',  5,          10,         15,     true    };
        {'Bilayer heads SLD',    1e-6,       1.47e-6,    3e-6,   true    };
        {'Bilayer heads hydr',   20,         30,         50,     true    };
        {'Bilayer heads rough'   5,          7,          15,     true    };
        {'Bilayer tails thick',  10,         10,         20,     true    };
        {'Bilayer tails SLD',    -5e-7,      -4e-7,      -1e-7,  false   };
        {'Bilayer tails hydr',   0,          10,         20,     true    };
        {'Bilayer tails rough',  5,          9,          15,     true    };
};

% We want the water layer to be matched in SLD to the bulk water phase. So
% we give it an SLD of 0, and a hydration of 100%, and make these
% non-fittable
watParams = {
        {'Water thick',         0,          1,          15,     true    };
        {'Water SLD',           0,          0,          0,      false   };
        {'Water hydr',          100,        100,        100,    false   };  
};


% Add these parameters to the project as before.
project.addParameterGroup(watParams);
project.addParameterGroup(bilParams);

% Now make the layers
waterLayer = {
    'Water Layer',...           % Layer name
    'Water thick',...
    'Water SLD',...
    'Bilayer heads rough',...    % Outer interface of the water layer is a bilayer headgroup
    'Water hydr',...
    'Bulk out'
};

% Inner lipid layer headgroup:
bilInnerHead = {
    'Bil inner head',...        % Layer name
    'Bilayer heads thick',...
    'Bilayer heads SLD',...
    'Bilayer heads rough',...
    'Bilayer heads hydr',...
    'Bulk out'
    };

% Lipid tail group (inner and outer)
bilTails = {
    'Bil tail',...
    'Bilayer tails thick',...
    'Bilayer tails SLD',...
    'Bilayer heads rough',...
    'Bilayer tails hydr',...
    'bulk out'
    };

% Outer lipid layer head group
bilOuterHead = {
    'Bil outer head',...        % Layer name
    'Bilayer heads thick',...
    'Bilayer heads SLD',...
    'Bilayer heads rough',...
    'Bilayer heads hydr',...
    'Bulk out'
    };

%% 
% 
% 
% Add these layers to the project:

project.addLayerGroup({waterLayer, bilInnerHead, bilTails, bilOuterHead});
%% 
% We have three datasets we need to consider - the bilayer against D2O, Silicon 
% Matched water and H2O. Load these datafiles in and put them in the data block....

% Read in the datafiles
D2O_data = dlmread('c_PLP0016596.dat');
SMW_data = dlmread('c_PLP0016601.dat');
H2O_data = dlmread('c_PLP0016607.dat');

% Add the data to the project
project.addData('Bilayer / D2O', D2O_data(:,1:3));
project.addData('Bilayer / SMW', SMW_data(:,1:3));
project.addData('Bilayer / H2O', H2O_data(:,1:3));

project.setData(2,'dataRange',[0.013 0.35]);
project.setData(3,'dataRange',[0.013 0.32996]);
project.setData(4,'dataRange',[0.013 0.33048]);

%% 
% We also need the correct SLD's for the bulk phases.....

% Change bulk in from air to silicon....
project.setBulkIn(1,'name','Silicon','min',2.07e-6,'value',2.073e-6,'max',2.08e-6,'fit',false);

% Add two more values for bulk out....
project.addBulkOut('SLD SMW',2e-6,2.073e-6,3e-6,true);
project.addBulkOut('SLD H2O',-0.6e-6,-0.56e-6,-0.3e-6,true);
project.setBulkOut(1,'min',4e-6,'fit',true);

 project.setBulkOut(1,'fit',true);
 project.setBulkOut(2,'fit',true);
 project.setBulkOut(3,'fit',true);


%% 
% We also need a different background for each contrast. Backgrounds in RAT 
% are split into two parts - background parameters (which are fittable), and these 
% are then used in the backgrounds themselves as required (there will be more 
% explanation on this in a future worksheet, but this allows custom background 
% functions with several fittable parameters - or background data - to be defined). 
% In this case, we'll just use constant background types, so these need only one 
% parameter each...

% Change the name of the existing parameters to refer to D2O
project.setBackgroundParam(1,'name','Backs par D2O','fit',true,'min',1e-8,'max',1e-5);

% Add two new backs parameters for the other two..
project.addBackgroundParam('Backs par SMW',1e-8,1e-8,1e-5,true);
project.addBackgroundParam('Backs par H2O',1e-8,1e-8,1e-5,true);

% And add the two new constant backgrounds..
project.addBackground('Background SMW','constant','Backs par SMW');
project.addBackground('Background H2O','constant','Backs par H2O');

% And edit the other one....
project.setBackground(1,'name','Background D2O','source','Backs par D2O');

% Finally modify some of the other parameters to be more suitable values
% for a solid / liquid experiment.

% Set the scalefactor...
project.setScalefactor(1,'Value',1,'min',0.5,'max',2,'fit',false);


%% 
% Now we need to add some contrasts - we need three in total. We do this with 
% the 'addContrast' method, and include the relevant bits from the other groups 
% as name value pairs.

% D2O contrast..
project.addContrast('name','Bilayer / D2O',...
    'background','Background D2O',...
    'backgroundAction', backgroundActions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'resample',false,....
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD D2O',...
    'data', 'Bilayer / D2O');

% SMW contrast..
project.addContrast('name','Bilayer / SMW',...
    'background','Background SMW',...
    'backgroundAction', backgroundActions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'resample',false,....
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD SMW',...
    'data', 'Bilayer / SMW');

% SMW contrast..
project.addContrast('name','Bilayer / H2O',...
    'background','Background H2O',...
    'backgroundAction', backgroundActions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'resample',false,...
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD H2O',...
    'data', 'Bilayer / H2O');

%% 
% Finally, add the layers to the contrasts to complete the models:

project.setContrastModel(1,{'Oxide Layer',...
              'Water Layer',...
              'Bil inner head',...
              'Bil tail',...
              'Bil tail',...
              'Bil outer head'});
          
 project.setContrastModel(2, {'Oxide Layer',...
              'Water Layer',...
              'Bil inner head',...
              'Bil tail',...
              'Bil tail',...
              'Bil outer head'});
          
 project.setContrastModel(3,{'Oxide Layer',...
              'Water Layer',...
              'Bil inner head',...
              'Bil tail',...
              'Bil tail',...
              'Bil outer head'});

end