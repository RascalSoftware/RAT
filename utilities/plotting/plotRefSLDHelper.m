function plotRefSLDHelper(data, noDelay)
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
    shiftedData = data.shiftedData;
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
        thisData = shiftedData{i};
        if i == 1
            mult = 1;
        else
            mult = 2^(4*i);
        end
    
        % If there is data present
        % plot it - size of shiftedData
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
        for j=1:size(slds, 2)
           sld = slds{i, j};
           plot(sld(:, 1), sld(:, 2), '-'); 
        end
    
        % If there is resampling, plot the resampled layers also
        % TODO for domains...
        if (data.resample(i) == 1) || (strcmpi(modelType, 'custom xy'))
            ssub = data.ssubs(i); 
            layers = allLayers{i, 1};
            bulkIn = layers(1, 2);
            bulkOut = layers(end, 2);

            for j=1:size(allLayers, 2)
                layer = allLayers{i, j};                          
                numberOfLayers = size(layer, 1);
                nrepeats = 1;
                newProf = makeSLDProfileXY(bulkIn,bulkOut,ssub,layer,numberOfLayers,nrepeats);
                plot(newProf(:,1)-49,newProf(:,2));
            end
        end
    
    end
    
    if noDelay
        drawnow limitrate;
    end
end