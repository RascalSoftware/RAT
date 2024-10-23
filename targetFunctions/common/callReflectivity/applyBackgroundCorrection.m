function [reflectivity,simulation,outputData] = applyBackgroundCorrection(reflectivity,simulation,shiftedData,background,backgroundAction)

% Find where the data range lies within the simulation range
lowXVals = find(simulation(:,1) == shiftedData(1,1));
highXVals = find(simulation(:,1) == shiftedData(end,1));

lowIndex = lowXVals(1);
highIndex = highXVals(end);

% Reduce ranges here - background is defined over the simulation range
backData = background(lowIndex:highIndex,2);
backError = background(lowIndex:highIndex,3);

switch backgroundAction
    case 1
        % Add the data to the simulation
        reflectivity(:,2) = reflectivity(:,2) + backData;
        simulation(:,2) = simulation(:,2) + background(:,2);
    case 2
        % Subtract the background data from the shiftedData
        shiftedData(:,2) = shiftedData(:,2) - backData;
        shiftedData(:,3) = sqrt(shiftedData(:,3).^2 + backError.^2);   % Propagate the errors
    otherwise
        error('The index "%d" does not represent a valid contrast background action.', backgroundAction);
end

% Reduce data to original three columns
outputData = shiftedData(:,1:3);

end
