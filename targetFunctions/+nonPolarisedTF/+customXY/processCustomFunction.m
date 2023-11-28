function [allSLDs,allRoughs] = processCustomFunction(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
        shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)

    % Top-level function for processing custom XY profiles for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    tempAllSLDs = cell(numberOfContrasts,1);
    allSLDs = cell(numberOfContrasts,1);
    allRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        allSLDs{i} = [1,1];    % Type def as double (size not important)
        tempAllSLDs{i} = [0 0];
    end
    coder.varsize('tempAllSLDs{:}',[10000 3],[1 1]);    % 3 columns to allow for potential imaginary curve

    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast...
        [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

        if isnan(str2double(functionHandle))
            [tempAllSLDs{i}, allRoughs(i)] = callMatlabFunction(params,i,functionHandle,bulkIn,bulkOut,numberOfContrasts,0);
        else
            [tempAllSLDs{i}, allRoughs(i)] = callCppFunction(params, bulkIn, bulkOut, i, -1, functionHandle);
        end
    end

    allSLDs = tempAllSLDs;
end
