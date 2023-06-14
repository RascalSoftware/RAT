function obj = project(options)
    % Creates a project object.
    % The input arguments are the experiment name which is a char
    % array; the calculation type, which is a calculationTypes enum; the
    % model type, which is a modelTypes enum; the geometry, which is a
    % geometryOptions enum; and a logical to state whether or not
    % absorption terms are included in the refractive index.
    % All of the arguments are optional.
    %
    % problem = project(name='New experiment', calc='non polarised');
    arguments
        options.name {mustBeTextScalar} = ''
        options.calc = calculationTypes.NonPolarised
        options.model = modelTypes.StandardLayers
        options.geometry = geometryOptions.AirSubstrate
        options.absorption {mustBeA(options.absorption,'logical')} = false
    end
    
    % Validate input options
    invalidCalcMessage = sprintf('calculation type must be a calculationTypes enum or one of the following strings (%s)', ...
                                 strjoin(calculationTypes.values(), ', '));

    options.calc = validateOption(options.calc, 'calculationTypes', invalidCalcMessage).value;

    invalidModelMessage = sprintf('model type must be a modelTypes enum or one of the following strings (%s)', ...
                                  strjoin(modelTypes.values(), ', '));

    options.model = validateOption(options.model, 'modelTypes', invalidModelMessage).value;

    invalidGeometryMessage = sprintf('geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                     strjoin(geometryOptions.values(), ', '));

    options.geometry = validateOption(options.geometry, 'geometryOptions', invalidGeometryMessage).value;

    % Initialise object, including domains if necessary
    if any(strcmp(options.calc, {calculationTypes.Domains.value, calculationTypes.MagneticDomains.value}))
        obj = domainsClass(options.name, options.calc, options.model, options.geometry, options.absorption);
    else
        obj = projectClass(options.name, options.calc, options.model, options.geometry, options.absorption);
    end

    % Set specific options depending on the calculation type
    switch obj.calculationType
        case {calculationTypes.Magnetic.value, calculationTypes.MagneticDomains.value}
            obj.layers = layersClass({'SLD Real', 'SLD Imaginary', 'SLD Magnetic Real', 'SLD Magnetic Imaginary'});
        case calculationTypes.OilWater.value
            if isa(obj, 'domainsClass')
                obj.contrasts = contrastsClass(domains=true, oilWater=true);
            else
                obj.contrasts = contrastsClass(domains=false, oilWater=true);
            end
    end

end
