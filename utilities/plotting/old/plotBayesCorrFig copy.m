function plotBayesCorrFig(chain, fitNames, hFig)

x = chain;
y = chain;

nPars = size(chain,2);
for i = 1:nPars
    
    [N,edges] = histcounts(chain(:,i),15, 'Normalization','pdf');
    edges2 = edges(2:end) - (edges(2)-edges(1))/2;
    N2 = smoothdata(N, 'movmean');
    newDists{i} = [N2(:) edges2(:)];
    
end

rows = size(chain,2);
cols = rows;
figure(hFig);
parent = handle(get(groot, 'CurrentFigure'));
% inLayout=isa(parent,'matlab.graphics.layout.Layout');
% if inLayout && isempty(cax)
    cax=gca;
%end

% Create/find BigAx and make it invisible
BigAx = newplot(cax);
fig = ancestor(BigAx,'figure');
hold_state = ishold(BigAx);
set(BigAx,'Visible','off','color','none')
disableDefaultInteractivity(BigAx);

units = get(BigAx,'units');
set(BigAx,'units','pixels');
pos = get(BigAx,'Position');
set(BigAx,'units',units);
markersize = max(1,min(15,round(15*min(pos(3:4))/max(1,size(x,1))/max(rows,cols))));

% Create and plot into axes
ax = gobjects(rows,cols);
pos = get(BigAx,'Position');
BigAxUnits = get(BigAx,'Units');
width = pos(3)/cols;
height = pos(4)/rows;
space = .07; % 2 percent space between axes
pos(1:2) = pos(1:2) + space*[width height];
m = size(y,1);
k = size(y,3);
xlim = zeros([rows cols 2]);
ylim = zeros([rows cols 2]);
BigAxHV = get(BigAx,'HandleVisibility');
BigAxParent = get(BigAx,'Parent');
% if inLayout
%     % In TiledChartLayouts BigAx will be parented to the layout, but the
%     % visible axes (which use BigAxParent below) will be parented to the
%     % container holding the layout.
%     BigAxParent=ancestor(BigAx, 'matlab.ui.container.CanvasContainer','node');
% end

paxes = findobj(fig,'Type','axes','tag','PlotMatrixScatterAx');

for i=rows:-1:1
    for j=i:-1:1
        axPos = [pos(1)+(j-1)*width pos(2)+(rows-i)*height ...
            width*(1-space) height*(1-space)];
        findax = findaxpos(paxes, axPos);
        if isempty(findax)
            ax(i,j) = axes('Units',BigAxUnits,'Position',axPos,'HandleVisibility',BigAxHV,'parent',BigAxParent, 'Toolbar', []);
            set(ax(i,j),'visible','on','box','on');
        else
            ax(i,j) = findax(1);
        end
        
        xx = reshape(x(:,j,:),[m k]);
        yy = reshape(y(:,i,:),[m k]);
        
        data = [xx(:) yy(:)];
        
%        smoothhist2DLocal(data,30,[200 200]);
        [ctrs1,ctrs2,F] = makeSmoothHist2D(date,20,[200 200]);
        contourf(ctrs1,ctrs2,F);
        colormap(gca,[1 1 1; 0.7 0.7 0.7; 0.3 0.3 0.3]);
        
        %plot(xx,yy,'.','parent',ax(i,j));
        %contour(xx,yy,'parent',ax(i,j));
        
        hh(i,j,:) = ax(i,j);
        
        set(hh(i,j,:),'Visible','on','Tag','corrAxis');
        
        set(ax(i,j),'xlimmode','auto','ylimmode','auto','xgrid','off','ygrid','off');
        
        if j ~= 1
            set(ax(i,j),'YTick',[]);
        end
        
        if i ~= rows
            set(ax(i,j),'XTick',[]);
        end
        
        xlim(i,j,:) = get(ax(i,j),'xlim');
        ylim(i,j,:) = get(ax(i,j),'ylim');
        
        % Disable AxesToolbar
        currAx = ax(i,j);
        currAx.Toolbar = [];
    end
end

xlimmin = min(xlim(:,:,1),[],1); xlimmax = max(xlim(:,:,2),[],1);
ylimmin = min(ylim(:,:,1),[],2); ylimmax = max(ylim(:,:,2),[],2);

