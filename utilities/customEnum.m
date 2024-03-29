classdef customEnum
   properties (SetAccess = immutable)
      value
   end
   methods
      function obj = customEnum(value)
         % Creates a customEnum object. This is a base class used to  
         % associate separate values to an enumeration.
         %
         % enum = customEnum();
         obj.value = value;
      end
   end
   methods (Static)
       function s = toStruct(name)
         % Returns a structure containing all the enumeration names and
         % values. Expects the name of the enumeration class
         %
         % structure = enum.toStruct('priorTypes')
         s = cell2struct(customEnum.values(name), string(enumeration(name)));
      end
       
      function v = values(name)
         % Returns a cell array containing all the values of the
         % given enumeration class. Expects the name of the 
         % enumeration class
         % 
         % array = enum.values('priorTypes');
         list = enumeration(name);
         v = cell(length(list), 1);
         for i = 1:length(list)
            v{i} = list(i).value;
         end 
      end

      function e = fromValue(name, value)
         % Gets the enumeration with the given value. An empty value is 
         % returned if value is not found. Expects the name of the 
         % enumeration class and the value of an enumeration
         %
         % bulkInEnum = enum.fromValue('hydrationTypes', 'bulk in');   
         values = customEnum.values(name);
         if isText(value)
            index = find(strcmpi(value, values));
         else
            index = find(value==[values{:}]);
         end
         list = enumeration(name);
         e = list(index);  
      end
   end
end
