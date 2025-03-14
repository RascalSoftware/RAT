function [outputs,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInValues,bulkOutValues,contrastCustomFiles,numberOfContrasts,numberOfOutputColumns,customFiles,paramValues,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.
    outputs = cell(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);
    
    bulkOuts = bulkOutValues(contrastBulkOuts);

    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{contrastCustomFiles(i)};
        bulkIn = bulkInValues(contrastBulkIns(i));

        output = zeros(1, numberOfOutputColumns);
        coder.varsize('output',[10000 numberOfOutputColumns],[1 1]);

        if isnan(str2double(functionHandle))
            [output, subRoughs(i)] = callMatlabFunction(functionHandle, paramValues, bulkIn, bulkOuts, i, 0);
        else
            [output, subRoughs(i)] = callCppFunction(functionHandle, paramValues, bulkIn, bulkOuts, i-1, -1);
        end

        % If SLD is real, add dummy imaginary column
        if ~useImaginary
            outputs{i} = [output(:,1:2) zeros(size(output, 1), 1) output(:,3:end)];
        else
            outputs{i} = output;
        end

    end

end
