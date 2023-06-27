classdef eventTypes < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('eventTypes');
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue('eventTypes', value);
        end
    end

    enumeration
        Message (0)
        Plot (1)
    end
end