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
                events =  cell(0, 3);
            end

            switch op
               case 'set'    
                  events = newValue;
            end
            value = events;
        end
        
        function funcID = getCallbackID(callback)
            % Generates a id for a callback handle function
            %
            % ID = getCallbackID(@disp)
            funcID = func2str(callback);
            funcDetails = functions(callback);
            if strcmp(funcDetails.type, 'anonymous')
                workspace = functions(callback).workspace{:};
                if isfield(workspace, 'obj') &&  isprop(workspace.obj, 'callback') && isprop(workspace.obj, 'figureId')
                    funcID = sprintf('Function ''%s'' on figure %d', func2str(workspace.obj.callback), workspace.obj.figureId);
                end
            end
        end
        
        function callback = validateCallback(callback)
            % Validate the given callback and return handle for the
            % callback
            %
            % callback = validateCallback('disp');
            if ~isa(callback, 'function_handle') && (~isText(callback) || isempty(char(callback)))
                throw(exceptions.invalidType('Second value must be function name (text) or handle'));
            end
            
            if isText(callback)
                callback = str2func(callback);
            end
        end

        function register(eventType, callback)
            % Register a callback function for the given eventType. eventType 
            % should be an eventTypes enum and callback should be name or handle of the 
            % callback function.
            %
            % eventManager.register(eventTypes.Plot, 'plotRefSLDHelper');
            eventType = validateOption(eventType, 'eventTypes', 'Event type must be an eventTypes enum').value;
            callback = eventManager.validateCallback(callback);

            events = eventManager.getEvents();
            funcID = eventManager.getCallbackID(callback);
            
            if ~isempty(events) 
                for i=1:size(events, 1)
                    if strcmp(events{i, 1}, funcID) && events{i, 2} == eventType
                        return
                    end
                end
            end

            events(end + 1, :) = {funcID, eventType, callback};
            eventManager.setEvents(events);           
        end

        function notify(eventType, data)
            % Sends given data to the callbacks registered for the 
            % eventType. eventType should be an eventTypes enum and 
            % data should be the appropriate data for the event 
            %
            % eventManager.notify(eventTypes.Message, 'wow');
            events = eventManager.getEvents();
            eventType = validateOption(eventType, 'eventTypes', 'Event type must be an eventTypes enum').value;
            for i=1:size(events, 1)
                if eventType == events{i, 2}
                    try
                        funcHandle = events{i, 3};
                        funcHandle(data);
                    catch ME
                        fprintf('EVENTMANAGER: calling %s function failed on line %d because: \n\n %s\n', events{i, 1}, ME.stack(1).line, ME.message);
                    end
                end
            end
        end

        function unregister(eventType, callback)
            % Remove specific event callbacks 
            %
            % eventManager.unregister(eventTypes.Plot, 'plotRefSLDHelper');
            eventType = validateOption(eventType, 'eventTypes', 'Event type must be an eventTypes enum').value;
            callback = eventManager.validateCallback(callback);
            events = eventManager.getEvents();
            for i=size(events, 1):-1:1
                if (eventType == events{i, 2}) && strcmp(eventManager.getCallbackID(callback), events{i, 1})
                    events(i, :) = [];
                end
            end
            eventManager.setEvents(events);
        end
        
        function clear(varargin)
            % Clear all register event callbacks or specific types 
            %
            % eventManager.clear();
            % eventManager.clear(eventTypes.Plot);
            events = eventManager.getEvents();
            if isempty(events)
                return
            end
            if nargin == 0
                events = cell(0, 3);
            else
                eventType = validateOption(varargin{1}, 'eventTypes', 'Event type must be an eventTypes enum').value;
                events(eventType==[events{:, 2}], :) = [];
            end
            eventManager.setEvents(events);
        end

    end
end