% Modifed so that the gerenated mex file ends up in the correct directory
% rather that ther RAT root directory
%
% Last modified - AVH 26/01/22
pwd
addRatPaths;

% NEED TO ADD THE M2HTML BUILD SCRIPT HERE BUT NODES DONT GOT M2HTML so WE NEED TO INSTALL THAT FIRST
% THIS IS THE COMMAND TO GENERATE THE m2HTML DOCUMENTATION THIS NEEDS TO HAPPEN FROM RAT ROOT DIRECTORY 
% m2html('mfiles',{'./targetFunctions','./API'},'htmldir','m2htmlGeneratedDocs', 'recursive','on', 'global','on','template','frame', 'index','menu','ignoredDir',{'docs','Docs_old','tests','testSuite'},'graph','on','source','on');

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