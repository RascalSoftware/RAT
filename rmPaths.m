ratRoot = pwd;

ratPaths = {fullfile(ratRoot,'targetFunctions','common');
    fullfile(ratRoot,'targetFunctions','common','backSorts');
    fullfile(ratRoot,'targetFunctions','common','callModules');
    fullfile(ratRoot,'targetFunctions','common','callReflectivity');
    fullfile(ratRoot,'targetFunctions','common','chiSquared');
    fullfile(ratRoot,'targetFunctions','common','groupLayers');
    fullfile(ratRoot,'targetFunctions','common','makeSLDProfiles');
    fullfile(ratRoot,'targetFunctions','common','shiftData');
    fullfile(ratRoot,'targetFunctions','common','unpackParams');
    fullfile(ratRoot,'targetFunctions','common','resampleLayers');
    fullfile(ratRoot,'targetFunctions','common','matlabEngineCaller_customLayers');
    fullfile(ratRoot,'targetFunctions','standardTF');
    fullfile(ratRoot,'targetFunctions','standardTF','standardLayers');
    fullfile(ratRoot,'targetFunctions','standardTF','customLayers');
    fullfile(ratRoot,'targetFunctions','standardTF','customXY');    
    fullfile(ratRoot,'API');
    fullfile(ratRoot,'API','reflectivityCalculation');
    fullfile(ratRoot,'tests');
    fullfile(ratRoot,'minimisers','simplex');
    fullfile(ratRoot,'minimisers','generalUtils');
    fullfile(ratRoot,'minimisers','DE');
    fullfile(ratRoot,'minimisers','NSMain');
    fullfile(ratRoot,'utilities');
    fullfile(ratRoot,'utilities','plotting');
    fullfile(ratRoot,'utilities','testing');
    fullfile(ratRoot,'API','controlsDef');
    fullfile(ratRoot,'API','projectClass');
};


for i = 1:length(ratPaths)
    rmpath(ratPaths{i});
end

disp('debug');


    
