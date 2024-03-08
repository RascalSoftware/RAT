classdef searchStrategy < customEnum
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
        Random (1)
        LocalToBest (2)
        BestWithJitter (3)
        RandomWithPerVectorDither (4)
        RandomWithPerGenerationDither (5)
        RandomEitherOrAlgorithm (6)
    end
end