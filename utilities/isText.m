function textFlag = isText(input)
    % Checks whether input is either a character array or a string.
    %
    % isText('char array');
    textFlag = (ischar(input) || isstring(input));
end