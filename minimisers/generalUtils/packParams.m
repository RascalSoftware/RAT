function [problemDefStruct,fitNames] = packParams(problemDefStruct,problemDefCells,limits,checks)

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
                 
    numberOfTotal = length(problemDefStruct.params) + ...
                    length(problemDefStruct.backgroundParams) + ...
                    length(problemDefStruct.scalefactors) + ...
                    length(problemDefStruct.qzshifts) + ...
                    length(problemDefStruct.bulkIn) + ...
                    length(problemDefStruct.bulkOut) + ...
                    length(problemDefStruct.resolutionParams) + ...
                    length(problemDefStruct.domainRatio);
       
    fitParams = problemDefStruct.fitParams;%zeros(numberOfFitted,1);
    otherParams = zeros((numberOfTotal-numberOfFitted),1);
    fitLimits = zeros(numberOfFitted,2);
    otherLimits = zeros((numberOfTotal-numberOfFitted),2);
    %limits = problemDefStruct.limits;
    fitNames = cell(numberOfFitted,1);
    for i = 1:numberOfFitted
        fitNames{i} = '';
    end
    
    fitCounter = 1;
    otherCounter = 1;
    for n = 1:length(checks.fitParam)
        if checks.fitParam(n) == 1
            fitParams(fitCounter) = problemDefStruct.params(n);
            fitLimits(fitCounter,1) = limits.param(n,1);
            fitLimits(fitCounter,2) = limits.param(n,2);        
            fitNames{fitCounter} = problemDefCells{7}{n};
            fitCounter = fitCounter + 1;
    
        else
            otherParams(otherCounter) = problemDefStruct.params(n);
            otherLimits(otherCounter,1) = limits.param(n,1);
            otherLimits(otherCounter,2) = limits.param(n,2);
            otherCounter = otherCounter + 1;
        end
    end
    
    %Also do the same for backgrounds...
    for n = 1:length(checks.fitBackgroundParam)
        if checks.fitBackgroundParam(n) == 1
            fitParams(fitCounter) = problemDefStruct.backgroundParams(n);
            fitLimits(fitCounter,1) = limits.backgroundParam(n,1);
            fitLimits(fitCounter,2) = limits.backgroundParam(n,2);
            fitNames{fitCounter} = problemDefCells{8}{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemDefStruct.backgroundParams(n);
            otherLimits(otherCounter,1) = limits.backgroundParam(n,1);
            otherLimits(otherCounter,2) = limits.backgroundParam(n,2);
            otherCounter = otherCounter + 1;
        end
    end
    
    %..also for the scale factors
    for n = 1:length(checks.fitScalefactor)
        if checks.fitScalefactor(n) == 1
            fitParams(fitCounter) = problemDefStruct.scalefactors(n);
            fitLimits(fitCounter,1) = limits.scalefactor(n,1);
            fitLimits(fitCounter,2) = limits.scalefactor(n,2);
            fitNames{fitCounter} = problemDefCells{9}{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemDefStruct.scalefactors(n);
            otherLimits(otherCounter,1) = limits.scalefactor(n,1);
            otherLimits(otherCounter,2) = limits.scalefactor(n,2);
            otherCounter = otherCounter + 1;
        end
    end    
    
    %Need qzshifts
    for n = 1:length(checks.fitQzshift)
        if checks.fitQzshift(n) == 1
            fitParams(fitCounter) = problemDefStruct.qzshifts(n);
            fitLimits(fitCounter,1) = limits.qzshift(n,1);
            fitLimits(fitCounter,2) = limits.qzshift(n,2);
            fitNames{fitCounter} = problemDefCells{10}{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemDefStruct.qzshifts(n);
            otherLimits(otherCounter,1) = limits.qzshift(n,1);
            otherLimits(otherCounter,2) = limits.qzshift(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Bulk In
    for n = 1:length(checks.fitBulkIn)
        if checks.fitBulkIn(n) == 1
            fitParams(fitCounter) = problemDefStruct.bulkIn(n);
            fitLimits(fitCounter,1) = limits.bulkIn(n,1);
            fitLimits(fitCounter,2) = limits.bulkIn(n,2);
            fitNames{fitCounter} = problemDefCells{11}{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemDefStruct.bulkIn(n);
            otherLimits(otherCounter,1) = limits.bulkIn(n,1);
            otherLimits(otherCounter,2) = limits.bulkIn(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Bulk Out
    for n = 1:length(checks.fitBulkOut)
        if checks.fitBulkOut(n) == 1
            fitParams(fitCounter) = problemDefStruct.bulkOut(n);
            fitLimits(fitCounter,1) = limits.bulkOut(n,1);
            fitLimits(fitCounter,2) = limits.bulkOut(n,2);
            fitNames{fitCounter} = problemDefCells{12}{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemDefStruct.bulkOut(n);
            otherLimits(otherCounter,1) = limits.bulkOut(n,1);
            otherLimits(otherCounter,2) = limits.bulkOut(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Resolution.....
    for n = 1:length(checks.fitResolutionParam)
        if checks.fitResolutionParam(n) == 1
            fitParams(fitCounter) = problemDefStruct.resolutionParams(n);
            fitLimits(fitCounter,1) = limits.resolutionParam(n,1);
            fitLimits(fitCounter,2) = limits.resolutionParam(n,2);
            fitNames{fitCounter} = problemDefCells{13}{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemDefStruct.resolutionParams(n);
            otherLimits(otherCounter,1) = limits.resolutionParam(n,1);
            otherLimits(otherCounter,2) = limits.resolutionParam(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    % Domain Ratio
    for n = 1:length(checks.fitDomainRatio)
        if checks.fitDomainRatio(n) == 1
            fitParams(fitCounter) = problemDefStruct.domainRatio(n);
            fitLimits(fitCounter,1) = limits.domainRatio(n,1);
            fitLimits(fitCounter,2) = limits.domainRatio(n,2);
            fitNames{fitCounter} = problemDefCells{20}{n};
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemDefStruct.domainRatio(n);
            otherLimits(otherCounter,1) = limits.domainRatio(n,1);
            otherLimits(otherCounter,2) = limits.domainRatio(n,2);
            otherCounter = otherCounter + 1;
        end
    end
    
    problemDefStruct.fitParams = fitParams;
    problemDefStruct.otherParams = otherParams;
    problemDefStruct.fitLimits = fitLimits;
    problemDefStruct.otherLimits = otherLimits;

end