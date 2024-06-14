function checkIndices(problemStruct)
    % Make sure that the indices provided lie within the bounds of the
    % corresponding array.

    numBackgroundParams = length(problemStruct.backgroundParams);
    for i = 1:length(problemStruct.contrastBackgrounds)
        index = problemStruct.contrastBackgrounds(i);
        if index < 1 || index > numBackgroundParams
            error('contrastBackgrounds(%i) is %i, which is outside the range of backgroundParams', i, index);
        end
    end

    numQzshifts = length(problemStruct.qzshifts);
    for i = 1:length(problemStruct.contrastQzshifts)
        index = problemStruct.contrastQzshifts(i);
        if index < 1 || index > numQzshifts
            error('contrastQzshifts(%i) is %i, which is outside the range of qzshifts', i, index);
        end
    end

    numScalefactors = length(problemStruct.scalefactors);
    for i = 1:length(problemStruct.contrastScalefactors)
        index = problemStruct.contrastScalefactors(i);
        if index < 1 || index > numScalefactors
            error('contrastScalefactors(%i) is %i, which is outside the range of scalefactors', i, index);
        end
    end

    numBulkIns = length(problemStruct.bulkIn);
    for i = 1:length(problemStruct.contrastBulkIns)
        index = problemStruct.contrastBulkIns(i);
        if index < 1 || index > numBulkIns
            error('contrastBulkIns(%i) is %i, which is outside the range of bulkIn', i, index);
        end
    end

    numBulkOuts = length(problemStruct.bulkOut);
    for i = 1:length(problemStruct.contrastBulkOuts)
        index = problemStruct.contrastBulkOuts(i);
        if index < 1 || index > numBulkOuts
            error('contrastBulkOuts(%i) is %i, which is outside the range of bulkOut', i, index);
        end
    end

    numResolutionParams = length(problemStruct.resolutionParams);
    for i = 1:length(problemStruct.contrastResolutionParams)
        index = problemStruct.contrastResolutionParams(i);
        if (index < 1 && index ~= -1) || index > numResolutionParams
            error('contrastResolutionParams(%i) is %i, which is outside the range of resolutionParams', i, index);
        end
    end

    numDomainRatios = length(problemStruct.domainRatio);
    for i = 1:length(problemStruct.contrastDomainRatios)
        index = problemStruct.contrastDomainRatios(i);
        if (index < 1 && index ~= -1) || index > numDomainRatios
            error('contrastDomainRatios(%i) is %i, which is outside the range of domainRatios', i, index);
        end
    end
    