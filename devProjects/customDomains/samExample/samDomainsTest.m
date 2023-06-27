
% Test of custom layers domains prioject...
% Use incoherent summing on a permalloy layer
% as a test

problem = project(type="domains");
problem.setModelType('custom layers');
problem.setGeometry('substrate/liquid');
problem.absorption = true;

% Make some parameters...
params = {{'Alloy thick',      100,    150,    200,   true}
          {'Alloy SLD up RE',  9e-6,   11e-6,  13e-6, true}
          {'Alloy SLD up Im',  1e-8,   5e-8,  10e-8,  true}
          {'Alloy SLD dn',     5e-6,   7e-6,   10e-6, true}
          {'Alloy SLD dn Im',  1e-8,   5e-8,  10e-8,  true}
          {'Alloy rough',      5,      7,      11,    true}
          {'Gold thick',       100,    150,    200,   true}
          {'Gold SLD Re',      4e-6,   4.5e-6, 5e-6,  true}
          {'Gold SLD Im'       1e-8,   5e-8,   10e-8  true}
          {'Gold Rough',       5,      7,      11,    true}
          {'SAM tails thick',  5,      7,      11,    true}
          {'Sam Tails SLD',    -0.5e-6, -1e-6, 1e-6,  true}
          {'Sam Head thick',    5,     10,      12,   true}
          {'Sam Head SLD',      1e-6,  1.4e-6,  2e-6, true}
          {'Sam head Hydration', 0.1,   0.3,    0.5,  true}
          {'Sam coverage',       0.5,   0.9,    1.0,  true}
          {'Sam rough',         3,      5,      7,    true}
    };

problem.addParameterGroup(params);

% Set the bulk SLD
problem.setBulkIn(1,'name','Silicon','Value',2.073e-6);

% and scalefactor...
problem.setScalefactor(1,'min',0.8,'Value',1,'max',1.1);

% Add another bulk-out (and modify the first)
problem.addBulkOut('SLD H2O', -0.6e-6, -0.56e-6, -0.4e-6, true);
problem.setBulkOut(1,'fit',true);

% Set some fitting flags.
problem.setScalefactor(1,'fit',true);
problem.setBacksPar(1,'fit',true);
problem.setResolPar(1,'fit',true);
problem.setDomainRatio(1,'fit',true)

% Add the custom file...
problem.addCustomFile('Alloy domains SAM','alloyDomains_SAM.m','matlab',pwd);

% Load in the datafiles...
d2oData = dlmread('sam_D2O.dat');
h2oData = dlmread('sam_H2O.dat');

problem.addData('D2O_SAM',d2oData);
problem.addData('H2O_SAM',h2oData);

% Make some contrasts...
problem.addContrast('name',       'D2O Conrast', ...
                    'Data',       'D2O_SAM',...
                    'Background', 'Background 1',...
                    'nba',        'Silicon',...
                    'nbs',        'SLD D2O',...
                    'Scalefactor','Scalefactor 1', ...
                    'Resolution', 'Resolution 1',...
                    'Resample',    false,...
                    'domainRatio','Domain Ratio 1');

problem.addContrast('name',       'H2O Conrast', ...
                    'Data',       'H2O_SAM',...
                    'Background', 'Background 1',...
                    'nba',        'Silicon',...
                    'nbs',        'SLD H2O',...
                    'Scalefactor','Scalefactor 1', ...
                    'Resolution', 'Resolution 1',...
                    'Resample',    false,...
                    'domainRatio','Domain Ratio 1');

problem.setContrastModel(1,'Alloy domains SAM');
problem.setContrastModel(2,'Alloy domains SAM');







