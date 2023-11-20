classdef pythonWrapper < handle
    % A custom function wrapper for a python file. 

    properties (SetAccess = private)
        functionName
        libPath
    end

    properties (SetAccess = private, Hidden = true)
        tempFolder
        tempName
        filename
    end
    
    methods
        function obj = pythonWrapper(libPath, functionName)
            % Creates a pythonWrapper object. It creates a temporary function which runs 
            % the python code using the python executable connected to MATLAB pyenv. The 
            % arguments should be full or relative path of the python file with extension and 
            % the name of the function to call in the python file
            %
            % wrapper = pythonWrapper('customBilayer.py', 'customBilayer');
            % wrapper = pythonWrapper('D:/MATLAB/customBilayer.py', 'customDomains');
            obj.tempFolder = tempname();
            obj.libPath = libPath;
            obj.functionName = functionName;

            fnstr = ['function [output,sub_rough] = %s(varargin)\n' ...
                     '  [output, sub_rough] = pyRunner("%s", "%s", varargin);\n' ...
                     'end\n'];
            
            mkdir(obj.tempFolder);
            filename = sprintf('%s.m', tempname(obj.tempFolder));
            fid = fopen(filename, 'w+');
            [~, obj.tempName, ~] = fileparts(filename);
            fprintf(fid, fnstr, obj.tempName, obj.libPath, obj.functionName);
            fclose(fid);
            addpath(obj.tempFolder);
        end
        
        function delete(obj)
            % Removes the temporary runner file
            rmpath(obj.tempFolder);
            if exist(obj.tempFolder, 'dir')
                rmdir(obj.tempFolder, 's');
            end
        end
        
        function handle = getHandle(obj)
            % Gets the name of the temporary runner file
            handle = obj.tempName;
        end      

        function disp(obj)
            % Displays library path and function name
            fprintf('Python wrapper for %s function in %s\n', obj.functionName, obj.libPath);
        end
    end
end
