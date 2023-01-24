
% Add the paths needed for RAT to the current Matlab session.
% This pust be run from the base RAT directory.

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

ratPaths = {fullfile(ratRoot,'targetFunctions','common');
    fullfile(ratRoot,'targetFunctions','common','backSorts');
    fullfile(ratRoot,'targetFunctions','common','callMatlabFunction');
    fullfile(ratRoot,'targetFunctions','common','callReflectivity');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations','Abeles');
    fullfile(ratRoot,'targetFunctions','common','Resolution_Functions','Simple_Gaussian');
    fullfile(ratRoot,'targetFunctions','common','costFunctions','chiSquared');
    fullfile(ratRoot,'targetFunctions','common','groupLayers');
    fullfile(ratRoot,'targetFunctions','common','makeSLDProfiles');
    fullfile(ratRoot,'targetFunctions','common','shiftData');
    fullfile(ratRoot,'targetFunctions','common','legacyChanges');
    fullfile(ratRoot,'targetFunctions','common','resampleLayers');
    % fullfile(ratRoot,'targetFunctions','common','callCustomLayers');
    % fullfile(ratRoot,'targetFunctions','common','callMatlabFunction');
    fullfile(ratRoot,'targetFunctions','common','loopMatlabCustomLayers','mexCompile');  
    fullfile(ratRoot,'targetFunctions','common','loopCppCustlayWrapper');

    
    fullfile(ratRoot,'compile','reflectivity_calculation_compile_new');
    fullfile(ratRoot,'compile','simplex_compile');
    fullfile(ratRoot,'compile','DE_compile');

    fullfile(ratRoot,'targetFunctions','reflectivity_calculation');
    fullfile(ratRoot,'targetFunctions','standard_TF');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_stanLay');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_custLay');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_custXY');    
       
    %fullfile(ratRoot,'targetFunctions','domains_TF');
    %fullfile(ratRoot,'targetFunctions','domains_TF','domainsTF_stanLay');
    %fullfile(ratRoot,'targetFunctions','domains_TF','domainsTF_custLay');
    %fullfile(ratRoot,'targetFunctions','domains_TF','domainsTF_custXY');   
    
    fullfile(ratRoot,'API');
    fullfile(ratRoot,'API','outputFcn');
    fullfile(ratRoot,'API','controlsDef');
    fullfile(ratRoot,'API','projectClass');
    fullfile(ratRoot,'tests');
    fullfile(ratRoot,'testSuite','testCommonFunctions');
    fullfile(ratRoot,'testSuite','standardTFReflectivityCalculation');
    fullfile(ratRoot,'minimisers','simplex');
    fullfile(ratRoot,'minimisers','generalUtils');
    fullfile(ratRoot,'minimisers','NSMain');
    fullfile(ratRoot,'minimisers','mcmcstat_new');
    fullfile(ratRoot,'minimisers','mcmcstat_new','private');
    fullfile(ratRoot,'minimisers','mcmcstat_new','src');
    fullfile(ratRoot,'minimisers','DE');
    fullfile(ratRoot,'minimisers','Paramonte');
    fullfile(ratRoot,'minimisers','generalUtils','bayesStats');
    fullfile(ratRoot,'utilities');
    fullfile(ratRoot,'utilities','plotting');
    fullfile(ratRoot,'utilities','misc');
    fullfile(ratRoot,'utilities','misc','projectClassToR1');
    
};

for i = 1:length(ratPaths)
    addpath(ratPaths{i});
end

addpath(ratRoot);
setappdata(0,'ratRoot',ratRoot);

%setRootFolder(ratRoot);





    
