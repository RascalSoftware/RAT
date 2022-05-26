
function [outProblemDef,result] = processFits(problem,controls,chainName,chainTrim)

% problem = load(name);
% problem = problem.twentyMNProblem;
% 
% controls = controlsDef();

[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(problem,controls);
problemDefInput = problemDef;

[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);
nDims = length(problemDef.fitpars);

pm = paramonte();
pmpd = pm.ParaDRAM();

chainFile = fullfile('paramonte_out',chainName);
pmpd.readChain(chainFile);

chainTable = pmpd.chainList{1}.df;

chain = chainTable{2:end,8:end};

scaledChain = chain(chainTrim:end,:);

limits = problemDef.fitconstr;
rows = size(scaledChain,1);

for i = 1:rows
    thesePars = scaledChain(i,:)';
    unscaledPars = (thesePars.*(limits(:,2)-limits(:,1)))+limits(:,1);
    unscaledChain(i,:) = unscaledPars';
end


allProblem = {problemDef, controls, problemDef_limits, problemDef_cells};

bayesOutputs.bestPars = mean(unscaledChain);
bayesOutputs.chain = unscaledChain;
bayesOutputs.fitNames = fitNames;
bayesOutputs.s2chain = [];
bayesOutputs.sschain = [];
bayesOutputs.data = problemDef_cells{2};
bayesOutputs.results.mean = mean(unscaledChain);

[problemDef,outProblemStruct,result,bayesResults] = processBayes_newMethod(bayesOutputs,allProblem);


result = parseResultToStruct(outProblemStruct,result);

if isfield(problemDef,'fitpars')
    result.bestFitPars = problemDef.fitpars;
end

result = mergeStructs(result,bayesResults);

[~,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);
result.fitNames = fitNames;

outProblemDef = RATparseOutToProjectClass(problem,problemDef,[],[]);

end