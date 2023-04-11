function obj = project(options)
    % Creates a project object.
    % The input arguments are the experiment name which is a char
    % array; the calculation type, which is a calculationTypes enum; and
    % the geometry, which is a geometryOptions enum. All of the arguments
    % are optional.
    %
    % problem = project(name='New experiment', calc='nonPolarised');
    arguments
        options.name {mustBeTextScalar} = ''
        options.type = calculationTypes.NonPolarised
        options.geometry = geometryOptions.AirSubstrate
    end
    
    invalidTypeMessage = sprintf('calculation type must be a calculationTypes enum or one of the following strings (%s)', ...
                                 strjoin(calculationTypes.values(), ', '));

    options.type = validateOption(options.type, 'calculationTypes', invalidTypeMessage).value;

    invalidGeometryMessage = sprintf('geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                 strjoin(geometryOptions.values(), ', '));

    options.geometry = validateOption(options.geometry, 'geometryOptions', invalidGeometryMessage).value;

    % Initialise object, including domains if necessary
    if any(strcmp(options.type, {calculationTypes.Domains.value, calculationTypes.MagneticDomains.value}))
        obj = domainsClass(options.name, options.type, options.geometry);
    else
        obj = projectClass(options.name, options.type, options.geometry);
    end

    % Set specific options depending on the calculation type
    switch obj.calculationType
        case calculationTypes.Absorption.value
            obj.layers = layersClass({'SLD Real', 'SLD Imaginary'});
        case {calculationTypes.Magnetic.value, calculationTypes.MagneticDomains.value}
            obj.layers = layersClass({'SLD Real', 'SLD Imaginary', 'SLD Magnetic Real', 'SLD Magnetic Imaginary'});
        case calculationTypes.OilWater.value
            obj.addParam('Oil Thickness');
            obj.addParam('Oil Roughness');
    end

end
