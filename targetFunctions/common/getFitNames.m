function fitNames = getFitNames(problemStruct)

    %We need to pack the parameters into separate vectors
    %of those that are being fitted, and those that are
    %held constant.
    numberOfFitted = sum(problemStruct.checks.params) + ...
                     sum(problemStruct.checks.backgroundParams) + ...
                     sum(problemStruct.checks.scalefactors) + ...
                     sum(problemStruct.checks.qzshifts) + ...
                     sum(problemStruct.checks.bulkIns) + ...
                     sum(problemStruct.checks.bulkOuts) + ...
                     sum(problemStruct.checks.resolutionParams) + ...
                     sum(problemStruct.checks.domainRatios);

    fitNames = cell(numberOfFitted,1);
    for i = 1:numberOfFitted
        fitNames{i} = '';
    end
    
    fitCounter = 1;
    for n = 1:length(problemStruct.checks.params)
        if problemStruct.checks.params(n) == 1
            fitNames{fitCounter} = problemStruct.names.params{n};
            fitCounter = fitCounter + 1;
        end
    end
    
    %Also do the same for backgrounds...
    for n = 1:length(problemStruct.checks.backgroundParams)
        if problemStruct.checks.backgroundParams(n) == 1
            fitNames{fitCounter} = problemStruct.names.backgroundParams{n};
            fitCounter = fitCounter + 1;
        end
    end
    
    %..also for the scale factors
    for n = 1:length(problemStruct.checks.scalefactors)
        if problemStruct.checks.scalefactors(n) == 1
            fitNames{fitCounter} = problemStruct.names.scalefactors{n};
            fitCounter = fitCounter + 1;
        end
    end    
    
    %Need qzshifts
    for n = 1:length(problemStruct.checks.qzshifts)
        if problemStruct.checks.qzshifts(n) == 1
            fitNames{fitCounter} = problemStruct.names.qzshifts{n};
            fitCounter = fitCounter + 1;
        end
    end 
    
    %Bulk In
    for n = 1:length(problemStruct.checks.bulkIns)
        if problemStruct.checks.bulkIns(n) == 1
            fitNames{fitCounter} = problemStruct.names.bulkIns{n};
            fitCounter = fitCounter + 1;
        end
    end 
    
    %Bulk Out
    for n = 1:length(problemStruct.checks.bulkOuts)
        if problemStruct.checks.bulkOuts(n) == 1
            fitNames{fitCounter} = problemStruct.names.bulkOuts{n};
            fitCounter = fitCounter + 1;
        end
    end 
    
    %Resolution.....
    for n = 1:length(problemStruct.checks.resolutionParams)
        if problemStruct.checks.resolutionParams(n) == 1
            fitNames{fitCounter} = problemStruct.names.resolutionParams{n};
            fitCounter = fitCounter + 1;
        end
    end 
    
    % Domain Ratio
    for n = 1:length(problemStruct.checks.domainRatios)
        if problemStruct.checks.domainRatios(n) == 1
            fitNames{fitCounter} = problemStruct.names.domainRatios{n};
            fitCounter = fitCounter + 1;
        end
    end

end
