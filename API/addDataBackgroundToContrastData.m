function contrastData = addDataBackgroundToContrastData(contrastData,backgroundData)

% Deal with a Data background. The data and errors in this case are
% inserted into columns 5 and 6 of the relevant datafile.
%
% Currently, we throw an error if the qz column (column 1) of the two
% datafiles are different. Eventually this will be replaced by an
% interpolation to make it more general.

% Get the arrays from the cells
dataArray = contrastData{:};
backgroundArray = backgroundData{:};

% Check that we have the same q
if ~isequal(dataArray(:,1), backgroundArray(:,1))
    error("q points must be equal for Data and Background Data");
end

% Insert background data into columns 5 and 6 of contrast data
dataArray(:,5) = backgroundArray(:,2);
dataArray(:,6) = backgroundArray(:,3);

% Package as a cell array for output...
contrastData = {dataArray};

end
