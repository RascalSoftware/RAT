classdef (ConstructOnLoad) specialEventDataClass < event.EventData
   properties
      updateData
   end
   methods
      function eventData = specialEventDataClass(value)
         eventData.updateData = value;
      end
   end
end

