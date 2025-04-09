classdef boundHandlingOptions < customEnum
  % Options for bound handling in DREAM.
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
        None ('none')
        Reflect ('reflect')
        Bound ('bound')
        Fold ('fold')
    end
end
