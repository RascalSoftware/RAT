function [allLayers, allRoughs] = loopCaller(pars,bulkIn,bulkOut,numberOfContrasts)

fileName = 'debugMfile';
filePath  = '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_loop_single/';

% allRoughs = zeros(1,1);
% allLayers = cell(1,1);

%for i = 1:numberOfContrasts
    i = 1;
    params = pars{i};
    in = bulkIn(i);
    out = bulkOut(i);
    [layersList,sRoughs] = matlabEngineCaller_customLayers(params,i,fileName,filePath,in,out);
    allLayers = layersList;
    allRoughs = sRoughs;
%end

end



