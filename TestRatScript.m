% parpool();
% addRatPaths;
% reflectivity_calculation_compile_script;
% suite = matlab.unittest.TestSuite.fromFolder('./testSuite');
% results = run(suite)
% SHUT DOWN PARALLEL POOL AFTER 

% TESTING CODE


import matlab.unittest.TestSuite;
disp('Starting Parallel Pool')
% if parallel pool has already been started, continue with it
if isempty(gcp('nocreate'))
    parpool();
else
    % display how many workers are in the pool
    pool = gcp('nocreate');
    disp(['Current Parallel Pool has ' num2str(pool.NumWorkers) ' workers. No need to start.'])
end

disp('Adding paths Initiated')
addRatPaths;
disp('Adding paths Completed')
disp('Compiling RAT to mex Initiated')
% if reflectivity calculation has failed while compiling, try again
% try
% %     reflectivity_calculation_compile_script;
% catch
% %     disp('Compiling RAT to mex Failed once!')
% %     disp('Trying again')
% %     reflectivity_calculation_compile_script;
% end
disp('Compiling RAT to mex Completed')

allTests  = TestSuite.fromFolder('testSuite','IncludingSubfolders', true);
disp('Running unitTests')
run(allTests)
disp('Unit Testing Complete')