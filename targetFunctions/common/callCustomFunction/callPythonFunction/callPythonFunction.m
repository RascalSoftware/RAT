function [output,sub_rough] = callPythonFunction(fname,params,bulk_in,bulk_out,contrast)

% Calls a Python custom function from the base Matlab workspace.

% List of the currently loaded python modules
persistent functionList

% If first run through the function, intitialise 'functionList'
if isempty(functionList)
    functionList = {'',''};
end

% Check whether the module described in fname has already been loaded..
thisFunc = find(strcmp(fname,functionList));
if isempty(thisFunc)

    % First time encountering the module. Import it..
    mod = py.importlib.import_module(fname);    %'mod' becomes a handle to the module

    % We reload it just in case the puthon session has already 'seen' a
    % version of this module and the user has since modified it...   
    py.importlib.reload(mod);

    % Store this at the end of the 'functionList' array...
    nModules = size(functionList,1);
    functionList(nModules+1,:) = {fname,mod};

    thisMod = mod;

else    % Module has already been loaded..

    thisMod = functionList{thisFunc,2};

end

% Call the python function....
% We can pass matlab parameters directly to the python function (since r2008
% Matlab takes care of type conversions under the hood). 
out = thisMod.(fname)(params,bulk_in,bulk_out,int32(contrast));

% 'out' comes back as a tuple. An easy way of accessing everything is via
% a cell array....
outCell = cell(out);

% Convert them back to matlab types (from numpy arrays....)
output = double(outCell{1});
sub_rough = double(outCell{2});


end