function [problem,result] = RAT(problemDefInput,controls)

%Separate cells from the problemDef struct...
%[problemDef,problemDef_data,problemDef_limits] = RAT_remove_cells(problemDef,controls);

if class(problemDefInput) ~= 'problemDef'
    error('Input to RAT must be a problemDef class and a controlsDef class');
end

%This is going to make the 'old API' version of everything for now
%Will change at a letr date.
[problemDef,problemDef_cells,problemDef_limits,controls] = RatParseClassToStructs(problemDefInput,controls);

%Define variable size for code generation
coder.varsize('problemDef.resample',[Inf,1],[1 0]);
coder.varsize('problemDef.numberOfContrasts',[1,1],[0 0]);
coder.varsize('problemDef.geometry',[Inf,1],[1,0]);
coder.varsize('problemDef.nbairs',[1,Inf],[0,1]);
coder.varsize('problemDef.nbsubs',[1,Inf],[0,1]);
coder.varsize('problemDef.contrastBacks',[1,Inf],[0,1]);
coder.varsize('problemDef.contrastShifts',[1,Inf],[0,1]);
coder.varsize('problemDef.contrastScales',[1,Inf],[0,1]);
coder.varsize('problemDef.contrastNbas',[1,Inf],[0,1]);
coder.varsize('problemDef.contrastNbss',[1,Inf],[0,1]);
coder.varsize('problemDef.contrastRes',[1,Inf],[0,1]);
coder.varsize('problemDef.backs',[1,Inf],[0,1]);
coder.varsize('problemDef.shifts',[1,Inf],[0,1]);
coder.varsize('problemDef.sf',[1,Inf],[0,1]);
coder.varsize('problemDef.nba',[1,Inf],[0,1]);
coder.varsize('problemDef.nbs',[1,Inf],[0,1]);
coder.varsize('problemDef.res',[1,Inf],[0,1]);
coder.varsize('problemDef.dataPresent',[1,Inf],[0,1]);
coder.varsize('problemDef.nParams',[1,1],[0,0]);
coder.varsize('problemDef.params',[1,Inf],[0,1]);
coder.varsize('problemDef.numberOfLayers',[1,1],[0,0]);
coder.varsize('problemDef.whichType',[1,Inf],[0,1]);
coder.varsize('problemDef.fileHandle',[1,Inf],[0,1]);
coder.varsize('problemDef.lang',[1,Inf],[0,1]);
coder.varsize('problemDef.module',[1,Inf],[0,1]);
coder.varsize('problemDef.fitpars',[Inf,1],[1,0]);
coder.varsize('problemDef.otherpars',[Inf,1],[1,0]);
coder.varsize('problemDef.fitconstr',[Inf,2],[1,0]);
coder.varsize('problemDef.otherconstr',[Inf,2],[1,0]);

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
[outProblemStruct,problem,result] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls);

if ~strcmp(controls.proc,'NS')
    result = parseResultToStruct(outProblemStruct,problem,result);
end
outProblemDef = RATparseOutToProblemDef2(problemDefInput,outProblemStruct,problem,result);
problem = outProblemDef;

end


