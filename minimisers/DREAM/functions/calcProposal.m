function [x_new,CR] = calcProposal(X,CR,DREAMPar,Table_gamma,paramInfo)
% Calculate candidate points using discrete proposal distribution

% % % % Calculate the ergodicity perturbation
% % % eps = DREAMPar.zeta * randn(DREAMPar.nChains,DREAMPar.nParams);
% % % 
% % % % Determine which sequences to evolve with what DE strategy
% % % DE_pairs = randSample( [1:DREAMPar.delta ] , DREAMPar.nChains , [ 1/DREAMPar.delta*ones(1,DREAMPar.delta) ])';
% % % 
% % % % Generate series of permutations of chains
% % % [dummy,tt] = sort(rand(DREAMPar.nChains-1,DREAMPar.nChains));
% % % 
% % % % Generate uniform random numbers for each chain to determine which dimension to update
% % % D = rand(DREAMPar.nChains,DREAMPar.nParams);
% % % 
% % % % Ergodicity for each individual chain
% % % noise_x = DREAMPar.jumpProbability * (2 * rand(DREAMPar.nChains,DREAMPar.nParams) - 1);
% % % 
% % % % Initialize the delta update to zero
% % % delta_x = zeros(DREAMPar.nChains,DREAMPar.nParams);
% % % 
% % % % Each chain evolves using information from other chains to create offspring
% % % for qq = 1:DREAMPar.nChains,
% % %     
% % %     % Define ii and remove current member as an option
% % %     ii = ones(DREAMPar.nChains,1); ii(qq) = 0; idx = find(ii > 0);
% % %     
% % %     % randomly select two members of ii that have value == 1
% % %     rr = idx(tt(1:2*DE_pairs(qq,1),qq));
% % %     
% % %     % --- WHICH DIMENSIONS TO UPDATE? DO SOMETHING WITH CROSSOVER ----
% % %     [i] = find(D(qq,1:DREAMPar.nParams) > (1-CR(qq,1)));
% % %     
% % %     % Update at least one dimension
% % %     if isempty(i), i = randperm(DREAMPar.nParams); i = i(1); end;
% % %     % ----------------------------------------------------------------
% % %     
% % %     % Determine the associated JumpRate and compute the jump
% % %     if (rand < (1 - DREAMPar.pJumpRate_one)),
% % %         
% % %         %         % Now determine gamma, the jump factor
% % %         %         if ~DREAMPar.ABC
% % %         %
% % %         % Select the JumpRate (dependent of NrDim and number of pairs)
% % %         NrDim = size(i,2); JumpRate = Table_gamma(NrDim,DE_pairs(qq,1));
% % %         
% % %         %           else
% % %         %
% % %         %                 % Turner (2012) paper -- CU[0.5,1] but needs scaling if
% % %         %                 % more than 1 pair is used!
% % %         %                 JumpRate = (0.5 + rand/2) * sqrt(1/DREAMPar.delta);
% % %         
% % %         %        end;
% % %         
% % %         % Produce the difference of the pairs used for population evolution
% % %         delta = sum(X(rr(1:DE_pairs(qq,1)),1:DREAMPar.nParams) - X(rr(DE_pairs(qq,1)+1:2*DE_pairs(qq,1)),1:DREAMPar.nParams),1);
% % %         
% % %         % Then fill update the dimension
% % %         delta_x(qq,i) = (1 + noise_x(qq,i)) * JumpRate.*delta(1,i);
% % %         
% % %     else
% % %         
% % %         % Set the JumpRate to 1 and overwrite CR and DE_pairs
% % %         JumpRate = 1; CR(qq,1) = -1;
% % %         
% % %         % Compute delta from one pair
% % %         delta = X(rr(1),1:DREAMPar.nParams) - X(rr(2),1:DREAMPar.nParams);
% % %         
% % %         % Now jumprate to facilitate jumping from one mode to the other in all dimensions
% % %         delta_x(qq,1:DREAMPar.nParams) = JumpRate * delta;
% % %         
% % %     end;
% % %     
% % %     % Check this line to avoid that jump = 0 and x_new is similar to X
% % %     if (sum(delta_x(qq,1:DREAMPar.nParams).^2,2) == 0),
% % %         
% % %         % Compute the Cholesky Decomposition of X
% % %         R = (2.38/sqrt(DREAMPar.nParams)) * chol(cov(X(1:end,1:DREAMPar.nParams)) + 1e-5*eye(DREAMPar.nParams));
% % %         
% % %         % Generate jump using multinormal distribution
% % %         delta_x(qq,1:DREAMPar.nParams) = randn(1,DREAMPar.nParams) * R;
% % %         disp('hello');
% % %     end;
% % %     
% % % end;
% % % 
% % % % Generate candidate points by perturbing the current X values with jump and eps
% % % x_new = X + delta_x + eps;
% % % 
% % % % If specified do boundary handling ( "Bound","Reflect","Fold")
% % % if isfield(paramInfo,'boundhandling'),
% % %     [x_new] = BoundaryHandling(x_new,paramInfo,paramInfo.boundhandling);
% % % end;
% % % 


% ##################################################

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
