function checkIndices(problemStruct, customFiles)
    % Make sure that the indices provided lie within the bounds of the
    % corresponding array.

    numBackgroundParams = length(problemStruct.backgroundParams);
    numCustomFiles = length(customFiles);
    for i = 1:length(problemStruct.contrastBackgroundParams)

        indices = problemStruct.contrastBackgroundParams{i};

        if length(indices) > 1
            % The first index is a custom file, the rest are background parameters
            index = indices(1);
            if index < 1 || index > numCustomFiles
                throw(exceptions.indexOutOfRange(sprintf('contrastBackgroundParams{%i}(1) is %i, which is outside the range of customFiles', i, index)));
            end
            indices = indices(2:end);
        end

        % All of these indices are background parameters
        for j = 1:length(indices)
            index = indices(j);
            if index < 1 || index > numBackgroundParams
                throw(exceptions.indexOutOfRange(sprintf('contrastBackgroundParams{%i}(%i) is %i, which is outside the range of backgroundParams', i, j, index)));
            end
        end

    end

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

    numBulkIns = length(problemStruct.bulkIns);
    for i = 1:length(problemStruct.contrastBulkIns)
        index = problemStruct.contrastBulkIns(i);
        if index < 1 || index > numBulkIns
            throw(exceptions.indexOutOfRange(sprintf('contrastBulkIns(%i) is %i, which is outside the range of bulkIn', i, index)));
        end
    end

    numBulkOuts = length(problemStruct.bulkOuts);
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

    numDomainRatios = length(problemStruct.domainRatios);
    for i = 1:length(problemStruct.contrastDomainRatios)
        index = problemStruct.contrastDomainRatios(i);
        if (index < 1 && index ~= -1) || index > numDomainRatios
            throw(exceptions.indexOutOfRange(sprintf('contrastDomainRatios(%i) is %i, which is outside the range of domainRatio', i, index)));
        end
    end
    