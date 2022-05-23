classdef (ConstructOnLoad) SpecialEventDataClass < event.EventData
   properties
      ratUpdateData
   end
   methods
      function eventData = SpecialEventDataClass(value)
         eventData.ratUpdateData = value;
      end
   end
end

