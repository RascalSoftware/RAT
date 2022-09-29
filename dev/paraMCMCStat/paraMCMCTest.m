function paraMCMCTest
% Parallel Computing Toolbox for MCMCstat?

% Add the exmaple path
ratRoot = getappdata(0,'ratRoot');
examplePath = fullfile(ratRoot,'examples','standard layers');
addpath(examplePath);

% Make projectClass (problem)
orsoDSPC_stanLay_script();


% Single cored....
controls = controlsDef();
controls.procedure = 'bayes';
controls.nsimu = 5000;
controls.repeats = 3;

[sProblem,sResults] = RAT(problem,controls);

%%


%controls.nsimu = 10000;
controls.display = 'off';

numWorkers = 4;

outProblem = cell(numWorkers,1);
outResult = cell(numWorkers,1);

% Need to make the output variables in the workspace befor the parfor
% loop..
parfor i = 1:numWorkers
    [prob,res] = loopFunction(problem,controls,i);
    outProblem{i} = prob;
    outResult{i} = res;
end

%%
totalResult = outResult{1};
totalChain = totalResult.chain;
tic
for i = 1:numWorkers
    thisResult = outResult{i};
    thisChain = thisResult.chain;
    totalChain = [totalChain ; thisChain];
end
toc
totalResult.chain = totalChain;

end

%%


function [probOut,resOut] = loopFunction(problem,controls,i)

    [probOut,resOut] = RAT(problem,controls);

end




