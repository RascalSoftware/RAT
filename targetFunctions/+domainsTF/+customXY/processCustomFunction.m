function [slds,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params)

    % Top-level function for processing custom XY profiles for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    tempSLDs = cell(numberOfContrasts,2);
    slds = cell(numberOfContrasts,2);
    subRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        slds{i,1} = [1,1];    % Type def as double (size not important)
        slds{i,2} = [1,1];
        tempSLDs{i,1} = [0 0];
        tempSLDs{i,2} = [0 0];
    end
    coder.varsize('tempSLDs{:}',[10000 3],[1 1]);    % 3 columns to allow for potential imaginary curve
    
    bulkOuts = bulkOutArray(contrastBulkOuts);
    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this contrast...
        thisBulkIn = bulkInArray(contrastBulkIns(i));
        
        if isnan(str2double(functionHandle))
            [tempSLDs{i, 1}, subRoughs(i)] = callMatlabFunction(functionHandle, params, thisBulkIn, bulkOuts, i, 1);
            [tempSLDs{i, 2}, ~] = callMatlabFunction(functionHandle, params, thisBulkIn, bulkOuts, i, 2);
        else
            [tempSLDs{i, 1}, subRoughs(i)] = callCppFunction(functionHandle, params, thisBulkIn, bulkOuts, i-1, 0);
            [tempSLDs{i, 2}, ~] = callCppFunction(functionHandle, params, thisBulkIn, bulkOuts, i-1, 1);
        end
    end

    slds = tempSLDs;
end
