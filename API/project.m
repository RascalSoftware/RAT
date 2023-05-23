function obj = project(options)
    % Creates a project object.
    % The input arguments are the experiment name which is a char
    % array; the calculation type, which is a calculationTypes enum; the
    % geometry, which is a geometryOptions enum; and a logical to state
    % whether or not absorption terms are included in the refractive index.
    % All of the arguments are optional.
    %
    % problem = project(name='New experiment', calc='non polarised');
    arguments
        options.name {mustBeTextScalar} = ''
        options.type = calculationTypes.NonPolarised
        options.geometry = geometryOptions.AirSubstrate
        options.absorption {mustBeA(options.absorption,'logical')} = false
    end
    
    invalidTypeMessage = sprintf('calculation type must be a calculationTypes enum or one of the following strings (%s)', ...
                                 strjoin(calculationTypes.values(), ', '));

    options.type = validateOption(options.type, 'calculationTypes', invalidTypeMessage).value;

    invalidGeometryMessage = sprintf('geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                 strjoin(geometryOptions.values(), ', '));

    options.geometry = validateOption(options.geometry, 'geometryOptions', invalidGeometryMessage).value;

    % Initialise object, including domains if necessary
    if any(strcmp(options.type, {calculationTypes.Domains.value, calculationTypes.MagneticDomains.value}))
        obj = domainsClass(options.name, options.type, options.geometry, options.absorption);
    else
<<<<<<< HEAD
        obj = projectClass(options.name, options.type, options.geometry, options.absorption);
=======
        obj = projectClass(options.name, options.type, options.geometry);
    end

    % Set the imaginary term in the refractive index if absorption is
    % selected
    if options.absorption
        obj.layers = layersClass({'SLD Real', 'SLD Imaginary'});
        obj.useImaginary = true;
>>>>>>> d87cc1d0 (Absorbance option added for standard layers single)
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
