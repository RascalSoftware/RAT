function output = findParameterIndex(input, allowedNames, inputDesc)
    % Get the index of an input name in list of allowed names.
    % 
    % Parameters
    % ----------
    % input: string or char array
    %     A name to validate.
    % allowedNames: cell
    %     A cell containing the valid names.
    % inputDesc: string or char array
    %     A description of the input.
    % 
    % Returns
    % -------
    % output: whole number
    %     Index of the input name in the allowed list of names.
    if isempty(input)
        throw(exceptions.invalidValue(sprintf("Input %s cannot be empty.", inputDesc)));
    end
    found = strcmpi(input, allowedNames);
    if ~any(found)
        if isempty(allowedNames)
            msg = sprintf('"%s" is not a recognised %s. Did you forget to add the %s?', input, inputDesc, inputDesc);
        else
            msg = sprintf('"%s" is not a recognised %s. The allowed names are: "%s".', input, inputDesc, strjoin(allowedNames, '", "'));
        end
        throw(exceptions.nameNotRecognised(msg));
    end
    output = find(found, 1);
end
