function [delta_tot] = calcDelta(DREAMPar,delta_tot,delta_normX,CR)
% Calculate total normalized Euclidean distance for each crossover value.
%
% Parameters
% ----------
% DREAMPar : struct
%     Algorithmic control information for DREAM.
% delta_tot : array
%     The initial normalised Euclidean distance for each crossover value.
% delta_normX : array
%     The Euclidean distance between the new and old crossover value.
% CR : array
%     The crossover values for each parameter.
%
% Returns
% -------
% delta_tot : array
%     The updated normalised Euclidean distance for each crossover value.

% Derive sum_p2 for each different CR value 
for j = 1:DREAMPar.nCR
    
    % Find which chains are updated with j/DREAMPar.nCR
    idx = find(CR==j/DREAMPar.nCR); 
    
    % Add the normalized squared distance tot the current delta_tot;
    delta_tot(1,j) = delta_tot(1,j) + sum(delta_normX(idx,1));
    
end
