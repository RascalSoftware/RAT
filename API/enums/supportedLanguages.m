classdef supportedLanguages < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('supportedLanguages');
        end
            
        function e = fromValue(value)
            e = customEnum.fromValue('supportedLanguages', value);
        end
    end

    enumeration
        Cpp ('cpp')
        Matlab ('matlab')
        Python ('python')
    end
end