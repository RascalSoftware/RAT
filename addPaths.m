% Add the paths needed for RAT to the current Matlab session.
% This must be run from the base RAT directory.

% RAT (will soon) allow use of the Paramonte library for Bayesian
% inference.
% For this to work it assumes that Paramonte is installed on your system as 
% described here  https://uk.mathworks.com/matlabcentral/fileexchange/78946-paramonte

% The installation should permanently add the Paramonte paths to your
% Matlab install (you can check by typing 'pathtool' at the Matlab command
% prompt - the Paramonte directories should be present). If not, you will
% need to add them to this file. Please see the Paramonte Docs for more
% details.

root = pwd;  % Returns base RAT directory
eventCompilePath = fullfile(root,'compile','events');
paths = {

    fullfile(root,'API');
    fullfile(root,'API','enums');
    fullfile(root,'API','events');
    fullfile(root,'API','projectClass');

    eventCompilePath;
    fullfile(root,'compile','customWrapper');
    fullfile(root,'compile','reflectivityCalculation');
    fullfile(root,'compile','fullCompile');
    fullfile(root,'compile');

    fullfile(root,'minimisers','DREAM');
    fullfile(root,'minimisers','DREAM','diagnostics');
    fullfile(root,'minimisers','DREAM','functions');
    fullfile(root,'minimisers','DREAM','postprocessing');
    fullfile(root,'minimisers','generalUtils');
    fullfile(root,'minimisers','generalUtils','bayesStats');
    fullfile(root,'minimisers','simplex');
    fullfile(root,'minimisers','DE');
    %fullfile(root,'minimisers','mcmcstat_new');
    %fullfile(root,'minimisers','mcmcstat_new','src');
    fullfile(root,'minimisers','NS');
    
    fullfile(root,'targetFunctions' );
    fullfile(root,'targetFunctions','common');
    fullfile(root,'targetFunctions','common','callReflectivity');
    fullfile(root,'targetFunctions','common','costFunctions');
    fullfile(root,'targetFunctions','common','customModelFunctions');
    fullfile(root,'targetFunctions','common','groupLayers');
    fullfile(root,'targetFunctions','common','makeSLDProfiles');
    fullfile(root,'targetFunctions','common','reflectivityCalculations','abeles');
    fullfile(root,'targetFunctions','common','resampleLayers');
    fullfile(root,'targetFunctions','common','resolutionFunctions','simpleGaussian'); 
    
    fullfile(root,'tests','nonPolarisedTFReflectivityCalculation');
    fullfile(root,'tests','domainsTFReflectivityCalculation');
    fullfile(root,'tests','testCommonFunctions');
    fullfile(root,'tests','testProjectConversion');

    fullfile(root,'utilities');
    fullfile(root,'utilities','misc');
    fullfile(root,'utilities','plotting');

    fullfile(root,'3rdParty','paramonte'); 
};

for i = 1:length(paths)
    addpath(paths{i});
end

addpath(root);
setappdata(0, 'root', root);
includedir = {fullfile(root, 'compile', 'customWrapper'), eventCompilePath};
setappdata(0, 'includeDirs', includedir);

% Add the folder with the eventManager dynamic library to the system path so 
% it can be found without copying the library file to every folder  
if exist(eventCompilePath, 'dir')
    setenv("RAT_PATH", [eventCompilePath filesep]);
end
