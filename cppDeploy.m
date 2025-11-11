% Copies all files required to build cpp to 'cppDeploy' folder
root = getappdata(0, 'root');
compileDir = fullfile(root, 'compile');
curPath = pwd;
cd(compileDir)
[~, ~, ~] = rmdir('fullCompile/cppDeploy', 's');
load fullCompile/codegen/lib/RATMain/buildInfo.mat;
packNGo(buildInfo,'fileName','deploy.zip');
unzip('fullCompile/deploy.zip', 'fullCompile/cppDeploy');

% Copy events
mkdir('fullCompile/cppDeploy/events/');
copyfile('events/eventManager.cpp', 'fullCompile/cppDeploy/events/eventManager.cpp');
copyfile('events/eventManager.h', 'fullCompile/cppDeploy/events/eventManager.h');
copyfile('events/eventManagerImpl.hpp', 'fullCompile/cppDeploy/events/eventManagerImpl.hpp');

% Clean up
delete 'fullCompile/deploy.zip' 'fullCompile/cppDeploy/buildInfo.mat'...
       'fullCompile/cppDeploy/rtw_proj.tmw' 'fullCompile/cppDeploy/defines.txt'...
       'fullCompile/cppDeploy/RATMain.a' 'fullCompile/cppDeploy/RATMain.lib';
cd(curPath);
