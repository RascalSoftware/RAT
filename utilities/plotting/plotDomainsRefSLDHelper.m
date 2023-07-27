function plotDomainsRefSLDHelper(data, noDelay)
% Helper function to make it eaier to plot from event. data is a struct
% with the plot data and no delay indicates if draw should be delayed.
%
% plotRefSLDHelper(data, false);
arguments
    data
    noDelay {logical} = true
end

modelType = data.modelType;
reflectivity = data.reflectivity;
shifted_data = data.shifted_data;
slds = data.sldProfiles;
allLayers = data.allLayers;
dataPresent = data.dataPresent;
numberOfContrasts = length(reflectivity);

% Plot the reflectivity
subplot(1,2,1);
set(gca,'YScale','log','XScale','log');
hold on
for i = 1:numberOfContrasts
    thisRef = reflectivity{i};
    thisData = shifted_data{i};
    if i == 1
        mult = 1;
    else
        mult = 2^(4*i);
    end

    % If there is data present
    % plot it - size of shifted_data
    % will be [n x 3] if so
    if dataPresent(i)
        errorbar(thisData(:,1),thisData(:,2)./mult,thisData(:,3)./mult,'.','MarkerSize',2.5);
    end

    % Plot the fit
    plot(thisRef(:,1),thisRef(:,2)./mult,'-','LineWidth',2);
end

% Plot the SLDs
subplot(1,2,2);
hold on

for i = 1:numberOfContrasts

    theseSlds1 = slds{i,1};
    theseSlds2 = slds{i,2};
    plot(theseSlds1(:,1),theseSlds1(:,2),'-');
    plot(theseSlds2(:,1),theseSlds2(:,2),'-');

    % If there is resampling, plot the resampled layers also
    % TODO for domains...
    if (data.resample(i) == 1) || (strcmpi(modelType, 'custom xy'))
        thisLayers1 = allLayers{i,1};
        thisLayers2 = allLayers{i,2};
        nbair = thisLayers1(1,2);
        nbsub = thisLayers1(end,2);
        ssub = result.contrastParams.ssubs(i);

        % Domain1
        numberOfLayers = size(thisLayers1,1);
        nrepeats = 1;
        newProf = makeSLDProfileXY(nbair,nbsub,ssub,thisLayers1,numberOfLayers,nrepeats);
        plot(newProf(:,1)-49,newProf(:,2));

        % Domain2
        numberOfLayers = size(thisLayers2,1);
        nrepeats = 1;
        newProf = makeSLDProfileXY(nbair,nbsub,ssub,thisLayers2,numberOfLayers,nrepeats);
        plot(newProf(:,1)-49,newProf(:,2));
    end

end

if noDelay
    drawnow;
end

end