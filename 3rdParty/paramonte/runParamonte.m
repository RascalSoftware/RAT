function [outProblemDef,results,outPmpd] = runParamonte(problem,inputControls,pmPars)

global logFunc;

% Check the input classes to make sure they are of correct type
if ~isa(pmPars,'pmPars')
    error('Third input must be a ''pmPars'' object');
elseif ~isa(problem,'projectClass')
    error('First input must be a ''projectClass'' object');
elseif ~isa(inputControls,'controlsClass')
    error('Second input must be a ''controlsClass'' object');
end


rng('default');

% Split problem using the routines from RAT..
[problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(problem,inputControls);

%controls.para = 'points';

% Make an instance of the paramonte objective function class
logFunc = pmLogFunction();

[problemDef,fitNames,fitPriors] = packparams_priors(problemDef,problemDefCells,problemDefLimits,priors,controls.checks);
nDims = length(problemDef.fitpars);
testPars = problemDef.fitpars;

% Scale the parameters
problemDef = scalePars(problemDef);

% Also need to scale the priors...
%scaledPriors = scalePriors(problemDef,fitPriors);

logFunc.problemDef = problemDef;
logFunc.problemDefCells = problemDefCells;
logFunc.problemDefLimits = problemDefLimits;
logFunc.priors = fitPriors; %scaledPriors;
logFunc.controls = controls;
logFunc.NDIM = nDims;
logFunc.scaled = true;

% Create a paraMonte object
pm = paramonte();

% create a ParaDRAM simulation object
pmpd = pm.ParaDRAM();

scaledMins = zeros(length(testPars),1);
scaledMaxs = ones(length(testPars),1);

if ~isempty(pmPars.covMat)
    pmpd.spec.proposalStartCovMat = covMat; % Note SCALED covmat
end

% if isfield(pmPars,'stVec')
%     pmpd.spec.startPointVec = pmPars.stVec;
% else
%     pmpd.spec.startPointVec = problemDef.fitpars;   % Maybe dependent on scaling?
% end

% if isfield(pmPars,'burninAdapt')
%     pmpd.spec.burninAdaptationMeasure = 1e-2; %pmPars.burninAdapt;
% end

if ~isempty(pmPars.delayedRejectionCount)
    pmpd.spec.delayedRejectionCount = pmPars.delayedRejectionCount;
end

name = pmPars.name;
pmpd.reportEnabled = false;
pmpd.spec.outputFileName = sprintf("./paramonte_out/%s",name);%,datestr(now,30)); 
pmpd.spec.domainLowerLimitVec = scaledMins;%problemDef.fitconstr(:,1);
pmpd.spec.domainUpperLimitVec = scaledMaxs;%problemDef.fitconstr(:,2);
pmpd.spec.overwriteRequested = true;
pmpd.spec.scaleFactor = pmPars.scalefactor; %1e-4;
pmpd.spec.sampleRefinementCount = pmPars.chainSize;
%pmpd.spec.adaptiveUpdatePeriod = 8*nDims;
%pmpd.spec.outputFileName = fullfile(pwd,'out','pdramRun');
%pmpd.spec.overwriteRequested = true;
%pmpd.spec.proposalStartCovMat = covMat;
%pmpd.spec.greedyAdaptationCount = pmPars.greedyAdaptationCount;
pmpd.spec.variableNameList = fitNames;

pmpd.mpiEnabled = pmPars.mpi;
pmpd.reportEnabled = false;
pmpd.spec.parallelizationModel = 'multiChain';
pmpd.spec.chainSize = pmPars.chainSize; %10000;

pmpd.runSampler ( logFunc.NDIM  ... number of dimensions of the objective function
                , @logFunc.get  ... the objective function
                );

[outProblemDef,results,outPmpd] = processParamonteRuns(problem,inputControls,pmPars.name,pmPars.chainTrim);    
        

% pmpd.readChain();
% 
% chainTable = pmpd.chainList{1}.df;
% 
% % Get out the chain, and unscale it.....
% scaledChain = chainTable{2:end,8:end};
% 
% limits = problemDef.fitconstr;
% rows = size(scaledChain,1);
% 
% for i = 1:rows
%     thesePars = scaledChain(i,:)';
%     unscaledPars = (thesePars.*(limits(:,2)-limits(:,1)))+limits(:,1);
%     unscaledChain(i,:) = unscaledPars';
% end
% 
% 
% % problemDef,problemDefCells,problemDefLimits,priors,controls
% outProblem = {problemDef ; controls ; problemDefLimits ; problemDefCells};
% 
% numberOfContrasts = problemDef.numberOfContrasts;
% data = cell(1,numberOfContrasts);
% for i = 1:numberOfContrasts
%     thisData = problemDefCells{2}{i};
%     if ~isempty(thisData)
%         data{i} = thisData(:,:);
%     end
% end
% 
% output.results.mean = mean(unscaledChain);
% output.chain = unscaledChain;
% output.s2chain = [];
% output.sschain = [];
% output.bestPars = mean(unscaledChain);
% output.data = data;
% 
% [problemDef,outProblem,result,bayesResults] = processBayes_newMethod(output,outProblem);

% pmpdOut = pmpd;

clear logFunc pm 

end




