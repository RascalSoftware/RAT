function out = runR2withR1Bayes(problemDefInput,controls)


% This part is modified from R1 bayesGuiRun....

% --- R1 Codes ------
% nsimu = str2num(panel.getMcmcPointsBox().getText);
% burnin = str2num(panel.getBurninTextBox().getText);
% loop = str2num(panel.getRepeatRunsTextBox().getText);
% 
% %Now make the priors structure....
% table = getappdata(0,'mainbayesBacksTable');
% params = {};
% rows = table.getRowCount();

% ------------

% Process the input classes via the RAT method..
[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(problemDefInput,controls);

checks = controls.checks;
[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,checks);
%fitPriors = packPriors(priors,checks);

% Seed the Random Number Generator
rng(0);

% Use the R2 method to make the params structure....
prior = {};
lims = problemDef.fitconstr;

% Preallocate params array to keep the compiler happy
params = cell(length(fitNames),1);
for i = 1:length(params)
    params{i} = cell(1,6);
end

% We have a list of 'fitPars' which is created by packparams.m
% packparams doesn't do the same for our priors however. So we need 
% to make an array of the priors for the fitted parameters 
% so that we can then build the params array for the algorithm

% Put all the priors into one array
allPriors = [priors.paramPriors ; ...
    priors.backsPriors ; ...
    priors.resolPriors ; ...
    priors.nbaPriors ; ...
    priors.nbsPriors ; ...
    priors.shiftPriors ; 
    priors.scalesPriors];

% Get a list of all the prior names -- we can then use this to
% find the locations of the strings in 'fitNames'
allPriorNames = allPriors(:,1);

for i = 1:length(fitNames)
    name = fitNames{i};
    value = problemDef.fitpars(i);
    min = lims(i,1);
    max = lims(i,2);
    
    % Find this parameter in the priors list
    parPos = find(strcmp(allPriorNames,name));
    
    if isempty(parPos)
        error('Can"t find this fitting parameter');
    end
    
    mu = allPriors{parPos,3};
    sigma = allPriors{parPos,4};
    
    thisGroup = {name, value, min, max, mu, sigma};
    params{i} = thisGroup;
end

% Now run the Bayes with the R1 codes.
params = params(:);
loop = controls.repeats;
nsimu = controls.nsimu;
burnin = controls.burnin;

problem{1} = problemDef;
problem{2} = controls;
problem{3} = problemDef_limits; 
problem{4} = problemDef_cells;

% Run the analysis
output = runBayes_r1(loop,nsimu,burnin,params,problem);








disp('test');



end