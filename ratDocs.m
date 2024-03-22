

% Opens the documentation in the Matlab browser.

% Get the root path..
[thisPath,~,~] = fileparts(mfilename('fullpath')); % Could also use getappdata(0,'root') here

% Build the full filename of the index
indexLoc = fullfile(thisPath,'docs','build','html','index.html');

% open if present, error if not
if ~exist(indexLoc,'file')
    error('Documentation does not seem to have been built');
else
    web(indexLoc);
end

