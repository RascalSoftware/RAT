
function priorFitList = getFittedPriors(paramNames,priors,fitconstr)

% Get the list of all the priors..
priorNames = priors.priorNames;
priorVals = priors.priorVals;

% Find the values for fitpars
numberOfParams = length(paramNames);
%priorFitList = cell(numberOfParams,5);

% for i = 1:numberOfParams
%     priorFitList{i,1} = 0;
%     priorFitList{i,2} = 0;
%     priorFitList{i,3} = 0;
%     priorFitList{i,4} = 0;
%     priorFitList{i,5} = 0;
% end
priorFitList = zeros(numberOfParams,5);

% In order to keep 'priorFitList' homogenous (otherwise we would need to
% use a struct), we change the prior type to a numeric flag. So....
% 'uniform' = 1
% 'gaussian' = 2
% 'jeffreys' = 3
thisType = 1;
thisMu = 0;
thisSig = 0;
for i = 1:numberOfParams
    thisParam = paramNames{i};
    paramLoc = find(strcmpi({thisParam},priorNames));
    % thisType = priorVals{paramLoc,1};
    
%     if strcmpi(thisType,'uniform')
%         priorType = 1;
%     elseif strcmpi(thisType,'gaussian')
%         priorType = 2;
%     elseif strcmpi(thisType,'jeffreys')
%         priorType = 3;
%     else
%         priorType = 1;
%     end
    priorType =  priorVals(paramLoc,1);
    priorFitList(i,1) = priorType;

    thisMu = priorVals(paramLoc,2);
    thisSig = priorVals(paramLoc,3);
    priorFitList(i,2) = thisMu;
    priorFitList(i,3) = thisSig;

    priorFitList(i,4) = fitconstr(i,1);
    priorFitList(i,5) = fitconstr(i,2);
end
end
