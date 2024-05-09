function [reflect,simul,shiftedData] = applyBackgroundCorrection(reflect,simul,shiftedData,backgroundParams,contrastBackgroundActions)

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
