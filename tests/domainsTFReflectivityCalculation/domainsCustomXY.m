function project = domainsCustomXY()
    project = createProject(calcType="domains");
    project.setModelType('custom XY');
    project.setGeometry('air/substrate');
    
    params = {{'Oxide thick',   10,         20,     50,     true}
              {'Layer thick',   150,        300,    500,    true}
              {'Layer SLD',     1e-6,       2e-6,   4e-6,   true}
              {'Layer rough',   5,          10,     20,     true}
              {'Domain d L1',   10,         200,     300,   true}
              {'Domain rho l1', 1e-6,       2e-6,   3e-6,   true}
        };
    
    project.addParameterGroup(params);
    
    
    project.setBackgroundParam(1,'name','Backs par D2O','fit',true,'min',1e-10,'max',1e-5,'val',1e-07);
    
    project.addBackgroundParam('Backs par SMW',1e-10,1e-7,1e-5,true);
    project.addBackgroundParam('Backs par H2O',1e-10,1e-7,1e-5,true);
    
    project.addBackground('Background SMW','constant','Backs par SMW');
    project.addBackground('Background H2O','constant','Backs par H2O');
    
    project.setBackground(1,'name','Background D2O', 'source','Backs par D2O');
    
    % Finally modify some of the other parameters to be more suitable values
    % for a solid / liquid experiment.
    
    project.setScalefactor(1,'Value',1,'min',0.5,'max',2);
    
    project.setBulkIn(1,'name','Air','Value',0,'fit',false);
    
    project.setScalefactor(1,'min',0.8,'Value',1,'max',1.1,'fit',true);
    
    project.setBulkOut(1,'name','Silicon','min',2.073e-6,'value',2.073e-6,'fit',false);
    
    project.addCustomFile('DSPC Model', 'domainsXYModel.m', 'matlab', 'tests/domainsTFReflectivityCalculation/');
    
    project.addContrast('name','Test',...
        'background','Background D2O',...
        'resolution','Resolution 1',...
        'scalefactor', 'Scalefactor 1',...
        'bulkIn', 'Air',....
        'bulkOut', 'silicon',...
        'domainRatio', 'Domain Ratio 1',...
        'data', 'Simulation');
    
    project.setContrastModel(1,'DSPC Model');
end
