function [problemDefOutput,result] = RAT(problemDefInput,inputControls)

[problemDefStruct,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(problemDefInput,inputControls);
[problemDefStruct,~] = packParams(problemDefStruct,problemDefCells,problemDefLimits,controls.checks);

% Set controls.calcSLD to 1 if we are doing customXY
switch lower(problemDefStruct.modelType)
    case 'custom xy'
        controls.calcSldDuringFit = true;
end

%Call the main RAT routine...
    
% If display is not silent print a line confirming RAT is starting
if ~strcmpi(controls.display,'off')
    fprintf('Starting RAT ________________________________________________________________________________________________\n\n');
end

tic
[problemDefStruct,problem,resultCells,bayesResults] = RATMain_mex(problemDefStruct,problemDefCells,problemDefLimits,controls,priors);

if ~strcmpi(controls.display,'off')
    toc
end

result = parseResultToStruct(problem,resultCells);

if isfield(problemDefStruct,'fitParams')
    result.bestFitPars = problemDefStruct.fitParams;
end

if any((strcmpi(controls.procedure,{'bayes','NS','dream'})))
    result = mergeStructs(result, bayesResults);
end

[~,fitNames] = packParams(problemDefStruct,problemDefCells,problemDefLimits,controls.checks);
result.fitNames = fitNames;

problemDefOutput = parseOutToProjectClass(problemDefInput,problemDefStruct);

if ~strcmpi(controls.display,'off')
   fprintf('\nFinished RAT ______________________________________________________________________________________________ \n\n');
end

end
