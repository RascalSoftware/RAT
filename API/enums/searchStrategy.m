classdef searchStrategy < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('searchStrategy');
        end
            
        function e = fromValue(value)
            e = customEnum.fromValue('searchStrategy', value);
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