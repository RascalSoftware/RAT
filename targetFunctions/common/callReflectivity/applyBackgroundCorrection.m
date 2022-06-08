function    [reflect,Simul,shifted_dat] = applyBackgroundCorrection(reflect,Simul,shifted_dat,backg,backsType)

switch backsType
    case 1
        %Add background to the simulation
        reflect(:,2) = reflect(:,2) + backg;
        Simul(:,2) = Simul(:,2) + backg;
     case 2 
%         %Subtract the background from the data..
        shifted_dat(:,2) = shifted_dat(:,2) - backg;
        %shifted_dat(:,3) = shifted_dat(:,3) - backg;   
 end
        
end