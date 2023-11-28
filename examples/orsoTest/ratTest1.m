



orsoVals = [0.000000000000000000e+00 2.069999999999999840e+00 0.000000000000000000e+00 0.000000000000000000e+00
            1.000000000000000000e+02 3.450000000000000178e+00 1.000000000000000056e-01 3.000000000000000000e+00
            2.000000000000000000e+02 5.000000000000000000e+00 1.000000000000000021e-02 1.000000000000000000e+00
            0.000000000000000000e+00 6.000000000000000000e+00 0.000000000000000000e+00 5.000000000000000000e+00];

orsoVals(:,2) = orsoVals(:,2) .* 1e-6;
orsoVals(:,3) = orsoVals(:,3) .* 1e-6;

problem = createProject(absorption = true);

% Make the parameters....
paramGroup = {
              {'Layer 1 thick',orsoVals(2,1)};
              {'Layer 1 SLD re',orsoVals(2,2)};
              {'Layer 1 SLD im',orsoVals(2,3)};
              {'Layer 1 rough',orsoVals(2,4)};
              {'Layer 2 thick',orsoVals(3,1)}
              {'Layer 2 SLD re',orsoVals(3,2)};
              {'Layer 2 SLD im',orsoVals(3,3)};
              {'Layer 2 rough',orsoVals(3,4)};
              {'Hydration',0}
              };

problem.addParameterGroup(paramGroup);

% Group them into layers...
layer1 = ({'Layer 1' ...
    'Layer 1 thick',...
    'Layer 1 SLD re',...
    'Layer 1 SLD im',...
    'Layer 1 rough'});

layer2 = ({'Layer 2' ...
    'Layer 2 thick',...
    'Layer 2 SLD re',...
    'Layer 2 SLD im',...
    'Layer 2 rough'});

% Add the layers....
problem.addLayer(layer1);
problem.addLayer(layer2);

% Set bulk in...
problem.setBulkIn(1,'Name','Silicon','Value',2.073e-6);

problem.addContrast('name','Orso Test 1',...
    'background','Background 1',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'bulkIn', 'Silicon',...
    'bulkOut', 'SLD D2O',...
    'data', 'Simulation');

problem.setContrastModel(1,{'Layer 1','Layer 2'})


controls = controlsClass();



