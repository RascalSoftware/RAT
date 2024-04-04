function [pCR,lCR] = adaptPCR(DREAMPar,CR,delta_tot,lCRold) 
% Updates the probabilities of the various crossover values

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