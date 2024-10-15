function [reflect,simul,shiftedData] = applyBackgroundCorrection(reflect,simul,shiftedData,background,contrastBackgroundActions)

% Find where the data range lies within the simulation range
lowXVals = find(simul(:,1) == shiftedData(1,1));
highXVals = find(simul(:,1) == shiftedData(end,1));

lowIndex = lowXVals(1);
highIndex = highXVals(end);

% reduce ranges here
backData = background(lowIndex:highIndex,2);
backError = background(lowIndex:highIndex,3);

switch contrastBackgroundActions
    case 1
        % Add the data to the simulation...
        reflect(:,2) = reflect(:,2) + backData;
        simul(:,2) = simul(:,2) + background(:,2);
    case 2
        % Subtract the background data from the shiftedData....
        measuredRefl = shiftedData(:,2);
        measuredErr = shiftedData(:,3);

        newRefl = measuredRefl - backData;
        newReflErr = sqrt(measuredErr.^2 + backError.^2);   % Propogate the errors....

        % Put these back into the data array....
        shiftedData(:,2) = newRefl;
        shiftedData(:,3) = newReflErr;
    otherwise
        error('The index "%d" does not represent a valid contrast background action.', contrastBackgroundActions);
end

end
