classdef eventManager < handle
    % A static event manager class that stores a list of event types and handler pairs 
    % and notifies callback when triggered. Static properties are implemented using 
    % persistent variables.

    methods (Static)
        function value = getEvents() 
            % Gets the list of registered events
            %
            % eventType = eventManager.getEvents();
            value = eventManager.events('get');
        end
        
        function setEvents(value)
            % Sets the list of registered events
            %
            % eventManager.setEvents(eventList);
            eventManager.events('set', value);
        end

        function value=events(op, newValue)
            % Helper to store the list of registered events as static variable
            %
            % eventList = eventManager.events('get');
            % eventManager.events('set', eventList); 
            persistent events
            
            if isempty(events) 
                events = {};
            end

            switch op
               case 'set'    
                  events = newValue;
            end
            value = events;
        end
        
        function value = getHandlers()
            % Gets the list of registered callbacks
            %
            % handlerList = eventManager.getHandlers();
            value = eventManager.handlers('get');
        end
        
        function setHandlers(value)
            % Sets the list of registered callbacks
            %
            % eventManager.setHandlers(handlerList);
            eventManager.handlers('set', value);
        end

        function value=handlers(op, newValue)            
            % Helper to store the list of registered callbacks as static variable
            %
            % handlerList = eventManager.handlers('get');
            % eventManager.handlers('set', handlerList); 
            persistent handlers
            
            if isempty(handlers) 
                handlers = {};
            end

            switch op
               case 'set'    
                  handlers = newValue;
            end
            value = handlers;
        end

        function register(eventType, functionName)
            % Register a callback function for the given eventType. eventType 
            % should be an eventTypes enum and functionName should be name of the 
            % callback function.
            %
            % eventManager.register(eventTypes.Plot, 'plotRefSLDHelper')
            eventType = validateOption(eventType, 'eventTypes', 'Event type must be an eventTypes enum').value;

            if ~isText(functionName) || isempty(char(functionName))
                throw(invalidType('Second value must be function name (text)'));
            end

            events = eventManager().getEvents();
            handlers = eventManager().getHandlers();
            
            if isempty(events) || ~any([events{:}] == eventType)
                eventManagerInterface('register', eventType);
            end

            events{end + 1} = eventType;
            handlers{end + 1} = functionName;

            eventManager().setEvents(events)
            eventManager().setHandlers(handlers)           
        end

        function notify(eventType, data)
            % Sends given data to the callbacks registered for the 
            % eventType. eventType should be an eventTypes enum and 
            % data should be the appropriate data for the event 
            %
            % eventManager.notify(eventTypes.Message, 'wow')
            events = eventManager().getEvents();
            handlers = eventManager().getHandlers();

            eventType = validateOption(eventType, 'eventTypes', 'Event type must be an eventTypes enum').value;
            for i=1:length(events)
                if (eventType == events{i})
                    try
                        funcHandle = str2func(handlers{i});
                        funcHandle(data);
                    catch ME
                        fprintf('EVENTMANAGER: calling %s function failed because: \n\n %s\n', handlers{i}, ME.message);
                    end
                end
            end
        end

        function clear()
            % Clear all register event callbacks 
            %
            % eventManager.clear()
            eventManager().setEvents({})
            eventManager().setHandlers({})
            eventManagerInterface('clear');
        end

    end
end