classdef outputClass < handle
    
    % The main RAT output class. It creates a 'ratUpdate' event
    % and then passes update information to any listeners which
    % have been registered.
    properties
        customEventData = struct('textUpdate', '',...
            'dataUpdate',0);
    end
    
	events
	   ratUpdate
	end

	methods
	   function triggerEvent(obj)
            notify(obj,'ratUpdate',specialEventDataClass(obj.customEventData));
       end
       
       function set.customEventData(obj,value)
            obj.customEventData = value;  
            %notify(obj,ratUpdate,specialEventDataClass(value)); 
       end
	end
end