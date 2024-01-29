function [allSLDs,allRoughs] = processCustomFunction(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backgroundParams, ...
    qzshifts,scalefactor,bulkIn,bulkOut,res,cCustFiles,numberOfContrasts,customFiles,params)

    % Top-level function for processing custom XY profiles for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    tempAllSLDs = cell(numberOfContrasts,2);
    allSLDs = cell(numberOfContrasts,2);
    allRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        allSLDs{i,1} = [1,1];    % Type def as double (size not important)
        allSLDs{i,2} = [1,1];
        tempAllSLDs{i,1} = [0 0];
        tempAllSLDs{i,2} = [0 0];
    end
    coder.varsize('tempAllSLDs{:}',[10000 3],[1 1]);    % 3 columns to allow for potential imaginary curve
    
    allBulkOuts = bulkOut(contrastBulkOuts);
    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this contrast...
        thisBulkIn = bulkIn(contrastBulkIns(i));
        
        if isnan(str2double(functionHandle))
            [tempAllSLDs{i, 1}, allRoughs(i)] = callMatlabFunction(functionHandle, params, thisBulkIn, allBulkOuts, i, 1);
            [tempAllSLDs{i, 2}, ~] = callMatlabFunction(functionHandle, params, thisBulkIn, allBulkOuts, i, 2);
        else
            [tempAllSLDs{i, 1}, allRoughs(i)] = callCppFunction(functionHandle, params, thisBulkIn, allBulkOuts, i-1, 0);
            [tempAllSLDs{i, 2}, ~] = callCppFunction(functionHandle, params, thisBulkIn, allBulkOuts, i-1, 1);
        end
    end

    allSLDs = tempAllSLDs;
end
