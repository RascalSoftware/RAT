parpool();
project = openProject('RAT.prj');
reflectivity_calculation_compile_script;
suite = matlab.unittest.TestSuite.fromProject(project);
results = run(suite)
% SHUT DOWN PARALLEL POOL AFTER 
