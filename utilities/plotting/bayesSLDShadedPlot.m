function bayesSLDShadedPlot(problem,result,varargin)


%  Parse the input options
if ~isempty(varargin)
    defaultFit = 'mean';
    defaultKeep = false;
    
    p = inputParser;
    addOptional(p,  'fit',      defaultFit,     @(x) any(strcmpi(x,{'mean','max','average','all'})));
    addOptional(p,  'KeepAxes',  defaultKeep,    @(x) islogical(x));
    
    parse(p,varargin{:});
    inputBlock = p.Results;
    
    fit = inputBlock.fit;
    keepAx = inputBlock.KeepAxes;
else
    fit = 'max';
    keepAx = true;
end

                   %mean    %Max    %Average
showWhichCurves = [false    false    false];

switch fit
    case 'mean'
        showWhichCurves(1) = 1;
    case 'max'
        showWhichCurves(2) = 1;
    case 'average'
        showWhichCurves(3) = 1;
    case 'all'
        showWhichCurves(1:3) = 1;
end

f = gcf;
if ~ keepAx
    clf; hold on; box on
end

pLims = result.predlims;
sldPlims = pLims{2};
bayesRes = result.bayesRes;


% Get the slds from 'max' and 'mean'
bestSld_max = result.bestFitsMax{2}{:};
bestSld_mean = result.bestFitsMean{2}{:};

numberOfContrasts = length(result.sldProfiles);

hold on
for i = 1:numberOfContrasts
    
    thisSldMax = bestSld_max{i};
        
    % Get the limits        
    h = plot(thisSldMax(:,1),thisSldMax(:,2),'k-');
    col = get(h,'Color');
    
    theseLims = sldPlims{i}{:};
    
    % Get the ranges..
    thisMin = theseLims(2,:);
    thisMax = theseLims(8,:);

    xdata = thisSldMax(:,1);
    plot(xdata,thisMin);
    plot(xdata,thisMax);
    sldShadedPlot(xdata,thisMin,thisMax,[0.8 0.8 0.8]);
    
    % Plot the requested fit lines;
    %if showWhichCurves(1)
        % Plot the mean
        %plot(thisSldMean(:,1),thisSldMean(:,2),'b-');
    %end
    
    %if showWhichCurves(2)
        % Plot the max

    %end
    
end


end
