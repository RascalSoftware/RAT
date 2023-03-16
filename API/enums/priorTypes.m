classdef priorTypes < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('priorTypes');
        end
            
        function e = fromValue(value)
            e = customEnum.fromValue('priorTypes', value);
        end
    end

    enumeration
        Uniform ('uniform')
        Gaussian ('gaussian')
        Jeffreys ('jeffreys')
    end
end