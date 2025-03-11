function [slds,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInValues,bulkOutValues,contrastCustomFiles,numberOfContrasts,customFiles,paramValues,useImaginary)

    % Top-level function for processing custom XY profiles for all the
    % contrasts.
    slds = cell(numberOfContrasts,2);
    subRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        slds{i,1} = [0 0 0];
        slds{i,2} = [0 0 0];
    end
    coder.varsize('slds{:}',[10000 3],[1 1]);    % 3 columns to allow for potential imaginary curve
    
    bulkOuts = bulkOutValues(contrastBulkOuts);
    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{contrastCustomFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this contrast...
        thisBulkIn = bulkInValues(contrastBulkIns(i));
        
        if isnan(str2double(functionHandle))
            [sld1, subRoughs(i)] = callMatlabFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i, 1);
            [sld2, ~] = callMatlabFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i, 2);
        else
            [sld1, subRoughs(i)] = callCppFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i-1, 0);
            [sld2, ~] = callCppFunction(functionHandle, paramValues, thisBulkIn, bulkOuts, i-1, 1);
        end

        % If SLD is real, add dummy imaginary column
        sld1Size = size(sld1);
        sld2Size = size(sld2);
        if ~useImaginary
            slds{i,1} = [sld1 zeros(sld1Size(1), 1)];
            slds{i,2} = [sld2 zeros(sld2Size(1), 1)];
        else
            slds{i,1} = sld1;
            slds{i,2} = sld2;
        end

    end
end
