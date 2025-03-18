function newObj = copyProperties(oldObj, newObj)
    % Copy public, non-dependent property values between two instances of a class.
    %
    % Parameters
    % ----------
    % oldObj : object
    %     The object to copy from.
    % newObj : object
    %     The object to copy to.
    %
    P = metaclass(oldObj).Properties;
    for k = 1:length(P)
        if isprop(newObj, P{k}.Name) && ~P{k}.Dependent && strcmpi(findprop(newObj, P{k}.Name).SetAccess, 'public')
            newObj.(P{k}.Name) = oldObj.(P{k}.Name);
        end
    end
end
