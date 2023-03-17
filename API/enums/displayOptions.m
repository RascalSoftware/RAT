classdef displayOptions < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('displayOptions');
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue('displayOptions', value);
        end
    end

    enumeration
        Off ('off')
        Iter ('iter')
        Notify ('notify')
        Final ('final')
    end
end