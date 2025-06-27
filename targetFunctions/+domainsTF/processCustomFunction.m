function [outputs1,outputs2,subRoughs] = processCustomFunction(bulkIns,bulkOuts,...
    contrastCustomFiles,numberOfContrasts,numberOfOutputColumns,customFiles,paramValues,useImaginary)

    % Top-level function for processing custom layers for all the contrasts
    outputs1 = cell(numberOfContrasts,1);
    outputs2 = cell(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);
    
    for i = 1:numberOfContrasts

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{contrastCustomFiles(i)};

        output1 = zeros(1, numberOfOutputColumns);
        coder.varsize('output1',[10000 numberOfOutputColumns], [1 1]);

        output2 = zeros(1, numberOfOutputColumns);
        coder.varsize('output2',[10000 numberOfOutputColumns], [1 1]);

        if isnan(str2double(functionHandle))
            [output1, subRoughs(i)] = callMatlabFunction(functionHandle, paramValues, bulkIns(i), bulkOuts, i, 1);
            [output2, ~] = callMatlabFunction(functionHandle, paramValues, bulkIns(i), bulkOuts, i, 2);
        else
            [output1, subRoughs(i)] = callCppFunction(functionHandle, paramValues, bulkIns(i), bulkOuts, i-1, 0);
            [output2, ~] = callCppFunction(functionHandle, paramValues, bulkIns(i), bulkOuts, i-1, 1);
        end

        % If SLD is real, add dummy imaginary column
        if ~useImaginary
            outputs1{i} = [output1(:,1:2) zeros(size(output1, 1), 1) output1(:,3:end)];
            outputs2{i} = [output2(:,1:2) zeros(size(output2, 1), 1) output2(:,3:end)];
        else
            outputs1{i} = output1;
            outputs2{i} = output2;
        end

    end

end
