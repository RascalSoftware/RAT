function [outProblemDef,results] = RAT_runParamonte(problem,controls,pmPars)

global logFunc;

rng('default');

% Split problem using the routines from RAT..
[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(problem,controls);

controls.para = 'points';

% Make an instance of the paramonte objective function class
logFunc = ratPmLogFunc();

[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);
nDims = length(problemDef.fitpars);
testPars = problemDef.fitpars;


% Scale the parameters
problemDef = scalePars(problemDef);

logFunc.problemDef = problemDef;
logFunc.problemDef_cells = problemDef_cells;
logFunc.problemDef_limits = problemDef_limits;
logFunc.priors = priors;
logFunc.controls = controls;
logFunc.NDIM = nDims;
logFunc.scaled = true;

% Create a laraMonte object
pm = paramonte();

% create a ParaDRAM simulation object
pmpd = pm.ParaDRAM();

scaledMins = zeros(length(testPars),1);
scaledMaxs = ones(length(testPars),1);

pmpd.spec.outputFileName = sprintf("./paramonte_out/%s",pmpPars.name); 
pmpd.spec.startPointVec = problemDef.fitpars;
pmpd.spec.domainLowerLimitVec = scaledMins;%problemDef.fitconstr(:,1);
pmpd.spec.domainUpperLimitVec = scaledMaxs;%problemDef.fitconstr(:,2);
pmpd.spec.overwriteRequested = true;
pmpd.spec.scaleFactor = pmPars.scalefactor; %1e-4;
%pmpd.spec.adaptiveUpdatePeriod = 8*nDims;
%pmpd.spec.outputFileName = fullfile(pwd,'out','pdramRun');
%pmpd.spec.overwriteRequested = true;
%pmpd.spec.proposalStartCovMat = covMat;
%pmpd.spec.greedyAdaptationCount = pmPars.greedyAdaptationCount;
pmpd.spec.variableNameList = fitNames;

pmpd.mpiEnabled = false;
pmpd.reportEnabled = false;
% pmpd.spec.parallelizationModel = 'singleChain';
pmpd.spec.chainSize = pmPars.chainSize; %10000;

pmpd.runSampler ( logFunc.NDIM  ... number of dimensions of the objective function
                , @logFunc.get  ... the objective function
                );
            
            
            
[outProblemDef,results] = processParamonteRuns(problem,controls,pmPars.name,pmPars.chainTrim);    
        

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
% % problemDef,problemDef_cells,problemDef_limits,priors,controls
% outProblem = {problemDef ; controls ; problemDef_limits ; problemDef_cells};
% 
% numberOfContrasts = problemDef.numberOfContrasts;
% data = cell(1,numberOfContrasts);
% for i = 1:numberOfContrasts
%     thisData = problemDef_cells{2}{i};
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

clear logFunc pm pmpd

end




