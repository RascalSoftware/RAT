function plotContours(x, y, parent, smooth, smoothingFactor)
    % Creates a contour plot.
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
    %    indicates if moving average smoothing is applied to the plot.
    % smoothingFactor : double [0, 1], default: 0.25
    %    adjusts the level of smoothing by scaling the window size, values near 0 produce smaller moving window sizes, 
    %    resulting in less smoothing and values near 1 produce larger moving window sizes, resulting in more smoothing.
    
    arguments
        x {mustBeNumeric}
        y {mustBeNumeric}
        parent {mustBeA(parent, ["matlab.graphics.axis.Axes", "matlab.ui.Figure", "double"])} = []
        smooth {mustBeA(smooth, 'logical')} = false
        smoothingFactor {mustBeInRange(smoothingFactor, 0, 1)} = 0.25
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

    [N, xEdges, yEdges] = histcounts2(x, y, nbins, 'Normalization', 'pdf');

    if (smooth)
        N = smoothdata(N, 'movmean', 'SmoothingFactor', smoothingFactor);
    end

    histogram2('XBinEdges', xEdges, 'YBinEdges', yEdges, 'BinCounts', N)
    C{1} = xEdges(2:end) - (xEdges(2)-xEdges(1))/2;
    C{2} = yEdges(2:end) - (yEdges(2)-yEdges(1))/2;

    K=(1/10)*ones(5);
    N=conv2(N,K,'same');

    NN = N/sum(N(:));
    NS = sort(NN(:));

    [c, ind, ~] = unique(cumsum(NS),'stable');
    levels = interp1(c, NS(ind), [0.015 0.1 0.3 0.65 0.9],'linear','extrap');

    contourf(C{1}, C{2}, NN', levels, 'parent', parent);

    colormap(flipud(gray(5)));

    hold on
end
