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
            obj.handle = @(varargin) obj.updatePlot(varargin{:});
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
        
        function updatePlot(obj, data)
            % Clears axes and updates plot
            figure(obj.figureId);
            subplot(1, 2, 1); cla;
            subplot(1, 2, 2); cla;
            obj.callback(data, false);
        end

        function closeFigure(obj)
            % Safely close the updating figure and clear the event.
            
            % Removes event for this plot
            eventManager.unregister(eventTypes.Plot, obj.handle);
            
            % close the figure.
            delete(obj.figureId);
        end
    end
end