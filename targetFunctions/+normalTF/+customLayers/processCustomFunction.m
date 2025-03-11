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
        bulkIn = bulkInValues(contrastBulkIns(i));

        layers = [1 1 1 1]; % typeDef
        coder.varsize('layers',[10000 6],[1 1]);
        if isnan(str2double(functionHandle))
            [layers, subRoughs(i)] = callMatlabFunction(functionHandle, paramValues, bulkIn, bulkOuts, i, 0);
        else
            [layers, subRoughs(i)] = callCppFunction(functionHandle, paramValues, bulkIn, bulkOuts, i-1, -1);
        end

        % If SLD is real, add dummy imaginary column
        if ~useImaginary
            contrastLayers{i} = [layers(:,1:2) zeros(size(layers, 1), 1) layers(:,3:end)];
        else
            contrastLayers{i} = layers;
        end

    end

end
