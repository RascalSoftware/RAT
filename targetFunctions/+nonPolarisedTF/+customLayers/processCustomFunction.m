function [allLayers,allRoughs] = processCustomFunction(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backs,...
        shifts,scalefactor,bulkIn,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    tempAllLayers = cell(numberOfContrasts,1);
    allLayers = cell(numberOfContrasts,1);
    allRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        allLayers{i} = [1 , 1];    % Type def as double (size not important)
        tempAllLayers{i} = [0 0 0 0 0];
    end
    coder.varsize('tempAllLayers{:}',[10000 6],[1 1]);


    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast...
        [~,~,~,bulkIn,bulkOut,~] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backs,shifts,scalefactor,bulkIn,nbs,res);

        thisContrastLayers = [1 1 1]; % typeDef
        coder.varsize('thisContrastLayers',[10000, 6],[1 1]);

        if isnan(str2double(functionHandle))
            [thisContrastLayers,allRoughs(i)] = callMatlabFunction(params,i,functionHandle,bulkIn,bulkOut,numberOfContrasts,0);
        else
            [thisContrastLayers, allRoughs(i)] = callCppFunction(params, bulkIn, bulkOut, i, -1, functionHandle);
        end

        % If the output layers has 5 columns, then we need to do
        % the hydration correction (the user has not done it in the
        % custom function). Do that here....
        if ~useImaginary
           thisContrastLayers = applyHydrationReal(thisContrastLayers,bulkIn,bulkOut);
        else
           thisContrastLayers = applyHydrationImag(thisContrastLayers,bulkIn,bulkOut);
        end

        tempAllLayers{i} = thisContrastLayers;
    end

    allLayers = tempAllLayers;

end
