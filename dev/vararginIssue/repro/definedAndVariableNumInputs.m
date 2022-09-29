function definedAndVariableNumInputs(X,Y,varargin)
    disp("Total number of input arguments: " + nargin)
    disp(size(varargin))
    disp(varargin{2})
    for i = 1:3
        disp(varargin{i})
    end
end