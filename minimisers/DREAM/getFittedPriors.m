function priorFitList = getFittedPriors(paramNames,priors,fitconstr)

% Get the list of all the priors..
priorNames = priors.priorNames;
priorValues = priors.priorValues;

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

for i = 1:numberOfParams
    thisParam = paramNames{i};
    indices = find(strcmpi({thisParam},priorNames));
    
    if ~isempty(indices)
        index = indices(1);
        priorType =  priorValues(index,1);
        priorFitList(i,1) = priorType;
        priorFitList(i,2) = priorValues(index,2);
        priorFitList(i,3) = priorValues(index,3);
        priorFitList(i,4) = fitconstr(i,1);
        priorFitList(i,5) = fitconstr(i,2);
    else
        priorFitList(i,1) = 1;
    end
end
end
