pwd;
addPaths;

% Save this path
thisPath = pwd;

% Go to the correct compile directory
compilePath = fullfile(thisPath,'compile','reflectivityCalculation');
cd(compilePath);
reflectivityCalculationCompileScript

compilePath = fullfile(thisPath,'compile','fullCompile');
cd(compilePath);
ratMainCompileScript;
ratMainCodeGen;

% Finally, change the paths back or the tests might fail...
compilePath = fullfile(thisPath, 'compile', 'events');
cd(compilePath);
eventCompileScript;

compilePath = fullfile(thisPath, 'compile', 'customWrapper');
cd(compilePath);
wrapperCompileScript;

% Return to RAT root directory
cd(thisPath);
