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

    invalidCalcMessage = sprintf('Calculation type must be a calculationTypes enum or one of the following strings (%s)', ...
                             strjoin(calculationTypes.values(), ', '));

    % Initialise object, including domains if necessary
    switch validateOption(options.calcType, 'calculationTypes', invalidCalcMessage)
        case calculationTypes.Normal
            obj = projectClass(options.name, options.model, options.geometry, options.absorption);
        case calculationTypes.Domains
            obj = domainsClass(options.name, options.model, options.geometry, options.absorption);
        otherwise
            throw(exceptions.invalidOption(invalidCalcMessage));
    end

end
