function [output,sRough] = matlabEngineCaller_customLayers(params,contrast,funcName,funcPath,bulkIn,bulkOut)


paramsLen = int16(length(params));
% dotM = strfind(funcName,'.m');
% if ~isempty(dotM)
%     funcName = funcName(1:dotM-1);
% end
%[path,funcName,extension] = fileparts(funcName);
funName = ['[total,layers] = ' funcName '(params,bulk_in,bulk_out,contrast)'];
sRough = params(1);

pathCall= ['cd ''' funcPath ''';'];

debug = 0;
if coder.target('MATLAB')
    if debug == 1
        disp('Debug');
        disp(funName);
        disp(pathCall);
        layers= 1;
    end
    dotM = strfind(funcName,'.m');
    if ~isempty(dotM)
        funcName = funcName(1:dotM-1);
    end
    fileHandle = str2func(funcName);
    [output,layers] = fileHandle(params,bulkIn,bulkOut,contrast);
else
    
    path = '/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew';

    
    incPath1 = '/usr/local/MATLAB/R2020a/extern/include';
    %incPath2 = '/usr/include/openmpi-x86_64';
    
    linkPath1 = '/usr/local/MATLAB/R2020a/bin/glnxa64';
    linkFile1 = 'libeng.so';
    linkFile2 = 'libmx.so';
    
    source1 = 'matlabCallFun.c';
    %source2 = 'matlabCallFun.h';
    
    %source1 = 'matlabCallFun.c';
    %source2 = 'matlabCallFun.h';
    
    libPriority = '';
    libPreCompiled = true;
    libLinkOnly = true;

    %coder.cinclude(source2);
    coder.updateBuildInfo('addSourceFiles',source1);
    %coder.updateBuildInfo('addSourceFiles',source2);
    coder.updateBuildInfo('addSourcePaths',path);
    coder.updateBuildInfo('addIncludePaths',incPath1);
    %coder.updateBuildInfo('addIncludePaths',incPath2);
    coder.updateBuildInfo('addLinkObjects',linkFile1,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    coder.updateBuildInfo('addLinkObjects',linkFile2,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    
    %Need to reserve some meory for the referencenced variables
    outp = zeros(1000,3);
    nLayers = 0;
    
    coder.ceval('matlabCallFun', params, paramsLen, funName, pathCall, bulkIn, bulkOut, contrast, coder.wref(outp), coder.wref(nLayers));
    
    rowCount = 1;
    colCount = 1;
    
    m = size(outp,1);
    n = size(outp,3);
    
    %reshape the output to [layers * 3] array
    if (nLayers >= 1)
        output = zeros(nLayers,3);
        for i = 1:(nLayers*3)
            thisVal = outp(i);  %Make use of Matlab linear indexing.
            output(rowCount,colCount) = thisVal;
            rowCount = rowCount + 1;
            if rowCount == (nLayers+1)
                rowCount = 1;
                colCount = colCount + 1;
            end
        end
    else
        output = [1 1 1];
        sRough = 1;
    end

end
