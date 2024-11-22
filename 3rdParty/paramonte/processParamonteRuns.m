function [outProject,result,pmpd] = processParamonteRuns(problem,controls,chainName,chainTrim)

% problem = load(name);
% problem = problem.twentyMNProblem;
% 
% controls = controlsClass();

[problemStruct,problemCells,problemLimits,~,controls] = parseClassToStructs(problem,controls);

[problemStruct,fitNames] = packParams(problemStruct,problemLimits,controls.checks);

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

bayesOutputs.bestParams = mean(unscaledChain);
bayesOutputs.chain = unscaledChain;
bayesOutputs.fitNames = fitNames;
bayesOutputs.s2chain = [];
bayesOutputs.sschain = [];
bayesOutputs.data = problemStruct.data;
bayesOutputs.results.mean = mean(unscaledChain);

[problemStruct,result,bayesResults] = processBayes(bayesOutputs,problemStruct,problemCells,problemLimits,controls);
bayesResults.chain = unscaledChain;

result = mergeStructs(result,bayesResults);

outProject = parseOutToProjectClass(problem,problemStruct);

end
