% Modifed so that the gerenated mex file ends up in the correct directory
% rather that ther RAT root directory
%
% Last modified - AVH 20/10/21
pwd
addRatPaths;

% Save this path
thisPath = pwd;

disp($(START_DIR))

% Go to the correct compile directory
cd('compile/reflectivity_calculation_compile_new/');

% Run the compile script whist in that directory (ensures mex file ends up
% in the correct place)
reflectivity_calculation_compile_script

% Return to RAT root directory
%cd(thisPath);