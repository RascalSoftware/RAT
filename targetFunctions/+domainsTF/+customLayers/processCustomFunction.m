function [resampledLayers,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.
    resampledLayers = cell(numberOfContrasts,2);
    subRoughs = zeros(numberOfContrasts,1);
    
    bulkOuts = bulkOutArray(contrastBulkOuts);

    for i = 1:numberOfContrasts

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast
        thisBulkIn = bulkInArray(contrastBulkIns(i));
        thisBulkOut = bulkOuts(i);

        thisContrastLayers1 = [1 1 1 1]; % typeDef
        coder.varsize('thisContrastLayers1',[10000 6],[1 1]);

        thisContrastLayers2 = [1 1 1 1]; % typeDef
        coder.varsize('thisContrastLayers2',[10000 6],[1 1]);

        if isnan(str2double(functionHandle))
            [thisContrastLayers1, subRoughs(i)] = callMatlabFunction(functionHandle, params, thisBulkIn, bulkOuts, i, 1);
            [thisContrastLayers2, ~] = callMatlabFunction(functionHandle, params, thisBulkIn, bulkOuts, i, 2);
        else
            [thisContrastLayers1, subRoughs(i)] = callCppFunction(functionHandle, params, thisBulkIn, bulkOuts, i-1, 0);
            [thisContrastLayers2, ~] = callCppFunction(functionHandle, params, thisBulkIn, bulkOuts, i-1, 1);
        end

        % If SLD is real, add dummy imaginary column
        contrastLayers1Size = size(thisContrastLayers1);
        contrastLayers2Size = size(thisContrastLayers2);
        if ~useImaginary
            thisContrastLayers1 = [thisContrastLayers1(:,1:2) zeros(contrastLayers1Size(1), 1) thisContrastLayers1(:,3:end)];
            thisContrastLayers2 = [thisContrastLayers2(:,1:2) zeros(contrastLayers2Size(1), 1) thisContrastLayers2(:,3:end)];
        end

        % If the output layers has 6 columns, then we need to do
        % the hydration correction (the user has not done it in the
        % custom function).
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
