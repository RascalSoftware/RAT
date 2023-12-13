function    [reflect,simul,shifted_dat] = applyBackgroundCorrection(reflect,simul,shifted_dat,backgroundParams,contrastBackgroundsType)

switch contrastBackgroundsType
    case 1
        %Add background to the simulation
        reflect(:,2) = reflect(:,2) + backgroundParams;
        simul(:,2) = simul(:,2) + backgroundParams;
     case 2 
%         %Subtract the background from the data..
        shifted_dat(:,2) = shifted_dat(:,2) - backgroundParams;
        %shifted_dat(:,3) = shifted_dat(:,3) - backgroundParams;   
 end
        
end