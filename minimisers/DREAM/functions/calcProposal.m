function [x_new,CR] = calcProposal(X,CR,DREAMPar,Table_gamma,paramInfo)
% Calculate candidate points using discrete proposal distribution.
%
% Parameters
% ----------
% X : array
%     The current position of each chain.
% CR : array
%     The crossover values for each parameter.
% DREAMPar : struct
%     Algorithmic control information for DREAM.
% Table_gamma : array
%     The DE jump length values for each parameter.
% paramInfo : struct
%     Prior, bound, and boundary handling information for each parameter.
%
% Returns
% -------
% x_new : array
%     The new points in parameter space.
% CR : array
%     The new crossover values for each parameter.

% Calculate the ergodicity perturbation
eps = DREAMPar.zeta * randn(DREAMPar.nChains,DREAMPar.nParams);

% Determine how many chain pairs to use for each individual chain
DE_pairs = randSample( [1:DREAMPar.delta ] , DREAMPar.nChains , [ 1/DREAMPar.delta*ones(1,DREAMPar.delta) ])';

% Generate uniform random numbers for each chain to determine which dimension to update
rnd_cr = rand(DREAMPar.nChains,DREAMPar.nParams);

% Ergodicity for each individual chain
rnd_jump = DREAMPar.jumpProbability * (2 * rand(DREAMPar.nChains,DREAMPar.nParams) - 1);
%rnd_jump = DREAMPar.jumpProbability * (2 * rand(DREAMPar.nChains,1) - 1);

% Randomly permute numbers [1,...,N-1] N times
[~,draw] = sort(rand(DREAMPar.nChains-1,DREAMPar.nChains));             

% Set jump vectors equal to zero
dx = zeros(DREAMPar.nChains,DREAMPar.nParams);               

% Determine when jumprate is 1
gamma = randSample([0 1],DREAMPar.nChains,[ 1 - DREAMPar.pUnitGamma DREAMPar.pUnitGamma ]);   

% Create N proposals
for i = 1:DREAMPar.nChains               
    % Derive vector r1
    r1 = DREAMPar.R(i,draw(1:DE_pairs(i),i)); 
    % Derive vector r2
    r2 = DREAMPar.R(i,draw(DE_pairs(i)+1:2*DE_pairs(i),i));
    % Derive subset A with dimensions to sample
    A = find( rnd_cr(i,1:DREAMPar.nParams) < CR(i,1));
    % How many dimensions are sampled?
    D = numel(A);                
    % Make sure that at least one dimension is selected!
    if ( D == 0 )
        a = randperm(DREAMPar.nParams); A = a(1); D = 1;
    end
    % Which gamma to use?
    if ( gamma(i) == 1 )
        % Calculate direct jump
        dx(i,1:DREAMPar.nParams) = ( 1 + rnd_jump(i,1:DREAMPar.nParams) ) .* sum( X(r1,1:DREAMPar.nParams) - X(r2,1:DREAMPar.nParams) , 1 ) ...
            + eps(i,1:DREAMPar.nParams); 
        % Set CR to -1 so that this jump does not count for calculation of pCR
        CR(i,1) = -1;
    else
        % Unpack jump rate
        gamma_D = Table_gamma(D,DE_pairs(i));
        % Calculate jump
        dx(i,A) = ( 1 + rnd_jump(i,A) ) .* gamma_D .* sum( X(r1,A) - X(r2,A) , 1 ) + eps(i,A);
    end
end

% Generate candidate points by perturbing the current X values with jump and eps
x_new = X + dx;

% If specified do boundary handling ( "Bound","Reflect","Fold")
if isfield(paramInfo,'boundhandling')
    [x_new] = boundaryHandling(x_new,paramInfo);
end
