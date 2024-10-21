function h = plotHists(results,f,varargin)   
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
    
        parse(p,varargin{:});
        inputBlock = p.Results;
        
        smooth = inputBlock.smooth;
    else
        smooth = defaultSmooth;
    end
    
    % Sort the figure..
    if (isnumeric(f) || isa(f,'matlab.ui.Figure')) && ~isempty(f)
        h = figure(f);
    elseif isempty(f)
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