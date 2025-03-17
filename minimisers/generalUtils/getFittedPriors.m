function priorFitList = getFittedPriors(paramNames,priorNames,priorValues,fitLimits)
% Convert RAT prior information into an array.
%
% Parameters
% ----------
% paramNames : array
%     The name of each parameter in the list.
% priorNames : array
%     The name of the prior for each parameter ('uniform', 'gaussian', or 'jeffreys')
% priorValues : array
%     The values for the prior (mu/sigma for Gaussian, unused otherwise)
% fitLimits : array
%     The lower and upper limits for each parameter.
%
% Returns
% -------
% priorFitList : array
%     a ``length(paramNames)x5`` array, where each row
%     is the index of the parameter, a numeric flag for the prior,
%     the prior values, and the limits for each parameter.

% Find the values for fitParams
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
        priorFitList(i,4) = fitLimits(i,1);
        priorFitList(i,5) = fitLimits(i,2);
    else
        priorFitList(i,1) = 1;
    end
end
end
