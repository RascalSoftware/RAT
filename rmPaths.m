root = pwd;

paths = {

    fullfile(root,'API');
    fullfile(root,'API','enums');
    fullfile(root,'API','events');
    fullfile(root,'API','projectClass');

    fullfile(root,'compile');
    fullfile(root,'compile','customWrapper');
    fullfile(root,'compile','events');
    fullfile(root,'compile','exceptions');
    fullfile(root,'compile','fullCompile');
    fullfile(root,'compile','reflectivityCalculation');

    fullfile(root,'minimisers','DE');
    fullfile(root,'minimisers','DREAM');
    fullfile(root,'minimisers','DREAM','diagnostics');
    fullfile(root,'minimisers','DREAM','functions');
    fullfile(root,'minimisers','DREAM','postprocessing');
    fullfile(root,'minimisers','generalUtils');
    fullfile(root,'minimisers','generalUtils','bayesStats');
    fullfile(root,'minimisers','NS');
    fullfile(root,'minimisers','simplex');

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
    
    fullfile(root,'utilities');
    fullfile(root,'utilities','misc');
    fullfile(root,'utilities','plotting');

    fullfile(root,'3rdParty','paramonte');
    
};

for i = 1:length(paths)
    rmpath(paths{i});
end
