

problem = createProject(model = 'custom XY', geometry = 'Air/substrate');

% Add the parameters
parameters = {{'layerThick',10,   50,   70  }
              {'layerSLD',  2e-6, 3e-6, 4e-6}
              {'layerRough',  5,  8,    12  }
              };

problem.addParameterGroup(parameters);

% Change the bulk-out to Si....
problem.setBulkOut(1,'name','SLD Silicon','value',2.073e-6,'fit',false);

% Add the custom model....
problem.addCustomFile('LayerMod','tanhLayer.m','matlab',pwd);

% Make the contrast...
problem.addContrast('name',         'Simple Layer',...
                    'bulkIn',       'SLD Air',...
                    'bulkOut',      'SLD Silicon',...
                    'resolution',   'Resolution 1',...
                    'scalefactor',  'Scalefactor 1',...
                    'background',   'Background 1',...
                    'Data',         'Simulation');

problem.setContrastModel(1,'LayerMod');








