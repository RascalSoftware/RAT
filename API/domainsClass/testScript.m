clear

d = domainsClass();

problem.setModelType('custom layers');
problem.setGeometry('Substrate/liquid');

d.addSimContrast('my sim contrast');

d.addParam('newParam1');
d.addParam('newParam2');


d.setSimContrast(1,'nba','sld air');
d.setSimContrast(1,'nbs','sld d2o');

d.setSimContrastModel(1,{'Layer 1','Layer 2'});

d.addSimContrast('name','test','nba','sld air','nbs','sld d2o');

d.addReflContrast('name','Test',...
    'background','Background 1',...
    'resolution','Resolution 1',...
    'scalefactor', 'Scalefactor 1',...
    'nbs', 'SLD D2O',...                % This is bulk out ('Nb Subs')
    'nba', 'SLD Air',...                % This is bulk in ('Nb Air')
    'domainRatio', 'Domain Ratio 1');





controls = controlsDef();


%[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(d,controls);