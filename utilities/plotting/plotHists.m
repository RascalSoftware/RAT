function h = plotHists(result, options)   
    % Plots the Bayes histogram plot from the chain, with or without smoothing.
    % If selected, smoothing is via a moving average algorithm.
    %
    % Example Usage::
    % 
    %    plotHists(result, 'smooth', false);
    %
    % Parameters
    % ----------
    % result : struct
    %    The result of the RAT Bayesian calculation. 
    % options
    %    Keyword/value pair to configure plotting, the following are allowed
    %       * figure ('matlab.ui.Figure' or int, default: []) figure or number of the figure to use for the plot.
    %       * smooth (logical, default: true) indicates if moving average smoothing to the plot

    arguments
      result
      options.figure {isFigure} = []
      options.smooth {logical} = true
    end
    
    % Parse the inputs...
    % Parse the input options
    chain = result.chain;
    fitNames = result.fitNames;
    smooth = options.smooth;

    if ~isempty(options.figure)
      h = figure(options.figure);
    else
        h = figure();
    end

    % Work out how many plots....
    [~,npar2]=size(chain);
    inds = 1:npar2;
    
    % Plot the histograms....
    np  = length(inds);
    ns1 = ceil(sqrt(np));
    ns2 = round(sqrt(np));
    for i=1:np
        h=subplot(ns1,ns2,i);
        thisChain = chain(:,inds(i));
    
        [N,edges] = histcounts(thisChain,25, 'Normalization','pdf');
        edges2 = edges(2:end) - (edges(2)-edges(1))/2;
    
        % Smooth if requested
        if smooth
            N = smoothdata(N, 'movmean');
        end
    
        bar(edges2,N,1,'w')
    
        set(h,'ytick',[]);
        title(sprintf('%s',fitNames{i}))
    end
end
