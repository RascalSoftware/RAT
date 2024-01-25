
% Test of custom layers domains project...
% Use incoherent summing on a permalloy layer
% as a test

problem = createProject(calcType="domains");
problem.setModelType('custom layers');
problem.setGeometry('substrate/liquid');

% Make some parameters...
params = {{'Alloy thick',   100,    150,    200,   true}
          {'Alloy SLD up',  9e-6,   11e-6,  13e-6, true}
          {'Alloy SLD dn',  5e-6,   7e-6,   10e-6, true}
          {'Alloy rough',   5,      7,      11,    true}
          {'Gold thick',    100,    150,    200,   true}
          {'Gold SLD',      4e-6,   4.5e-6, 5e-6,  true}
          {'Gold Rough',    5,      7,      11,    true}
    };

problem.addParameterGroup(params);

% Set the bulk SLD
problem.setBulkIn(1,'name','Silicon','Value',2.073e-6);

% Add the custom file...
problem.addCustomFile('Alloy domains','alloyDomains.m','matlab',pwd);

% Make a contrast...
problem.addContrast('name',        'D2O Conrast', ...
                    'Data',        'Simulation',...
                    'Background',  'Background 1',...
                    'BulkIn',      'Silicon',...
                    'BulkOut',     'SLD D2O',...
                    'Scalefactor', 'Scalefactor 1', ...
                    'Resolution',  'Resolution 1',...
                    'Resample',     false,...
                    'domainRatio', 'Domain Ratio 1');

problem.setContrastModel(1,'Alloy domains');








