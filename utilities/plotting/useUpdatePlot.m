% A simple function to make an updating plot...

% Make the figure
h = figure(1000);
subplot(1,2,1);
subplot(1,2,2);

% Register the event..
eventManager.register(eventTypes.Plot, 'updatePlot');

% Register the close function with the figure...
% (close function will also clear the events)
set(h,'CloseRequestFcn','closeUpdateFig');

fprintf(' Live updating plot started in figure 1000.\n To ensure slds are plotted, set controls.calcSldDuringFit = true\n');

