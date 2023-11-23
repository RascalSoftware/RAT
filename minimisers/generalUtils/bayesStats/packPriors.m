function fitPriors = packPriors(priors,checks)

%We need to pack the parameters into seperate vectors
%of those that are being fitted, and those that are
%held constant.
numberOfFitted = sum(checks.fitParam) + ...
                 sum(checks.fitBackgroundParam) + ...
                 sum(checks.fitScalefactor) + ...
                 sum(checks.fitQzshift) + ...
                 sum(checks.fitNbairs) + ...
                 sum(checks.fitNbsubs) + ...
                 sum(checks.fitResolutionParam);
             
% numberOfTotal = length(problemDef.params) + ...
%                 length(problemDef.backs) + ...
%                 length(problemDef.sf) + ...
%                 length(problemDef.shifts) + ...
%                 length(problemDef.nba) + ...
%                 length(problemDef.nbs) + ...
%                 length(problemDef.res);
   
% fitpars = problemDef.fitpars;%zeros(numberOfFitted,1);
% otherpars = zeros((numberOfTotal-numberOfFitted),1);
% fitconstr = zeros(numberOfFitted,2);
% otherconstr = zeros((numberOfTotal-numberOfFitted),2);
% %limits = problemDef.limits;
% fitNames = cell(numberOfFitted,1);
fitCounter = 1;
% otherCounter = 1;
thesePriors = priors.paramPriors;
for n = 1:length(checks.fitParam)
    if checks.fitParam(n) == 1
        fitPriors{fitCounter} = thesePriors(n,:);
        fitCounter = fitCounter + 1;
        
%         fitpars(fitCounter) = problemDef.params(n);
%         fitconstr(fitCounter,1) = limits.params(n,1);
%         fitconstr(fitCounter,2) = limits.params(n,2);        
%         fitNames{fitCounter} = problemDefCells{7}{n};
%         fitCounter = fitCounter + 1;
% 
%     else
%         otherpars(otherCounter) = problemDef.params(n);
%         otherconstr(otherCounter,1) = limits.params(n,1);
%         otherconstr(otherCounter,2) = limits.params(n,2);
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