classdef (ConstructOnLoad) specialEventDataClass < event.EventData
   properties
      ratUpdateData
   end
   methods
      function eventData = specialEventDataClass(value)
         eventData.ratUpdateData = value;
      end
   end
end

