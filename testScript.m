% TESTING CODE
import matlab.unittest.TestSuite;
import matlab.unittest.plugins.CodeCoveragePlugin
import matlab.unittest.plugins.codecoverage.CoverageReport

sourceCodeFolder = {'API', 'targetFunctions', 'utilities'};
reportFolder = 'htmlcov';
reportFormat = CoverageReport(reportFolder);
p = CodeCoveragePlugin.forFolder(sourceCodeFolder, ...
                                 'Producing', reportFormat, ...
                                 'IncludingSubfolders', true);

disp('Starting Parallel Pool')
% if parallel pool has already been started, continue with it
if isempty(gcp('nocreate'))
    parpool('threads');
else
    % display how many workers are in the pool
    pool = gcp('nocreate');
    disp(['Current Parallel Pool has ' num2str(pool.NumWorkers) ' workers. No need to start.'])
end

disp('Adding paths Initiated')
addPaths;
disp('Adding paths Completed')

allTests = TestSuite.fromFolder('tests','IncludingSubfolders', true);
disp('Running unit tests')
runner = testrunner;
runner.addPlugin(p)
result = run(runner, allTests);
if(any(arrayfun(@(x) x.Failed, result)))
    error('Test failed');
end
disp('Unit Testing Complete')