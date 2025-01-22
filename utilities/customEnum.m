classdef customEnum
   properties (SetAccess = immutable)
      value
   end   
   properties (Dependent, SetAccess = immutable)
        index
   end
   methods
      function index = get.index(obj)
         % Returns the index of the enum
         index = find(obj==enumeration(obj));
      end
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
       function s = toStruct(name, useIndexAsValue)
         % Returns a structure containing all the enumeration names and
         % values. Expects the name of the enumeration class
         %
         % structure = enum.toStruct('priorTypes')
         arguments
            name
            useIndexAsValue {logical} = false
         end         
         values = customEnum.values(name);
         if useIndexAsValue
             values = num2cell(1:numel(values))';
         end
         s = cell2struct(values, string(enumeration(name)));
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

      function e = fromValue(name, value, acceptIndex)
         % Gets the enumeration with the given value. An empty value is 
         % returned if value is not found. Expects the name of the 
         % enumeration class and the value of an enumeration. If acceptIndex 
         % is true the function will accept an index inplace of the value (it will not 
         % work if enum values are numeric)
         %
         % bulkInEnum = enum.fromValue('hydrationTypes', 'bulk in');
         arguments
            name
            value
            acceptIndex {logical} = false
         end
         values = customEnum.values(name);
         if isText(value)
            index = find(strcmpi(value, values), 1);
         else
            if acceptIndex
                index = value;
            else
                index = find(value==[values{:}], 1);
            end
         end
         
         list = enumeration(name);
         if isempty(index) || index < 1 || index > length(list) || mod(index, 1) ~= 0
            index = zeros(0, 1);
         end
         e = list(index);  
      end
   end
end
