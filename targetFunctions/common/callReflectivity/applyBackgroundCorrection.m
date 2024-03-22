function [reflect,simul,shiftedData] = applyBackgroundCorrection(reflect,simul,shiftedData,backgroundParams,contrastBackgroundsType)

switch contrastBackgroundsType
    case 1
        %Add background to the simulation
        reflect(:,2) = reflect(:,2) + backgroundParams;
        simul(:,2) = simul(:,2) + backgroundParams;
    case 2 
        %Subtract the background from the data..
        shiftedData(:,2) = shiftedData(:,2) - backgroundParams;
        %shiftedData(:,3) = shiftedData(:,3) - backgroundParams;
end
        
end
