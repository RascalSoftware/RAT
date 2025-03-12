function [outputs,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInValues,bulkOutValues,contrastCustomFiles,numberOfContrasts,numberOfOutputColumns,customFiles,paramValues,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.
    outputs = cell(numberOfContrasts,2);
    subRoughs = zeros(numberOfContrasts,1);
    
    bulkOuts = bulkOutValues(contrastBulkOuts);

    for i = 1:numberOfContrasts

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{contrastCustomFiles(i)};
        bulkIn = bulkInValues(contrastBulkIns(i));

        output1 = zeros(1, numberOfOutputColumns);
        coder.varsize('output1',[10000 numberOfOutputColumns],[1 1]);

        output2 = zeros(1, numberOfOutputColumns);
        coder.varsize('output2',[10000 numberOfOutputColumns],[1 1]);

        if isnan(str2double(functionHandle))
            [output1, subRoughs(i)] = callMatlabFunction(functionHandle, paramValues, bulkIn, bulkOuts, i, 1);
            [output2, ~] = callMatlabFunction(functionHandle, paramValues, bulkIn, bulkOuts, i, 2);
        else
            [output1, subRoughs(i)] = callCppFunction(functionHandle, paramValues, bulkIn, bulkOuts, i-1, 0);
            [output2, ~] = callCppFunction(functionHandle, paramValues, bulkIn, bulkOuts, i-1, 1);
        end

        % If SLD is real, add dummy imaginary column
        if ~useImaginary
            outputs{i,1} = [output1(:,1:2) zeros(size(output1, 1), 1) output1(:,3:end)];
            outputs{i,2} = [output2(:,1:2) zeros(size(output2, 1), 1) output2(:,3:end)];
        else
            outputs{i,1} = output1;
            outputs{i,2} = output2;
        end

    end

end
