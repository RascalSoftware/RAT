function [problemDef,fitNames,fitPriors] = packparams_priors(problemDef,problemDef_cells,limits,priors,checks)

%Separate out the params array into fitting
%and unfitting arrays.


%problem = getappdata(0,'problem');

% controls.checks.params_fitYesNo = ones(length(problem.params),1);
% controls.checks.backs_fitYesNo = ones(length(problem.backs),1);
% controls.checks.scales_fitYesNo = ones(length(problem.scalefac),1);
% controls.checks.nbairs_fitYesNo = ones(length(problem.nba),1);
% controls.checks.nbsubs_fitYesNo = ones(length(problem.nbs),1);
% controls.checks.resol_fitYesNo = ones(length(problem.resolution),1);

% calculation.limits.params = problem.constr;
% calculation.limits.backs = problem.backs_constr;
% calculation.limits.scales = problem.scale_constr;
% calculation.limits.shifts = problem.shifts_constr;
% calculation.limits.nba = problem.nbairs_constr;
% calculation.limits.nbs = problem.nbsubs_constr;
% calculation.limits.res = problem.resolution_constr;



%We need to pack the parameters into seperate vectors
%of those that are being fitted, and those that are
%held constant.
numberOfFitted = sum(checks.params_fitYesNo) + ...
                 sum(checks.backs_fitYesNo) + ...
                 sum(checks.scales_fitYesNo) + ...
                 sum(checks.shifts_fitYesNo) + ...
                 sum(checks.nbairs_fitYesNo) + ...
                 sum(checks.nbsubs_fitYesNo) + ...
                 sum(checks.resol_fitYesNo) + ...
                 sum(checks.domainRatio_fitYesNo);
             
numberOfTotal = length(problemDef.params) + ...
                length(problemDef.backs) + ...
                length(problemDef.sf) + ...
                length(problemDef.shifts) + ...
                length(problemDef.nba) + ...
                length(problemDef.nbs) + ...
                length(problemDef.res) + ...
                length(problemDef.domainRatio);
   
fitpars = problemDef.fitpars;%zeros(numberOfFitted,1);
otherpars = zeros((numberOfTotal-numberOfFitted),1);
fitconstr = zeros(numberOfFitted,2);
otherconstr = zeros((numberOfTotal-numberOfFitted),2);
%limits = problemDef.limits;
fitNames = cell(numberOfFitted,1);
fitPriors = zeros(numberOfFitted,2);
fitCounter = 1;
otherCounter = 1;
for n = 1:length(checks.params_fitYesNo)
    if checks.params_fitYesNo(n) == 1
        fitpars(fitCounter) = problemDef.params(n);
        fitconstr(fitCounter,1) = limits.params(n,1);
        fitconstr(fitCounter,2) = limits.params(n,2);        
        fitNames{fitCounter} = problemDef_cells{7}{n};
        thisPrior = priors.paramPriors{n};
        if (strcmpi(thisPrior{2},'gaussian'))
            thisGausPrior = [thisPrior{3} thisPrior{4}];
        else
            thisGausPrior = [0 Inf];
        end
        fitPriors(fitCounter,:) = thisGausPrior; 
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.params(n);
        otherconstr(otherCounter,1) = limits.params(n,1);
        otherconstr(otherCounter,2) = limits.params(n,2);
        otherCounter = otherCounter + 1;
    end
end

%Also do the same for backgrounds...
for n = 1:length(checks.backs_fitYesNo)
    if checks.backs_fitYesNo(n) == 1
        fitpars(fitCounter) = problemDef.backs(n);
        fitconstr(fitCounter,1) = limits.backs(n,1);
        fitconstr(fitCounter,2) = limits.backs(n,2);
        fitNames{fitCounter} = problemDef_cells{8}{n};
        thisPrior = priors.backsPriors{n};
        if (strcmpi(thisPrior{2},'gaussian'))
            thisGausPrior = [thisPrior{4} thisPrior{5}];
        else
            thisGausPrior = [0 Inf];
        end
        fitPriors(fitCounter,:) = thisGausPrior;
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.backs(n);
        otherconstr(otherCounter,1) = limits.backs(n,1);
        otherconstr(otherCounter,2) = limits.backs(n,2);
        otherCounter = otherCounter + 1;
    end
end

%..also for the scale factors
for n = 1:length(checks.scales_fitYesNo)
    if checks.scales_fitYesNo(n) == 1
        fitpars(fitCounter) = problemDef.sf(n);
        fitconstr(fitCounter,1) = limits.scales(n,1);
        fitconstr(fitCounter,2) = limits.scales(n,2);
        fitNames{fitCounter} = problemDef_cells{9}{n};
        thisPrior = priors.scalesPriors{n};
        if (strcmpi(thisPrior{2},'gaussian'))
            thisGausPrior = [thisPrior{4} thisPrior{5}];
        else
            thisGausPrior = [0 Inf];
        end
        fitPriors(fitCounter,:) = thisGausPrior;
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.sf(n);
        otherconstr(otherCounter,1) = limits.scales(n,1);
        otherconstr(otherCounter,2) = limits.scales(n,2);
        otherCounter = otherCounter + 1;
    end
