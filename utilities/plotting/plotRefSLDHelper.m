function plotRefSLDHelper(data, noDelay)
    % Helper function to make it easier to plot from event. Data is a struct
    % with the plot data and noDelay indicates if draw should be delayed.
    %
    % plotRefSLDHelper(data, false);
    arguments
        data
        noDelay {logical} = true
    end
    
    defaultState = 'on';
    s = warning();
    if any(strcmp({s.identifier}, 'MATLAB:Axes:NegativeDataInLogAxis'))
        defaultState = 'off';
    end
    warning('off','MATLAB:Axes:NegativeDataInLogAxis');

    numberOfContrasts = length(data.reflectivity);
    
    % Plot the data.reflectivity
    subplot(1,2,1);
    set(gca,'YScale','log','XScale','log');
    hold on
    lines = cell(numberOfContrasts, 1);
    for i = 1:numberOfContrasts
        thisRef = data.reflectivity{i};
        thisData = data.shiftedData{i};
        if i == 1
            mult = 1;
        else
            mult = 2^(4*i);
        end
    
        % If there is data present
        % plot it - size of data.shiftedData
        % will be [n x 3] if so
        if data.dataPresent(i)
            errorbar(thisData(:,1),thisData(:,2)./mult,thisData(:,3)./mult,'.','MarkerSize',2.5);
        end
    
        % Plot the fit
        lines{i} = plot(thisRef(:,1),thisRef(:,2)./mult,'-','LineWidth',2);
        
    end
    legend([lines{:}], data.contrastNames{:});

    % Plot the SLDs
    subplot(1,2,2);
    hold on
    nColumns = size(data.sldProfiles, 2);
    lines = cell(numberOfContrasts * nColumns, 1);
    names = cell(numberOfContrasts * nColumns, 1);
    for i = 1:numberOfContrasts
        for j=1:nColumns
           index = nColumns*(i-1)+j ;
           sld = data.sldProfiles{i, j};
           lines{index} = plot(sld(:, 1), sld(:, 2), '-');
           if nColumns == 2
               names{index} = sprintf("%s Domain %d", data.contrastNames{i}, j); 
           else
               names{index} = data.contrastNames{i};
           end
        end
    
        % If there is resampling, plot the resampled layers also
        % TODO for domains...
        if (data.resample(i) == 1) || (strcmpi(data.modelType, 'custom xy'))
            roughness = data.subRoughs(i); 
            layers = data.resampledLayers{i, 1};
            bulkIn = layers(1, 2);
            bulkOut = layers(end, 2);

            for j=1:size(data.resampledLayers, 2)
                layer = data.resampledLayers{i, j};                                               

                % Because we plot only real SLD, if we have imaginary in
                % layers then take it out...
                if size(layers,2) == 4
                    layer = [layer(:,1:2),layer(:,4)];
                end
                numberOfLayers = size(layer, 1);
                nrepeats = 1;
                newProf = makeSLDProfileXY(bulkIn,bulkOut,roughness,layer,numberOfLayers,nrepeats);
                plot(newProf(:,1)-49,newProf(:,2));
            end
        end
    end
    legend([lines{:}], names{:});
    if noDelay
        drawnow limitrate;
    end
    warning(defaultState, 'MATLAB:Axes:NegativeDataInLogAxis');
end