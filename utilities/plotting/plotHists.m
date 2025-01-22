function h = plotHists(results,varargin)   
    % Plots the Bayes histogram plot from the chain, with or without smoothing.
    % If selected, smoothing is via a moving average algorithm.
    
    % Parse the inputs...
    % Parse the input options
    chain = results.chain;
    fitNames = results.fitNames;
    
    defaultSmooth = true;
    if ~isempty(varargin)
        p = inputParser;
        addOptional(p,  'smooth',       defaultSmooth,      @islogical);     % Use smoothing
        addOptional(p, 'figure', [], @isFigure);  % use an existing figure if given
        parse(p,varargin{:});
        inputBlock = p.Results;
        
        smooth = inputBlock.smooth;

        if ~isempty(inputBlock.figure)
          h = figure(inputBlock.figure);
        end
    else
        smooth = defaultSmooth;
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

function isFigure(figure)
  if ~(isnumeric(figure) || isa(f, 'matlab.ui.Figure'))
    error("'figure' must be a figure number or a figure object.")
  end
end