% Try to be smart about axes limits and labels.  Set all the limits of a
% row or column to be the same and inset the tick marks by 10 percent.
% inset = .15;
% for i=1:rows
%     thisAx = ax(i,1);
%     if strcmpi(get(thisAx,'Tag'),'corrAxis')
%         set(thisAx,'ylim',[ylimmin(i,1) ylimmax(i,1)])
%         dy = diff(get(ax(i,1),'ylim'))*inset;
%         set(thisAx,'ylim',[ylimmin(i,1)-dy ylimmax(i,1)+dy])
%     end
% end
% dx = zeros(1,cols);
% for j=1:cols
%     if strcmpi(class(ax(1,j)),'matlab.graphics.axis.Axes')
%         set(ax(1,j),'xlim',[xlimmin(1,j) xlimmax(1,j)])
%         dx(j) = diff(get(ax(1,j),'xlim'))*inset;
%         set(ax(:,j),'xlim',[xlimmin(1,j)-dx(j) xlimmax(1,j)+dx(j)])
%     end
% end

% for n = 1:rows-1
%     if strcmpi(class(ax(1,j)),'matlab.graphics.axis.Axes')
%         set(ax(n,:),'xticklabel','')
%     end
% end
% set(ax(:,2:cols),'yticklabel','')
% set(BigAx,'XTick',get(ax(rows,1),'xtick'),'YTick',get(ax(rows,1),'ytick'), ...
%     'YLim',get(ax(rows,1),'ylim'),... %help Axes make room for y-label
%     'tag','PlotMatrixBigAx')
% set(ax,'tag','PlotMatrixScatterAx');

dohist = 1;
if dohist % Put a histogram on the diagonal for plotmatrix(y) case
    histAxes = gobjects(1, rows);
    paxes = findobj(fig,'Type','axes','tag','PlotMatrixHistAx');
    pax = gobjects(1, rows);
    for i=rows:-1:1
        axPos = get(ax(i,i),'Position');
        findax = findaxpos(paxes, axPos);
        if isempty(findax)
            axUnits = get(ax(i,i),'Units');
            histax = axes('Units',axUnits,'Position',axPos,'HandleVisibility',BigAxHV,'parent',BigAxParent, 'Toolbar', []);
            set(histax,'visible','on');
            histAxes(i) = histax;
        else
            histax = findax(1);
        end
        thisHist = newDists{i};
        hhist(i) = bar(thisHist(:,2),thisHist(:,1),'w');
        
        %hhist(i) = histogram(histax,y(:,i,:));
%         set(histax,'xtick',[],'ytick',[],'xgrid','off','ygrid','off');
%         set(histax,'xlim',[xlimmin(1,i)-dx(i) xlimmax(1,i)+dx(i)])
        set(histax,'tag','PlotMatrixHistAx','YTick',[],'TitleFontSizeMultiplier',0.8);
        ht = title(histax,split(fitNames{i}));
        
        
        if i ~= rows
            set(histax,'XTick',[]);
        end
        
        % Disable the AxesToolbar
        histax.Toolbar = [];
        pax(i) = histax;  % ax handles for histograms
    end
else
    histAxes = []; % Make empty for listener
end

drawnow;

end

function findax = findaxpos(ax, axpos)
tol = eps;
findax = [];
for i = 1:length(ax)
    axipos = get(ax(i),'Position');
    diffpos = axipos - axpos;
    if (max(max(abs(diffpos))) < tol)
        findax = ax(i);
        break;
    end
end

end

