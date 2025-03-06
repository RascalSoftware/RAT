function priors = validatePriors(priorType, mu, sigma)
    % Validates the prior types, mu and sigma variables. If mu and sigma are set on a uniform prior, 
    % they would be changed to 0 and Inf respectively and a warning issued.
    % 
    % Examples
    % --------
    % To validate a uniform prior.
    % 
    % >>> prior = validatePriors('uniform', 2, 3); 
    % >>> prior
    % 
    % ans =
    %    1×3 cell array
    %      {'uniform'}    {[0]}    {[Inf]}
    %
    % Parameters
    % ----------
    % priorType : PriorTypes 
    %     The prior type to validate.
    % mu : double, default: []
    %     The Gaussian mean value to validate.
    % sigma : double, default: []
    %     The Gaussian standard deviation value to validate.
    %
    % Returns
    % -------
    % priors : cell
    %     A cell array containing the valid prior type, mu and sigma.
    %
    % Warns
    % -----
    % generic warning
    %     If ``mu`` or ``sigma`` is set on a uniform prior.
    arguments
        priorType
        mu {isscalar, mustBeNumeric}
        sigma {isscalar, mustBeNumeric}
    end
    invalidPriorsMessage = sprintf('Prior type must be a priorTypes enum or one of the following strings (%s)', ...
                                   strjoin(priorTypes.values(), ', '));
    priorType = validateOption(priorType, 'priorTypes', invalidPriorsMessage).value;

    if ~strcmp(priorType, priorTypes.Gaussian.value)
        if mu ~= 0 
            warning('mu cannot be %d when the prior types is not Gaussian - resetting to 0', mu);
        end
        if sigma ~= Inf
            warning('sigma cannot be %d when the prior types is not Gaussian - resetting to Inf', sigma);
        end
        mu = 0;
        sigma = Inf;
    end
    priors = {priorType, mu, sigma};
end