function validateLimits(min, value, max)
    % Validates the value, minimum and maximum limit variables.
    % 
    % Examples
    % --------
    % Incorrect bounds throws exception.
    % 
    % >>> validateLimits(2, 4, 1);  % throws exception as max is less than min 
    % 
    % Parameters
    % ----------
    % min : double
    %     The minimum value to validate.
    % value : double
    %     The value to validate.
    % max : double
    %     The maximum value to validate.
    %
    % Returns
    % -------
    % index : whole number
    %     A valid row index.
    %
    % Raises
    % ------
    % invalidValue
    %     If ``min`` is greater than ``max`` or ``value`` is outside the limits.
    arguments
        min {isscalar, mustBeNumeric}
        value {isscalar, mustBeNumeric}
        max {isscalar, mustBeNumeric}
    end
        
    if min > max
        throw(exceptions.invalidValue(sprintf('min limit %d must be less than or equal to max limit %d', min, max)));
    end

    if value < min || value > max
        throw(exceptions.invalidValue(sprintf('Parameter value %d must be within the limits %d to %d', value, min, max)));
    end
end
