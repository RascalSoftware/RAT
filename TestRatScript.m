parpool();
addRatPaths;
reflectivity_calculation_compile_script;
suite = matlab.unittest.TestSuite.fromFolder('./testSuite');
results = run(suite)
% SHUT DOWN PARALLEL POOL AFTER 
