function [outProblemDef,result] = RAT(problemDefInput,controls)

[problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(problemDefInput,controls);
[problemDef,~] = packParams(problemDef,problemDefCells,problemDefLimits,controls.checks);

% Set controls.calCls always to 1
% if we are doing customXY
switch lower(problemDef.modelType)
    case 'custom xy'
        controls.calcSldDuringFit = true;
end

%Call the main RAT routine...
    
% If display is not silent print a
% line confirminf RAT is starting
if ~strcmpi(controls.display,'off')
    fprintf('Starting RAT ________________________________________________________________________________________________\n\n');
end

tic
[outProblemStruct,problem,result,bayesResults] = RATMain_mex(problemDef,problemDefCells,problemDefLimits,controls,priors);

if ~strcmpi(controls.display,'off')
    toc
end

% Then just do a final calculation to fill in SLD if necessary (i.e. if
% calSLD is no for fit)
if ~controls.calcSldDuringFit
    originalProcedure = controls.procedure;
    controls.calcSldDuringFit = true;
    controls.procedure = 'calculate';
    [outProblemStruct,problem,result,~] = RATMain_mex(outProblemStruct,problemDefCells,problemDefLimits,controls,priors);
    controls.procedure = originalProcedure;
end

result = parseResultToStruct(problem,result);

if isfield(outProblemStruct,'fitpars')
    result.bestFitPars = outProblemStruct.fitpars;
end

if any((strcmpi(controls.procedure,{'bayes','NS','dream'})))
    result = mergeStructs(result,bayesResults);
end

[~,fitNames] = packParams(problemDef,problemDefCells,problemDefLimits,controls.checks);
result.fitNames = fitNames;

outProblemDef = parseOutToProjectClass(problemDefInput,outProblemStruct);

if ~strcmpi(controls.display,'off')
   fprintf('\nFinished RAT ______________________________________________________________________________________________ \n\n');
end

end
