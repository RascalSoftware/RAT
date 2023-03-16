classdef allowedTypes < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('allowedTypes');
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue('allowedTypes', value);
        end
    end

    enumeration
        Constant ('constant')
        Function ('function')
        Data ('data')
    end
end