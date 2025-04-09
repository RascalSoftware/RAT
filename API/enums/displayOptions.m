classdef displayOptions < customEnum 
  % The available options for terminal output.
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
        Off ('off')
        Iter ('iter')
        Notify ('notify')
        Final ('final')
    end
end
