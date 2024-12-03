function [problemStruct,fitNames] = packParams(problemStruct,limits)

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
                 
    numberOfTotal = length(problemStruct.params) + ...
                    length(problemStruct.backgroundParams) + ...
                    length(problemStruct.scalefactors) + ...
                    length(problemStruct.qzshifts) + ...
                    length(problemStruct.bulkIns) + ...
                    length(problemStruct.bulkOuts) + ...
                    length(problemStruct.resolutionParams) + ...
                    length(problemStruct.domainRatios);
       
    fitParams = zeros(numberOfFitted, 1);
    otherParams = zeros((numberOfTotal-numberOfFitted), 1);
    fitLimits = zeros(numberOfFitted,2);
    otherLimits = zeros((numberOfTotal-numberOfFitted),2);

    fitNames = cell(numberOfFitted,1);
    for i = 1:numberOfFitted
        fitNames{i} = '';
    end
    
    fitCounter = 1;
    otherCounter = 1;
    for n = 1:length(problemStruct.checks.params)
        if problemStruct.checks.params(n) == 1
            fitParams(fitCounter) = problemStruct.params(n);
            fitLimits(fitCounter,1) = limits.params(n,1);
            fitLimits(fitCounter,2) = limits.params(n,2);        
            fitNames{fitCounter} = problemStruct.names.params{n};
            fitCounter = fitCounter + 1;
    
        else
            otherParams(otherCounter) = problemStruct.params(n);
            otherLimits(otherCounter,1) = limits.params(n,1);
            otherLimits(otherCounter,2) = limits.params(n,2);
            otherCounter = otherCounter + 1;
        end
    end
    
    %Also do the same for backgrounds...
    for n = 1:length(problemStruct.checks.backgroundParams)
        if problemStruct.checks.backgroundParams(n) == 1
            fitParams(fitCounter) = problemStruct.backgroundParams(n);
            fitLimits(fitCounter,1) = limits.backgroundParams(n,1);
            fitLimits(fitCounter,2) = limits.backgroundParams(n,2);
            fitNames{fitCounter} = problemStruct.names.backgroundParams{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.backgroundParams(n);
            otherLimits(otherCounter,1) = limits.backgroundParams(n,1);
            otherLimits(otherCounter,2) = limits.backgroundParams(n,2);
            otherCounter = otherCounter + 1;
        end
    end
    
    %..also for the scale factors
    for n = 1:length(problemStruct.checks.scalefactors)
        if problemStruct.checks.scalefactors(n) == 1
            fitParams(fitCounter) = problemStruct.scalefactors(n);
            fitLimits(fitCounter,1) = limits.scalefactors(n,1);
            fitLimits(fitCounter,2) = limits.scalefactors(n,2);
            fitNames{fitCounter} = problemStruct.names.scalefactors{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.scalefactors(n);
            otherLimits(otherCounter,1) = limits.scalefactors(n,1);
            otherLimits(otherCounter,2) = limits.scalefactors(n,2);
            otherCounter = otherCounter + 1;
        end
    end    
    
    %Need qzshifts
    for n = 1:length(problemStruct.checks.qzshifts)
        if problemStruct.checks.qzshifts(n) == 1
            fitParams(fitCounter) = problemStruct.qzshifts(n);
            fitLimits(fitCounter,1) = limits.qzshifts(n,1);
            fitLimits(fitCounter,2) = limits.qzshifts(n,2);
            fitNames{fitCounter} = problemStruct.names.qzshifts{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.qzshifts(n);
            otherLimits(otherCounter,1) = limits.qzshifts(n,1);
            otherLimits(otherCounter,2) = limits.qzshifts(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Bulk In
    for n = 1:length(problemStruct.checks.bulkIns)
        if problemStruct.checks.bulkIns(n) == 1
            fitParams(fitCounter) = problemStruct.bulkIns(n);
            fitLimits(fitCounter,1) = limits.bulkIns(n,1);
            fitLimits(fitCounter,2) = limits.bulkIns(n,2);
            fitNames{fitCounter} = problemStruct.names.bulkIns{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.bulkIns(n);
            otherLimits(otherCounter,1) = limits.bulkIns(n,1);
            otherLimits(otherCounter,2) = limits.bulkIns(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Bulk Out
    for n = 1:length(problemStruct.checks.bulkOuts)
        if problemStruct.checks.bulkOuts(n) == 1
            fitParams(fitCounter) = problemStruct.bulkOuts(n);
            fitLimits(fitCounter,1) = limits.bulkOuts(n,1);
            fitLimits(fitCounter,2) = limits.bulkOuts(n,2);
            fitNames{fitCounter} = problemStruct.names.bulkOuts{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.bulkOuts(n);
            otherLimits(otherCounter,1) = limits.bulkOuts(n,1);
            otherLimits(otherCounter,2) = limits.bulkOuts(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Resolution.....
    for n = 1:length(problemStruct.checks.resolutionParams)
        if problemStruct.checks.resolutionParams(n) == 1
            fitParams(fitCounter) = problemStruct.resolutionParams(n);
            fitLimits(fitCounter,1) = limits.resolutionParams(n,1);
            fitLimits(fitCounter,2) = limits.resolutionParams(n,2);
            fitNames{fitCounter} = problemStruct.names.resolutionParams{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.resolutionParams(n);
            otherLimits(otherCounter,1) = limits.resolutionParams(n,1);
            otherLimits(otherCounter,2) = limits.resolutionParams(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    % Domain Ratio
    for n = 1:length(problemStruct.checks.domainRatios)
        if problemStruct.checks.domainRatios(n) == 1
            fitParams(fitCounter) = problemStruct.domainRatios(n);
            fitLimits(fitCounter,1) = limits.domainRatios(n,1);
            fitLimits(fitCounter,2) = limits.domainRatios(n,2);
            fitNames{fitCounter} = problemStruct.names.domainRatios{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.domainRatios(n);
            otherLimits(otherCounter,1) = limits.domainRatios(n,1);
            otherLimits(otherCounter,2) = limits.domainRatios(n,2);
            otherCounter = otherCounter + 1;
        end
    end
    
    problemStruct.fitParams = fitParams;
    problemStruct.otherParams = otherParams;
    problemStruct.fitLimits = fitLimits;
    problemStruct.otherLimits = otherLimits;

end