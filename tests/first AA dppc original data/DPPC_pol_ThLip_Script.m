%%
function problem = orsoTestScript()

% Start by making an empty project
problem = projectClass('Custom DPPC');

% Set the experiment type and geometry
problem.setModelType('custom XY');
problem.setGeometry('Substrate/liquid');

% Add some parameters....
Parameters = {
    %       Name                min         val         max         fit? 
        {'Oxide thick',         0,          15,         60,         true   };
        {'Alloy thick'          120,        135,        200,        true   };
        {'Allot SLD up'         5e-6,       9.9e-6,     11e-6,      true   };
        {'Alloy SLD down'       5e-6,       7e-6,       11e-6,      true   };
        {'Alloy rough',         1,          7,          11,         true   };
        {'Gold thick',          100,        153,        200,        true   };
        {'Gold rough',          1,          9,          15,         true   };
        {'SAM tails thick',     10,         15,         21,         true   };
        {'SAM tails SLD',       -1e-6,    -0.4e-6,    -0.1e-6,    true   };
        {'SAM tails Coveraage', 0.8,        0.9,        1.0,        true   };
        {'SAM heads thick',     7,          11,         15,         true   };
        {'SAM heads SLD',       1e-6,       1.7e-6,     3e-6,       true   };
        {'SAM heads coverage'   0.6,        0.7,        1.0,        true   };
        {'SAM rough',           1,          7,          15,         true   };
        {'Bilayer Position'     25          45          90          true   };
        {'Bilayer Coverage'     0.8         0.99        1.0         true   };
        {'Bilayer Roughness'    0.1           6           9           true   };
        };
problem.addParamGroup(Parameters);
problem.setParameter(1,'value',5);

%%
% Need to add the relevant Bulk SLD's. Change the bulk in from air to silicon, 
% and add two additional water contrasts:

% Change bulk in from air to silicon....
problem.setBulkIn(1,'name','Silicon','min',2.07e-6,'value',2.073e-6,'max',2.08e-6,'fit',false);

% Add two more values for bulk out....
problem.addBulkOut({'SLD H2O',-0.6e-6,-0.56e-6,-0.3e-6,true});
problem.setBulkOut(1,'fit',true,'min',5e-6);

%%
% Now add the custom file to the project..
problem.addCustomFile({'DPPC Model','DPPC_customXY.m','matlab','pwd'});

%%
% Add the data to the project
D2O_up = dlmread(fullfile(pwd,'simsAndData','f92408_10_D2O_u_3pc_sc.dat'));
D2O_dn = dlmread(fullfile(pwd,'simsAndData','f92408_10_D2O_d_3pc.dat'));
H2O_up = dlmread(fullfile(pwd,'simsAndData','f92411_13_H2O_u_3pc_sc.dat'));
H2O_dn = dlmread(fullfile(pwd,'simsAndData','f92411_13_H2O_d_3pc_sc.dat'));

problem.addData('D2O up',D2O_up);
problem.addData('D2O dn',D2O_dn);
problem.addData('H2O up',H2O_up);
problem.addData('H2O dn',H2O_dn);

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

% D2O up contrast..
problem.addContrast('name','Bilayer / D2O up',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...        % This is bulk out ('Nb Subs')
    'nba', 'Silicon',...        % This is bulk in ('Nb Air')
    'data','D2O dn');              

% D2O dn contrast..
problem.addContrast('name','Bilayer / D2O dn',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...        % This is bulk out
    'nba', 'Silicon',...        % This is bulk in
    'data','D2O up');                

% H2O up contrast..
problem.addContrast('name','Bilayer / H2O up',...
    'background','Background H2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD H2O',...        % This is bulk out
    'nba', 'Silicon',...        % This is bulk in
    'data','H2O up');      

% H2O up contrast..
problem.addContrast('name','Bilayer / H2O dn',...
    'background','Background H2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD H2O',...        % This is bulk out
    'nba', 'Silicon',...        % This is bulk in
    'data','H2O dn'); 


%%
% Set the model for each contrasts
problem.setContrastModel(1,'DPPC Model');
problem.setContrastModel(2,'DPPC Model');
problem.setContrastModel(3,'DPPC Model');
problem.setContrastModel(4,'DPPC Model');

disp('debug');

%%

% Make a controls block
controls = controlsDef();

%%

% Send this to RAT
[problem,results] = RAT(problem,controls);

% % Plot the results....
% figure(1); clf
% plotRefSLD(problem,results);
% 
% controls.procedure = 'bayes';
% controls.nsimu = 5000;
% controls.repeats = 3;
% controls.parallel = 'contrasts';
% [problem,results] = RAT(problem,controls);
% plotBayes(problem,results)







