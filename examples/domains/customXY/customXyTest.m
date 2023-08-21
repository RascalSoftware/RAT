problem = project(calcType="domains");
problem.setModelType('custom XY');
problem.setGeometry('air/substrate');

% Make some parameters...
params = {{'Oxide thick',   10,         20,     50,     true}
          {'Layer thick',   150,         300,    500,    true}
          {'Layer SLD',     1e-6,       2e-6,   4e-6,   true}
          {'Layer rough',   5,          10,     20,     true}
          {'Domain d L1',   10,         200,     300,     true}
          {'Domain rho l1', 1e-6,       2e-6,   3e-6,   true}
    };

problem.addParameterGroup(params);


problem.setBacksPar(1,'name','Backs par D2O','fit',true,'min',1e-10,'max',1e-5,'val',1e-07);

% Add two new backs parameters for the other two..
problem.addBacksPar('Backs par SMW',1e-10,1e-7,1e-5,true);
problem.addBacksPar('Backs par H2O',1e-10,1e-7,1e-5,true);

% And add the two new constant backgrounds..
problem.addBackground('Background SMW','constant','Backs par SMW');
problem.addBackground('Background H2O','constant','Backs par H2O');

% And edit the other one....
problem.setBackground(1,'name','Background D2O', 'value1','Backs par D2O');

% Finally modify some of the other parameters to be more suitable values
% for a solid / liquid experiment.

% Set the scalefactor...
problem.setScalefactor(1,'Value',1,'min',0.5,'max',2,'fit',true);


% Set the bulk SLD
problem.setBulkIn(1,'name','Air','Value',0,'fit',false);

% and scalefactor...
problem.setScalefactor(1,'min',0.8,'Value',1,'max',1.1);

% Add another bulk-out (and modify the first)
problem.setBulkOut(1,'name','Silicon','value',2.073e-6,'fit',false);

% Add the custom file...
problem.addCustomFile('DSPC Model','testXyModel','matlab',pwd);

% Make a contrast
problem.addContrast('name','Test',...
    'background','Background D2O',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'silicon',...        % This is bulk out ('Nb Subs')
    'nba', 'Air',....           % This is bulk in ('Nb Air);
    'domainRatio', 'Domain Ratio 1',...
    'data', 'Simulation');

problem.setContrastModel(1,'DSPC Model');

