function [project,result] = RAT(project,controls)

[problemStruct,problemCells,problemLimits,priors,controls] = parseClassToStructs(project,controls);
[problemStruct,~] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

% Set controls.calcSLD to 1 if we are doing customXY
switch lower(problemStruct.modelType)
    case 'custom xy'
        controls.calcSldDuringFit = true;
end

%Call the main RAT routine...
    
% If display is not silent print a line confirming RAT is starting
if ~strcmpi(controls.display,'off')
    fprintf('Starting RAT ________________________________________________________________________________________________\n\n');
end

tic
[problemStruct,contrastParams,resultCells,bayesResults] = RATMain_mex(problemStruct,problemCells,problemLimits,controls,priors);

if ~strcmpi(controls.display,'off')
    toc
end

result = parseResultToStruct(contrastParams,resultCells);

if isfield(problemStruct,'fitParams')
    result.bestFitPars = problemStruct.fitParams;
end

if any((strcmpi(controls.procedure,{'bayes','NS','dream'})))
    result = mergeStructs(result, bayesResults);
end

[~,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);
result.fitNames = fitNames;

project = parseOutToProjectClass(project,problemStruct);

if ~strcmpi(controls.display,'off')
   fprintf('\nFinished RAT ______________________________________________________________________________________________ \n\n');
end

end
