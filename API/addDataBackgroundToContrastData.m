function thisContrastData = addDataBackgroundToContrastData(thisContrastData,thisBackgroundData)

% Deal with a Data background. The data and errors in this case are added
% as columns 5 and 6 to the relevant datafile. Column 4 is always
% conventionally (and in RAT) Resolution if used, so if it's absent add a
% column of zeros so that 4 and 5 can be background.
%
% Currently, we throw an error if the qz column (column 1) of the two
% datafiles are different. Eventually this will be replaced by an
% interpolation to make it more general.

% Get the arrays from the cells...
dataArray = thisContrastData{:};
backArray = thisBackgroundData{:};

% Check that we have the same q....
if ~isequal(dataArray(:,1),backArray(:,1))
    error('Currently q points must be equal for Data and Background Data');
end

% Check that we have a 4 column datafile, and add zeros if not...
if size(dataArray,2) ~= 4
    dataArray = [dataArray zeros(size(dataArray,1),1)];
end

% Make the 6 column array....
dataArray = [dataArray backArray(:,2:3)];

% Package as a cell array for output...
thisContrastData = {dataArray};

end