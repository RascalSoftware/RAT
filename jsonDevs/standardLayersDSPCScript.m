% Standard Layers fit of a DSPC floating bilayer

% Make the project
problem = createProject(name='original_dspc_bilayer', calcType='normal', model='standard layers', geometry='substrate/liquid', absorption=false);

% Make priors visible..
problem.showPriors = false;

% Set up the relevant parameters
paramGroup = {
              {'Oxide Thickness',           5,      19.54,      60,     true,   'uniform',      0,  Inf};
              {'Oxide SLD',         3.39e-06,   3.39e-06, 3.41e-06, false,  'uniform',      0,  Inf};
              {'Sam Tails Thickness',       15,     22.66,      35,     true,   'uniform',      0,  Inf};
              {'Sam Tails SLD',         -5e-07, -4.01e-07, -3e-07,  false,  'uniform',      0,  Inf};
              {'Sam Tails Hydration',   1,      5.253,      50,     true,   'uniform',      0,  Inf};
              {'Sam Roughness',             1,      5.64,       15,     true,   'uniform',      0,  Inf};
              {'CW Thickness',              10,     17.12,      28,     true,   'uniform',      0,  Inf};
              {'CW SLD',                0,      0,          1e-09,  false,  'uniform',      0,  Inf};
              {'SAM Heads Thickness',        5,      8.56,       17,     true,   'gaussian',    10,    2};
              {'SAM Heads SLD',          1e-07,  1.75e-06,   2e-06,  false,  'uniform',      0,  Inf};
              {'SAM Heads Hydration',    10,     45.45,      50,     true,   'uniform',      0,  Inf};
              {'Bilayer Heads Thickness',    7,      10.70,      17,     true,   'gaussian',    10,    2};
              {'Bilayer Heads SLD',      5e-07,  1.47e-06, 1.5e-06,  false,  'uniform',      0,  Inf};
              {'Bilayer Roughness',         2,      6.014,      15,     true,   'uniform',      0,  Inf};
              {'Bilayer Tails Thickness',   14,     17.82,      22,     true,   'uniform',      0,  Inf};
              {'Bilayer Tails SLD',     -5e-07, -4.610e-07, 0,      false,  'uniform',      0,  Inf};
              {'Bilayer Tails Hydration',    10,     17.64,      50,     true,   'uniform',      0,  Inf};
              {'Bilayer Heads Hydration',    10,     36.15,      50,     true,   'gaussian',    30,    3};
              {'CW Hydration',          99.9,   100,        100,    false,  'uniform',      0,  Inf};
              {'Oxide Hydration',       0,      23.61,      60,     true,   'uniform',      0,  Inf};
              };
problem.addParameterGroup(paramGroup);
problem.setParameter(1,'max',10);

% Group these into layers....
Layers =    {
            {'Oxide',           'Oxide Thickness',          'Oxide SLD',         'Substrate Roughness',     'Oxide Hydration',      'bulk out'};
            {'Sam Tails',       'Sam Tails Thickness',      'Sam Tails SLD',     'Sam Roughness',           'Sam Tails Hydration',  'bulk out'};
            {'Sam Heads',       'SAM Heads Thickness',       'SAM Heads SLD',     'Sam Roughness',            'SAM Heads Hydration',   'bulk out'};
            {'Central water',   'CW Thickness',             'CW SLD',            'Bilayer Roughness',        'CW Hydration',         'bulk out'};
            {'Bilayer heads',   'Bilayer Heads Thickness',  'Bilayer Heads SLD', 'Bilayer Roughness',        'Bilayer Heads Hydration',   'bulk out'};
            {'Bilayer tails',   'Bilayer Tails Thickness',  'Bilayer Tails SLD', 'Bilayer Roughness',        'Bilayer Tails Hydration',   'bulk out'};
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

% Now deal with the backgrounds....
problem.removeBackgroundParam(1);
problem.addBackgroundParam('Backs parameter D2O', 5e-10, 2.23e-06, 7e-06,      true);
problem.addBackgroundParam('Backs parameter SMW', 1e-10, 3.38e-06, 4.99e-06,   true);

problem.removeBackground(1);
problem.addBackground('D2O Background','constant','Backs parameter D2O');
problem.addBackground('SMW Background','constant','Backs parameter SMW');

% Now add the data....
d2o_dat = readmatrix(fullfile('standardLayers','DSPC_D2O.dat'));
problem.addData('dspc_bil_d2O', d2o_dat);

smw_dat = readmatrix(fullfile('standardLayers','DSPC_SMW.dat'));
problem.addData('dspc_bil_smw', smw_dat);

% Set the model for the contrasts
stack =  {'Oxide',...
          'Sam tails',...
          'Sam heads',...
          'Central water',...
          'Bilayer heads',... 
          'Bilayer tails',...
          'Bilayer tails',... 
          'Bilayer heads',...
          };

% Make the two contrasts
problem.addContrast('name',         'D2O',...
                    'BulkIn',       'Silicon',...
                    'BulkOut',      'D2O',...
                    'background',   'D2O Background',...
                    'resolution',   'Resolution 1',...
                    'scalefactor',  'Scalefactor 1',...
                    'data',         'dspc_bil_d2o',...
                    'resample',      true,...
                    'model',         stack);

problem.addContrast('name',         'SMW',...
                    'BulkIn',       'Silicon',...
                    'BulkOut',      'SMW',...
                    'background',   'SMW Background',...
                    'resolution',   'Resolution 1',... 
                    'scalefactor',  'Scalefactor 2',...
                    'data',         'dspc_bil_smw',...
                    'resample',      true,...
                    'model',         stack);

