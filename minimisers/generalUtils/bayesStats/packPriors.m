function fitPriors = packPriors(priors,checks)

%We need to pack the parameters into seperate vectors
%of those that are being fitted, and those that are
%held constant.
numberOfFitted = sum(checks.params) + ...
                 sum(checks.backgroundParams) + ...
                 sum(checks.scalefactors) + ...
                 sum(checks.qzshifts) + ...
                 sum(checks.bulkIns) + ...
                 sum(checks.bulkOuts) + ...
                 sum(checks.resolutionParams);
             
% numberOfTotal = length(problemStruct.params) + ...
%                 length(problemStruct.backgroundParams) + ...
%                 length(problemStruct.scalefactors) + ...
%                 length(problemStruct.qzshifts) + ...
%                 length(problemStruct.bulkIns) + ...
%                 length(problemStruct.bulkOuts) + ...
%                 length(problemStruct.resolutionParams);
   
% fitParams = problemStruct.fitParams;%zeros(1,numberOfFitted);
% otherParams = zeros(1,(numberOfTotal-numberOfFitted));
% fitLimits = zeros(numberOfFitted,2);
% otherLimits = zeros((numberOfTotal-numberOfFitted),2);
% %limits = problemStruct.limits;
% fitNames = cell(numberOfFitted,1);
fitCounter = 1;
% otherCounter = 1;
thesePriors = priors.param;
for n = 1:length(checks.fitParam)
    if checks.fitParam(n) == 1
        fitPriors{fitCounter} = thesePriors(n,:);
        fitCounter = fitCounter + 1;
        
%         fitParams(fitCounter) = problemStruct.params(n);
%         fitLimits(fitCounter,1) = limits.params(n,1);
%         fitLimits(fitCounter,2) = limits.params(n,2);        
%         fitNames{fitCounter} = problemStruct.params{n};
%         fitCounter = fitCounter + 1;
% 
%     else
%         otherParams(otherCounter) = problemStruct.params(n);
%         otherLimits(otherCounter,1) = limits.params(n,1);
%         otherLimits(otherCounter,2) = limits.params(n,2);
%         otherCounter = otherCounter + 1;
    end
end

% backs

% scales

% shifts

% nba

% nbs

% resol














end