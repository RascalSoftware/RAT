function [outProblemDef,result] = RAT_new(problemDefInput,controls)

[problemDef,problemDef_cells,problemDef_limits,controls] = RatParseClassToStructs_new(problemDefInput,controls);

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

% Set up the output class and events.
ratOut = ratOutputClass();
ratListener = listener(ratOut,'ratUpdate',@defaultRatOutputFunction);
%ratListener = listener(ratOut,'ratUpdate',@bayesAddInfoText);
setappdata(0,'ratOut',{ratOut ; ratListener});

% This creates an output class from RAT from which updates are sent.
% To use it, register an output function with ratOut using the listener
% class. To supress the default listener (outputs to command window only)
% being called, this must be manually deleted (delete(ratListener)).
% To trigger output within RAT...
%
% outputs = getappdata(0,'ratOut');
% ratOutHandle = ratOut{1};
% ratOut.customEventData.textUpdate = 'new text';
% ratOut.triggerEvent;


%Call the main RAT routine...


fprintf('Starting RAT ________________________________________________________________________________________________ \n');

tic
[outProblemStruct,problem,result,bayesResults] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls);
fprintf('\n');
toc

% Then just do a final calculation to fill in SLD if necessary (i.e. if
% calSLD is no for fit)
if controls.calcSld == 0
    originalProc = controls.proc;
    controls.calcSld = 1;
    controls.proc = 'calculate';
    [outProblemStruct,problem,result,bRes] = RAT_main(outProblemStruct,problemDef_cells,problemDef_limits,controls);
    controls.proc = originalProc;
end

result = parseResultToStruct(problem,result);
if any((strcmpi(controls.proc,{'NS','bayes'})))
   result.chain = bayesResults.chain;
   result.bayesRes = bayesResults.res;
   result.sschain = bayesResults.sschain;
   result.predlims = bayesResults.predlims;
   
%   result.posteriors = bayesResults.posteriors;
%   result.best = bayesResults.best;
%   result.posteriors = bayesResults.posteriors;
end

[~,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);
result.fitNames = fitNames;

outProblemDef = RATparseOutToProjectClass(problemDefInput,outProblemStruct,problem,result);



fprintf('\nFinished RAT ______________________________________________________________________________________________ \n\n');


end


