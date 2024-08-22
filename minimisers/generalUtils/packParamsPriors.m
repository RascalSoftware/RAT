function [problemStruct,fitNames,fitPriors] = packParamsPriors(problemStruct,problemCells,limits,priors,checks)

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
                 
    numberOfTotal = length(problemStruct.params) + ...
                    length(problemStruct.backgroundParams) + ...
                    length(problemStruct.scalefactors) + ...
                    length(problemStruct.qzshifts) + ...
                    length(problemStruct.bulkIn) + ...
                    length(problemStruct.bulkOut) + ...
                    length(problemStruct.resolutionParams) + ...
                    length(problemStruct.domainRatio);
       
    fitParams = zeros(numberOfFitted, 1);
    otherParams = zeros((numberOfTotal-numberOfFitted), 1);
    fitLimits = zeros(numberOfFitted,2);
    otherLimits = zeros((numberOfTotal-numberOfFitted),2);
    fitNames = cell(numberOfFitted,1);
    fitPriors = zeros(numberOfFitted,2);
    fitCounter = 1;
    otherCounter = 1;
    
    for n = 1:length(checks.fitParam)
        if checks.fitParam(n) == 1
            fitParams(fitCounter) = problemStruct.params(n);
            fitLimits(fitCounter,1) = limits.param(n,1);
            fitLimits(fitCounter,2) = limits.param(n,2);        
            fitNames{fitCounter} = problemCells{7}{n};
            thisPrior = priors.param{n};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{3} thisPrior{4}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior; 
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.params(n);
            otherLimits(otherCounter,1) = limits.param(n,1);
            otherLimits(otherCounter,2) = limits.param(n,2);
            otherCounter = otherCounter + 1;
        end
    end
    
    %Also do the same for backgrounds...
    for n = 1:length(checks.fitBackgroundParam)
        if checks.fitBackgroundParam(n) == 1
            fitParams(fitCounter) = problemStruct.backgroundParams(n);
            fitLimits(fitCounter,1) = limits.backgroundParam(n,1);
            fitLimits(fitCounter,2) = limits.backgroundParam(n,2);
            fitNames{fitCounter} = problemCells{8}{n};
            thisPrior = priors.backgroundParam{n};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{4} thisPrior{5}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior;
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.backgroundParams(n);
            otherLimits(otherCounter,1) = limits.backgroundParam(n,1);
            otherLimits(otherCounter,2) = limits.backgroundParam(n,2);
            otherCounter = otherCounter + 1;
        end
    end
    
    %..also for the scale factors
    for n = 1:length(checks.fitScalefactor)
        if checks.fitScalefactor(n) == 1
            fitParams(fitCounter) = problemStruct.scalefactors(n);
            fitLimits(fitCounter,1) = limits.scalefactor(n,1);
            fitLimits(fitCounter,2) = limits.scalefactor(n,2);
            fitNames{fitCounter} = problemCells{9}{n};
            thisPrior = priors.scalefactor{n};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{4} thisPrior{5}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior;
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.scalefactors(n);
            otherLimits(otherCounter,1) = limits.scalefactor(n,1);
            otherLimits(otherCounter,2) = limits.scalefactor(n,2);
            otherCounter = otherCounter + 1;
        end
    end    
    
    %Need qzshifts
    for n = 1:length(checks.fitQzshift)
        if checks.fitQzshift(n) == 1
            fitParams(fitCounter) = problemStruct.qzshifts(n);
            fitLimits(fitCounter,1) = limits.qzshift(n,1);
            fitLimits(fitCounter,2) = limits.qzshift(n,2);
            fitNames{fitCounter} = problemCells{10}{n};
            thisPrior = priors.qzshift{n};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{4} thisPrior{5}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior;
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.qzshifts(n);
            otherLimits(otherCounter,1) = limits.qzshift(n,1);
            otherLimits(otherCounter,2) = limits.qzshift(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Bulk In
    for n = 1:length(checks.fitBulkIn)
        if checks.fitBulkIn(n) == 1
            fitParams(fitCounter) = problemStruct.bulkIn(n);
            fitLimits(fitCounter,1) = limits.bulkIn(n,1);
            fitLimits(fitCounter,2) = limits.bulkIn(n,2);
            fitNames{fitCounter} = problemCells{11}{n};
            thisPrior = priors.bulkIn{n};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{4} thisPrior{5}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior;
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.bulkIn(n);
            otherLimits(otherCounter,1) = limits.bulkIn(n,1);
            otherLimits(otherCounter,2) = limits.bulkIn(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Bulk Out
    for n = 1:length(checks.fitBulkOut)
        if checks.fitBulkOut(n) == 1
            fitParams(fitCounter) = problemStruct.bulkOut(n);
            fitLimits(fitCounter,1) = limits.bulkOut(n,1);
            fitLimits(fitCounter,2) = limits.bulkOut(n,2);
            fitNames{fitCounter} = problemCells{12}{n};
            thisPrior = priors.bulkOut{n};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{3} thisPrior{4}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior;
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.bulkOut(n);
            otherLimits(otherCounter,1) = limits.bulkOut(n,1);
            otherLimits(otherCounter,2) = limits.bulkOut(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    %Resolution.....
    for n = 1:length(checks.fitResolutionParam)
        if checks.fitResolutionParam(n) == 1
            fitParams(fitCounter) = problemStruct.resolutionParams(n);
            fitLimits(fitCounter,1) = limits.resolutionParam(n,1);
            fitLimits(fitCounter,2) = limits.resolutionParam(n,2);
            fitNames{fitCounter} = problemCells{13}{n};
            thisPrior = priors.resolutionParam{n};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{4} thisPrior{5}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior;
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.resolutionParams(n);
            otherLimits(otherCounter,1) = limits.resolutionParam(n,1);
            otherLimits(otherCounter,2) = limits.resolutionParam(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    % Domain Ratio
    for n = 1:length(checks.fitDomainRatio)
        if checks.fitDomainRatio(n) == 1
            fitParams(fitCounter) = problemStruct.domainRatio(n);
            fitLimits(fitCounter,1) = limits.domainRatio(n,1);
            fitLimits(fitCounter,2) = limits.domainRatio(n,2);
            fitNames{fitCounter} = problemCells{20}{n};
            thisPrior = priors.domainRatio{n};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{4} thisPrior{5}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior;
            fitCounter = fitCounter + 1;
        else
            otherParams(otherCounter) = problemStruct.domainRatio(n);
            otherLimits(otherCounter,1) = limits.domainRatio(n,1);
            otherLimits(otherCounter,2) = limits.domainRatio(n,2);
            otherCounter = otherCounter + 1;
        end
    end 
    
    problemStruct.fitParams = fitParams;
    problemStruct.otherParams = otherParams;
    problemStruct.fitLimits = fitLimits;
    problemStruct.otherLimits = otherLimits;

end