function [fitPriors,fitNames] = packFitPriors(fitNames,priors)


% Start by making a master list of all the priors.
allPriors = [priors.paramPriors ; ...
    priors.backsPriors ; ...
    priors.resolPriors ; ...
    priors.nbaPriors ; ...
    priors.nbsPriors ; ...
    priors.shiftPriors];




















end