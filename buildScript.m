addPaths;
root = getappdata(0,'root');

% Save this path
thisPath = pwd;

% Go to the correct compile directory
compilePath = fullfile(root,'compile','reflectivityCalculation');
cd(compilePath);
reflectivityCalculationMexBuild;

compilePath = fullfile(root,'compile','fullCompile');
cd(compilePath);
ratMainMexBuild;
ratMainCodeGen;

compilePath = fullfile(root,'compile','customWrapper');
cd(compilePath);
wrapperMexBuild;

% Return to RAT root directory
cd(thisPath);
