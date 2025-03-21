function [pCR,lCR] = adaptPCR(DREAMPar,CR,delta_tot,lCRold) 
% Update the probabilities of the various crossover values.
% 
% Parameters
% ----------
% DREAMPar : struct
%     Algorithmic control settings for DREAM.
% CR : vector
%     The vector of crossover values.
% delta_tot : float
%     The normalised Euclidean distance for each crossover value.
% lCRold : array
%     The old jumping distance weights for each crossover value.
%
% Returns
% -------
% pCR : array
%     The crossover selection probability for each parameter.
% lCR : array
%     The jumping distance weights for each crossover value.

% Make CR to be a single vector
CR = CR(:);

% Determine lCR
lCR = zeros(1,DREAMPar.nCR);
for zz = 1:DREAMPar.nCR
    % Determine how many times a particular CR value is used
    idx = find(CR==zz/DREAMPar.nCR);
    % This is used to weight delta_tot
    lCR(1,zz) = lCRold(1,zz) + size(idx,1);    
end

% Adapt pCR using information from averaged normalized jumping distance
pCR = DREAMPar.nChains * (delta_tot./lCR); % / sum(delta_tot);

% Normalize pCR so that selection probabilities add up to 1
pCR = pCR./sum(pCR);
