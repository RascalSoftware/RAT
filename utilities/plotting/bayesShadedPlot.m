function bayesShadedPlot(problem,result,varargin)

% Plot the shaded reflectivities from Bayes output
% from RAT

if isa(problem,'domainsClass')
    isDomains = true;
else
    isDomains = false;
end

%  Parse the input options
if ~isempty(varargin)
    defaultq4  = false;
    defaultKeep = false;
    defaultInterval = 95;
    
    allIntervals = [65 95];
    
    p = inputParser;
    addOptional(p,  'q4',           defaultq4,          @islogical);
    addOptional(p,  'KeepAxes',     defaultKeep,        @islogical);
    addOptional(p,  'interval',     defaultInterval,    @(x) ismember(x,allIntervals));
    
    parse(p,varargin{:});
    inputBlock = p.Results;
    
    q4 = inputBlock.q4;
    keepAx = inputBlock.KeepAxes;
    interval = inputBlock.interval;

else

    q4 = false;
    keepAx = false;
    interval = 95;

end


if ~ keepAx
    clf; hold on; box on
end

refPlims = result.predictionIntervals.reflectivity;
sldPlims = result.predictionIntervals.sld;

% Get the reflectivities and SLDs
bestRefMean = result.reflectivity;
bestSldMean = result.sldProfiles;

shiftedData = result.shiftedData;
numberOfContrasts = length(shiftedData);

% Calculate the best fits depending on the selected options
subplot(1,2,1)
set(gca,'YScale','log','XScale','log');
hold on; box on

for i = 1:numberOfContrasts
    
    thisData = shiftedData{i};
    thisRefMean = bestRefMean{i};
    
    mult = 2^(4*i);
    switch q4
        case true
            thisQ4 = thisData(:,1).^4;
        case false
            if i == 1
                mult = 1;
            end
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
        
    thisRefMean(:,2) = thisRefMean(:,2)./mult;
    
    thisDataX = thisData(:,1);
    thisDataY = thisData(:,2)./mult;
    thisDataErr = thisData(:,3)./mult;
    
    thisSimX = result.reflectivity{i}(:,1);
    thisSimQ4 = thisSimX.^4;
    
    switch q4
        case true
            thisMin = thisMin .* thisSimQ4;
            thisMax = thisMax .* thisSimQ4;
            thisRefMean(:,2) = thisRefMean(:,2) .* thisQ4;         
            thisDataY = thisDataY(:) .* thisQ4;
            thisDataErr = thisDataErr(:) .* thisQ4;
    end
    
    errorbar(thisDataX,thisDataY,thisDataErr,'.');

    shade(thisSimX,thisMin,thisSimX,thisMax,'FillColor',[0.7 0.7 0.7],'FillType',[1 2;2 1],'FillAlpha',0.3);
    
    % Plot the requested fit lines
    plot(thisRefMean(:,1),thisRefMean(:,2),'b-');

end

% Now plot the SLD's
subplot(1,2,2); hold on; box on

if ~isDomains
    for i = 1:numberOfContrasts

        thisSldMean = bestSldMean{i};

        theseLims = sldPlims{i};

        thisSldX = result.sldProfiles{i}(:,1);

        switch interval
            case 95
                vals = [1 5];
            case 65
                vals = [2 4];
        end

        thisMin = theseLims(vals(1),:);
        thisMax = theseLims(vals(2),:);

        plot(thisSldMean(:,1),thisSldMean(:,2),'b-');
        shade(thisSldX,thisMin,thisSldX,thisMax,'FillColor',[0.7 0.7 0.7],'FillType',[1 2;2 1],'FillAlpha',0.3);

    end

else

    for i = 1:numberOfContrasts

        thisSldMean = bestSldMean(i,:);

        theseLims = sldPlims(i,:);

        thisSldX = result.sldProfiles(i,:);

        switch interval
            case 95
                vals = [1 5];
            case 65
                vals = [2 4];
        end

        for j = 1:2
            thisMin = theseLims{j}(vals(1),:);
            thisMax = theseLims{j}(vals(2),:);

            thisDomainSldX = thisSldX{j}(:,1);

            plot(thisSldMean{j}(:,1),thisSldMean{j}(:,2),'b-');
            shade(thisDomainSldX,thisMin,thisDomainSldX,thisMax,'FillColor',[0.7 0.7 0.7],'FillType',[1 2;2 1],'FillAlpha',0.3);
        end
    end

end

end
