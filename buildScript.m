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

compilePath = fullfile(thisPath, 'compile', 'customWrapper');
cd(compilePath);
wrapperCompileScript;

% Return to RAT root directory
cd(thisPath);
