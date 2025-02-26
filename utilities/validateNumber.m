function input = validateNumber(input, message, validateInt)
    % Checks input is a number and throws an exception with given message.
    %
    % If validateInt is true, also check that input is a whole number.
    %
    % validateNumber(2, 'This is not a number');
    % validateNumber(2.5, 'This is not a whole number', true);
    arguments
        input
        message {mustBeTextScalar} = 'The input is not a number'
        validateInt {mustBeA(validateInt,'logical')} = false
    end
    
    if ~isnumeric(input)
        throw(exceptions.invalidType(message));
    elseif validateInt && any(mod(input, 1) ~= 0)
        throw(exceptions.invalidValue(message));
    end
end