function smoothhist2DLocal(X,lambda,nbins,outliercutoff,plottype)
% SMOOTHHIST2D Plot a smoothed histogram of bivariate data.
%   SMOOTHHIST2D(X,LAMBDA,NBINS) plots a smoothed histogram of the bivariate
%   data in the N-by-2 matrix X.  Rows of X correspond to observations.  The
%   first column of X corresponds to the horizontal axis of the figure, the
%   second to the vertical. LAMBDA is a positive scalar smoothing parameter;
%   higher values lead to more smoothing, values close to zero lead to a plot
%   that is essentially just the raw data.  NBINS is a two-element vector
%   that determines the number of histogram bins in the horizontal and
%   vertical directions.
%
%   SMOOTHHIST2D(X,LAMBDA,NBINS,CUTOFF) plots outliers in the data as points
%   overlaid on the smoothed histogram.  Outliers are defined as points in
%   regions where the smoothed density is less than (100*CUTOFF)% of the
%   maximum density.
%
%   SMOOTHHIST2D(X,LAMBDA,NBINS,[],'surf') plots a smoothed histogram as a
%   surface plot.  SMOOTHHIST2D ignores the CUTOFF input in this case, and
%   the surface plot does not include outliers.
%
%   SMOOTHHIST2D(X,LAMBDA,NBINS,CUTOFF,'image') plots the histogram as an
%   image plot, the default.
%
%   Example:
%       X = [mvnrnd([0 5], [3 0; 0 3], 2000);
%            mvnrnd([0 8], [1 0; 0 5], 2000);
%            mvnrnd([3 5], [5 0; 0 1], 2000)];
%       smoothhist2D(X,5,[100, 100],.05);
%       smoothhist2D(X,5,[100, 100],[],'surf');
%
%   Reference:
%      Eilers, P.H.C. and Goeman, J.J (2004) "Enhancing scaterplots with
%      smoothed densities", Bioinformatics 20(5):623-628.

%   Copyright 2009 The MathWorks, Inc.
%   Revision: 1.0  Date: 2006/12/12
%
%   Requires MATLAB® R14.

if nargin < 4 || isempty(outliercutoff), outliercutoff = .05; end
if nargin < 5, plottype = 'image'; end

minx = min(X,[],1);
maxx = max(X,[],1);
edges1 = linspace(minx(1), maxx(1), nbins(1)+1);
ctrs1 = edges1(1:end-1) + .5*diff(edges1);
edges1 = [-Inf edges1(2:end-1) Inf];
edges2 = linspace(minx(2), maxx(2), nbins(2)+1);
ctrs2 = edges2(1:end-1) + .5*diff(edges2);
edges2 = [-Inf edges2(2:end-1) Inf];

[n,p] = size(X);
bin = zeros(n,2);
% Reverse the columns of H to put the first column of X along the
% horizontal axis, the second along the vertical.
[dum,bin(:,2)] = histc(X(:,1),edges1);
[dum,bin(:,1)] = histc(X(:,2),edges2);
H = accumarray(bin,1,nbins([2 1])) ./ n;

% Eiler's 1D smooth, twice
G = smooth1D(H,lambda);
F = smooth1D(G',lambda)';
% % An alternative, using filter2.  However, lambda means totally different
% % things in this case: for smooth1D, it is a smoothness penalty parameter,
% % while for filter2D, it is a window halfwidth
% F = filter2D(H,lambda);

relF = F./max(F(:));
if outliercutoff > 0
    outliers = (relF(nbins(2)*(bin(:,2)-1)+bin(:,1)) < outliercutoff);
end

nc = 256;
contour(ctrs1,ctrs2,F)
%colormap(gca,[1 1 1; 0.7 0.7 0.7; 0.3 0.3 0.3])


% colormap(hot(nc));
% switch plottype
% case 'surf'
%     surf(ctrs1,ctrs2,F,'edgealpha',0);
% case 'image'
%     image(ctrs1,ctrs2,floor(nc.*relF) + 1);
%     hold on
%     % plot the outliers
%     if outliercutoff > 0
%         plot(X(outliers,1),X(outliers,2),'.','MarkerEdgeColor',[.8 .8 .8]);
%     end
% %     % plot a subsample of the data
% %     Xsample = X(randsample(n,n/10),:);
% %     plot(Xsample(:,1),Xsample(:,2),'bo');
%     hold off
% end
end
%-----------------------------------------------------------------------------
function Z = smooth1D(Y,lambda)
[m,n] = size(Y);
E = eye(m);
D1 = diff(E,1);
D2 = diff(D1,1);
P = lambda.^2 .* D2'*D2 + 2.*lambda .* D1'*D1;
Z = (E + P) \ Y;
% This is a better solution, but takes a bit longer for n and m large
% opts.RECT = true;
% D1 = [diff(E,1); zeros(1,n)];
% D2 = [diff(D1,1); zeros(1,n)];
% Z = linsolve([E; 2.*sqrt(lambda).*D1; lambda.*D2],[Y; zeros(2*m,n)],opts);
end

%-----------------------------------------------------------------------------
function Z = filter2D(Y,bw)
z = -1:(1/bw):1;
k = .75 * (1 - z.^2); % epanechnikov-like weights
k = k ./ sum(k);
Z = filter2(k'*k,Y);

end