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
        options.calc = calculationTypes.NonPolarised
        options.geometry = geometryOptions.AirSubstrate
    end
    
    invalidCalcMessage = sprintf('calculation type must be a calculationTypes enum or one of the following strings (%s)', ...
                                 strjoin(calculationTypes.values(), ', '));

    options.calc = validateOption(options.calc, 'calculationTypes', invalidCalcMessage).value;

    invalidGeometryMessage = sprintf('geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                 strjoin(geometryOptions.values(), ', '));

    options.geometry = validateOption(options.geometry, 'geometryOptions', invalidGeometryMessage).value;

    % Initialise object, including domains if necessary
    if any(strcmp(options.calc, {calculationTypes.Domains.value, calculationTypes.MagneticDomains.value}))
        obj = domainsClass(options.name, options.calc, options.geometry);
    else
        obj = projectClass(options.name, options.calc, options.geometry);
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
