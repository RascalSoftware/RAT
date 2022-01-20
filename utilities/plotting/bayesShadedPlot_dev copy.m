function bayesShadedPlot_dev(problem,result,sf,varargin)

% Plot the shaded reflectivities and SLD's fro Bayes output
% from RAT

%  Parse the input options
if ~isempty(varargin)
    defaultq4  = false;
    defaultFit = 'mean';
    defaultKeep = false;
    
    p = inputParser;
    addOptional(p,  'q4',       defaultq4,      @(x) islogical(x));
    addOptional(p,  'fit',      defaultFit,     @(x) any(strcmpi(x,{'mean','max','average','all'})));
    addOptional(p,  'KeepAxes',  defaultKeep,    @(x) islogical(x));
    
    parse(p,varargin{:});
    inputBlock = p.Results;
    
    q4 = inputBlock.q4;
    fit = inputBlock.fit;
    keepAx = inputBlock.KeepAxes;
else
    q4 = false;
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
refPlims = pLims{1};
sldPlims = pLims{2};
bayesRes = result.bayesRes;

% Get the reflectivities from 'max' and 'mean'
bestRef_max = result.bestFitsMax{1}{:};
bestSld_max = result.bestFitsMax{2}{:};

bestRef_mean = result.bestFitsMean{1}{:};
betsSld_mean = result.bestFitsMean{2}{:};

shifted_data = result.shifted_data;
numberOfContrasts = length(shifted_data);

% Calculate the best fits depending on the selected options
%subplot(1,2,1)
set(gca,'YScale','log','XScale','log');
hold on

for i = 1:numberOfContrasts
    
    %thisRef = reflect{i};
    thisData = shifted_data{i};
    thisRefMean = bestRef_mean{i};
    thisRefMax = bestRef_max{i};
    thisSf = sf(i);
    
    switch q4
        case false
            if i == 1
                mult = 1;
            else
                mult = 2^(4*i);
            end
        otherwise
            mult = 2^(4*i);
            thisQ4 = thisData(:,1).^4;
    end
        
    % Get the limits and fits
    theseLims = refPlims{i}{:};
    
    % Get the ranges..
    allRanges = [0.97 ];
    
    
    thisMin = theseLims(3,:)./mult;
    thisMax = theseLims(7,:)./mult;
    
    thisMin = thisMin ./ sf(i);
    thisMax = thisMax ./ sf(i);
    
    
    thisRefMean(:,2) = thisRefMean(:,2)./mult;
    thisRefMax(:,2) = thisRefMax(:,2)./mult;
    
    thisDataX = thisData(:,1);
    thisDataY = thisData(:,2)./mult;
    thisDataErr = thisData(:,3)./mult;
    
    switch q4
        case true
            thisMin = thisMin(:) .* thisQ4;
            thisMax = thisMax(:) .* thisQ4;
            thisRefMean(:,2) = thisRefMean(:,2) .* thisQ4;
            thisRefMax(:,2) = thisRefMax(:,2) .* thisQ4;          
            thisDataY = thisDataY(:) .* thisQ4;
            thisDataErr = thisDataErr(:) .* thisQ4;
    end
    
    errorbar(thisDataX,thisDataY,thisDataErr,'.');

    plot(thisData(:,1),thisMin,'-','color',[0.7 0.7 0.7]);
    plot(thisData(:,1),thisMax,'-','color',[0.7 0.7 0.7]);
    %plot(thisData(:,1),thisRef,'LineWidth',2.0);
    fillyy(thisData(:,1),thisMin,thisMax,[0.8 0.8 0.8]);
    
    % Plot the requested fit lines;
    if showWhichCurves(1)
        % Plot the mean
        plot(thisRefMean(:,1),thisRefMean(:,2),'b-');
    end
    
    if showWhichCurves(2)
        % Plot the max
        plot(thisRefMax(:,1),thisRefMax(:,2),'r-');
    end
    
end


end