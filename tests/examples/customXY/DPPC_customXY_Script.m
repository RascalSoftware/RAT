%%
% Start by making an empty project
problem = projectClass('Custom DPPC');

% Set the experiment type and geometry
problem.setModelType('custom XY');
problem.setGeometry('Substrate/liquid');

% Add some parameters....
Parameters = {
    %       Name                min         val         max     fit? 
        {'Oxide thick',         5,          15,         60,     true   };
        {'Oxide Coverage'       0.7,        0.9,        1,      true   };
        {'Bilayer Position'     45          60          90      true   };
        {'Bilayer Coverage'     0.8         0.99        1.0     true   };
        {'Bilayer Roughness'    3           6           9       true   };
        };
problem.addParamGroup(Parameters);
problem.setParameter(1,'value',5);

%%
% Need to add the relevant Bulk SLD's. Change the bulk in from air to silicon, 
% and add two additional water contrasts:

% Change bulk in from air to silicon....
problem.setBulkIn(1,'name','Silicon','min',2.07e-6,'value',2.073e-6,'max',2.08e-6,'fit',false);

% Add two more values for bulk out....
problem.addBulkOut('SLD SMW',1e-6,2.073e-6,3e-6,true);
problem.addBulkOut('SLD H2O',-0.6e-6,-0.56e-6,-0.3e-6,true);
problem.setBulkOut(1,'fit',true,'min',5e-6);

%%
% Now add the custom file to the project..
problem.addCustomFile('DPPC Model','DPPC_customXY.m','matlab','pwd');


%% 
% Also, add the relevant background parameters - one each for each contrast:

% Change the name of the existing parameters to refer to D2O
problem.setBacksPar(1,'name','Backs par D2O','fit',true,'min',1e-7,'max',1e-5,'val',1e-6);

% Add two new backs parameters for the other two..
problem.addBacksPar('Backs par SMW',1e-7,1e-7,1e-5,true);
problem.addBacksPar('Backs par H2O',1e-7,1e-7,1e-5,true);

% And add the two new constant backgrounds..
problem.addBackground('Background SMW','constant','Backs par SMW');
problem.addBackground('Background H2O','constant','Backs par H2O');

% And edit the other one....
problem.setBackgroundValue(1,'name','Background D2O');
problem.setBackgroundValue(1,'value','Backs par D2O');

% Set the scalefactor...
problem.setScalefactor(1,'Value',1,'min',0.5,'max',2,'fit',true);

%%
% Now add the three contrasts as before:

% D2O contrast..
problem.addContrast('name','Bilayer / D2O',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...        % This is bulk out ('Nb Subs')
    'nba', 'Silicon',...        % This is bulk in ('Nb Air')
    'data','Simulation');       % Empty data object       

% SMW contrast..
problem.addContrast('name','Bilayer / SMW',...
    'background','Background SMW',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD SMW',...        % This is bulk out
    'nba', 'Silicon',...        % This is bulk in
    'data','Simulation');       % empty data object for Simulation          

% SMW contrast..
problem.addContrast('name','Bilayer / H2O',...
    'background','Background H2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD H2O',...        % This is bulk out
    'nba', 'Silicon',...        % This is bulk in
    'data','Simulation');       % Empty data object
    
% Just doing simulations for now, so no Data required

%%
% Set the model for each contrasts
problem.setContrastModel(1,'DPPC Model');
problem.setContrastModel(2,'DPPC Model');
problem.setContrastModel(3,'DPPC Model');

disp('debug');

%%

% Make a controls block
controls = controlsDef();
controls.parallel = 'points';

%%

% % Send this to RAT
 [problem,results] = RAT(problem,controls);
% 
% % Plot the results....
% figure(1); clf
% plotRefSLD(problem,results);







