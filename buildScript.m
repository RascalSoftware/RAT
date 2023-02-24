pwd
addPaths;

% NEED TO ADD THE M2HTML BUILD SCRIPT HERE BUT NODES DONT GOT M2HTML so WE NEED TO INSTALL THAT FIRST
% THIS IS THE COMMAND TO GENERATE THE m2HTML DOCUMENTATION THIS NEEDS TO HAPPEN FROM RAT ROOT DIRECTORY 
%m2html('mfiles',{'./targetFunctions','./API'},'htmldir','m2htmlGeneratedDocs', 'recursive','on', 'global','on','template','frame', 'index','menu','ignoredDir',{'docs','Docs_old','tests','testSuite'},'graph','on','source','on');
% or use can just use buildM2htmlDocs.m file

% Save this path
thisPath = pwd;

% Go to the correct compile directory
compilePath = fullfile(thisPath,'compile','reflectivity_calculation_compile_new');
cd(compilePath);

% Run the compile script whist in that directory (ensures mex file ends up
% in the correct place)
reflectivity_calculation_compile_script

% Now we need to change the defined paths to generate the source code. At
% the moment, RAT uses a 'feval' call to the base workspace to excecute
% Matlab custom model files. This will fail for standalone codegen. So, we
% need to change RAT paths to exclude these files from the source generation
setCompilePaths('lib');

% Now generate the source....
reflectivity_calculation_codeOnly_script;

% Finally, change the paths back or the tests might fail...
setCompilePaths('mex');

% Return to RAT root directory
cd(thisPath);

%% Algorithm compiles..


