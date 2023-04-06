function obj = project(experimentName, calculationType)
    % Creates a project object.
    % The input arguments are the experiment name which is a char
    % array and the calculation type, which is a calculationTypes enum.
    % Both arguments are optional.
    %
    % problem = project('New experiment');
    arguments
        experimentName {mustBeTextScalar} = ''
        calculationType = calculationTypes.nonPolarised
    end
    
    invalidTypeMessage = sprintf('calculationType must be a calculationTypes enum or one of the following strings (%s)', ...
                                 strjoin(calculationTypes.values(), ', '));

    calculationType = validateOption(calculationType, 'calculationTypes', invalidTypeMessage).value;

    % Initialise object, including domains if necessary
    if any(strcmp(calculationType, {calculationTypes.Domains.value, calculationTypes.MagneticDomains.value}))
        obj = domainsClass(experimentName, calculationType);
    else
        obj = projectClass(experimentName, calculationType);
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
