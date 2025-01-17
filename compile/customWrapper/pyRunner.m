function [output, varargout] = pyRunner(filename, functionName, args)
    % Calls a Python custom function from the base Matlab
    % workspace. The arguments should be full or relative path of the 
    % python file with extension, the name of the function to call in the 
    % python file and a cell array of argument for the reflectivity calculation
    %
    % data = pythonWrapper.runner('backs.py', 'backs', {xdata, params});
    % [o, s] = pythonWrapper.runner('layers.py', 'layer', {params, bulk_in, bulk_out, contrast});
    % [o, s] = pythonWrapper.runner('layers.py', 'layer', {params, bulk_in, bulk_out, contrast, domain});
    
    [filepath, name, ~] = fileparts(filename);
    insert(py.sys.path, int32(0), filepath)
    
    module = py.importlib.import_module(name);
    py.importlib.reload(module);       
    
    % Call the python function
    if numel(args) == 2
        nargoutchk(1, 1);
        out = module.(functionName)(args{1}, args{2});
        output = out;
    else
        nargoutchk(2, 2);
        if numel(args) == 4
            out = module.(functionName)(args{1}, args{2}, args{3}, int32(args{4} - 1));
        else
            out = module.(functionName)(args{1}, args{2}, args{3}, int32(args{4} - 1), int32(args{5} - 1));
        end
        output = out{1};
        varargout{1} = double(out{2});
    end

    if isa(output, "py.numpy.ndarray")
        % convert python (Numpy) ndarray to matlab
        if output.ndim == 1 && numel(args) == 2
            temp = zeros(double(output.shape), 1);
        elseif output.ndim == 1 && numel(args) ~= 2
            temp = zeros(1, double(output.shape));
        else
            temp = zeros(double(output.shape));
        end
        
        list = output.tolist();
        for i=1:size(temp, 1)
            temp(i, :) = double(list{i});
        end
        output = double(temp);
    else
        output = double(output);
        if numel(args) == 2 && size(output, 1) == 1 
            output = output'; % ensure output is column array for background 
        end
    end
        
    % remove the module from sys modules to ensure reload works
    py.sys.modules().pop(name);
    py.sys.path().remove(filepath);
end
