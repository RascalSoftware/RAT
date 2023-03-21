function textFlag = isText(input)
    % Checks whether input is either a character array or a string.
    %
    % isText('char array');    
    if ischar(input) || isstring(input)
        textFlag = True;
    else
        textFlag = False;
    end
end