pwd;
addPaths;

% Save this path
thisPath = pwd;

% Go to the correct compile directory
compilePath = fullfile(thisPath,'compile','reflectivityCalculation');
cd(compilePath);

% Run the compile script whist in that directory (ensures mex file ends up
% in the correct place)
reflectivityCalculationCompileScript

% Now we need to change the defined paths to generate the source code. At
% the moment, RAT uses a 'feval' call to the base workspace to excecute
% Matlab custom model files. This will fail for standalone codegen. So, we
% need to change RAT paths to exclude these files from the source generation
% setCompilePaths('lib');
% 
% % Now generate the source....
% reflectivityCalculationCodeOnlyScript;

% Finally, change the paths back or the tests might fail...
% setCompilePaths('mex');

compilePath = fullfile(thisPath, 'compile', 'events');
cd(compilePath);

eventCompileScript;

% Return to RAT root directory
cd(thisPath);
