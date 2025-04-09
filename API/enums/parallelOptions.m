classdef parallelOptions < customEnum
  % Ways in which the calculation can be parallelised.
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
        Single ('single')
        Points ('points')
        Contrasts ('contrasts')
    end
end
