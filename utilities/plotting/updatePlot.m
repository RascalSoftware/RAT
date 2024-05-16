function updatePlot(varargin)

h = figure(1000);

subplot(1,2,1); cla
subplot(1,2,2); cla
plotRefSLDHelper(varargin{:});
drawnow limitrate

end

