function setCompilePaths()

% This function sets the paths for compiling, depending on whether a mex
% file of source code is being generated.

% The difference is in the handling of Matlab custom models. Currently for
% mex, these are run in the base Matlab workspace (the fastest option). 
% This doesn't exist if source code is being generated, and so code 
% generation will fail.

% To deal with this, we have two directories with alternate functions of
% the same filenames, and we can switch between them by manipulating the 
% Matlab path between the two compile cases. Currently, the 'source'
% functions just output zeros, so building the toolbox outside Matlab will give
% nonsense results for custom models. However, soon the source version will 
% launch an external Matlab engine to deal with custom layers, although that 
% is not fully implemented yet. The C++ option for user custom models will
% work for both cases.

% To choose between the two options, we select between the following
% directories....

% <RATroot>/targetFunctions/common/loopMatlabCustomLayers/mexCompile
% <RATroot>/targetFunctions/common/loopMatlabCustomLayers/sourceCompile

% First get the RAT root directory
% root = getappdata(0,'root');

% Get a list of all the paths currently on paths list...
% pathCell = regexp(path, pathsep, 'split');

% Choose the relevant directory based on the input... 
% switch which
%     case 'mex'
%         addDir = fullfile(root,'targetFunctions','common','loopMatlabCustomLayers','mexCompile');
%         rmDir = fullfile(root,'targetFunctions','common','loopMatlabCustomLayers','sourceCompile');
%     otherwise
%         addDir = fullfile(root,'targetFunctions','common','loopMatlabCustomLayers','sourceCompile');
%         rmDir = fullfile(root,'targetFunctions','common','loopMatlabCustomLayers','mexCompile');
% end

% Add the 'add dir' if it is not currently on the Matlab path list..
% if ~any(strcmpi(addDir,pathCell))
%     addpath(addDir);
%     fprintf('Added directory %s to path \n',addDir);
% end

% Remove the 'revove dir' if it is currently on the Matlab path list..
% if any(strcmpi(rmDir,pathCell))
%     rmpath(rmDir);
%     fprintf('Removed directory %s from path \n',rmDir);
% end
        
end