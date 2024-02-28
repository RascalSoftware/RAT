classdef eventTypes < customEnum
    methods (Static)
        function s = toStruct()
            s = customEnum.toStruct('eventTypes');
        end
        
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
        Progress (2)
    end
end
