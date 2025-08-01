
% Test the save and load of jsons....
problem = standardLayersDSPCScript();
checkJsons(problem);

problem = customLayersDSPCScript();
checkJsons(problem);

problem = domainsStandardLayersScript();
checkJsons(problem);

function checkJsons(problem)

% Make controls...
controls = controlsClass();
controls.display = 'final';

% Check it runs...
[problem,results] = RAT(problem,controls);

% Plot what we have..
figure(1); clf
plotRefSLD(problem,results)

% Try saving a loading of problem and controls...
projectToJson(problem,'problemSaveTest.json');
controlsToJson(controls,'controlsSaveTest.json');

% Load them back....
problem_reload = jsonToProject('problemSaveTest.json');
controls_reload = jsonToControls('controlsSaveTest.json');

% Check they still run....
try
    [problemCheck, resultsCheck] = RAT(problem_reload, controls_reload);
catch
    error('problem and controls reload failed');
end
figure(1); plotRefSLD(problemCheck, resultsCheck);
disp('problem and controls reload run normally');

% Verify that the results from the reloaded problem and controls match the original results
if isequal(results, resultsCheck)
    disp('Reloaded problem and controls produce the same results.');
else
    error('Warning: Results do not match after reload.');
end

% Try the results save and load
% Save the results to a JSON file
resultsToJson(results, 'resultsSaveTest.json');

% Load the results back in
results_reload = jsonToResults('resultsSaveTest.json');

% Check the results are the same
if isequal(results, results_reload)
    disp('Reloaded results match the original results.');
else
    checkresults(results,results_reload);
end

% Plot to check....
figure(1); plotRefSLD(problem,results);

% Clean up...
files = {'problemSaveTest.json','controlsSaveTest.json','resultsSaveTest.json'};
for i = 1:length(files)
    delete(files{i});
end

close all

end