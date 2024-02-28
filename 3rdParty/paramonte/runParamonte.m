function [project,results,outPmpd] = runParamonte(project,inputControls,pmPars)

global logFunc;

% Check the input classes to make sure they are of correct type
if ~isa(pmPars,'pmPars')
    error('Third input must be a ''pmPars'' object');
elseif ~isa(project,'projectClass')
    error('First input must be a ''projectClass'' object');
elseif ~isa(inputControls,'controlsClass')
    error('Second input must be a ''controlsClass'' object');
end


rng('default');

% Split problem using the routines from RAT..
[problemStruct,problemCells,problemLimits,priors,controls] = parseClassToStructs(project,inputControls);

%controls.parallel = 'points';

% Make an instance of the paramonte objective function class
logFunc = pmLogFunction();

[problemStruct,fitNames,fitPriors] = packParamsPriors(problemStruct,problemCells,problemLimits,priors,controls.checks);
nDims = length(problemStruct.fitParams);
testPars = problemStruct.fitParams;

% Scale the parameters
problemStruct = scalePars(problemStruct);

% Also need to scale the priors...
%scaledPriors = scalePriors(problemStruct,fitPriors);

logFunc.problemStruct = problemStruct;
logFunc.problemCells = problemCells;
logFunc.problemLimits = problemLimits;
logFunc.priors = fitPriors; %scaledPriors;
logFunc.controls = controls;
logFunc.NDIM = nDims;
logFunc.scaled = true;

% Create a paramonte object
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
%     pmpd.spec.startPointVec = problemStruct.fitParams;   % Maybe dependent on scaling?
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
pmpd.spec.domainLowerLimitVec = scaledMins;%problemStruct.fitLimits(:,1);
pmpd.spec.domainUpperLimitVec = scaledMaxs;%problemStruct.fitLimits(:,2);
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

[project,results,outPmpd] = processParamonteRuns(project,inputControls,pmPars.name,pmPars.chainTrim);    
        

% pmpd.readChain();
% 
% chainTable = pmpd.chainList{1}.df;
% 
% % Get out the chain, and unscale it.....
% scaledChain = chainTable{2:end,8:end};
% 
% limits = problemStruct.fitLimits;
% rows = size(scaledChain,1);
% 
% for i = 1:rows
%     thesePars = scaledChain(i,:)';
%     unscaledPars = (thesePars.*(limits(:,2)-limits(:,1)))+limits(:,1);
%     unscaledChain(i,:) = unscaledPars';
% end
% 
% 
% % problemStruct,problemCells,problemLimits,priors,controls
% outProblem = {problemStruct ; controls ; problemLimits ; problemCells};
% 
% numberOfContrasts = problemStruct.numberOfContrasts;
% data = cell(1,numberOfContrasts);
% for i = 1:numberOfContrasts
%     thisData = problemCells{2}{i};
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
% [problemStruct,result,bayesResults] = processBayes(output,outProblem);

% pmpdOut = pmpd;

clear logFunc pm 

end




