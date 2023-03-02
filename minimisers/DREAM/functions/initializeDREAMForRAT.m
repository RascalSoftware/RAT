function [chain,output,X,fx,CR,pCR,lCR,delta_tot,log_L] = initializeDREAMForRAT(DREAMPar,Par_info,Meas_info,chain,output,log_L,ratInputs)
% Initializes the starting positions of the Markov chains 

% Create the initial positions of the chains
switch Par_info.prior
    
    case {'uniform'}
        
        % Random sampling
        [x] = repmat(Par_info.min,DREAMPar.N,1) + rand(DREAMPar.N,DREAMPar.d) .* ( repmat(Par_info.max - Par_info.min,DREAMPar.N,1) );
        
    case {'latin'}
        % Initialize chains with latinHypercubeSampling hypercube sampling
        if isfield(Par_info,'min_initial') && isfield(Par_info,'max_initial')
            [x] = latinHypercubeSampling(Par_info.min_initial,Par_info.max_initial,DREAMPar.N);
        else            
            [x] = latinHypercubeSampling(Par_info.min,Par_info.max,DREAMPar.N);
        end
    case {'normal'}
        
        % Initialize chains with (multi)-normal distribution
        [x] = repmat(Par_info.mu,DREAMPar.N,1) + randn(DREAMPar.N,DREAMPar.d) * chol(Par_info.cov);
        
    case {'prior'}
        
        % Create the initial position of each chain by drawing each parameter individually from the prior
        
        % **** Will use our own pdf here ******

%         for qq = 1:DREAMPar.d,
%             for zz = 1:DREAMPar.N,
%                 x(zz,qq) = eval(char(Par_info.prior_marginal(qq)));
%             end;
%         end;
%         
    otherwise
        
        error('unknown initial sampling method');
end;

% If specified do boundary handling ( "Bound","Reflect","Fold")
if isfield(Par_info,'boundhandling')
    [x] = boundaryHandling(x,Par_info);
end

% Now evaluate the model ( = pdf ) and return fx
[fx] = evaluateRATModel(x,DREAMPar,Meas_info,ratInputs);

% Calculate the log-likelihood and log-prior of x (fx)
%[log_L_x,log_PR_x] = ratcalcDensity(x,fx,DREAMPar,Par_info,Meas_info,ratInputs);
[log_L_x,log_PR_x] = calcDensity(x,fx,DREAMPar,Par_info,Meas_info);

% Define starting x values, corresponding density, log densty and simulations (Xfx)
X = [x log_PR_x log_L_x];

% Store the model simulations (if appropriate)
storeDREAMResults ( DREAMPar , fx , Meas_info , 'w+' );

% Set the first point of each of the DREAMPar.N chain equal to the initial X values
chain(1,1:DREAMPar.d+2,1:DREAMPar.N) = reshape(X',1,DREAMPar.d+2,DREAMPar.N);

% Define selection probability of each crossover
pCR = (1/DREAMPar.nCR) * ones(1,DREAMPar.nCR);

% Generate the actula CR value, lCR and delta_tot
CR = drawCR(DREAMPar,pCR); lCR = zeros(1,DREAMPar.nCR); delta_tot = zeros(1,DREAMPar.nCR);

% Save pCR values in memory
output.CR(1,1:DREAMPar.nCR+1) = [ DREAMPar.N pCR ]; 

% Save history log density of individual chains
log_L(1,1:DREAMPar.N+1) = [ DREAMPar.N log_L_x' ];

% Compute the R-statistic
[output.R_stat(1,1:DREAMPar.d+1)] = [ DREAMPar.N Gelman(chain(1,1:DREAMPar.d,1:DREAMPar.N),DREAMPar) ];
