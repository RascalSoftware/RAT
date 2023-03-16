classdef modelTypes < customEnum
   methods (Static)
      function v = values()
         v = customEnum.values('modelTypes');
      end
       
      function e = fromValue(value)
         e = customEnum.fromValue('modelTypes', value);
      end
   end

   enumeration
      CustomLayers ('custom layers')
      CustomXY ('custom xy')
      StandardLayers ('standard layers')
   end
end