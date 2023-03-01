
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
    priorFitList(i,1) = priorVals(paramLoc,1);
    priorFitList{i,2} = str2double(priorVals{paramLoc,2});
    priorFitList{i,3} = str2double(priorVals{paramLoc,3});
    priorFitList{i,4} = fitconstr(i,1);
    priorFitList{i,5} = fitconstr(i,2);
end

end