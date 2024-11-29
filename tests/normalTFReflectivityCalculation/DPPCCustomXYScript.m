function project = DPPCCustomXYScript()

%%
% Start by making an empty project
project = projectClass('Custom DPPC');

% Set the experiment type and geometry
project.setModelType('custom XY');
project.setGeometry('Substrate/liquid');

% Add some parameters....
Parameters = {
    %       Name                min         val         max     fit? 
        {'Oxide thick',         5,          15,         60,     true   };
        {'Oxide Coverage'       0.7,        0.9,        1,      true   };
        {'Bilayer Position'     45          60          90      true   };
        {'Bilayer Coverage'     0.8         0.99        1.0     true   };
        {'Bilayer Roughness'    3           6           9       true   };
        };
project.addParameterGroup(Parameters);
project.setParameter(1,'value',5);

%%
% Need to add the relevant Bulk SLD's. Change the bulk in from air to silicon, 
% and add two additional water contrasts:

% Change bulk in from air to silicon....
project.setBulkIn(1,'name','Silicon','min',2.07e-6,'value',2.073e-6,'max',2.08e-6,'fit',false);

% Add two more values for bulk out....
project.addBulkOut('SLD SMW',1e-6,2.073e-6,3e-6,true);
project.addBulkOut('SLD H2O',-0.6e-6,-0.56e-6,-0.3e-6,true);
project.setBulkOut(1,'fit',true,'min',5e-6);

%%
% Now add the custom file to the project..
project.addCustomFile('DPPC Model','DPPCCustomXY.m','matlab','tests/normalTFReflectivityCalculation/');


%% 
% Also, add the relevant background parameters - one each for each contrast:

% Change the name of the existing parameters to refer to D2O
project.setBackgroundParam(1,'name','Backs par D2O','fit',true,'min',1e-7,'max',1e-5,'val',1e-6);

% Add two new backs parameters for the other two..
project.addBackgroundParam('Backs par SMW',1e-7,1e-7,1e-5,true);
project.addBackgroundParam('Backs par H2O',1e-7,1e-7,1e-5,true);

% And add the two new constant backgrounds..
project.addBackground('Background SMW','constant','Backs par SMW');
project.addBackground('Background H2O','constant','Backs par H2O');

% And edit the other one....
project.setBackground(1,'name','Background D2O','source','Backs par D2O');

% Set the scalefactor...
project.setScalefactor(1,'Value',1,'min',0.5,'max',2,'fit',true);

%%
% Now add the three contrasts as before:

% D2O contrast..
project.addContrast('name','Bilayer / D2O',...
    'background','Background D2O',...
    'backgroundAction', actions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD D2O',...
    'data','Simulation');       % Empty data object       

% SMW contrast..
project.addContrast('name','Bilayer / SMW',...
    'background','Background SMW',...
    'backgroundAction', actions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD SMW',...
    'data','Simulation');       % empty data object for Simulation          

% SMW contrast..
project.addContrast('name','Bilayer / H2O',...
    'background','Background H2O',...
    'backgroundAction', actions.Add,...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD H2O',...
    'data','Simulation');       % Empty data object
    
% Just doing simulations for now, so no Data required

%%
% Set the model for each contrasts
project.setContrastModel(1,'DPPC Model');
project.setContrastModel(2,'DPPC Model');
project.setContrastModel(3,'DPPC Model');


end
