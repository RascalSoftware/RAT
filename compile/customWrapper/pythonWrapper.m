classdef pythonWrapper < handle
    % A custom function wrapper for a python file. 

    properties (Access = private, Hidden = true)
        filename;
        tempFolder
        tempName;
        libPath;
        functionName;
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
            obj.tempFolder = tempname;
            obj.libPath = libPath;
            obj.functionName = functionName;

            fnstr = ['function [output,sub_rough] = %s(varargin)\n' ...
                     '  [output, sub_rough] = pythonWrapper.runner("%s", "%s", varargin);\n' ...
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
            % Displays libarary path and function name
            fprintf('Python wrapper for %s function in %s\n', obj.functionName, obj.libPath);
        end
    end

    methods (Static)
        function [output,sub_rough] = runner(filename, functionName, args)
            % Calls a Python custom function from the base Matlab
            % workspace. The arguments should be full or relative path of the 
            % python file with extension, the name of the function to call in the 
            % python file and a celll array of argument for the relfectiveity calculation
            %
            % [o, s] = pythonWrapper.runner('layers.py', 'layer', {params, bulk_in, bulk_out, contrast});
            % [o, s] = pythonWrapper.runner('layers.py', 'layer', {params, bulk_in, bulk_out, contrast, domain});
            
            [filepath, name, ~] = fileparts(filename);
            insert(py.sys.path, int32(0), filepath)
            
            module = py.importlib.import_module(name);
            py.importlib.reload(module);       
            
            % Call the python function
            if (numel(args) == 4)
                out = module.(functionName)(args{1}, args{2}, args{3}, int32(args{4} - 1));
            else
                out = module.(functionName)(args{1}, args{2}, args{3}, int32(args{4} - 1), int32(args{5} - 1));
            end

            output = out{1};
            if isa(output, "py.numpy.ndarray")
                % convert python (Numpy) ndarray to matlab
                temp = zeros(double(output.shape));
                list = output.tolist();
                for i=1:size(temp, 1)
                    temp(i, :) = double(list{i});
                end
                output = temp;
            end
            output = double(output);
            sub_rough = double(out{2});
            
            % remove the module from sys modules to ensure reload works
            py.sys.modules().pop(name);
            py.sys.path().remove(filepath);
        end
    end
end

