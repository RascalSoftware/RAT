
function priorFitList = getFittedPriors(paramNames,priors,fitconstr)

% Get the list of all the priors..
priorNames = priors.priorNames;
priorVals = priors.priorVals;

% Find the values for fitpars
numberOfParams = length(paramNames);
priorFitList = cell(numberOfParams,5);

for i = 1:numberOfParams
    thisParam = paramNames{i};
    paramLoc = strcmpi(thisParam,priorNames);
    priorFitList(i,1:3) = priorVals(paramLoc,:);
    priorFitList(i,4:5) = {fitconstr(i,1) fitconstr(i,2)};
end

end