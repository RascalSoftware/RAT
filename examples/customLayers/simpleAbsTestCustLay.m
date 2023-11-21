% Test of absorbance for standard layers....

% (1) Two layers with absorption..
problem = createProject(absorption=true);
problem.modelType = 'custom layers';

% Add some parameters...
paramGroup = {{'Lay 1 Thick',   20, 50, 90, false}
              {'Lay 1 SLD Re',  1e-6 , 3e-6, 5e-6, false}
              {'Lay 1 SLD Im',  1e-8 , 3e-8, 5e-8, false}
              {'Lay 1 rough',   3 , 5, 7, false} 
              {'Lay 2 Thick',   20, 50, 90, false}
              {'Lay 2 SLD Re',  1e-6 , 1e-6, 5e-6, false}
              {'Lay 2 SLD Im',  1e-8 , 1e-8, 5e-8, false}
              {'Lay 2 rough',   3 , 5, 7, false}
};
problem.addParameterGroup(paramGroup);

% Add the custom model..
path = pwd;
problem.addCustomFile('simple model','simpleAbsCustomBilayer.m','matlab',path);

% Build a contrast....
problem.addContrast('name','Contrast 1',...
    'background','Background 1',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'resample',true,....
    'nbs', 'SLD D2O',...        % This is bulk out ('Nb Subs')
    'nba', 'SLD Air',...        % This is bulk in ('Nb Air')
    'data', 'Simulation');

% Set the model...
problem.setContrastModel(1,{'simple model'});