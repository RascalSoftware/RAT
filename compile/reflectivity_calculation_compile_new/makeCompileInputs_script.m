% Script to generate inputs for compiling reflectivity_calculation

% Start by making an empty instance of the project definition class:
problem = projectClass('Orso lipid example');

Parameters = {
    %       Name                min         val         max     fit? 
        {'Oxide thick',         5,         20,         60,     true   };
        {'Oxide SLD',           3e-6,       3.41e-6,    4e-6,   false  };
        {'Oxide Hydration'      0,          20,         30,     true   }};
 problem.addParamGroup(Parameters);
        
% Now make the oxide layer
Oxide =     {'Oxide Layer',...          % Name of the layer
                'Oxide thick',...           % Layer thickness
                'Oxide SLD',...             % Layer SLD
                'Substrate Roughness',...   % Layer roughness
                'Oxide Hydration',...       % Oxide hydration (precent)
                'bulk out' };               % Which bulk phase is hydrating the layer
            
% Add this to the project...
problem.addLayer(Oxide);

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
problem.addParamGroup(watParams);
problem.addParamGroup(bilParams);

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

% Add these layers to the project:
problem.addLayerGroup({waterLayer ; bilInnerHead ; bilTails ; bilOuterHead});

% We have three datasets we need to consider - the bilayer against D2O, Silicon 
% Matched water and H2O. Load these datafiles in and put them in the data block....

% Read in the datafiles
D2O_data = dlmread('c_PLP0016596.dat');
SMW_data = dlmread('c_PLP0016601.dat');
H2O_data = dlmread('c_PLP0016607.dat');

% Add the data to the project
problem.addData('Bilayer / D2O', D2O_data(:,1:3));
problem.addData('Bilayer / SMW', SMW_data(:,1:3));
problem.addData('Bilayer / H2O', H2O_data(:,1:3));

problem.setData(2,'dataRange',[0.013 0.35],'simRange',[0.013 0.35]);
problem.setData(3,'dataRange',[0.013 0.35],'simRange',[0.013 0.35]);
problem.setData(4,'dataRange',[0.013 0.35],'simRange',[0.013 0.35]);


% We also need the correct SLD's for the bulk phases.....

% Change bulk in from air to silicon....
problem.setBulkIn(1,'name','Silicon','min',2.07e-6,'value',2.073e-6,'max',2.08e-6,'fit',false);

% Add two more values for bulk out....
problem.addBulkOut({'SLD SMW',2e-6,2.073e-6,3e-6,true});
problem.addBulkOut({'SLD H2O',-0.6e-6,-0.56e-6,-0.3e-6,true});
problem.setBulkOut(1,'min',4e-6,'fit',true);

problem.setBulkOut(1,'fit',true);
problem.setBulkOut(2,'fit',true);
problem.setBulkOut(3,'fit',true);



% We also need a different background for each contrast. Backgrounds in RAT 
% are split into two parts - background parameters (which are fittable), and these 
% are then used in the backgrounds themselves as required (there will be more 
% explanation on this in a future worksheet, but this allows custom background 
% functions with several fittable parameters - or background data - to be defined). 
% In this case, we'll just use constant background types, so these need only one 
% parameter each...

% Change the name of the existing parameters to refer to D2O
problem.setBacksPar(1,'name','Backs par D2O','fit',true,'min',1e-8,'max',1e-5);

% Add two new backs parameters for the other two..
problem.addBacksPar('Backs par SMW',1e-8,1e-8,1e-5,true);
problem.addBacksPar('Backs par H2O',1e-8,1e-8,1e-5,true);

% And add the two new constant backgrounds..
problem.addBackground('Background SMW','constant','Backs par SMW');
problem.addBackground('Background H2O','constant','Backs par H2O');

% And edit the other one....
problem.setBackgroundValue(1,'name','Background D2O');
problem.setBackgroundValue(1,'value','Backs par D2O');

% Finally modify some of the other parameters to be more suitable values
% for a solid / liquid experiment.
% Set the scalefactor...
problem.setScalefactor(1,'Value',1,'min',0.5,'max',2,'fit',false);


% Now we need to add some contrasts - we need three in total. We do this with 
% the 'addContrast' method, and include the relevant bits from the other groups 
% as name value pairs.

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


% Finally, add the layers to the contrasts to complete the models:

problem.setContrastModel(1,{'Oxide Layer',...
              'Water Layer',...
              'Bil inner head',...
              'Bil tail',...
              'Bil tail',...
              'Bil outer head'});
          
 problem.setContrastModel(2, {'Oxide Layer',...
              'Water Layer',...
              'Bil inner head',...
              'Bil tail',...
              'Bil tail',...
              'Bil outer head'});
          
 problem.setContrastModel(3,{'Oxide Layer',...
              'Water Layer',...
              'Bil inner head',...
              'Bil tail',...
              'Bil tail',...
              'Bil outer head'});

% Now set somne priors (for completeness - they are not passed to
% reflectivity_calculation)
problem.setUsePriors(true); 
problem.setParamPrior('Bilayer heads thick','gaussian',10,0.2);
problem.setParamPrior('Bilayer heads sld','gaussian',1.4e-6,2e-7);

% Just so that all the inputs are properly defined, also add a 
% custom file, otherwise the compiler can't tell the size of
% this array..
problem.addCustomFile({'A Model','aModelFile.m','matlab','pwd'});
        
% We need a controls Def class
controls = controlsDef;
controls.procedure = 'calculate';
controls.calcSldDuringFit = 'yes';

% Convert these to the types (structs) needed for direct input to reflectivity_calculation using 
% the functions from RAT.
[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(problem,controls);

% Call 'reflectivity_calculation'....
[problem,result] = reflectivity_calculation(problemDef,problemDef_cells,problemDef_limits,controls);





