
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
currentDir = pwd;
cd(dirName);

% Export the jsons...
projectToJson(problem,'project.json');
resultsToJson(results,'result.json');
controlsToJson(controls,'controls.json');

% Now do some custom file housekeeping. We need to copy these to our new
% folder if there are any..
cd(currentDir)
filesTable = problem.customFile.varTable;

for i = size(filesTable,1)
    thisFile = fullfile(filesTable{i,'Path'},filesTable{i,'Filename'});
    copyfile(thisFile,dirName)
end

end