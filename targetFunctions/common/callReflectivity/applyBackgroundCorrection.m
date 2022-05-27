function    [reflect,Simul,shifted_dat] = applyBackgroundCorrection(reflect,Simul,shifted_dat,backg,backsType)

switch backsType
    case 1
        %Add background to the simulation
        reflect = reflect + backg;
        Simul = Simul + backg;
     case 2 
%         %Subtract the background from the data..
        shifted_dat(:,2) = shifted_dat(:,2) - backg;
        %shifted_dat(:,3) = shifted_dat(:,3) - backg;   
 end
        
end