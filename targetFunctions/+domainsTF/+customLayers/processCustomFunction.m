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
        bulkIn = bulkInValues(contrastBulkIns(i));

        layers1 = [0 0 0 0]; % typeDef
        coder.varsize('layers1',[10000 6],[1 1]);

        layers2 = [0 0 0 0]; % typeDef
        coder.varsize('layers2',[10000 6],[1 1]);

        if isnan(str2double(functionHandle))
            [layers1, subRoughs(i)] = callMatlabFunction(functionHandle, paramValues, bulkIn, bulkOuts, i, 1);
            [layers2, ~] = callMatlabFunction(functionHandle, paramValues, bulkIn, bulkOuts, i, 2);
        else
            [layers1, subRoughs(i)] = callCppFunction(functionHandle, paramValues, bulkIn, bulkOuts, i-1, 0);
            [layers2, ~] = callCppFunction(functionHandle, paramValues, bulkIn, bulkOuts, i-1, 1);
        end

        % If SLD is real, add dummy imaginary column
        if ~useImaginary
            contrastLayers{i,1} = [layers1(:,1:2) zeros(size(layers1, 1), 1) layers1(:,3:end)];
            contrastLayers{i,2} = [layers2(:,1:2) zeros(size(layers2, 1), 1) layers2(:,3:end)];
        else
            contrastLayers{i,1} = layers1;
            contrastLayers{i,2} = layers2;
        end

    end

end
