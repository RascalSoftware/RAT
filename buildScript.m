pwd;
addPaths;

% Save this path
thisPath = pwd;

% Go to the correct compile directory
compilePath = fullfile(thisPath,'compile','reflectivityCalculation');
cd(compilePath);
reflectivityCalculationMexBuild;

compilePath = fullfile(thisPath,'compile','fullCompile');
cd(compilePath);
ratMainMexBuild;
ratMainCodeGen;

compilePath = fullfile(thisPath,'compile','customWrapper');
cd(compilePath);
wrapperMexBuild;

% Return to RAT root directory
cd(thisPath);
