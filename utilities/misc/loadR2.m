
function [problem,varargout] = loadR2(dirName)
% Loads in a RasCAL2 project...

% Load the project...
projectFile = fullfile(dirName,'project.json');
problem = jsonToProject(projectFile);

% If there is a second argument, also load results..
if nargout > 1
    resultsFile = fullfile(dirName, 'results.json');
    varargout{1} = jsonToResults(resultsFile);
end

end