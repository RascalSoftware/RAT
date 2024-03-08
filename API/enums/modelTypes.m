classdef modelTypes < customEnum
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
      CustomLayers ('custom layers')
      CustomXY ('custom xy')
      StandardLayers ('standard layers')
    end
end