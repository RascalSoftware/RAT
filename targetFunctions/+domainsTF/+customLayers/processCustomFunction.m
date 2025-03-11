function [contrastLayers,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInValues,bulkOutValues,contrastCustomFiles,numberOfContrasts,customFiles,paramValues,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.
    contrastLayers = cell(numberOfContrasts,2);
    subRoughs = zeros(numberOfContrasts,1);
    
    bulkOuts = bulkOutValues(contrastBulkOuts);

    for i = 1:numberOfContrasts

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{contrastCustomFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast
        thisBulkIn = bulkInValues(contrastBulkIns(i));
        thisBulkOut = bulkOuts(i);

        layers1 = [1 1 1 1]; % typeDef
        coder.varsize('layers1',[10000 6],[1 1]);

        layers2 = [1 1 1 1]; % typeDef
        coder.varsize('layers2',[10000 6],[1 1]);

        if isnan(str2double(functionHandle))
            [layers1, subRoughs(i)] = callMatlabFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i, 1);
            [layers2, ~] = callMatlabFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i, 2);
        else
            [layers1, subRoughs(i)] = callCppFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i-1, 0);
            [layers2, ~] = callCppFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i-1, 1);
        end

        % If SLD is real, add dummy imaginary column
        layers1Size = size(layers1);
        layers2Size = size(layers2);
        if ~useImaginary
            layers1 = [layers1(:,1:2) zeros(layers1Size(1), 1) layers1(:,3:end)];
            layers2 = [layers2(:,1:2) zeros(layers2Size(1), 1) layers2(:,3:end)];
        end

        % If the output layers has 6 columns, then we need to do
        % the hydration correction (the user has not done it in the
        % custom function).
        contrastLayers{i,1} = applyHydration(layers1,thisBulkIn,thisBulkOut);
        contrastLayers{i,2} = applyHydration(layers2,thisBulkIn,thisBulkOut);
    end

end
