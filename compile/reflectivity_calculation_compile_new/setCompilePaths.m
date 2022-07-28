function setCompilePaths(which)

% This function sets the paths for compiling, depending on whether a mex
% file of source code is being generated.

% The difference is in the handling of Matlab custom layers. Currently for
% mex, these are run in the base Matlab workspace. This doesn't exist if
% source code is being generated, and so code generation will fail.

% So, to choose between the two cases, we select between the following
% directories....

% <RATroot>/targetFunctions/common/loopMatlabCustomLayers/mexCompile
% <RATroot>/targetFunctions/common/loopMatlabCustomLayers/sourceCompile

ratRoot = getappdata(0,'ratRoot');

% Get a list of all the paths currently on paths list...
pathCell = regexp(path, pathsep, 'split');

switch which
    case 'mex'
        addDir = fullfile(ratRoot,'targetFunctions','common','loopMatlabCustomLayers','mexCompile');
        rmDir = fullfile(ratRoot,'targetFunctions','common','loopMatlabCustomLayers','sourceCompile');
    otherwise
        addDir = fullfile(ratRoot,'targetFunctions','common','loopMatlabCustomLayers','sourceCompile');
        rmDir = fullfile(ratRoot,'targetFunctions','common','loopMatlabCustomLayers','mexCompile');
end

% Add the 'add dir' if it is not currently on the path..
if ~any(strcmpi(addDir,pathCell))
    addpath(addDir);
    fprintf('Added directory %s to path \n',addDir);
end

% Add the 'add dir' if it is not currently on the path..
if any(strcmpi(rmDir,pathCell))
    rmpath(rmDir);
    fprintf('Removed directory %s from path \n',rmDir);
end
        
end