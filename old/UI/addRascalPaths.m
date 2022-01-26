
ratRoot = getappdata(0,'ratRoot');
rascalPath = fullfile(ratRoot,'UI');
setappdata(0,'rascalPath',rascalPath);

% Add matlab paths
rascalPaths = {fullfile(rascalPath,'Rascal_functions');
    fullfile(rascalPath,'Rascal_functions','UI','mainGUI');
    };

for i = 1:length(rascalPaths)
    addpath(rascalPaths{i});
end

% Debug paths stuff
addpath '/Users/arwel/Documents/coding/RAT/UI/Rascal_functions/UI/mainGUI';


% Add Java paths
% javaaddpath (fullfile(rascalPath,'javaSources','SplashWindow1','dist','SplashWindow1.jar'));
% javaaddpath (fullfile(rascalPath,'javaSources','openGenieWindow','JavaLibrary37','dist','openGenieWindow.jar'));
% 
% javaaddpath (fullfile(rascalPath,'javaSources','fitControlsPanel','dist','fitControlsPanel.jar'));
% javaaddpath (fullfile(rascalPath,'javaSources','BayesGui','dist','BayesGui.jar'));
% javaaddpath (fullfile(rascalPath,'javaSources','editProjectGui','dist','editProjectGui.jar'));
% javaaddpath (fullfile(rascalPath,'javaSources','JXLayer','filters.jar'));
% javaaddpath (fullfile(rascalPath,'javaSources','newMDI','dist','newMDI.jar'));
% javaaddpath (fullfile(rascalPath,'javaSources','newMatlabChartConstructs','newMatlabChartConstructs','dist','newMatlabChartConstructs.jar'));
% javaaddpath (fullfile(rascalPath,'javaSources','RasCALTables','dist','RasCALTables.jar'));
% javaaddpath (fullfile(rascalPath,'javaSources','JXLayer','jxlayer.jar'));
javaaddpath (fullfile(rascalPath,'javaSources','mainGuiDetailsFrame','dist','mainGuiDetailsFrame.jar'));
javaaddpath (fullfile(rascalPath,'javaSources','newMDI','dist','newMDI.jar'));
javaaddpath (fullfile(rascalPath,'javaSources','RasCALTables','dist','RasCALTables.jar'));
javaaddpath (fullfile(rascalPath,'RascalClasses','jfreechart-1.5.x','target','jfreechart-1.5.4-SNAPSHOT.jar',''));
javaaddpath (fullfile(rascalPath,'RascalClasses','swing-layout-1.0.2.jar'));

% Load in the relevant icons
hourglassBusy = javax.swing.ImageIcon(fullfile(rascalPath,'Rascal_functions','Hourglass.gif'));
hourglassBusy = javaObjectEDT(hourglassBusy);
setappdata(0,'hourglassBusy',hourglassBusy);

stopIcon = javax.swing.ImageIcon(fullfile(rascalPath,'Rascal_functions','stop.jpg'));
stopIcon = javaObjectEDT(stopIcon);
setappdata(0,'stopIcon',stopIcon);

readyIcon = javax.swing.ImageIcon(fullfile(rascalPath,'Rascal_functions','Ready.gif'));
readyIcon = javaObjectEDT(readyIcon);
setappdata(0,'readyIcon',readyIcon);

