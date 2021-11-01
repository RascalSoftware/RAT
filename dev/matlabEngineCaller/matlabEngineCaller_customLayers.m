function [output,sRough] = matlabEngineCaller_customLayers(params,contrast,funcName,funcPath,bulkIn,bulkOut)

% Evaluate matlab function from compiled mex using an external Matlab
% engine. This version uses the Matlab Engine API for C 
% (https://uk.mathworks.com/help/matlab/calling-matlab-engine-from-c-programs-1.html)

% In reality, we want to be using a Class via the Matleb engine API for C++
% (https://uk.mathworks.com/help/matlab/matlab_external/matlab-engine-api-for-c.html)


% Irrespective of we use Matlab or Mex, we need the same calling string.
% We put together the Matlab command string that that we will excecute
paramsLen = int16(length(params));
funName = ['[total,layers] = ' funcName '(params,bulk_in,bulk_out,contrast)'];
sRough = params(1);

% Also make a commans string to change the Matlab Path to the location of
% the Matlab function
pathCall= ['cd ''' funcPath ''';'];

debug = 0;

% If not compiled, excecute our custom function from Matlab
if coder.target('MATLAB')
    if debug == 1
        % Show our command strings
        disp('Debug');
        disp(funName);
        disp(pathCall);
    end
    
    % If the file extensin is present, strip it off
    dotM = strfind(funcName,'.m');
    if ~isempty(dotM)
        funcName = funcName(1:dotM-1);
    end
    
    % Call the function using a handle
    fileHandle = str2func(funcName);
    [output,layers] = fileHandle(params,bulkIn,bulkOut,contrast);
else
    
    % Matlab coder will compile from here
   
    
    % Path to the engine 'h' files. This is always relative to the base
    % Matlab path on any system
    incPath1 = '/Applications/MATLAB_R2021a.app/extern/include';
    
    % Link path to the Matlab shared libraries. This will vary depending on
    % the OS
    linkPath1 = '/Applications/MATLAB_R2021a.app/bin/maci64';
    
    % The libraries we need
    linkFile1 = 'libeng.dylib';
    linkFile2 = 'libmx.dylib';
    
    % The source file including Path
    thisPath = '/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller';
    source1 = 'matlabCallFun.c';
    
    %source2 = '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabCallFun.h';
    
    %source1 = 'matlabCallFun.c';
    %source2 = 'matlabCallFun.h';
    
    libPriority = '';
    libPreCompiled = true;
    libLinkOnly = true;

    %coder.cinclude(source2);
    coder.updateBuildInfo('addSourceFiles',source1);
    %coder.updateBuildInfo('addSourceFiles',source2);
    coder.updateBuildInfo('addSourcePaths',thisPath);
    coder.updateBuildInfo('addIncludePaths',incPath1);
    %coder.updateBuildInfo('addIncludePaths',incPath2);
    coder.updateBuildInfo('addLinkObjects',linkFile1,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    coder.updateBuildInfo('addLinkObjects',linkFile2,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    
    %Need to reserve some meory for the referencenced variables
    outp = zeros(100,3);
    nLayers = 0;
    
    coder.ceval('matlabCallFun', params, paramsLen, funName, pathCall, bulkIn, bulkOut, contrast, coder.wref(outp), coder.wref(nLayers));
    
    rowCount = 1;
    colCount = 1;
    
    m = size(outp,1);
    n = size(outp,2);
    
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
