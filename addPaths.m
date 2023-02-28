
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

ratRoot = pwd;  % Returns base RAT directory

ratPaths = {

    fullfile(ratRoot,'API');
    fullfile(ratRoot,'API','controlsClass');
    fullfile(ratRoot,'API','outputFunction');
    fullfile(ratRoot,'API','projectClass');

    fullfile(ratRoot,'compile','DE_compile');
    fullfile(ratRoot,'compile','reflectivityCalculation');
    fullfile(ratRoot,'compile','simplex');

    fullfile(ratRoot,'minimisers','DREAM');
    fullfile(ratRoot,'minimisers','DREAM','diagnostics');
    fullfile(ratRoot,'minimisers','DREAM','functions');
    fullfile(ratRoot,'minimisers','DREAM','postprocessing');
    fullfile(ratRoot,'minimisers','generalUtils');
    fullfile(ratRoot,'minimisers','generalUtils','bayesStats');
    fullfile(ratRoot,'minimisers','simplex');
    %fullfile(ratRoot,'minimisers','DE');
    %fullfile(ratRoot,'minimisers','mcmcstat_new');
    %fullfile(ratRoot,'minimisers','mcmcstat_new','private');
    %fullfile(ratRoot,'minimisers','mcmcstat_new','src');
    %fullfile(ratRoot,'minimisers','NSMain');

    fullfile(ratRoot,'targetFunctions','common');
    fullfile(ratRoot,'targetFunctions','common','backSort');
    fullfile(ratRoot,'targetFunctions','common','callMatlabFunction');
    fullfile(ratRoot,'targetFunctions','common','callReflectivity');
    fullfile(ratRoot,'targetFunctions','common','costFunctions','chiSquared');
    fullfile(ratRoot,'targetFunctions','common','groupLayers');
    fullfile(ratRoot,'targetFunctions','common','loopCppCustomLayersWrapper');
    fullfile(ratRoot,'targetFunctions','common','loopMatlabCustomLayers','mexCompile');  
    fullfile(ratRoot,'targetFunctions','common','makeSLDProfiles');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations','Abeles');
    fullfile(ratRoot,'targetFunctions','common','resampleLayers');
    fullfile(ratRoot,'targetFunctions','common','resolutionFunctions','simpleGaussian');   
    fullfile(ratRoot,'targetFunctions','common','shiftData');
    
    fullfile(ratRoot,'targetFunctions','reflectivityCalculation');
    fullfile(ratRoot,'targetFunctions','standardTF');
    fullfile(ratRoot,'targetFunctions','standardTF','customLayers');
    fullfile(ratRoot,'targetFunctions','standardTF','customXY');
    fullfile(ratRoot,'targetFunctions','standardTF','standardLayers');
    
    fullfile(ratRoot,'tests','standardTFReflectivityCalculation');
    fullfile(ratRoot,'tests','testCommonFunctions');

    fullfile(ratRoot,'utilities');
    fullfile(ratRoot,'utilities','exceptions');
    fullfile(ratRoot,'utilities','misc');
    fullfile(ratRoot,'utilities','misc','projectClassToR1');
    fullfile(ratRoot,'utilities','plotting');

    fullfile(ratRoot,'3rdParty','paramonte');
    
};

for i = 1:length(ratPaths)
    addpath(ratPaths{i});
end

addpath(ratRoot);
setappdata(0,'ratRoot',ratRoot);
