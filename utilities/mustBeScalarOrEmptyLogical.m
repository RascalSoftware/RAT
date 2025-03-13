function mustBeScalarOrEmptyLogical(input)
    if ~islogical(input) || length(input) > 1
        throwAsCaller(MException("RAT:validators:mustBeScalarOrEmptyLogical", "Value must be a scalar and logical."));
    end
end
