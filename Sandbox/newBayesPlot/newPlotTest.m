clear
figure(1); clf

chain = load('chain');
chain = chain.chain;

chain = chain(:,1:10);

x = chain;
y = chain;

rows = size(chain,2);
cols = rows;

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
        plot(xx,yy,'.','parent',ax(i,j));
        
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
%     set(ax(1,j),'xlim',[xlimmin(1,j) xlimmax(1,j)])
%     dx(j) = diff(get(ax(1,j),'xlim'))*inset;
%     set(ax(:,j),'xlim',[xlimmin(1,j)-dx(j) xlimmax(1,j)+dx(j)])
% end

% set(ax(1:rows-1,:),'xticklabel','')
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
        hhist(i) = histogram(histax,y(:,i,:));
%         set(histax,'xtick',[],'ytick',[],'xgrid','off','ygrid','off');
%         set(histax,'xlim',[xlimmin(1,i)-dx(i) xlimmax(1,i)+dx(i)])
        set(histax,'tag','PlotMatrixHistAx','YTick',[]);
        
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


