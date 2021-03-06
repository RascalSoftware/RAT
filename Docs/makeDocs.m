

addpath('/home/arwel/Documents/RascalDev/m2html');

ratRoot = '/home/arwel/Documents/RascalDev/RAT'; %Linux
ratRoot = 'RAT';

ratPaths = {fullfile(ratRoot,'targetFunctions','common');
    fullfile(ratRoot,'targetFunctions','common','backSorts');
    fullfile(ratRoot,'targetFunctions','common','callModules');
    fullfile(ratRoot,'targetFunctions','common','callReflectivity');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations','Abeles');
    fullfile(ratRoot,'targetFunctions','common','Resolution Functions','Simple_Gaussian');
    fullfile(ratRoot,'targetFunctions','common','costFunctions','chiSquared');
    fullfile(ratRoot,'targetFunctions','common','groupLayers');
    fullfile(ratRoot,'targetFunctions','common','makeSLDProfiles');
    fullfile(ratRoot,'targetFunctions','common','shiftData');
    fullfile(ratRoot,'targetFunctions','common','standard_layers_mod');
    fullfile(ratRoot,'targetFunctions','common','unpackParams');
    fullfile(ratRoot,'targetFunctions','common','legacyChanges');
    fullfile(ratRoot,'targetFunctions','common','resampleLayers');
    fullfile(ratRoot,'targetFunctions','common','matlabEngineCaller_customLayers');

    fullfile(ratRoot,'targetFunctions','standard_TF');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_stanLay');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_stanLay');

    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_custLay');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_custXY');    
    fullfile(ratRoot,'API');
    fullfile(ratRoot,'API','reflectivity_calculation');
    %fullfile(ratRoot,'API','outputFcn');
    %fullfile(ratRoot,'API','problemDef_class');
    %fullfile(ratRoot,'API','controlsDef_class');
    %fullfile(ratRoot,'tests');
    %fullfile(ratRoot,'minimisers','simplex');
    %fullfile(ratRoot,'minimisers','generalUtils');
    %fullfile(ratRoot,'minimisers','DE');
    %fullfile(ratRoot,'minimisers','NSMain');
    %fullfile(ratRoot,'minimisers','mcmcstat');
    %fullfile(ratRoot,'utilities');
    %fullfile(ratRoot,'utilities','plotting');
    %fullfile(ratRoot,'utilities','testing');
};

ignores = {fullfile(ratRoot,'targetFunctions','common','backSorts','old');
    fullfile(ratRoot,'targetFunctions','common','callModules','old');
    fullfile(ratRoot,'targetFunctions','common','callReflectivity','old');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations','old');
    fullfile(ratRoot,'targetFunctions','common','reflectivityCalculations','Abeles','old');
    fullfile(ratRoot,'targetFunctions','common','Resolution Functions','Simple_Gaussian','old');
    fullfile(ratRoot,'targetFunctions','common','costFunctions','chiSquared','old');
    fullfile(ratRoot,'targetFunctions','common','groupLayers','old');
    fullfile(ratRoot,'targetFunctions','common','makeSLDProfiles','old');
    fullfile(ratRoot,'targetFunctions','common','shiftData','old');
    fullfile(ratRoot,'targetFunctions','common','standard_layers_mod','old');
    fullfile(ratRoot,'targetFunctions','common','unpackParams','old');
    fullfile(ratRoot,'targetFunctions','common','legacyChanges','old');
    fullfile(ratRoot,'targetFunctions','common','resampleLayers','old');
    fullfile(ratRoot,'targetFunctions','common','matlabEngineCaller_customLayers','old');
    fullfile(ratRoot,'targetFunctions','common','%resampleLayers');
    fullfile(ratRoot,'targetFunctions','devel');
    fullfile(ratRoot,'targetFunctions','standard_TF','old');
    fullfile(ratRoot,'targetFunctions','standard_TF','standardTF_stanLay','old');
    fullfile(ratRoot,'targetFunctions','common','%matlabEngineCaller_customLayers');
    fullfile(ratRoot,'targetFunctions','common','matlabEngineCaller_customLayers','old');
    fullfile(ratRoot,'codegen');
    fullfile(ratRoot,'Sandbox');
    fullfile(ratRoot,'.git');
    fullfile(ratRoot,'API','codegen');
    fullfile(ratRoot,'API','reflectivity_calculation_compile');
    fullfile(ratRoot,'API','tests');
};

docDir = fullfile(ratRoot,'Docs','doc');

m2html('mfiles',ratPaths,'ignoreddir',ignores, 'htmldir',docDir, 'recursive','on', 'global','on',... 
          'template','frame', 'index','menu', 'graph','on','source','on');




