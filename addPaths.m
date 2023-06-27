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
    fullfile(root,'API','controlsClass');
    fullfile(root,'API','enums');
    fullfile(root,'API','events');
    fullfile(root,'API','outputFunction');
    fullfile(root,'API','projectClass');

    fullfile(root,'compile','DE');
    eventCompilePath;
    fullfile(root,'compile','reflectivityCalculation');
    fullfile(root,'compile','simplex');
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
    fullfile(root,'minimisers','NSMain');

    fullfile(root,'targetFunctions','common');
    fullfile(root,'targetFunctions','common','backSort');
    fullfile(root,'targetFunctions','common','callCustomFunction');
    fullfile(root,'targetFunctions','common','callCustomFunction','callMatlabFunction');
    fullfile(root,'targetFunctions','common','callCustomFunction','callCppFunction');
    fullfile(root,'targetFunctions','common','callCustomFunction','callPythonFunction');

    fullfile(root,'targetFunctions','common','callReflectivity');
    fullfile(root,'targetFunctions','common','costFunctions','chiSquared');
    fullfile(root,'targetFunctions','common','groupLayers');

    fullfile(root,'targetFunctions','common','makeSLDProfiles');
    fullfile(root,'targetFunctions','common','reflectivityCalculations');
    fullfile(root,'targetFunctions','common','reflectivityCalculations','abeles');
    fullfile(root,'targetFunctions','common','resampleLayers');
    fullfile(root,'targetFunctions','common','resolutionFunctions','simpleGaussian');   
    fullfile(root,'targetFunctions','common','shiftData');
    fullfile(root,'targetFunctions','common','customModelsClass');
    
    fullfile(root,'targetFunctions','reflectivityCalculation');
    fullfile(root,'targetFunctions','standardTF');
    fullfile(root,'targetFunctions','standardTF','customLayers');
    fullfile(root,'targetFunctions','standardTF','customXY');
    fullfile(root,'targetFunctions','standardTF','standardLayers');
    
    fullfile(root,'tests','standardTFReflectivityCalculation');
    fullfile(root,'tests','testCommonFunctions');
    fullfile(root,'tests','testProjectConversion');

    fullfile(root,'utilities');
    fullfile(root,'utilities','exceptions');
    fullfile(root,'utilities','misc');
    fullfile(root,'utilities','plotting');

    fullfile(root,'3rdParty','paramonte'); 
};

for i = 1:length(paths)
    addpath(paths{i});
end

addpath(root);
setappdata(0, 'root', root);
includedir = strcat(" -I '", fullfile(root, 'targetFunctions', 'common', 'customModelsIncludes'), "'",...
                    " -I '", fullfile(root, 'compile', 'events'), "'");
setappdata(0, 'includeDir', includedir);

% Add the folder with the eventManager dynamic library to the system path so 
% it can be found without copying the library file to every folder  
systemPath = getenv("PATH");
if startsWith(systemPath, eventCompilePath)
    setenv("PATH", eventCompilePath + ";" + systemPath);
end
