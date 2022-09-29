priors = load('priorStruct.mat');

priors = priors.priors;

priorNames = priors(:,1);
priorVals = priors(:,2:end);

allPriors.priorNames = priorNames;
allPriors.priorVals = priorVals;

mySmallFunc(allPriors);

