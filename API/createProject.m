function obj = createProject(options)
    % Creates a project object.
    % The input arguments are the experiment name which is a char
    % array; the calculation type, which is a calculationTypes enum; the
    % model type, which is a modelTypes enum; the geometry, which is a
    % geometryOptions enum; and a logical to state whether or not
    % absorption terms are included in the refractive index.
    % All of the arguments are optional.
    %
    % project = createProject(name='New experiment', calc='normal');
    arguments
        options.name {mustBeTextScalar} = ''
        options.calcType = calculationTypes.Normal
        options.model = modelTypes.StandardLayers
        options.geometry = geometryOptions.AirSubstrate
        options.absorption {mustBeA(options.absorption,'logical')} = false
    end
    
    % Validate input options
    invalidCalcMessage = sprintf('calculation type must be a calculationTypes enum or one of the following strings (%s)', ...
                                 strjoin(calculationTypes.values(), ', '));

    options.calcType = validateOption(options.calcType, 'calculationTypes', invalidCalcMessage).value;

    invalidModelMessage = sprintf('model type must be a modelTypes enum or one of the following strings (%s)', ...
                                  strjoin(modelTypes.values(), ', '));

    options.model = validateOption(options.model, 'modelTypes', invalidModelMessage).value;

    invalidGeometryMessage = sprintf('geometry must be a geometryOptions enum or one of the following strings (%s)', ...
                                     strjoin(geometryOptions.values(), ', '));

    options.geometry = validateOption(options.geometry, 'geometryOptions', invalidGeometryMessage).value;

    % Initialise object, including domains if necessary
    if strcmpi(options.calcType, calculationTypes.Domains.value)
        obj = domainsClass(options.name, options.calcType, options.model, options.geometry, options.absorption);
    else
        obj = projectClass(options.name, options.calcType, options.model, options.geometry, options.absorption);
    end

end
