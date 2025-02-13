% Quick script to check if we have a clean D2O calibfration surface..

% Make an instance of projectClass...
problem = projectClass();

% Add some data....
% dat = readtable('f82395c.dat');
dat = readtable('IvsQ_81455_81456.dat');
dat = table2array(dat);
problem.addData('D2O',dat);

problem.setScalefactor(1,'min',0.9,'max',1.1,'value',0.93,'fit',true);
problem.setBackgroundParam(1,'fit',true);
problem.setParameter(1,'max',8.0);

% Run to fit...
controls = controlsClass();
controls.procedure = 'de';
controls.display = 'final';
[problem,results] = RAT(problem,controls);

% Do the nested sampling...
controls.procedure = 'ns';
controls.nsTolerance = 0.01;
% controls.nMCMC = 100;
[problem,resultsNoLayer] = RAT(problem,controls);


%% Add a layer...
paramGroup = {
             {'Lay thick',      5,      10,     20,      true}
             {'Lay SLD',     -1e-6,     0,     1e-6,     true}
             {'Lay rough',   -1e-6,     10,     20,      true}
                                                        };

problem.addParameterGroup(paramGroup);
problem.addLayer('Layer1',  'Lay thick',  'Lay SLD',    'Lay rough');

% Make our contrast....
problem.addContrast('name',          'D2O Contrast',...
                    'BulkIn',        'SLD Air',...
                    'BulkOut',       'SLD D2O',...
                    'resolution',    'Resolution 1',...
                    'background',    'Background 1',...
                    'data',          'D2O',...
                    'scalefactor',   'Scalefactor 1', ...
                    'model',         'Layer1');

%% Re-run the nested sampling....
[problem,oneLayerResults] = RAT(problem,controls);


%% Check the stats....
oneLayerLogZ = oneLayerResults.nestedSamplerOutput.LogZ;
noLayerLogZ = resultsNoLayer.nestedSamplerOutput.LogZ;

evDiff = exp(noLayerLogZ - oneLayerLogZ);
fprintf('Nested sampling suggests thatconfidence level of the surface being clean is %g %% \n', (evDiff / (1+evDiff)) * 100)
