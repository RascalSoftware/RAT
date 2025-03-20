function mustBeScalarTextOrWholeNumber(input)
    if isnumeric(input) && length(input) == 1 && mod(input, 1) == 0 
        return;
    elseif ischar(input) &&  size(input, 1) <= 1
        return;
    elseif isstring(input) && length(input) == 1 
        return;
    else
        throwAsCaller(MException("RAT:validators:mustBeScalarTextOrWholeNumber", "Value must be a scalar text or a whole number."));
    end
end
