function input = validateOption(input, enum,  message)
    % Checks input is a valid member of enum and throws an exception with given message.
    % Returns the enum as a char array
    %
    % validateOption('uniform', priorTypes, 'This is not a valid PriorType');
    arguments
        input
        enum {mustBeCustomEnum}
        message {mustBeTextScalar} = 'The input is not a valid option'
    end

    if isstring(input)
        input = convertStringsToChars(input);
    end
    
    options = enumeration(enum);
    if ~(isenum(input) || isa(input, class(options(1).value)))
        throw(invalidType(message));
    end

    if ~isenum(input)
        input = options(1).fromValue(input);
    end
    
    if isempty(input) || ~ismember(input, options)
        throw(invalidOption(message));
    end
    
    enum = str2func(enum); % Gets class handle via name
    input = enum(input);
end

function mustBeCustomEnum(value)
    % Check for name of class with enumeration
    if ~(ischar(value) || isstring(value))
        throwAsCaller(invalidType('Enum class argument must be passed as string or char array.'));
    end
    
    metaClass = meta.class.fromName(value);
    if isempty(metaClass) || metaClass.Enumeration ~= 1 || metaClass.SuperclassList.Name ~= "customEnum"
        throwAsCaller(invalidValue(sprintf('The enum class (''%s'') must inherit customEnum and have an enumeration block.', value)));
    end
end