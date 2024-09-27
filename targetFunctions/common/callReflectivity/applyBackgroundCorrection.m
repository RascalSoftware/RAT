function [reflect,simul,shiftedData] = applyBackgroundCorrection(reflect,simul,shiftedData,backgroundParams,contrastBackgroundActions)

% Decide which kind of background we are applyin - 'constant','data', or
% 'function'.
if backgroundParams == -1
    % This is a data background....
    backData = shiftedData(:,5);
    backError = shiftedData(:,6);
    switch contrastBackgroundActions
        case 1
            % Add the data to the simulation...
            reflect(:,2) = reflect(:,2) + backData;
            simul(:,2) = simul(:,2) + backData;
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
else
    % This is a constant background....
    switch contrastBackgroundActions
        case 1
            %Add background to the simulation
            reflect(:,2) = reflect(:,2) + backgroundParams;
            simul(:,2) = simul(:,2) + backgroundParams;
        case 2
            %Subtract the background from the data..
            shiftedData(:,2) = shiftedData(:,2) - backgroundParams;
            %shiftedData(:,3) = shiftedData(:,3) - backgroundParams;
        otherwise
            error('The index "%d" does not represent a valid contrast background action.', contrastBackgroundActions);
    end
end

end
