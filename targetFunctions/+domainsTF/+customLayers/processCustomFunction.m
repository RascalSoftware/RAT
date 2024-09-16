function [resampledLayers,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    resampledLayers = cell(numberOfContrasts,2);
    subRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        resampledLayers{i,1} = [0 0 0 0 0];
        resampledLayers{i,2} = [0 0 0 0 0];
    end
    coder.varsize('resampledLayers{:}',[10000 6],[1 1]);
    
    bulkOuts = bulkOutArray(contrastBulkOuts);
    for i = 1:numberOfContrasts

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast...
        thisContrastLayers1 = [1 1 1]; % typeDef
        coder.varsize('thisContrastLayers1',[10000 6],[1 1]);

        thisContrastLayers2 = [1 1 1]; % typeDef
        coder.varsize('thisContrastLayers2',[10000 6],[1 1]);

        thisBulkIn = bulkInArray(contrastBulkIns(i));
        thisBulkOut = bulkOuts(i);

        if isnan(str2double(functionHandle))
            [thisContrastLayers1, subRoughs(i)] = callMatlabFunction(functionHandle, params, thisBulkIn, bulkOuts, i, 1);
            [thisContrastLayers2, ~] = callMatlabFunction(functionHandle, params, thisBulkIn, bulkOuts, i, 2);
        else
            [thisContrastLayers1, subRoughs(i)] = callCppFunction(functionHandle, params, thisBulkIn, bulkOuts, i-1, 0);
            [thisContrastLayers2, ~] = callCppFunction(functionHandle, params, thisBulkIn, bulkOuts, i-1, 1);
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

        resampledLayers{i,1} = thisContrastLayers1;
        resampledLayers{i,2} = thisContrastLayers2;
    end

end
