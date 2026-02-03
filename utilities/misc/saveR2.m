
function saveR2(dirName,problem,results,controls)

% Saves the current project in RasCAL2 format...

arguments
    dirName {mustBeText}
    problem {mustBeA(problem, 'projectClass')}
    results 
    controls {mustBeA(controls, 'controlsClass')}
end

% Check whether the save directory exists, create it if necessary
if exist(dirName,'dir') ~= 7
    mkdir(dirName);
end
currentDir = pwd; % Save the current directory name

% Do some custom file housekeeping. We need to copy these to our new
% folder if there are any..
filesTable = problem.customFile.varTable;
for i = size(filesTable,1)
    thisFile = fullfile(filesTable{i,'Path'},filesTable{i,'Filename'});
    copyfile(thisFile,dirName)

    % Change the paths of our custom files in projectClass to point to our
    % new files..
    problem.setCustomFile(i,'path',fullfile(currentDir,dirName));
end

% Go to our new directory and export the jsons...
cd(dirName);
projectToJson(problem,'project.json');
resultsToJson(results,'results.json');
controlsToJson(controls,'controls.json');

% Go back to our original dir and we are done...
cd(currentDir);

end