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

paths = {

    fullfile(root,'API');
    fullfile(root,'API','controlsClass');
    fullfile(root,'API','enums');
    fullfile(root,'API','outputFunction');
    fullfile(root,'API','projectClass');

    fullfile(root,'compile','DE');
    fullfile(root,'compile','reflectivityCalculation');
    fullfile(root,'compile','simplex');

    fullfile(root,'minimisers','DREAM');
    fullfile(root,'minimisers','DREAM','diagnostics');
    fullfile(root,'minimisers','DREAM','functions');
    fullfile(root,'minimisers','DREAM','postprocessing');
    fullfile(root,'minimisers','generalUtils');
    fullfile(root,'minimisers','generalUtils','bayesStats');
    fullfile(root,'minimisers','simplex');
    %fullfile(root,'minimisers','DE');
    %fullfile(root,'minimisers','mcmcstat_new');
    %fullfile(root,'minimisers','mcmcstat_new','src');
    %fullfile(root,'minimisers','NSMain');

    fullfile(root,'targetFunctions','common');
    fullfile(root,'targetFunctions','common','backSort');
    fullfile(root,'targetFunctions','common','callMatlabFunction');
    fullfile(root,'targetFunctions','common','callReflectivity');
    fullfile(root,'targetFunctions','common','costFunctions','chiSquared');
    fullfile(root,'targetFunctions','common','groupLayers');
    fullfile(root,'targetFunctions','common','loopCppCustomLayersWrapper');
    fullfile(root,'targetFunctions','common','loopMatlabCustomLayers','mexCompile');  
    fullfile(root,'targetFunctions','common','makeSLDProfiles');
    fullfile(root,'targetFunctions','common','reflectivityCalculations');
    fullfile(root,'targetFunctions','common','reflectivityCalculations','abeles');
    fullfile(root,'targetFunctions','common','resampleLayers');
    fullfile(root,'targetFunctions','common','resolutionFunctions','simpleGaussian');   
    fullfile(root,'targetFunctions','common','shiftData');
    
    fullfile(root,'targetFunctions','reflectivityCalculation');
    fullfile(root,'targetFunctions','standardTF');
    fullfile(root,'targetFunctions','standardTF','customLayers');
    fullfile(root,'targetFunctions','standardTF','customXY');
    fullfile(root,'targetFunctions','standardTF','standardLayers');
    
    fullfile(root,'tests','standardTFReflectivityCalculation');
    fullfile(root,'tests','testCommonFunctions');

    fullfile(root,'utilities');
    fullfile(root,'utilities','exceptions');
    fullfile(root,'utilities','misc');
    fullfile(root,'utilities','misc','projectClassToR1');
    fullfile(root,'utilities','plotting');

    fullfile(root,'3rdParty','paramonte');
    
};

for i = 1:length(paths)
    addpath(paths{i});
end

addpath(root);
setappdata(0,'root',root);
