

addpath('/Users/arwel/Documents/coding/RAT/Docs/m2html');

ratRoot = '/Users/arwel/Documents/coding/RAT/'; %Linux
ratRoot = 'RAT';

ratPaths = {fullfile(ratRoot,'targetFunctions','common');
    fullfile(ratRoot,'targetFunctions','common','backSorts');
    fullfile(ratRoot,'targetFunctions','common','callModules');
    fullfile(ratRoot,'targetFunctions','common','callReflectivity');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations','Abeles');
    fullfile(ratRoot,'targetFunctions','common','Resolution_Functions','Simple_Gaussian');
    fullfile(ratRoot,'targetFunctions','common','costFunctions','chiSquared');
    fullfile(ratRoot,'targetFunctions','common','groupLayers');
    fullfile(ratRoot,'targetFunctions','common','makeSLDProfiles');
    fullfile(ratRoot,'targetFunctions','common','shiftData');
    fullfile(ratRoot,'targetFunctions','common','standard_layers_mod');
    fullfile(ratRoot,'targetFunctions','common','unpackParams');
    fullfile(ratRoot,'targetFunctions','common','legacyChanges');
    fullfile(ratRoot,'targetFunctions','common','resampleLayers');
    %fullfile(ratRoot,'targetFunctions','common','matlabEngineCaller_customLayers');
    fullfile(ratRoot,'targetFunctions','common','callMatlabFunction');
    fullfile(ratRoot,'targetFunctions','common','jacobianEst');
    fullfile(ratRoot,'compile','reflectivity_calculation_compile_new');


    %/home/arwel/Documents/RascalDev/RAT/targetFunctions/reflectivity_calculation
    fullfile(ratRoot,'targetFunctions','reflectivity_calculation');
    fullfile(ratRoot,'targetFunctions','standard_TF');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_stanLay');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_stanLay');

    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_custLay');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_custXY');    
    fullfile(ratRoot,'API')};



docDir = fullfile(ratRoot,'reflectivity_calculation''Docs','reflectivityCalcDocs');

m2html_modified('mfiles',ratPaths,'htmldir',docDir, 'recursive','on', 'global','on',... 
          'template','frame', 'index','menu','graph','on','source','on');




