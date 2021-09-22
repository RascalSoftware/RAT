function [chainTable,logFunc,outProblem] = runParamonte_scaled(problem,controls)

global logFunc;

% Try to run the ORSO example using paramonte


% Split problem using the routines from RAT..
[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(problem,controls);

controls.para = 'contrasts';

% Make an instance of the paramonte objective function class
logFunc = orsoLogFunc();

[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);
nDims = length(problemDef.fitpars);

% Scale the parameters
problemDef = scalePars(problemDef);

logFunc.problemDef = problemDef;
logFunc.problemDef_cells = problemDef_cells;
logFunc.problemDef_limits = problemDef_limits;
logFunc.controls = controls;
logFunc.NDIM = nDims;
logFunc.scaled = true;

% Make sure this runs and we get a sensible answer
testPars = problemDef.fitpars;
val = logFunc.get(testPars);

% Create a laraMonte object
pm = paramonte();

% create a ParaDRAM simulation object
pmpd = pm.ParaDRAM();

scaledMins = zeros(length(testPars),1);
scaledMaxs = ones(length(testPars),1);

pmpd.spec.outputFileName = "./out/"; 
pmpd.spec.startPointVec = problemDef.fitpars;
pmpd.spec.domainLowerLimitVec = scaledMins;%problemDef.fitconstr(:,1);
pmpd.spec.domainUpperLimitVec = scaledMaxs;%problemDef.fitconstr(:,2);
pmpd.spec.overwriteRequested = true;
pmpd.spec.scaleFactor = 0.1;
%pmpd.spec.adaptiveUpdatePeriod = 8*nDims;
%pmpd.spec.outputFileName = fullfile(pwd,'out','pdramRun');
%pmpd.spec.overwriteRequested = true;
%pmpd.spec.proposalStartCovMat = covMat;
pmpd.spec.greedyAdaptationCount = 5000;
pmpd.spec.variableNameList = fitNames;

pmpd.mpiEnabled = true;
pmpd.reportEnabled = false;
pmpd.spec.parallelizationModel = 'singleChain';
pmpd.spec.chainSize = 7000;

pmpd.runSampler ( logFunc.NDIM  ... number of dimensions of the objective function
                , @logFunc.get  ... the objective function
                );
 
pmpd.readChain();

chainTable = pmpd.chainList{1}.df;

% problemDef,problemDef_cells,problemDef_limits,priors,controls
%problem = {problemDef ; controls ; problemDef_limits ; problemDef_cells};
outProblem{1} = problemDef;
outProblem{2} = controls; %problemDef_cells;
outProblem{3} = problemDef_limits;
outProblem{4} = problemDef_cells;

end


function chi = chiFunc(params)
    global logFunc;
    chi = abs(logFunc.get(params))*2;
end




