function h = plotBayesHists(chain,fitNames,h,varargin)

% Plots the Bayes histogram plot from the chain, with or without smoothing.
% If selected, smoothing is via a moving average algorithm.

% Parse the inputs...
% Parse the input options

if ~isempty(varargin)

    defaultSmooth = 'no';
    
    p = inputParser;
    addOptional(p,  'smooth',       defaultSmooth,      @(x) islogical(x));     % Use smoothing?
    
    parse(p,varargin{:});
    inputBlock = p.Results;
    
    smooth = inputBlock.smooth;
end

% Work out how many plots....
[nsimu,npar2]=size(chain);
inds = 1:npar2;

% Make the figure (if required).
if isempty(h)
    h = figure();
else
    figure(h);
end

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
        N2 = smoothdata(N, 'movmean');
    end

    bar(edges2,N2,1,'w')

    set(h,'ytick',[]);
    title(sprintf('%s',fitNames{i}))
end


end