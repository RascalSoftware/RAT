function [resampledLayers,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    tempResampledLayers = cell(numberOfContrasts,1);
    resampledLayers = cell(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        resampledLayers{i} = [1 , 1];    % Type def as double (size not important)
        tempResampledLayers{i} = [0 0 0 0 0];
    end
    coder.varsize('tempResampledLayers{:}',[10000 6],[1 1]);

    bulkOuts = bulkOutArray(contrastBulkOuts);
    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast...
        thisBulkIn = bulkInArray(contrastBulkIns(i));
        thisBulkOut = bulkOuts(i);

        thisContrastLayers = [1 1 1]; % typeDef
        coder.varsize('thisContrastLayers',[10000, 6],[1 1]);
        if isnan(str2double(functionHandle))
            [thisContrastLayers,subRoughs(i)] = callMatlabFunction(functionHandle, params, thisBulkIn, bulkOuts, i, 0);
        else
            [thisContrastLayers, subRoughs(i)] = callCppFunction(functionHandle, params, thisBulkIn, bulkOuts, i-1, -1);
        end

        % If the output layers has 5 columns, then we need to do
        % the hydration correction (the user has not done it in the
        % custom function). Do that here....
        if ~useImaginary
           thisContrastLayers = applyHydrationReal(thisContrastLayers,thisBulkIn,thisBulkOut);
        else
           thisContrastLayers = applyHydrationImag(thisContrastLayers,thisBulkIn,thisBulkOut);
        end

        tempResampledLayers{i} = thisContrastLayers;
    end

    resampledLayers = tempResampledLayers;

end
