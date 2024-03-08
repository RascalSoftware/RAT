classdef geometryOptions < customEnum
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
        AirSubstrate ('air/substrate')
        SubstrateLiquid ('substrate/liquid')
    end
end