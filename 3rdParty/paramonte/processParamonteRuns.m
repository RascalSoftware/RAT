
function [outProblemDef,result,pmpd] = processFits(problem,controls,chainName,chainTrim)

% problem = load(name);
% problem = problem.twentyMNProblem;
% 
% controls = controlsClass();

[problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(problem,controls);
problemDefInput = problemDef;

[problemDef,fitNames] = packparams(problemDef,problemDefCells,problemDefLimits,controls.checks);
nDims = length(problemDef.fitpars);

pm = paramonte();
pmpd = pm.ParaDRAM();

chainFile = fullfile('paramonte_out',chainName);
pmpd.readChain(chainFile);

chainTable = pmpd.chainList{1}.df;

chain = chainTable{2:end,8:end};

npoints = floor(chainTrim * size(chain,1));

% only take last part of chain...
scaledChain = chain((end-npoints):end,:);

limits = problemDef.fitconstr;
rows = size(scaledChain,1);

for i = 1:rows
    thesePars = scaledChain(i,:)';
    unscaledPars = (thesePars.*(limits(:,2)-limits(:,1)))+limits(:,1);
    unscaledChain(i,:) = unscaledPars';
end


allProblem = {problemDef, controls, problemDefLimits, problemDefCells};

bayesOutputs.bestPars = mean(unscaledChain);
bayesOutputs.chain = unscaledChain;
bayesOutputs.fitNames = fitNames;
bayesOutputs.s2chain = [];
bayesOutputs.sschain = [];
bayesOutputs.data = problemDefCells{2};
bayesOutputs.results.mean = mean(unscaledChain);

[problemDef,outProblemStruct,result,bayesResults] = processBayes(bayesOutputs,allProblem);
bayesResults.chain = unscaledChain;


result = parseResultToStruct(outProblemStruct,result);

if isfield(problemDef,'fitpars')
    result.bestFitPars = problemDef.fitpars;
end

result = mergeStructs(result,bayesResults);

[~,fitNames] = packparams(problemDef,problemDefCells,problemDefLimits,controls.checks);
result.fitNames = fitNames;

outProblemDef = parseOutToProjectClass(problem,problemDef);

end