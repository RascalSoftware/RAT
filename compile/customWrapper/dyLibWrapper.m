classdef dyLibWrapper < handle
    % A custom function wrapper for c++ dynamic library. The library should be a .dll
    % (Windows), .so (Linux), or .dylib (MacOS).

    properties (Access = private, Hidden = true)
        objectHandle; % Handle to the underlying C++ class instance
        mexHandle; % Handle to the mex function
        libPath;
        functionName;
    end
    
    methods
        function obj = dyLibWrapper(libPath, functionName)
            % Creates a dyLibWrapper object. It creates a callback interface for the 
            % library via wrapperMex.The arguments should be full or relative path of 
            % the library with extension and the name of the function to call in the dynamic library
            %
            % wrapper = dyLibWrapper('customBilayer.so', 'customBilayer');
            % wrapper = dyLibWrapper('D:/MATLAB/customBilayer.dll', 'customDomains');
            obj.mexHandle = @wrapperMex;
            obj.objectHandle = obj.mexHandle('new', libPath, functionName);
            obj.libPath = libPath;
            obj.functionName = functionName;
        end
        
        
        function delete(obj)
            % Destroys the callback class instance in wrapperMex
            if ~isempty(obj.objectHandle)
                obj.mexHandle('delete', obj.objectHandle);
            end
            obj.objectHandle = [];
        end
         
        function handle = getHandle(obj)
            % Gets the wrapper object handle
            handle = obj.objectHandle;
        end      
        
        function disp(obj)
            % Displays libarary path and function name
            fprintf('Dynamic library wrapper for %s function in %s\n', obj.functionName, obj.libPath);
        end

    end
end