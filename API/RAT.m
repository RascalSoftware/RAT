function [outProblemDef,result] = RAT(problemDefInput,controls)

[problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(problemDefInput,controls);
[problemDef,~] = packparams(problemDef,problemDefCells,problemDefLimits,controls.checks);

% %Define variable size for code generation
% coder.varsize('problemDef.resample',[Inf,1],[1 0]);
% coder.varsize('problemDef.numberOfContrasts',[1,1],[0 0]);
% coder.varsize('problemDef.geometry',[Inf,1],[1,0]);
% coder.varsize('problemDef.nbairs',[1,Inf],[0,1]);
% coder.varsize('problemDef.nbsubs',[1,Inf],[0,1]);
% coder.varsize('problemDef.contrastBacks',[1,Inf],[0,1]);
% coder.varsize('problemDef.contrastShifts',[1,Inf],[0,1]);
% coder.varsize('problemDef.contrastScales',[1,Inf],[0,1]);
% coder.varsize('problemDef.contrastNbas',[1,Inf],[0,1]);
% coder.varsize('problemDef.contrastNbss',[1,Inf],[0,1]);
% coder.varsize('problemDef.contrastRes',[1,Inf],[0,1]);
% coder.varsize('problemDef.backs',[1,Inf],[0,1]);
% coder.varsize('problemDef.shifts',[1,Inf],[0,1]);
% coder.varsize('problemDef.sf',[1,Inf],[0,1]);
% coder.varsize('problemDef.nba',[1,Inf],[0,1]);
% coder.varsize('problemDef.nbs',[1,Inf],[0,1]);
% coder.varsize('problemDef.res',[1,Inf],[0,1]);
% coder.varsize('problemDef.dataPresent',[1,Inf],[0,1]);
% coder.varsize('problemDef.nParams',[1,1],[0,0]);
% coder.varsize('problemDef.params',[1,Inf],[0,1]);
% coder.varsize('problemDef.numberOfLayers',[1,1],[0,0]);
% coder.varsize('problemDef.whichType',[1,Inf],[0,1]);
% coder.varsize('problemDef.fileHandle',[1,Inf],[0,1]);
% coder.varsize('problemDef.lang',[1,Inf],[0,1]);
% coder.varsize('problemDef.module',[1,Inf],[0,1]);
% coder.varsize('problemDef.fitpars',[Inf,1],[1,0]);
% coder.varsize('problemDef.otherpars',[Inf,1],[1,0]);
% coder.varsize('problemDef.fitconstr',[Inf,2],[1,0]);
% coder.varsize('problemDef.otherconstr',[Inf,2],[1,0]);

% Set controls.calCls always to 1
% if we are doing customXY
switch lower(problemDef.modelType)
    case 'custom xy'
        controls.calcSld = 1;
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
if controls.calcSld == 0
    originalProcedure = controls.procedure;
    controls.calcSld = 1;
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

[~,fitNames] = packparams(problemDef,problemDefCells,problemDefLimits,controls.checks);
result.fitNames = fitNames;

outProblemDef = parseOutToProjectClass(problemDefInput,outProblemStruct,problem,result);

if ~strcmpi(controls.display,'off')
   fprintf('\nFinished RAT ______________________________________________________________________________________________ \n\n');
end

end
