function [output,sRough] = matlabEngineCaller_customLayers(params,contrast,funcName,funcPath,bulkIn,bulkOut)

    % ____________________ REMOVE GHOST CODE AT SOME POINT ____________________

paramsLen = int16(length(params));
% dotM = strfind(funcName,'.m');
% if ~isempty(dotM)
%     funcName = funcName(1:dotM-1);
% end
%[path,funcName,extension] = fileparts(funcName);
funName = ['[total,layers] = ' funcName '(params,bulk_in,bulk_out,contrast)'];
if ~isempty(params) 
    sRough= params(1);
end

pathCall= ['cd ''' funcPath ''';'];
% add FuncPath to the path using addPath()

% if funcPath is 'matlabroot', dont add it to path since this is only used for start/stop of matlab engine
if ~strcmp(funcPath,'matlabroot')
    addpath(funcPath);
end


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
    
   % p = mfilename('fullpath');
    %extension = '.m';
    %path = strcat(p,extension);


    %$path = pwd;
    %incPath1 = fullfile(matlabroot,'extern','include');

    % ------------------------PATH SETTING FILE SETTING FOR CODER-------------------------------------- 
    % matlabRoot = string(matlabroot) FOR SOME REASON THIS DIDNT WORK IN CODER> ERROR: Cannot pass a mxArray to 'string'.
    %matlabRoot = string(feval('matlabroot')) ;
    %matlabRoot = $matlabroot
    
    

    %m = matlabroot;
    %matlabRoot = char(m);
    source1 = 'matlabCallFun.c';
    
    if ismac % MacOs
        arch = string(computer('arch'));
        incPath1= matlabRoot+'/'+"extern"+'/'+string(arch)+'/'+"include";
        %incPath1 = append(matlabroot,'/','extern','/','include');

        linkPath1 = matlabRoot+'/'+arch+'/'+"glnxa64";

        %linkPath1 = append(matlabroot,'/',arch,'/','glnxa64')    APPEND,FULLFILE and STRCAT are not supported in MATLAB CODER
        %fullfile(matlabroot,arch,'glnxa64'); % NEED TO CONFIRM THIS
        linkFile1 = 'libeng.dylib';
        linkFile2 = 'libmx.dylib';
        
    elseif isunix %LINUX
        arch = string(computer('arch'));
        incPath1= matlabRoot+'/'+"extern"+'/'+"include";

        %incPath1 = append(matlabroot,'/','extern','/','include');

        linkPath1 = matlabRoot+'/'+arch+'/'+"glnxa64";
        %linkPath1 = append(matlabroot,'/',arch,'/','glnxa64');
        %fullfile(matlabroot,arch,'glnxa64');
        linkFile1 = 'libeng.so';
        linkFile2 = 'libmx.so';
        
    elseif ispc % WINDOWS
        %get the required paths for include and link files from a json file called 'customPaths.json' in
        % the RAT main directory

        %open the json file
        %fid = fopen('customPaths.json');
        %read the json file
        %txt = fread(fid,inf);
        %close the file
        %fclose(fid);

        % get the key



        arch = string(computer('arch'));
        %incPath1= matlabRoot+'\'+"extern"+'\'+"include";
        incPath1= 'C:/Program Files/MATLAB/R2021a/extern/include'

        linkPath1 = 'C:/Program Files/MATLAB/R2021a/bin/win64';
        %linkPath1 = fullfile(matlabroot,'extern','include','lib',arch,'mingw64');
        linkFile1 = 'libeng.dll';
        linkFile2 = 'libmx.dll';
    else
        arch = 'undefined';
        incPath1 = 'undefined';
        linkPath1 = 'undefined';
        linkFile1 = 'thisWontWork.lib';
        linkFile2 = 'thisWontWork.lib';
        % DEFINE SOMETHING TO MAKE COMPILER HAPPY
    end
    

    
    %path = 'C:\Users\oba7931403\source\repos\RAT-Sandbox\Sandbox\matlabEngineCaller\tmwExampleNew';
    %incPath1 = fullfile(matlabroot,'extern','include')
    
    %incPath1 = 'C:\Program Files\MATLAB\R2021a\extern\include';
    %incPath2 = '/usr/include/openmpi-x86_64';
    %linkPath1 = fullfile(matlabroot,'extern','include','lib','win64','mingw64')
    %linkPath1 = 'C:\Program Files\MATLAB\R2021a\extern\lib\win64\mingw64';
    %linkFile1 = 'libeng.lib';
    %linkFile2 = 'libmx.lib';
    
    
    %source2 = 'matlabCallFun.h';
    
    %source1 = 'matlabCallFun.c';
    %source2 = 'matlabCallFun.h';
    
    libPriority = '';
    libPreCompiled = true;
    libLinkOnly = true;

    %coder.cinclude(source2);
    coder.updateBuildInfo('addSourceFiles',source1);
    %coder.updateBuildInfo('addSourceFiles',source2);
    coder.updateBuildInfo('addSourcePaths','C:\Users\oba7931403\Documents\GitHub\RAT\C');
    coder.updateBuildInfo('addSourcePaths','$(START_DIR)\C');
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



