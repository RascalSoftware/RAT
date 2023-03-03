function input = validateNumber(input, message)
    % Checks input is a number and throws an exception with given message.
    %
    % validateNumber(2, 'This is not a number');
    arguments
        input
        message {mustBeTextScalar} = 'The input is not a number'
    end
    
    if ~isnumeric(input)
        throw(invalidType(message));
    end
end