classdef geometryOptions < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('geometryOptions');
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue('geometryOptions', value);
        end
    end

    enumeration
        AirSubstrate ('air/substrate')
        SubstrateLiquid ('substrate/liquid')
    end
end