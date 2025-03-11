function [contrastLayers,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInValues,bulkOutValues,contrastCustomFiles,numberOfContrasts,customFiles,paramValues,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.
    contrastLayers = cell(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);

    bulkOuts = bulkOutValues(contrastBulkOuts);

    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{contrastCustomFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast
        thisBulkIn = bulkInValues(contrastBulkIns(i));
        thisBulkOut = bulkOuts(i);

        layers = [1 1 1 1]; % typeDef
        coder.varsize('layers',[10000 6],[1 1]);
        if isnan(str2double(functionHandle))
            [layers, subRoughs(i)] = callMatlabFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i, 0);
        else
            [layers, subRoughs(i)] = callCppFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i-1, -1);
        end

        % If SLD is real, add dummy imaginary column
        layersSize = size(layers);
        if ~useImaginary
            layers = [layers(:,1:2) zeros(layersSize(1), 1) layers(:,3:end)];
        end

        % If the output layers has 6 columns, then we need to do
        % the hydration correction (the user has not done it in the
        % custom function).
        contrastLayers{i} = applyHydration(layers,thisBulkIn,thisBulkOut);

    end

end
