classdef parallelOptions < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('parallelOptions');
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue('parallelOptions', value);
        end
    end

    enumeration
        Single ('single')
        Points ('points')
        Contrasts ('contrasts')
        All ('all')
    end
end