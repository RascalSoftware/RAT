% Copies all files required to build cpp to 'cppDeploy' folder
[~, ~, ~] = rmdir('compile/fullCompile/cppDeploy', 's');
load compile/fullCompile/codegen/lib/RATMain/buildInfo.mat;
packNGo(buildInfo,'fileName','deploy.zip');
unzip('compile/fullCompile/deploy.zip', 'compile/fullCompile/cppDeploy');

% Copy events
mkdir('compile/fullCompile/cppDeploy/events/');
copyfile('compile/events/eventManager.cpp', 'compile/fullCompile/cppDeploy/events/eventManager.cpp');
copyfile('compile/events/eventManager.h', 'compile/fullCompile/cppDeploy/events/eventManager.h');
copyfile('compile/events/eventManagerImpl.hpp', 'compile/fullCompile/cppDeploy/events/eventManagerImpl.hpp');

% Clean up
delete 'compile/fullCompile/deploy.zip' 'compile/fullCompile/cppDeploy/buildInfo.mat'...
       'compile/fullCompile/cppDeploy/rtw_proj.tmw' 'compile/fullCompile/cppDeploy/defines.txt'
       'compile/fullCompile/cppDeploy/RATMain.a';
