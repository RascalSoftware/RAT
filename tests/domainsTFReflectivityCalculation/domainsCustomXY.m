function problem = domainsCustomXY()
    problem = createProject(calcType="domains");
    problem.setModelType('custom XY');
    problem.setGeometry('air/substrate');
    
    params = {{'Oxide thick',   10,         20,     50,     true}
              {'Layer thick',   150,         300,    500,    true}
              {'Layer SLD',     1e-6,       2e-6,   4e-6,   true}
              {'Layer rough',   5,          10,     20,     true}
              {'Domain d L1',   10,         200,     300,     true}
              {'Domain rho l1', 1e-6,       2e-6,   3e-6,   true}
        };
    
    problem.addParameterGroup(params);
    
    
    problem.setBacksPar(1,'name','Backs par D2O','fit',true,'min',1e-10,'max',1e-5,'val',1e-07);
    
    problem.addBacksPar('Backs par SMW',1e-10,1e-7,1e-5,true);
    problem.addBacksPar('Backs par H2O',1e-10,1e-7,1e-5,true);
    
    problem.addBackground('Background SMW','constant','Backs par SMW');
    problem.addBackground('Background H2O','constant','Backs par H2O');
    
    problem.setBackground(1,'name','Background D2O', 'value1','Backs par D2O');
    
    % Finally modify some of the other parameters to be more suitable values
    % for a solid / liquid experiment.
    
    problem.setScalefactor(1,'Value',1,'min',0.5,'max',2);
    
    problem.setBulkIn(1,'name','Air','Value',0,'fit',false);
    
    problem.setScalefactor(1,'min',0.8,'Value',1,'max',1.1,'fit',true);
    
    problem.setBulkOut(1,'name','Silicon','value',2.073e-6,'fit',false);
    
    problem.addCustomFile('DSPC Model','domainsXYModel','matlab',pwd);
    
    problem.addContrast('name','Test',...
        'background','Background D2O',...
        'resolution','Resolution 1',...
        'scalefactor', 'Scalefactor 1',...
        'nbs', 'silicon',...        
        'nba', 'Air',....           
        'domainRatio', 'Domain Ratio 1',...
        'data', 'Simulation');
    
    problem.setContrastModel(1,'DSPC Model');
end
