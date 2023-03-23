root = pwd;

paths = {

    fullfile(root,'API');
    fullfile(root,'API','controlsClass');
    fullfile(root,'API','enums');
    fullfile(root,'API','outputFunction');
    fullfile(root,'API','projectClass');
    fullfile(root,'API','projects');

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
    fullfile(root,'tests','testProjectConversion');

    fullfile(root,'utilities');
    fullfile(root,'utilities','exceptions');
    fullfile(root,'utilities','misc');
    fullfile(root,'utilities','plotting');
    
    fullfile(root,'examples', 'standardLayers');
    fullfile(root,'examples', 'customLayers');
    fullfile(root,'examples', 'customXY');
    fullfile(root,'examples', 'manual', 'DSPCCustomLayers');
    fullfile(root,'examples', 'manual', 'DSPCStandardLayers');

    fullfile(root,'3rdParty','paramonte');
    
};

for i = 1:length(paths)
    rmpath(paths{i});
end
