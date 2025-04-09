classdef allowedTypes < customEnum
    % Ways of defining a background or resolution.
    methods (Static)
        function s = toStruct()
            s = customEnum.toStruct(mfilename('class'));
        end
        
        function v = values()
            v = customEnum.values(mfilename('class'));
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue(mfilename('class'), value);
        end
    end

    enumeration
        Constant ('constant')
        Function ('function')
        Data ('data')
    end
end
