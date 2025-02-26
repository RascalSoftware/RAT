function cornerPlot(results, options)
    % Creates a corner plot from chain data in the result struct, with or without smoothing.
    % If selected, smoothing is via a moving average algorithm.
    %
    % Examples
    % --------
    % >>> cornerPlot(result, 'smooth', false);
    % >>> cornerPlot(result, 'smooth', false, 'params', [1, 3]);  % should plot 1st and 3rd fitted parameters only. 
    % >>> cornerPlot(result, 'smooth', true, 'smoothingFactor', 0.5);
    %
    % Parameters
    % ----------
    % result : struct
    %    The result of the RAT Bayesian calculation. 
    % options
    %    Keyword/value pair to configure plotting, the following are allowed
    %       * figure ('matlab.ui.Figure' or int, default: []) figure or number of the figure to use for the plot.
    %       * smooth (logical, default: true) indicates if moving average smoothing is applied to the plot.
    %       * params (1D 'array of int', 'array of string' or 'cell array of char vectors', default: []) indices or names of a subset of parameters to the plot.
    %       * smoothingFactor (double [0, 1], default: 0.25) adjusts the level of smoothing by scaling the window size, values near 0 produce smaller moving window sizes, 
    %             resulting in less smoothing and values near 1 produce larger moving window sizes, resulting in more smoothing.

    arguments
        results
        options.figure {isFigure} = []
        options.smooth {logical} = true
        options.params {mustBeVector(options.params,'allow-all-empties')} = []
        options.smoothingFactor {mustBeInRange(options.smoothingFactor, 0, 1)} = 0.25
    end
   
    chain = results.chain;
    rows = size(chain, 2);
    
    if isempty(options.params)
        params = 1:rows;
    else
        rows = numel(options.params);
        if isnumeric(options.params)
            params = options.params;
            validateNumber(params, '"params" option must be whole numbers.', true);
            if any(params < 1) || any(params > size(chain, 2))
                throw(exceptions.invalidValue(sprintf('The parameter indices must be between 1 and %d.', size(chain, 2))));     
            end
        elseif iscellstr(options.params) || isstring(options.params)
            names = cellstr(options.params);
            params = zeros(1, rows);
            for i=1:numel(params)
                paramIndex = find(strcmpi(results.fitNames, names{i}), 1);
                if isempty(paramIndex)
                    throw(exceptions.invalidValue(sprintf('The parameter name (%s) could not be found in the results.fitNames.', names{i})));
                end
                params(i) = paramIndex;
            end
        else
            throw(exceptions.invalidValue(sprintf('"params" option should either be a cell of char arrays, an array of strings, or array of integer indices.')));     
        end
    end

    if ~isempty(options.figure)
        h = figure(options.figure);
    else
        h = figure();
    end
    clf(h);

    % Create mainAxes and make it invisible
    mainAxes = newplot;
    set(mainAxes,'Visible','off','color','none')
    disableDefaultInteractivity(mainAxes);

    mainAxesUnits = get(mainAxes,'units');

    % Create and plot into subAxes
    subAxes = gobjects(rows, rows);
    pos = get(mainAxes, 'Position');
    width = pos(3)/rows;
    height = pos(4)/rows;
    space = .07; % 2 percent space between subAxes
    pos(1:2) = pos(1:2) + space*[width, height];
    mainAxesHV = get(mainAxes, 'HandleVisibility');
    mainAxesParent = get(mainAxes, 'Parent');

    for i=rows:-1:1
        for j=i:-1:1
            if i > j 
                axisPos = [pos(1)+(j-1)*width, pos(2)+(rows-i)*height, width*(1-space), height*(1-space)];
                subAxes(i,j) = axes('Units',mainAxesUnits,'Position',axisPos,'HandleVisibility',mainAxesHV,'parent',mainAxesParent, 'Toolbar', []);
                set(subAxes(i,j),'visible','on','box','on');
                
                xx = chain(:,params(j));
                yy = chain(:,params(i));
        
                plotContours(xx, yy, subAxes(i,j), options.smooth, options.smoothingFactor);
                
                set(subAxes(i,j),'Visible','on','Tag','corrAxis','xlimmode','auto','ylimmode','auto','xgrid','off','ygrid','off');
                
                if j ~= 1
                    set(subAxes(i,j),'YTick',[]);
                end
                
                if i ~= rows
                    set(subAxes(i,j),'XTick',[]);
                end
                
                % Disable AxesToolbar
                subAxes(i,j).Toolbar = [];
            elseif i==j
                axisPos = [pos(1)+(j-1)*width, pos(2)+(rows-i)*height, width*(1-space), height*(1-space)];
                histAxis = axes('Units',mainAxesUnits,'Position',axisPos,'HandleVisibility',mainAxesHV,'parent',mainAxesParent, 'Toolbar', []);
                set(histAxis,'visible','on');
                
                [N,edges] = histcounts(chain(:, params(i)), 25, 'Normalization','pdf');
                edges2 = edges(2:end) - (edges(2)-edges(1))/2;
                if (options.smooth)
                    N = smoothdata(N, 'movmean', 'SmoothingFactor', options.smoothingFactor);
                end
                bar(edges2(:), N(:), 1, 'w');
                
                set(histAxis, 'TitleFontSizeMultiplier', 0.8);
                title(histAxis, split(results.fitNames{params(i)}));         
                
                if i ~= rows
                    set(histAxis,'XTick',[]);
                end
                if i ~= 1
                    set(histAxis,'YTick',[]);
                end
                
                % Disable the AxesToolbar
                histAxis.Toolbar = [];
            end
        end
    end 
    drawnow;
end