end    

%Need qshifts
for n = 1:length(checks.shifts_fitYesNo)
    if checks.shifts_fitYesNo(n) == 1
        fitpars(fitCounter) = problemDef.shifts(n);
        fitconstr(fitCounter,1) = limits.shifts(n,1);
        fitconstr(fitCounter,2) = limits.shifts(n,2);
        fitNames{fitCounter} = problemDef_cells{10}{n};
        thisPrior = priors.shiftPriors{n};
        if (strcmpi(thisPrior{2},'gaussian'))
            thisGausPrior = [thisPrior{4} thisPrior{5}];
        else
            thisGausPrior = [0 Inf];
        end
        fitPriors(fitCounter,:) = thisGausPrior;
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.shifts(n);
        otherconstr(otherCounter,1) = limits.shifts(n,1);
        otherconstr(otherCounter,2) = limits.shifts(n,2);
        otherCounter = otherCounter + 1;
    end
end 

%Nbairs
for n = 1:length(checks.nbairs_fitYesNo)
    if checks.nbairs_fitYesNo(n) == 1
        fitpars(fitCounter) = problemDef.nba(n);
        fitconstr(fitCounter,1) = limits.nba(n,1);
        fitconstr(fitCounter,2) = limits.nba(n,2);
        fitNames{fitCounter} = problemDef_cells{11}{n};
        thisPrior = priors.nbaPriors{n};
        if (strcmpi(thisPrior{2},'gaussian'))
            thisGausPrior = [thisPrior{4} thisPrior{5}];
        else
            thisGausPrior = [0 Inf];
        end
        fitPriors(fitCounter,:) = thisGausPrior;
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.nba(n);
        otherconstr(otherCounter,1) = limits.nba(n,1);
        otherconstr(otherCounter,2) = limits.nba(n,2);
        otherCounter = otherCounter + 1;
    end
end 

%NBsubs
for n = 1:length(checks.nbsubs_fitYesNo)
    if checks.nbsubs_fitYesNo(n) == 1
        fitpars(fitCounter) = problemDef.nbs(n);
        fitconstr(fitCounter,1) = limits.nbs(n,1);
        fitconstr(fitCounter,2) = limits.nbs(n,2);
        fitNames{fitCounter} = problemDef_cells{12}{n};
        thisPrior = priors.nbsPriors{n};
        if (strcmpi(thisPrior{2},'gaussian'))
            thisGausPrior = [thisPrior{3} thisPrior{4}];
        else
            thisGausPrior = [0 Inf];
        end
        fitPriors(fitCounter,:) = thisGausPrior;
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.nbs(n);
        otherconstr(otherCounter,1) = limits.nbs(n,1);
        otherconstr(otherCounter,2) = limits.nbs(n,2);
        otherCounter = otherCounter + 1;
    end
end 

%Resolution.....
for n = 1:length(checks.resol_fitYesNo)
    if checks.resol_fitYesNo(n) == 1
        fitpars(fitCounter) = problemDef.res(n);
        fitconstr(fitCounter,1) = limits.res(n,1);
        fitconstr(fitCounter,2) = limits.res(n,2);
        fitNames{fitCounter} = problemDef_cells{13}{n};
        thisPrior = priors.resolPriors{n};
        if (strcmpi(thisPrior{2},'gaussian'))
            thisGausPrior = [thisPrior{4} thisPrior{5}];
        else
            thisGausPrior = [0 Inf];
        end
        fitPriors(fitCounter,:) = thisGausPrior;
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.res(n);
        otherconstr(otherCounter,1) = limits.res(n,1);
        otherconstr(otherCounter,2) = limits.res(n,2);
        otherCounter = otherCounter + 1;
    end
end 

% Domain Ratio
for n = 1:length(checks.domainRatio_fitYesNo)
    if checks.domainRatio_fitYesNo(n) == 1
        fitpars(fitCounter) = problemDef.domainRatio(n);
        fitconstr(fitCounter,1) = limits.domainRatio(n,1);
        fitconstr(fitCounter,2) = limits.domainRatio(n,2);
        fitNames{fitCounter} = problemDef_cells{17}{n};
        thisPrior = priors.domainRatioPriors{n};
        if (strcmpi(thisPrior{2},'gaussian'))
            thisGausPrior = [thisPrior{4} thisPrior{5}];
        else
            thisGausPrior = [0 Inf];
        end
        fitPriors(fitCounter,:) = thisGausPrior;
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.domainRatio(n);
        otherconstr(otherCounter,1) = limits.domainRatio(n,1);
        otherconstr(otherCounter,2) = limits.domainRatio(n,2);
        otherCounter = otherCounter + 1;
    end
end 

problemDef.fitpars = fitpars;
problemDef.otherpars = otherpars;
problemDef.fitconstr = fitconstr;
problemDef.otherconstr = otherconstr;

end