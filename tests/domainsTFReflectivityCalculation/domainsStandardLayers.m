function project = domainsStandardLayers()

    project = createProject(calcType="domains");
    
    Parameters = {
        %       Name                min         val         max     fit?
        {'D1 thick',         5,         20,         60,     true   };
        {'D1 SLD',           3e-6,      4.1e-6,    5e-6,    false  };
        {'D1 rough'          2,          5,         20,     true   };
        {'D1 Hydr'           10,        20,         30,     true   };
        {'D2 thick',         5,         60,         100,    true   };
        {'D2 SLD',           2.1e-6,    3e-6,      5e-6,    false  };
        {'D2 rough'          2,          5,         20,     true   };
        {'D2 Hydr'           10,        20,         30,     true   };
        };
    
    project.addParameterGroup(Parameters);
    
    Layer1 = {'Domain1 Layer',...   % Name of the layer
        'D1 thick',...              % Layer thickness
        'D1 SLD',...                % Layer SLD
        'D1 Rough',...              % Layer roughness
        'D1 Hydr',...               % hydration (precent)
        'bulk out' }; 
    
    Layer2 = {'Domain2 Layer',...   % Name of the layer
        'D2 thick',...              % Layer thickness
        'D2 SLD',...                % Layer SLD
        'D2 Rough',...              % Layer roughness
        'D2 Hydr',...               % hydration (precent)
        'bulk out' }; 
    
    project.addLayerGroup({Layer1, Layer2});
    
    
    project.addDomainContrast(name='Domain1');
    project.addDomainContrast(name='Domain2');
    
    project.setDomainContrastModel(1,'Domain1 Layer');
    project.setDomainContrastModel(2,'Domain2 Layer');
    
    project.addContrast('name','Domain Test',...
        'background','Background 1',...
        'backgroundAction', backgroundActions.Add,...
        'resolution','Resolution 1',...
        'scalefactor', 'Scalefactor 1',...
        'resample',false,...
        'bulkIn', 'SLD Air',...
        'bulkOut', 'SLD D2O',...
        'domainRatio', 'Domain Ratio 1',....
        'data', 'Simulation');
    
    project.setContrastModel(1,{'Domain1','Domain2'});
end
