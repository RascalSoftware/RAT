function bayesShadedPlot(problem, result, options)
% Plot the shaded reflectivities from Bayes output
% from RAT
arguments
    problem
    result
    options.q4 {logical} = false
    options.keepAxes {logical} = false
    options.interval {mustBeMember(options.interval, [65, 95])} = 95
end

if isa(problem,'domainsClass')
    isDomains = true;
else
    isDomains = false;
end

if ~options.keepAxes
    clf; hold on; box on
end

switch options.interval
    case 95
        vals = [1 5];
    case 65
        vals = [2 4];
end

fillColor = [0.7 0.7 0.7];
fillType = [1 2;2 1];
fillAlpha = 0.3;

% Get the reflectivities and SLDs
bestReflectivity = result.reflectivity;
bestSld = result.sldProfiles;

reflectivityLimits = result.predictionIntervals.reflectivity;
sldLimits = result.predictionIntervals.sld;

shiftedData = result.shiftedData;
numberOfContrasts = length(shiftedData);

% Calculate the best fits depending on the selected options
subplot(1,2,1)
set(gca,'YScale','log','XScale','log');
hold on; box on

for i = 1:numberOfContrasts
    
    thisData = shiftedData{i};
    reflectivity = bestReflectivity{i};
    
    mult = 2^(4*i);
    switch options.q4
        case true
            thisQ4 = thisData(:,1).^4;
        case false
            if i == 1
                mult = 1;
            end
    end
        
    % Get the limits and fits
    limits = reflectivityLimits{i};
    
    min = limits(vals(1),:)./mult;
    max = limits(vals(2),:)./mult;
        
    reflectivity(:,2) = reflectivity(:,2)./mult;
    
    dataX = thisData(:,1);
    dataY = thisData(:,2)./mult;
    dataErr = thisData(:,3)./mult;
    
    refXValues = result.reflectivity{i}(:,1);
    thisSimQ4 = refXValues.^4;
    
    switch options.q4
        case true
            min = min .* thisSimQ4;
            max = max .* thisSimQ4;
            reflectivity(:,2) = reflectivity(:,2) .* thisQ4;         
            dataY = dataY(:) .* thisQ4;
            dataErr = dataErr(:) .* thisQ4;
    end
    
    errorbar(dataX,dataY,dataErr,'.');
    shade(refXValues,min,refXValues,max,'FillColor',fillColor,'FillType',fillType,'FillAlpha',fillAlpha);
    plot(reflectivity(:,1),reflectivity(:,2),'b-');

end

% Now plot the SLDs
subplot(1,2,2); hold on; box on

if ~isDomains

    for i = 1:numberOfContrasts

        sld = bestSld{i};
        limits = sldLimits{i};
        sldXValues = result.sldProfiles{i}(:,1);

        min = limits(vals(1),:);
        max = limits(vals(2),:);

        plot(sld(:,1),sld(:,2),'b-');
        shade(sldXValues,min,sldXValues,max,'FillColor',fillColor,'FillType',fillType,'FillAlpha',fillAlpha);

    end

else

    for i = 1:numberOfContrasts

        sld = bestSld(i,:);
        limits = sldLimits(i,:);
        sldXValues = result.sldProfiles(i,:);

        for j = 1:2
            min = limits{j}(vals(1),:);
            max = limits{j}(vals(2),:);

            thisDomainSldXValues = sldXValues{j}(:,1);

            plot(sld{j}(:,1),sld{j}(:,2),'b-');
            shade(thisDomainSldXValues,min,thisDomainSldXValues,max,'FillColor',fillColor,'FillType',fillType,'FillAlpha',fillAlpha);
        end
    end

end

end
