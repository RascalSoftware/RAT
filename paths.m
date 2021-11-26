% function to export the set paths to a json file
%
function paths()

    if ismac % MacOs
        arch = string(computer('arch'));
        incPath1= matlabRoot+'/'+"extern"+'/'+string(arch)+'/'+"include";
        %incPath1 = append(matlabroot,'/','extern','/','include');

        linkPath1 = matlabRoot+'/'+arch+'/'+"glnxa64";

        %linkPath1 = append(matlabroot,'/',arch,'/','glnxa64')    APPEND,FULLFILE and STRCAT are not supported in MATLAB CODER
        %fullfile(matlabroot,arch,'glnxa64'); % NEED TO CONFIRM THIS
        linkFile1 = 'libeng.dylib';
        linkFile2 = 'libmx.dylib';

        paths = struct('include_paths',{incPath1},'link_paths',{linkPath1},'link_file1',{linkFile1},'link_file2',{linkFile2});
        % export the paths to a json file called customPaths.json
        jsonStr = jsonencode(paths);
        fid = fopen('customPaths.json','w');
        fprintf(fid,'%s',jsonStr);
        fclose(fid);



    elseif isunix %LINUX
        arch = string(computer('arch'));
        incPath1= matlabRoot+'/'+"extern"+'/'+"include";

        %incPath1 = append(matlabroot,'/','extern','/','include');

        linkPath1 = matlabRoot+'/'+arch+'/'+"glnxa64";
        %linkPath1 = append(matlabroot,'/',arch,'/','glnxa64');
        %fullfile(matlabroot,arch,'glnxa64');
        linkFile1 = 'libeng.so';
        linkFile2 = 'libmx.so';

        paths = struct('include_paths',{incPath1},'link_paths',{linkPath1},'link_file1',{linkFile1},'link_file2',{linkFile2});
        % export the paths to a json file called customPaths.json
        jsonStr = jsonencode(paths);
        fid = fopen('customPaths.json','w');
        fprintf(fid,'%s',jsonStr);
        fclose(fid);

        
    elseif ispc % WINDOWS
        arch = string(computer('arch'));
        %incPath1= matlabRoot+'\'+"extern"+'\'+"include";
        incPath1= 'C:\Program Files\MATLAB\R2021a\extern\include'

        linkPath1 = 'C:\Program Files\MATLAB\R2021a\bin'+"win64";
        %linkPath1 = fullfile(matlabroot,'extern','include','lib',arch,'mingw64');
        linkFile1 = 'libeng.lib';
        linkFile2 = 'libmx.lib';


        paths = struct('include_paths',{incPath1},'link_paths',{linkPath1},'link_file1',{linkFile1},'link_file2',{linkFile2});
        % export the paths to a json file called customPaths.json
        jsonStr = jsonencode(paths);
        fid = fopen('customPaths.json','w');
        fprintf(fid,'%s',jsonStr);
        fclose(fid);
    else
        arch = 'undefined';
        incPath1 = 'undefined';
        linkPath1 = 'undefined';
        linkFile1 = 'thisWontWork.lib';
        linkFile2 = 'thisWontWork.lib';
        % DEFINE SOMETHING TO MAKE COMPILER HAPPY
    end
end
