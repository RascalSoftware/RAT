classdef procedures < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('procedures');
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue('procedures', value);
        end
    end

    enumeration
        Calculate ('calculate')
        Simplex ('simplex')
        DE ('de')
        NS ('ns')
        Dream ('dream')
    end
end