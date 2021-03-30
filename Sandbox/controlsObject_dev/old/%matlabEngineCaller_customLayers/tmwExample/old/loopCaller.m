function [allLayers, allRoughs] = loopCaller(pars,bulkIn,bulkOut,numberOfContrasts)

fileName = 'debugMfile';
filePath  = '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample';

allRoughs = zeros(numberOfContrasts,1);
allLayers = cell(numberOfContrasts,1);

for i = 1:numberOfContrasts
    thisParams = pars{i};
    in = bulkIn(i);
    out = bulkOut(i);
    [layersList,sRoughs] = matlabEngineCaller_customLayers(thisParams,i,fileName,filePath,in,out);
    allLayers{i} = layersList;
    allRoughs(i) = sRoughs;
end

end



