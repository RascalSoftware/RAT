function project = jsonToProject(filename)
% Convert a Project JSON (e.g. from RasCAL-2) to a projectClass.
%
% Parameters
% ----------
% filename : string
%     The name of the JSON file to convert.
%
% Returns
% -------
% project : projectClass
%     The project class represented by the JSON.
%
json_struct = jsondecode(fileread(filename));

project = createProject('name', json_struct.name, ...
    'calcType', json_struct.calculation, ...
    'model', json_struct.model, ...
    'geometry', json_struct.geometry, ...
    'absorption', json_struct.absorption);

% add all parameters
for i=1:length(json_struct.parameters)
    p = json_struct.parameters(i);
    if p.name == "Substrate Roughness"
        project.setParameter(i, 'min', p.min, 'value', p.value, 'max', p.max, 'fit', p.fit, 'prior', p.prior_type, 'mu', p.mu, 'sigma', p.sigma);
    else
        try
        project.addParameter(p.name, p.min, p.value, p.max, p.fit, p.prior_type, p.mu, p.sigma);
        catch 
            disp('oops')
        end
    end
end

project.removeBulkIn(1);
for i=1:length(json_struct.bulk_in)
    p = json_struct.bulk_in(i);
    project.addBulkIn(p.name, p.min, p.value, p.max, p.fit, p.prior_type, p.mu, p.sigma);
end

project.removeBulkOut(1);
for i=1:length(json_struct.bulk_out)
    p = json_struct.bulk_out(i);
    project.addBulkOut(p.name, p.min, p.value, p.max, p.fit, p.prior_type, p.mu, p.sigma);
end

project.removeScalefactor(1);
for i=1:length(json_struct.scalefactors)
    p = json_struct.scalefactors(i);
    project.addScalefactor(p.name, p.min, p.value, p.max, p.fit, p.prior_type, p.mu, p.sigma);
end

for i=1:length(json_struct.custom_files)
    p = json_struct.custom_files(i);
    project.addCustomFile(p.name, p.filename, p.language, p.path);
end

project.removeBackgroundParam(1);
for i=1:length(json_struct.background_parameters)
    p = json_struct.background_parameters(i);
    project.addBackgroundParam(p.name, p.min, p.value, p.max, p.fit, p.prior_type, p.mu, p.sigma);
end

project.removeBackground(1);
for i=1:length(json_struct.backgrounds)
    p = json_struct.backgrounds(i);
    project.addBackground(p.name, p.type, p.source, p.value_1, p.value_2, p.value_3, p.value_4, p.value_5);
end

project.removeResolutionParam(1);
for i=1:length(json_struct.resolution_parameters)
    p = json_struct.resolution_parameters(i);
    project.addResolutionParam(p.name, p.min, p.value, p.max, p.fit, p.prior_type, p.mu, p.sigma);
end

project.removeResolution(1);
for i=1:length(json_struct.resolutions)
    p = json_struct.resolutions(i);
    project.addResolution(p.name, p.type, p.source, p.value_1, p.value_2, p.value_3, p.value_4, p.value_5);
end

project.removeData(1);
for i=1:length(json_struct.data)
    p = json_struct.data(i);
    project.addData(p.name, p.data, transpose(p.data_range), transpose(p.simulation_range));
end

if json_struct.model == "standard layers"
    if json_struct.absorption
        for i=1:length(json_struct.layers)
            p = json_struct.layers(i);
            project.addLayer(p.name, p.thickness, p.SLD_real, p.SLD_imaginary, p.roughness, p.hydration, p.hydrate_with);
        end
    else
        for i=1:length(json_struct.layers)
            p = json_struct.layers(i);
            project.addLayer(p.name, p.thickness, p.SLD, p.roughness, p.hydration, p.hydrate_with);
        end
    end
    if json_struct.calculation == "domains"
        for i=1:length(json_struct.domain_contrasts)
            p = json_struct.domain_contrasts(i);
            project.addDomainContrast('name', p.name, 'model', p.model);
        end
    end
end


if json_struct.model == "domains"
    for i=1:length(json_struct.domain_ratios)
        p = json_struct.domain_ratios(i);
        project.addDomainRatio(p.name, p.min, p.value, p.max, p.fit, p.prior_type, p.mu, p.sigma);
    end
    for i=1:length(json_struct.contrasts)
    p = json_struct.contrasts(i);
    project.addContrast('name', p.name, ...
        'data', p.data, ...
        'background', p.background, ...
        'backgroundAction', p.background_action, ...
        'bulkIn', p.bulk_in, ...
        'bulkOut', p.bulk_out, ...
        'scalefactor', p.scalefactor, ...
        'resample', p.resample, ...
        'domainRatio', p.domain_ratio, ...
        'model', p.model);
    end
else
    for i=1:length(json_struct.contrasts)
    p = json_struct.contrasts(i);
    project.addContrast('name', p.name, ...
        'data', p.data, ...
        'background', p.background, ...
        'backgroundAction', p.background_action, ...
        'bulkIn', p.bulk_in, ...
        'bulkOut', p.bulk_out, ...
        'scalefactor', p.scalefactor, ...
        'resample', p.resample, ...
        'resolution',p.resolution, ...
        'model', p.model);
    end
end

end