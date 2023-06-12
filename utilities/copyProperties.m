function newObj = copyProperties(oldObj, newObj)
    % Get all property values from one instance of a class and copy over
    % to an instance of a different class those that are defined,
    % non-dependent, and publicly accessible
    %.
    % newObj = copyProperties(oldObj, newObj)
    P = metaclass(oldObj).Properties;
    for k = 1:length(P)
        if isprop(newObj, P{k}.Name) && ~P{k}.Dependent && strcmpi(findprop(newObj, P{k}.Name).SetAccess, 'public')
            newObj.(P{k}.Name) = oldObj.(P{k}.Name);
        end
    end
end
