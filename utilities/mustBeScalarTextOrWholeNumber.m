function mustBeScalarTextOrWholeNumber(input)
    if isnumeric(input) && isscalar(input) && mod(input, 1) == 0 
        return;
    elseif ischar(input) &&  size(input, 1) <= 1
        return;
    elseif isstring(input) && isscalar(input)
        return;
    else
        throwAsCaller(MException("RAT:validators:mustBeScalarTextOrWholeNumber", "Value must be a scalar text or a whole number."));
    end
end
