function [outProblemDef,result,pmpd] = processParamonteRuns(problem,controls,chainName,chainTrim)

% problem = load(name);
% problem = problem.twentyMNProblem;
% 
% controls = controlsClass();

[problemStruct,problemCells,problemLimits,~,controls] = parseClassToStructs(problem,controls);

[problemStruct,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

pm = paramonte();
pmpd = pm.ParaDRAM();

chainFile = fullfile('paramonte_out',chainName);
pmpd.readChain(chainFile);

chainTable = pmpd.chainList{1}.df;

chain = chainTable{2:end,8:end};

npoints = floor(chainTrim * size(chain,1));

% only take last part of chain...
scaledChain = chain((end-npoints):end,:);

limits = problemStruct.fitLimits;
rows = size(scaledChain,1);

for i = 1:rows
    thesePars = scaledChain(i,:)';
    unscaledPars = (thesePars.*(limits(:,2)-limits(:,1)))+limits(:,1);
    unscaledChain(i,:) = unscaledPars';
end


allProblem = {problemStruct, controls, problemLimits, problemCells};

bayesOutputs.bestPars = mean(unscaledChain);
bayesOutputs.chain = unscaledChain;
bayesOutputs.fitNames = fitNames;
bayesOutputs.s2chain = [];
bayesOutputs.sschain = [];
bayesOutputs.data = problemCells{2};
bayesOutputs.results.mean = mean(unscaledChain);

[problemStruct,outProblemStruct,result,bayesResults] = processBayes(bayesOutputs,allProblem);
bayesResults.chain = unscaledChain;

result = parseResultToStruct(outProblemStruct,result);

if isfield(problemStruct,'fitParams')
    result.bestFitPars = problemStruct.fitParams;
end

result = mergeStructs(result,bayesResults);

[~,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);
result.fitNames = fitNames;

outProblemDef = parseOutToProjectClass(problem,problemStruct);

end