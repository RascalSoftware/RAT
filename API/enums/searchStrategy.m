classdef searchStrategy < customEnum
   methods (Static)           
        function s = toStruct()
            s = customEnum.toStruct(mfilename('class'), true);
        end
        
        function v = values()
            v = customEnum.values(mfilename('class'));
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue(mfilename('class'), value, true);
        end
    end

    enumeration
        Random ('random')
        LocalToBest ('local to best')
        BestWithJitter ('best jitter')
        RandomWithPerVectorDither ('vector dither')
        RandomWithPerGenerationDither ('generation dither')
        RandomEitherOrAlgorithm ('either or')
    end
end