function [project,result] = RAT(project,controls)

[problemStruct,problemCells,problemLimits,priors,controls] = parseClassToStructs(project,controls);

% Set controls.calcSLD to 1 if we are doing customXY
switch lower(problemStruct.modelType)
    case modelTypes.CustomXY.value
        controls.calcSldDuringFit = true;
end

% Call the main RAT routine...
display = ~strcmpi(controls.display, displayOptions.Off.value);
textProgressBar(0, 0, display);
% If display is not silent print a line confirming RAT is starting
if display
    fprintf('Starting RAT ________________________________________________________________________________________________\n\n');
end

tic
[problemStruct,result,bayesResults] = RATMain(problemStruct,problemCells,problemLimits,controls,priors);

if display
    toc
end
textProgressBar(0, 0, true);
if any(strcmpi(controls.procedure, {procedures.NS.value, procedures.Dream.value}))
    result = mergeStructs(result, bayesResults);
end

project = parseOutToProjectClass(project,problemStruct);

if ~strcmpi(controls.display, displayOptions.Off.value)
   fprintf('\nFinished RAT ______________________________________________________________________________________________ \n\n');
end

end
