% Standard Layers fit of a DSPC floating bilayer

% Make the project
problem = createProject(name='original_dspc_bilayer', calcType='non polarised', model='standard layers', geometry='substrate/liquid', absorption=false);

% Make priors visible..
problem.setUsePriors(true);

% Set up the relevant parameters
paramGroup = {
              {'Oxide thick',           5,      19.54,      60,     true,   'uniform',      0,  Inf};
              {'Oxide SLD',         3.39e-06,   3.39e-06, 3.41e-06, false,  'uniform',      0,  Inf};
              {'Sam tails thick',       15,     22.66,      35,     true,   'uniform',      0,  Inf};
              {'Sam tails SLD',         -5e-07, -4.01e-07, -3e-07,  false,  'uniform',      0,  Inf};
              {'Sam tails hydration',   1,      5.253,      50,     true,   'uniform',      0,  Inf};
              {'Sam rough',             1,      5.64,       15,     true,   'uniform',      0,  Inf};
              {'cw thick',              10,     17.12,      28,     true,   'uniform',      0,  Inf};
              {'cw SLD',                0,      0,          1e-09,  false,  'uniform',      0,  Inf};
              {'SAM head thick',        5,      8.56,       17,     true,   'gaussian',    10,    2};
              {'SAM head SLD',          1e-07,  1.75e-06,   2e-06,  false,  'uniform',      0,  Inf};
              {'SAM head hydration',    10,     45.45,      50,     true,   'uniform',     30,    3};
              {'Bilayer head thick',    7,      10.70,      17,     true,   'gaussian',    10,    2};
              {'Bilayer head SLD',      5e-07,  1.47e-06, 1.5e-06,  false,  'uniform',      0,  Inf};
              {'Bilayer rough',         2,      6.014,      15,     true,   'uniform',      0,  Inf};
              {'Bilayer tails thick',   14,     17.82,      22,     true,   'uniform',      0,  Inf};
              {'Bilayer tails SLD',     -5e-07, -4.610e-07, 0,      false,  'uniform',      0,  Inf};
              {'Bilayer tails hydr',    10,     17.64,      50,     true,   'uniform',      0,  Inf};
              {'Bilayer heads hydr',    10,     36.15,      50,     true,   'gaussian',    30,    3};
              {'cw hydration',          99.9,   100,        100,    false,  'uniform',      0,  Inf};
              {'Oxide Hydration',       0,      23.61,      60,     true,   'uniform',      0,  Inf};
              };
problem.addParameterGroup(paramGroup);
problem.setParameter(1,'max',10);

% Group these into layers....
Layers =    {
            {'Oxide',           'Oxide thick',          'Oxide SLD',        'substrate roughness',  'Oxide Hydration',      'bulk out'};
            {'Sam tails',       'Sam tails thick',      'Sam tails SLD',    'Sam rough',            'Sam tails hydration',  'bulk out'};
            {'Sam heads',       'SAM head thick',       'SAM head SLD',     'Sam rough',            'SAM head hydration',   'bulk out'};
            {'Central water',   'cw thick',             'cw SLD',           'Bilayer rough',        'cw hydration',         'bulk out'};
            {'Bilayer heads',   'Bilayer head thick',   'Bilayer head SLD', 'Bilayer rough',        'Bilayer heads hydr',   'bulk out'};
            {'Bilayer tails',   'Bilayer tails thick',  'Bilayer tails SLD','Bilayer rough',        'Bilayer tails hydr',   'bulk out'};
};
problem.addLayerGroup(Layers);

% Make the bulk SLD's
problem.removeBulkIn(1);
problem.addBulkIn('Silicon', 2e-06, 2.073e-06, 2.1e-06, false);

problem.removeBulkOut(1);
problem.addBulkOut('D2O', 5.50e-06, 5.98e-06, 6.4e-06, true);
problem.addBulkOut('SMW', 1e-06, 2.21e-06, 4.99e-06, true);

% Set the scalefactors - use one for each contrast
problem.removeScalefactor(1);
problem.addScalefactor('Scalefactor 1', 0.05, 0.10, 0.2, false);
problem.addScalefactor('Scalefactor 2', 0.05, 0.15, 0.2, false);

% Now add the data....
d2o_dat = readmatrix('DSPC_D2O.dat');
problem.addData('dspc_bil_d2O', d2o_dat);

smw_dat = readmatrix('DSPC_SMW.dat');
problem.addData('dspc_bil_smw', smw_dat);

% Now deal with the backgrounds....
% Original Constant background....
problem.removeBackgroundParam(1);
problem.addBackgroundParam('Backs parameter SMW', 1e-10, 3.38e-06, 4.99e-06,   true);

problem.removeBackground(1);
problem.addBackground('SMW Background','constant','Backs parameter SMW');

% Now deal with the data background....
% Add the background data....
d2oBack = readmatrix('d2o_background_data.dat');
problem.addData('D2O Background Data',d2oBack);

% We need an offset for the D2O BAckground data....
problem.addBackgroundParam('D2O Data Offset',-1e-8,0,1e-8,true);

% Add a D2O Data background....
problem.addBackground('D2O data background','data','D2O Background Data','D2O Data Offset');

% % Also the function background...
% problem.addCustomFile('Back Fun','backgroundFunction.m','matlab',pwd);
% 
% %..andBackgroundParams...
% problem.addBackgroundParam('Fn Ao',5e-7,8e-6,5e-5);
% problem.addBackgroundParam('Fn k',40,70,90);
% problem.addBackgroundParam('Fn Const',1e-7,8e-6,1e-5);
% 
% % ...and Background....
% problem.addBackground('Func Background','function','Fn Ao','Fn k','Fn Const');

% Make the two contrasts....
problem.addContrast('name',         'D2O',...
                    'BulkIn',       'Silicon',...
                    'BulkOut',      'D2O',...
                    'background',   'D2O data background',...
                    'resolution',   'Resolution 1',... 
                    'scalefactor',  'Scalefactor 1',...
                    'data',         'dspc_bil_d2o');

problem.addContrast('name',         'SMW',...
                    'BulkIn',       'Silicon',...
                    'BulkOut',      'SMW',...
                    'background',   'SMW Background',...
                    'resolution',   'Resolution 1',... 
                    'scalefactor',  'Scalefactor 2',...
                    'data',         'dspc_bil_smw');

% And set the model
stack =  {'Oxide',...
          'Sam tails',...
          'Sam heads',...
          'Central water',...
          'Bilayer heads',... 
          'Bilayer tails',...
          'Bilayer tails',... 
          'Bilayer heads',...
          };

problem.setContrastModel(1,stack);
problem.setContrastModel(2,stack);

% Make a controls class....
controls = controlsClass();

% Send everything to RAT....
[problem,results] = RAT(problem,controls);

plotRefSLD(problem,results);

