function checkIndices(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutionParams,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams)
    % Make sure that the indices provided lie within the bounds of the
    % corresponding array.

    numBackgroundParams = length(backgroundParams);
    for i = 1:length(contrastBackgrounds)
        index = contrastBackgrounds(i);
        if index < 1 || index > numBackgroundParams
            error('contrastBackgrounds(%i) is %i, which is outside the range of backgroundParams', i, index);
        end
    end

    numQzshifts = length(qzshifts);
    for i = 1:length(contrastQzshifts)
        index = contrastQzshifts(i);
        if index < 1 || index > numQzshifts
            error('contrastQzshifts(%i) is %i, which is outside the range of qzshifts', i, index);
        end
    end

    numScalefactors = length(scalefactors);
    for i = 1:length(contrastScalefactors)
        index = contrastScalefactors(i);
        if index < 1 || index > numScalefactors
            error('contrastScalefactors(%i) is %i, which is outside the range of scalefactors', i, index);
        end
    end

    numBulkIns = length(bulkIn);
    for i = 1:length(contrastBulkIns)
        index = contrastBulkIns(i);
        if index < 1 || index > numBulkIns
            error('contrastBulkIns(%i) is %i, which is outside the range of bulkIn', i, index);
        end
    end

    numBulkOuts = length(bulkOut);
    for i = 1:length(contrastBulkOuts)
        index = contrastBulkOuts(i);
        if index < 1 || index > numBulkOuts
            error('contrastBulkOuts(%i) is %i, which is outside the range of bulkOut', i, index);
        end
    end

    numResolutionParams = length(resolutionParams);
    for i = 1:length(contrastResolutionParams)
        index = contrastResolutionParams(i);
        if (index < 1 && index ~= -1) || index > numResolutionParams
            error('contrastResolutionParams(%i) is %i, which is outside the range of resolutionParams', i, index);
        end
    end
    