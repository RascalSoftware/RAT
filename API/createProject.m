function obj = createProject(options)
    % Creates a normal project or domain project object depending on the given calculation type. This is the 
    % recommended way to create a RAT project not via the ``projectClass`` or ``domainsClass``.
    %
    % Examples
    % --------
    % To create a normal, standard layers project.
    % 
    % >>> project = createProject(name='New experiment', calcType='normal');
    % 
    % To create a domains, custom layers project with absorption.
    % 
    % >>> project = createProject(name='Domains experiment', calcType='domains', model='custom layers', absorption=true);
    %
    % Parameters
    % ---------- 
    % name : string or char array, default: ''
    %     The name of the project.
    % calcType : calculationTypes, default: calculationTypes.Normal
    %     The calculation type which can be 'normal' or 'domains'.
    % model : modelTypes, default: modelTypes.StandardLayers
    %     The layer model type which can be 'standard layers', 'custom layers', or 'custom xy'.
    % geometry : geometryOptions, default: geometryOptions.AirSubstrate
    %     The geometry to use which can be 'air/substrate' or 'substrate/liquid'.
    % absorption : logical, default: false
    %     Indicates whether imaginary component is used for the SLD value in layers.
    %
    % Returns
    % -------
    % obj : projectClass or domainsClass
    %    A new normal project class or domains project class initialised with given parameters.

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
