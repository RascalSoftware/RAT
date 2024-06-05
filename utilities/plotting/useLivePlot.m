classdef useLivePlot < handle
    % Sets up a live plot on a given figure 
    properties
        figureId
        handle
    end

    properties (Constant)
        callback = @plotRefSLDHelper
    end

    methods
        function obj = useLivePlot(figureId)
            arguments
                figureId {mustBePositive, mustBeInteger} = 1000
            end
            obj.figureId = figureId;
            obj.handle = @(varargin) obj.callback(varargin{:}, true, obj.figureId);
            % Make the figure
            h = figure(obj.figureId);
            % Unregister other live plots only one at a time
            eventManager.clear(eventTypes.Plot)
            % Register the event
            eventManager.register(eventTypes.Plot, obj.handle);
            
            % Register the close function with the figure
            set(h,'CloseRequestFcn', @(varargin) obj.closeFigure());
            
            fprintf(['Live updating plot started in figure %d.\n To ensure slds are plotted, ' ...
                     'set controls.calcSldDuringFit = true\n'], figureId);
        end
        
        function closeFigure(obj)
            % Safely close the updating figure and clear the event...
            % Remove all events...
            eventManager.unregister(eventTypes.Plot, obj.handle);
            
            % close the figure....
            delete(obj.figureId);
        end
    end
end