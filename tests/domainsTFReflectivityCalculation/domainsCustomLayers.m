function project = domainsCustomLayers()
    % Test of custom layers domains prioject...
    % Use incoherent summing on a permalloy layer
    % as a test
    
    project = createProject(calcType="domains");
    project.modelType = 'custom layers';
    project.geometry = 'substrate/liquid';
    
    params = {{'Alloy thick',   100,    150,    200,   true}
              {'Alloy SLD up',  9e-6,   11e-6,  13e-6, true}
              {'Alloy SLD dn',  5e-6,   7e-6,   10e-6, true}
              {'Alloy rough',   5,      7,      11,    true}
              {'Gold thick',    100,    150,    200,   true}
              {'Gold SLD',      4e-6,   4.5e-6, 5e-6,  true}
              {'Gold Rough',    5,      7,      11,    true}
        };
    
    project.addParameterGroup(params);
    
    project.setBulkIn(1,'name','Silicon','Value',2.073e-6,'max',2.073e-6);
    
    project.addCustomFile('Alloy domains', 'domainsAlloyModel.m', 'matlab', 'tests/domainsTFReflectivityCalculation/');
    
    project.addContrast('name',       'D2O Conrast', ...
                        'Data',       'Simulation',...
                        'Background', 'Background 1',...
                        'backgroundAction', actions.Add,...
                        'bulkIn',     'Silicon',...
                        'bulkOut',    'SLD D2O',...
                        'Scalefactor','Scalefactor 1', ...
                        'Resolution', 'Resolution 1',...
                        'Resample',    false,...
                        'domainRatio','Domain Ratio 1');
    
    project.setContrastModel(1,'Alloy domains');
end
