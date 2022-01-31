% Modifed so that the gerenated mex file ends up in the correct directory
% rather that ther RAT root directory
%
% Last modified - AVH 26/01/22
pwd
addRatPaths;

% Save this path
thisPath = pwd;

% Go to the correct compile directory
compilePath = fullfile(thisPath,'compile','reflectivity_calculation_compile_new');
cd(compilePath);

% Run the compile script whist in that directory (ensures mex file ends up
% in the correct place)
reflectivity_calculation_compile_script

% Return to RAT root directory
cd(thisPath);