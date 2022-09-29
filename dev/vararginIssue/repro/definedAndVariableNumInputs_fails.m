function definedAndVariableNumInputs_fails(X,Y,varargin)
    disp("Total number of input arguments: " + nargin)
    disp(size(varargin))
    disp(varargin{2})
    disp(varargin{X})
end