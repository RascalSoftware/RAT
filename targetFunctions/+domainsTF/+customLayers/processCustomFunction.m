function [allLayers,allRoughs] = processCustomFunction(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backgroundParams, ...
    qzshifts,scalefactor,bulkIn,bulkOut,resolutionParams,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    %totNumCalcs = numberOfContrasts * 2;
    tempAllLayers = cell(numberOfContrasts,2);
    allLayers = cell(numberOfContrasts,2);
    allRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        allLayers{i,1} = [1, 1];    % Type def as double (size not important)
        allLayers{i,2} = [1, 1];
        tempAllLayers{i,1} = [0 0 0 0 0];
        tempAllLayers{i,2} = [0 0 0 0 0];
    end
    coder.varsize('tempAllLayers{:}',[10000 6],[1 1]);
    coder.varsize('allLayers{:}',[10000 6],[1 1]);

    for i = 1:numberOfContrasts

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast...
        [~,~,~,thisBulkIn,thisBulkOut,~] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),...
            contrastBulkOuts(i),contrastResolutions(i),backgroundParams,qzshifts,scalefactor,bulkIn,bulkOut,resolutionParams);

        thisContrastLayers1 = [1 1 1]; % typeDef
        coder.varsize('thisContrastLayers1',[10000, 6],[1 1]);

        thisContrastLayers2 = [1 1 1]; % typeDef
        coder.varsize('thisContrastLayers2',[10000, 6],[1 1]);

        if isnan(str2double(functionHandle))
            [thisContrastLayers1, allRoughs(i)] = callMatlabFunction(params,i,functionHandle,thisBulkIn,thisBulkOut,numberOfContrasts,1);
            [thisContrastLayers2, ~] = callMatlabFunction(params,i,functionHandle,thisBulkIn,thisBulkOut,numberOfContrasts,2);
        else
            [thisContrastLayers1, allRoughs(i)] = callCppFunction(params,thisBulkIn,thisBulkOut,i-1,0,functionHandle);
            [thisContrastLayers2, ~] = callCppFunction(params,thisBulkIn,thisBulkOut,i-1,1,functionHandle);
        end

        % If the output layers has 5 columns, then we need to do
        % the hydration correction (the user has not done it in the
        % custom function). Do that here....
        if ~useImaginary
           thisContrastLayers1 = applyHydrationReal(thisContrastLayers1,thisBulkIn,thisBulkOut);
           thisContrastLayers2 = applyHydrationReal(thisContrastLayers2,thisBulkIn,thisBulkOut);
        else
           thisContrastLayers1 = applyHydrationImag(thisContrastLayers1,thisBulkIn,thisBulkOut);
           thisContrastLayers2 = applyHydrationImag(thisContrastLayers2,thisBulkIn,thisBulkOut);
        end

        tempAllLayers{i,1} = thisContrastLayers1;
        tempAllLayers{i,2} = thisContrastLayers2;
    end

    allLayers = tempAllLayers;

end
