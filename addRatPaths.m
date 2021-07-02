ratRoot = '/Users/arwel/Documents/coding/RAT'; %OSX
%ratRoot = '/home/arwel/Documents/RascalDev/RAT'; %Linux

ratPaths = {fullfile(ratRoot,'targetFunctions','common');
    fullfile(ratRoot,'targetFunctions','common','backSorts');
    %fullfile(ratRoot,'targetFunctions','common','callModules');
    fullfile(ratRoot,'targetFunctions','common','callReflectivity');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations','Abeles');
    fullfile(ratRoot,'targetFunctions','common','Resolution_Functions','Simple_Gaussian');
    fullfile(ratRoot,'targetFunctions','common','costFunctions','chiSquared');
    fullfile(ratRoot,'targetFunctions','common','groupLayers');
    fullfile(ratRoot,'targetFunctions','common','makeSLDProfiles');
    fullfile(ratRoot,'targetFunctions','common','shiftData');
    %fullfile(ratRoot,'targetFunctions','common','standard_layers_mod');
    %fullfile(ratRoot,'targetFunctions','common','unpackParams');
    fullfile(ratRoot,'targetFunctions','common','legacyChanges');
    fullfile(ratRoot,'targetFunctions','common','resampleLayers');
    %fullfile(ratRoot,'targetFunctions','common','matlabEngineCaller_customLayers');
    fullfile(ratRoot,'targetFunctions','common','callMatlabFunction');
    fullfile(ratRoot,'targetFunctions','common','jacobianEst');
    fullfile(ratRoot,'compile','reflectivity_calculation_compile_new');
    fullfile(ratRoot,'compile','dram_compile');

    %/home/arwel/Documents/RascalDev/RAT/targetFunctions/reflectivity_calculation
    fullfile(ratRoot,'targetFunctions','reflectivity_calculation');
    fullfile(ratRoot,'targetFunctions','standard_TF');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_stanLay');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_stanLay');

    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_custLay');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_custXY');    
    fullfile(ratRoot,'API');

    fullfile(ratRoot,'API','outputFcn');
    %fullfile(ratRoot,'API','problemDef_class');
    fullfile(ratRoot,'API','controlsDef_class');
    fullfile(ratRoot,'API','newInputClasses');
    fullfile(ratRoot,'tests');
    fullfile(ratRoot,'minimisers','simplex');
    fullfile(ratRoot,'minimisers','generalUtils');
    fullfile(ratRoot,'minimisers','DE');
    fullfile(ratRoot,'minimisers','NSMain');
    fullfile(ratRoot,'minimisers','mcmcstat_new');
    fullfile(ratRoot,'minimisers','generalUtils','bayesStats');
    fullfile(ratRoot,'utilities');
    fullfile(ratRoot,'utilities','plotting');
    fullfile(ratRoot,'utilities','testing');
};

for i = 1:length(ratPaths)
    addpath(ratPaths{i});
end

addpath(ratRoot);

disp('debug');


    
