function [reflect,simul,shiftedData] = applyBackgroundCorrection(reflect,simul,shiftedData,backgroundParams,background,contrastBackgroundActions)

% Find where the data range lies within the simulation range
lowXVals = find(simul(:,1) == shiftedData(1,1));
highXVals = find(simul(:,1) == shiftedData(end,1));

lowIndex = lowXVals(1);
highIndex = highXVals(end);

% Decide which kind of background we are applyin - 'constant','data', or
% 'function'.
if backgroundParams(1) == -1
    % This is a data background....
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
elseif backgroundParams(1) == 0
    % This is a constant background....
    switch contrastBackgroundActions
        case 1
            %Add background to the simulation
            reflect(:,2) = reflect(:,2) + backgroundParams(2);
            simul(:,2) = simul(:,2) + backgroundParams(2);
        case 2
            %Subtract the background from the data..
            shiftedData(:,2) = shiftedData(:,2) - backgroundParams(2);
        otherwise
            error('The index "%d" does not represent a valid contrast background action.', contrastBackgroundActions);
    end
elseif backgroundParams(1) == -2
    % This is a function background.....
    % reduce ranges here
    backData = background(lowIndex:highIndex,2);
    switch contrastBackgroundActions
        case 1
            % Add the data to the simulation...
            reflect(:,2) = reflect(:,2) + backData;
            simul(:,2) = simul(:,2) + background(:,2);
        case 2
            % Subtract the background data from the shiftedData....
            measuredRefl = shiftedData(:,2);
            newRefl = measuredRefl - backData;

            % Put theis back into the data array....
            shiftedData(:,2) = newRefl;
        otherwise
            error('The index "%d" does not represent a valid contrast background action.', contrastBackgroundActions);
    end
end

end

