classdef boundHandlingOptions < customEnum
   methods (Static)
      function v = values()
         v = customEnum.values('boundHandlingOptions');
      end
         
      function e = fromValue(value)
         e = customEnum.fromValue('boundHandlingOptions', value);
      end
   end

   enumeration
      None ('none')
      Reflect ('reflect')
      Bound ('bound')
      Fold ('fold')
   end
end