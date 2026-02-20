
function [problem,varargout] = loadR2(dirName)
    % Loads in a RasCAL2 project.
    %
    % Examples
    % --------
    % >>> project = loadR2("r2_example");  % Load project from a given directory
    % >>> [project, results] = loadR2("r2_example");  % Load project and result
    %
    % Parameters
    % ----------
    % dirName : string or char array
    %    The path of the R2 project folder.
    %
    % Returns
    % -------
    % project : projectClass
    %    An instance of the ``projectClass`` which should be equivalent to the given R2 problem.
    % results : struct
    %    An optional output. A struct which contains the R2 results if present.
    
    arguments
        dirName {mustBeTextScalar, mustBeNonempty}
    end
    % Load the project.
    projectFile = fullfile(dirName,'project.json');
    problem = jsonToProject(projectFile);
    
    % If there is a second output, also load results.
    if nargout > 1
        resultsFile = fullfile(dirName, 'results.json');
        if exist(resultsFile, 'file') == 2
            varargout{1} = jsonToResults(resultsFile);
        else
            varargout{1} = struct();
            warning("result.json was not found in the project.");
        end
    end

end