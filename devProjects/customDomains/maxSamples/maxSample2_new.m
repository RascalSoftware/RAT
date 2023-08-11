% Test of custom layers domains prioject...
% Use incoherent summing on a ozone attacked sample

problem = project(calcType="domains");
problem.setModelType('custom layers');
problem.setGeometry('air/substrate');

% Make some parameters...
params = {{'Oxide thick',   10,         20,     50,     true}
          {'Layer thick',   150,         300,    500,    true}
          {'Layer SLD',     1e-6,       2e-6,   4e-6,   true}
          {'Layer rough',   5,          10,     20,     true}
          {'Domain d L1',   10,         20,     30,     true}
          {'Domain rho l1', 1e-6,       2e-6,   3e-6,   true}
          {'Domain sig l1', 3,          5,      9,      true}
          {'Water lay d',   5,          15,     50,     true}
          {'Water lay rho', -0.5e-6,    3e-6,   6.35e-6,true}
          {'Water lay sig', 3,          5,      10,     true}
          {'Dom nRepeats',  1,          10,     30,     true}
    };

problem.addParameterGroup(params);

% Set the bulk SLD
problem.setBulkIn(1,'name','Air','Value',0,'fit',false);

% and scalefactor...
problem.setScalefactor(1,'min',0.8,'Value',1,'max',1.1);

% Add another bulk-out (and modify the first)
problem.setBulkOut(1,'name','Silicon','value',2.073e-6,'fit',false);

% Set some fitting flags.
problem.setScalefactor(1,'fit',true);
problem.setBacksPar(1,'fit',true);
problem.setResolPar(1,'fit',true);
problem.setDomainRatio(1,'fit',true);

% Add the custom file...
problem.addCustomFile('Ozone domains','ozoneDomains_Si_new.m','matlab',pwd);

% Load in the datafiles...
thisData = dlmread('IvsQ_55214_55215.dat');
% d2oData = dlmread('sam_D2O.dat');
% h2oData = dlmread('sam_H2O.dat');

problem.addData('airSiData',thisData);
%problem.addData('H2O_SAM',h2oData);

% Make some contrasts...
problem.addContrast('name',       'Sample 2', ...
                    'Data',       'airSiData',...
                    'Background', 'Background 1',...
                    'nba',        'Air',...
                    'nbs',        'Silicon',...
                    'Scalefactor','Scalefactor 1', ...
                    'Resolution', 'Resolution 1',...
                    'Resample',    false,...
                    'domainRatio','Domain Ratio 1');

problem.setContrastModel(1,'Ozone domains')


