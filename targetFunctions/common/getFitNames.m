function fitNames = getFitNames(problemStruct,checks)

    %We need to pack the parameters into separate vectors
    %of those that are being fitted, and those that are
    %held constant.
    numberOfFitted = sum(checks.fitParam) + ...
                     sum(checks.fitBackgroundParam) + ...
                     sum(checks.fitScalefactor) + ...
                     sum(checks.fitQzshift) + ...
                     sum(checks.fitBulkIn) + ...
                     sum(checks.fitBulkOut) + ...
                     sum(checks.fitResolutionParam) + ...
                     sum(checks.fitDomainRatio);

    fitNames = cell(numberOfFitted,1);
    for i = 1:numberOfFitted
        fitNames{i} = '';
    end
    
    fitCounter = 1;
    for n = 1:length(checks.fitParam)
        if checks.fitParam(n) == 1
            fitNames{fitCounter} = problemStruct.names.params{n};
            fitCounter = fitCounter + 1;
        end
    end
    
    %Also do the same for backgrounds...
    for n = 1:length(checks.fitBackgroundParam)
        if checks.fitBackgroundParam(n) == 1
            fitNames{fitCounter} = problemStruct.names.backgroundParams{n};
            fitCounter = fitCounter + 1;
        end
    end
    
    %..also for the scale factors
    for n = 1:length(checks.fitScalefactor)
        if checks.fitScalefactor(n) == 1
            fitNames{fitCounter} = problemStruct.names.scalefactors{n};
            fitCounter = fitCounter + 1;
        end
    end    
    
    %Need qzshifts
    for n = 1:length(checks.fitQzshift)
        if checks.fitQzshift(n) == 1
            fitNames{fitCounter} = problemStruct.names.qzshifts{n};
            fitCounter = fitCounter + 1;
        end
    end 
    
    %Bulk In
    for n = 1:length(checks.fitBulkIn)
        if checks.fitBulkIn(n) == 1
            fitNames{fitCounter} = problemStruct.names.bulkIns{n};
            fitCounter = fitCounter + 1;
        end
    end 
    
    %Bulk Out
    for n = 1:length(checks.fitBulkOut)
        if checks.fitBulkOut(n) == 1
            fitNames{fitCounter} = problemStruct.names.bulkOuts{n};
            fitCounter = fitCounter + 1;
        end
    end 
    
    %Resolution.....
    for n = 1:length(checks.fitResolutionParam)
        if checks.fitResolutionParam(n) == 1
            fitNames{fitCounter} = problemStruct.names.resolutionParams{n};
            fitCounter = fitCounter + 1;
        end
    end 
    
    % Domain Ratio
    for n = 1:length(checks.fitDomainRatio)
        if checks.fitDomainRatio(n) == 1
            fitNames{fitCounter} = problemStruct.names.domainRatios{n};
            fitCounter = fitCounter + 1;
        end
    end

end