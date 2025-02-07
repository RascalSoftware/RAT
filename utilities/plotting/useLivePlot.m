classdef useLivePlot < handle
    % Sets up a live plot on a given figure. The live plot listens for plot events from the RAT calculation and
	% redraws the plot every time an event is recieved.	
    %
    % Example Usage::
    % 
    %    useLivePlot();   % Opens a new figure for plot
    %    useLivePlot(1);  % Use figure 1 for plot
    %
    % Parameters
    % ----------
    % figureId : 'matlab.ui.Figure' or int, default: []
    %     The number of the figure to use for the live plot.
    
    properties (Hidden)
        figureId
        handle
    end

    properties (Constant)
        callback = @plotRefSLDHelper
    end

    methods
        function obj = useLivePlot(figureId)
            arguments
                figureId {isFigure} = []
            end
            obj.handle = @(varargin) obj.updatePlot(varargin{:});
            % Make the figure         
            if ~isempty(figureId)
                h = figure(figureId);
            else
                h = figure();
                figureId = get(h, 'Number');
            end
            obj.figureId = figureId;
            % Unregister other live plots only one at a time
            eventManager.clear(eventTypes.Plot)
            % Register the event
            eventManager.register(eventTypes.Plot, obj.handle);
            
            % Register the close function with the figure
            set(h,'CloseRequestFcn', @(varargin) obj.closeFigure());
            
            fprintf(['Live updating plot started in figure %d.\n To ensure slds are plotted, ' ...
                     'set controls.calcSldDuringFit = true\n'], figureId);
        end
    end
    methods (Hidden)
        function updatePlot(obj, data)
            % Clears axes and updates plot with event data
            %
            % Parameters
            % ----------
            % data : struct
            %    A plot event struct.
            
            figure(obj.figureId);
            subplot(1, 2, 1); cla;
            subplot(1, 2, 2); cla;
            obj.callback(data, false);
        end

        function closeFigure(obj)
            % Safely close the updating figure and unregister the event handler.
            
            % Removes event for this plot
            eventManager.unregister(eventTypes.Plot, obj.handle);
            
            % close the figure.
            delete(obj.figureId);
        end
    end
end