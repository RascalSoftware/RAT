ratRoot = pwd;

ratPaths = {

    fullfile(ratRoot,'API');
    fullfile(ratRoot,'API','controlsClass');
    fullfile(ratRoot,'API','outputFunction');
    fullfile(ratRoot,'API','projectClass');

    fullfile(ratRoot,'compile','DE_compile');
    fullfile(ratRoot,'compile','reflectivityCalculation');
    fullfile(ratRoot,'compile','simplex');

    fullfile(ratRoot,'minimisers','DE');
    fullfile(ratRoot,'minimisers','generalUtils');
    fullfile(ratRoot,'minimisers','generalUtils','bayesStats');
    fullfile(ratRoot,'minimisers','mcmcstat_new');
    fullfile(ratRoot,'minimisers','mcmcstat_new','src');
    fullfile(ratRoot,'minimisers','NSMain');
    fullfile(ratRoot,'minimisers','simplex');

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
    rmpath(ratPaths{i});
end
