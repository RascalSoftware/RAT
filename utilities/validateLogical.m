function input = validateLogical(input, message)
    % Checks input is logical and throws an exception with given message.
    %
    % validateLogical(2, 'Input must be logical');
    arguments
        input
        message {mustBeTextScalar} = 'The input must be logical (true or false)'
    end
    
    if ~islogical(input)
        throw(invalidType(message));
    end
end