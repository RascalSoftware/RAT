function bayesShadedPlot(problem,result,varargin)

% Plot the shaded reflectivities from Bayes output
% from RAT
sf = result.contrastParams.scalefactors;
if isa(problem,'domainsClass')
    isDomains = true;
else
    isDomains = false;
end

%  Parse the input options
if ~isempty(varargin)
    defaultq4  = 0;
    defaultFit = 'mean';
    defaultKeep = false;
    defaultInterval = 95;
    
    
    allIntervals = [65 95];
    
    p = inputParser;
    addOptional(p,  'q4',           defaultq4,          @islogical);
    addOptional(p,  'fit',          defaultFit,         @(x) any(strcmpi(x,{'mean','average','all'})));
    addOptional(p,  'KeepAxes',     defaultKeep,        @islogical);
    addOptional(p,  'interval',     defaultInterval,    @(x) ismember(x,allIntervals));
    
    parse(p,varargin{:});
    inputBlock = p.Results;
    
    q4 = inputBlock.q4;
    fit = inputBlock.fit;
    keepAx = inputBlock.KeepAxes;
    interval = inputBlock.interval;

else
    q4 = false;
    fit = 'average';
    keepAx = false;
    interval = 65;
end

                   %mean  %Average   % All
showWhichCurves = [false    false    false];

switch fit
    case 'mean'
        showWhichCurves(1) = 1;
    case 'average'
        showWhichCurves(2) = 1;
    case 'all'
        showWhichCurves(1:2) = 1;
end

f = gcf;

if ~ keepAx
    clf; hold on; box on
end

pLims = result.predictionIntervals;
refPlims = pLims.reflectivity;
sldPlims = pLims.sld;
refXdata = pLims.reflectivityXData;
sldXdata = pLims.sldXData;

% Get the reflectivities for mean...
bestRefMean = result.reflectivity;
bestSldMean = result.sldProfiles;

shiftedData = result.shiftedData;
numberOfContrasts = length(shiftedData);

% Calculate the best fits depending on the selected options
subplot(1,2,1)
set(gca,'YScale','log','XScale','log');
hold on; box on

for i = 1:numberOfContrasts
    
    %thisRef = reflect{i};
    thisData = shiftedData{i};
    thisRefMean = bestRefMean{i};
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
    theseLims = refPlims{i};
    
    switch interval
        case 95
            vals = [1 5];
        case 65
            vals = [2 4];
    end
    
    thisMin = theseLims(vals(1),:)./mult;
    thisMax = theseLims(vals(2),:)./mult;
    
    thisRefAvg = theseLims(3,:)./mult;
    
    thisRefMean(:,2) = thisRefMean(:,2)./mult;
    %thisRefMax(:,2) = thisRefMax(:,2)./mult;
    
    thisDataX = thisData(:,1);
    thisDataY = thisData(:,2)./mult;
    thisDataErr = thisData(:,3)./mult;
    
    thisSimX = refXdata{i};
    thisSimQ4 = thisSimX.^4;
    
    switch q4
        case true
            thisMin = thisMin .* thisSimQ4;
            thisMax = thisMax .* thisSimQ4;
            thisRefMean(:,2) = thisRefMean(:,2) .* thisQ4;
            thisRefAvg = thisRefAvg .* thisSimQ4;          
            thisDataY = thisDataY(:) .* thisQ4;
            thisDataErr = thisDataErr(:) .* thisQ4;
    end
    
    errorbar(thisDataX,thisDataY,thisDataErr,'.');

    %plot(thisData(:,1),thisMin,'-','color',[0.7 0.7 0.7]);
    %plot(thisData(:,1),thisMax,'-','color',[0.7 0.7 0.7]);
    %plot(thisData(:,1),thisRef,'LineWidth',2.0);
    %fillyy(thisData(:,1),thisMin,thisMax,[0.8 0.8 0.8]);
    shade(thisSimX,thisMin,thisSimX,thisMax,'FillColor',[0.7 0.7 0.7],'FillType',[1 2;2 1],'FillAlpha',0.3);
    
    % Plot the requested fit lines;
    if showWhichCurves(1)
        % Plot the mean
        plot(thisRefMean(:,1),thisRefMean(:,2),'b-');
    end
    
    if showWhichCurves(2)
        % Plot the average
       plot(thisDataX,thisRefAvg,'r-');
    end
    
end

% Now plot the SLD's
subplot(1,2,2); hold on; box on

if ~isDomains
    for i = 1:numberOfContrasts

        thisSldMean = bestSldMean{i};
        %thisSldMax = bestSld_max{i};

        theseLims = sldPlims{i};

        thisSldX = sldXdata{i};

        switch interval
            case 95
                vals = [1 5];
            case 65
                vals = [2 4];
        end

        thisMin = theseLims(vals(1),:);
        thisMax = theseLims(vals(2),:);

        thisSldAvg = theseLims(3,:);

        if showWhichCurves(1)
            % Plot the mean
            plot(thisSldMean(:,1),thisSldMean(:,2),'b-');
        end

        if showWhichCurves(2)
            % Plot the max
            plot(thisSldX,thisSldAvg,'r-');
        end

        thisSldX = sldXdata{i};
        shade(thisSldX,thisMin,thisSldX,thisMax,'FillColor',[0.7 0.7 0.7],'FillType',[1 2;2 1],'FillAlpha',0.3);
    end
else
    for i = 1:numberOfContrasts

        thisSldMean = bestSldMean(i,:);
        %thisSldMax = bestSld_max{i};

        theseLims = sldPlims(i,:);

        thisSldX = sldXdata(i,:);

        switch interval
            case 95
                vals = [1 5];
            case 65
                vals = [2 4];
        end

        for m = 1:2
            thisMin = theseLims{m}(vals(1),:);
            thisMax = theseLims{m}(vals(2),:);

            thisSldAvg = theseLims{m}(3,:);

            if showWhichCurves(1)
                % Plot the mean
                plot(thisSldMean{m}(:,1),thisSldMean{m}(:,2),'b-');
            end

            if showWhichCurves(2)
                % Plot the max
                plot(thisSldX{m},thisSldAvg,'r-');
            end

            %thisSldX = sldXdata{i}{m};
            shade(thisSldX{m},thisMin,thisSldX{m},thisMax,'FillColor',[0.7 0.7 0.7],'FillType',[1 2;2 1],'FillAlpha',0.3);
        end
    end

end

end