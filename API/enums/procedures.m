classdef procedures < customEnum
    % The algorithms available in RAT.
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
        Calculate ('calculate')
        Simplex ('simplex')
        DE ('de')
        NS ('ns')
        Dream ('dream')
    end
end
