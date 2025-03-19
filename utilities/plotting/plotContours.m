function plotContours(x, y, parent, smooth)
    % Draw a contour plot for the posteriors of two parameters.
    %
    % Parameters
    % ----------
    % x : double
    %    1D array data for X axis. 
    % y : double
    %    1D array data for Y axis. 
    % parent : matlab.graphics.axes.Axes or matlab.ui.Figure, or figure number, default: []
    %    axes or figure object to make plot on.
    % smooth : logical, default: false 
    %    indicates if KDE smoothing is applied to the plot.
    % 
    arguments
        x {mustBeNumeric}
        y {mustBeNumeric}
        parent {mustBeA(parent, ["matlab.graphics.axis.Axes", "matlab.ui.Figure", "double"])} = []
        smooth {mustBeA(smooth, 'logical')} = false
    end

    if isempty(parent)
        h = figure;
        parent = axes(h);
    elseif ~isa(parent, "matlab.graphics.axis.Axes")
        h = figure(parent);
        if isempty(h.CurrentAxes)
            parent = axes(h);
        else
            parent = h.CurrentAxes(1);
        end
    end

    nbins = [50, 50];


    if (smooth)
        [~,density,Xs,Ys]=kde2D([x y], 2^4, [min(x) min(y)], [max(x) max(y)]);
    else
        [N, xEdges, yEdges] = histcounts2(x, y, nbins, 'Normalization', 'pdf');
        histogram2('XBinEdges', xEdges, 'YBinEdges', yEdges, 'BinCounts', N)
        Xs = xEdges(2:end) - (xEdges(2)-xEdges(1))/2;
        Ys = yEdges(2:end) - (yEdges(2)-yEdges(1))/2;

        K=(1/10)*ones(5);
        N=conv2(N,K,'same');

        density = N/sum(N(:));
    end

    levels = linspace(min(density, [], "all"), max(density, [], "all"), 10);

    contourf(Xs, Ys, density, levels, 'parent', parent);

    colormap(flipud(gray(5)));

    hold on
end
