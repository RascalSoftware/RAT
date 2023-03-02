function outStruct = lowerCaseStruct(inputStruct)

% A helper function to change all fieldnames in the input struct to lower
% case. This removes all the 'illegal' (from a Coder perspective) 'eval' and
% 'strvcat' from 'setupDREAM.m' (and maybe others...)

% Get the fieldnames...
names = fieldnames(inputStruct);

% Get the array contents...
cellDat = struct2cell(inputStruct);

% Make lower case field names...
names = lower(names);

% Re-build the struct with the new lower case fieldnames..
outStruct = cell2struct(cellDat,names);


end