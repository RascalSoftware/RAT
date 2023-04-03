function [output,sub_rough] = callPythonFunction(fname,params,bulk_in,bulk_out,contrast)

% Calls a Python custom function from the Matlab interpreter.

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

    % Store this at the end of the 'functionList' array...
    nModules = size(functionList,1);
    functionList(nModules+1,:) = {fname,mod};

    thisMod = mod;

else    % Module has already been loaded..

    thisMod = functionList(thisFunc,2);

end

% We can pass matlab parameters directly to the python function. Since 'contrast'
% is an array index in the function, this needs to be an integer..
contrast = int32(contrast);

% Call the python function....
% (could do with a better way than a messy eval tbh..)
% callString = ['thisMod.',fname,'(params,bulk_in,bulk_out,contrast)'];
% out = eval(callString);

out = thisMod.(fname)(params,bulk_in,bulk_out,contrast);

% 'out' comes back as a tuple. An easy way of accessing everything is via
% a cell array....
outCell = cell(out);

% Convert them back to matlab types (from numpy arrays....)
output = double(outCell{1});
sub_rough = double(outCell{2});


end