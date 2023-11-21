% Domains test...
problem = createProject(calcType="domains");

% Add some parameters....
Parameters = {
    %       Name                min         val         max     fit?
    {'D1 thick',         5,         20,         60,     true   };
    {'D1 SLD',           3e-6,      4.1e-6,    5e-6,    false  };
    {'D1 rough'          2,          5,         20,     true   };
    {'D1 Hydr'           10,        20,         30,     true   };
    {'D2 thick',         5,         100,         60,    true   };
    {'D2 SLD',           3e-6,      2.1e-6,    5e-6,    false  };
    {'D2 rough'          2,          5,         20,     true   };
    {'D2 Hydr'           10,        20,         30,     true   };
    };

problem.addParameterGroup(Parameters);

% Make some layers.....
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

problem.addLayerGroup({Layer1, Layer2});


problem.addDomainContrast('Domain1');
problem.addDomainContrast('Domain2');

problem.setDomainContrastModel(1,'Domain1 Layer');
problem.setDomainContrastModel(2,'Domain2 Layer');

problem.addContrast('name','Domain Test',...
    'background','Background 1',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'resample',false,...
    'nba', 'SLD Air',...        % This is bulk in
    'nbs', 'SLD D2O',...        % This is bulk out
    'domainRatio', 'Domain Ratio 1',....
    'data', 'Simulation');

problem.setContrastModel(1,{'Domain1','Domain2'});


