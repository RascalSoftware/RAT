function checkIndices(problemStruct)
    % Make sure that the indices provided lie within the bounds of the
    % corresponding array.

    % **** Comment out the background checks while we're working on it
    %
    % numBackgroundParams = length(problemStruct.backgroundParams);
    % for i = 1:length(problemStruct.contrastBackgroundParams)
    %     index = problemStruct.contrastBackgroundParams(i);
    %     if (index < 1 && index ~= -1) || index > numBackgroundParams
    %         throw(exceptions.indexOutOfRange(sprintf('contrastBackgroundParams(%i) is %i, which is outside the range of backgroundParams', i, index)));
    %     end
    % end

    numQzshifts = length(problemStruct.qzshifts);
    for i = 1:length(problemStruct.contrastQzshifts)
        index = problemStruct.contrastQzshifts(i);
        if index < 1 || index > numQzshifts
            throw(exceptions.indexOutOfRange(sprintf('contrastQzshifts(%i) is %i, which is outside the range of qzshifts', i, index)));
        end
    end

    numScalefactors = length(problemStruct.scalefactors);
    for i = 1:length(problemStruct.contrastScalefactors)
        index = problemStruct.contrastScalefactors(i);
        if index < 1 || index > numScalefactors
            throw(exceptions.indexOutOfRange(sprintf('contrastScalefactors(%i) is %i, which is outside the range of scalefactors', i, index)));
        end
    end

    numBulkIns = length(problemStruct.bulkIn);
    for i = 1:length(problemStruct.contrastBulkIns)
        index = problemStruct.contrastBulkIns(i);
        if index < 1 || index > numBulkIns
            throw(exceptions.indexOutOfRange(sprintf('contrastBulkIns(%i) is %i, which is outside the range of bulkIn', i, index)));
        end
    end

    numBulkOuts = length(problemStruct.bulkOut);
    for i = 1:length(problemStruct.contrastBulkOuts)
        index = problemStruct.contrastBulkOuts(i);
        if index < 1 || index > numBulkOuts
            throw(exceptions.indexOutOfRange(sprintf('contrastBulkOuts(%i) is %i, which is outside the range of bulkOut', i, index)));
        end
    end

    numResolutionParams = length(problemStruct.resolutionParams);
    for i = 1:length(problemStruct.contrastResolutionParams)
        index = problemStruct.contrastResolutionParams(i);
        if (index < 1 && index ~= -1) || index > numResolutionParams
            throw(exceptions.indexOutOfRange(sprintf('contrastResolutionParams(%i) is %i, which is outside the range of resolutionParams', i, index)));
        end
    end

    numDomainRatios = length(problemStruct.domainRatio);
    for i = 1:length(problemStruct.contrastDomainRatios)
        index = problemStruct.contrastDomainRatios(i);
        if (index < 1 && index ~= -1) || index > numDomainRatios
            throw(exceptions.indexOutOfRange(sprintf('contrastDomainRatios(%i) is %i, which is outside the range of domainRatio', i, index)));
        end
    end
    