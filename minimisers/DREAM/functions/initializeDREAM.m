function [chain,output,X,fx,CR,pCR,lCR,delta_tot,log_L] = initializeDREAM(DREAMPar,paramInfo,Meas_info,chain,output,log_L,ratInputs)
% Initializes the starting positions of the Markov chains 

% Create the initial positions of the chains
% switch paramInfo.prior
%     
%     case {'uniform'}
        
        % Random sampling
        [x] = repmat(paramInfo.min,DREAMPar.nChains,1) + rand(DREAMPar.nChains,DREAMPar.nParams) .* ( repmat(paramInfo.max - paramInfo.min,DREAMPar.nChains,1) );
        
%     case {'latin'}
%         % Initialize chains with latinHypercubeSampling hypercube sampling
%         if isfield(paramInfo,'min_initial') && isfield(paramInfo,'max_initial')
%             [x] = latinHypercubeSampling(paramInfo.min_initial,paramInfo.max_initial,DREAMPar.nChains);
%         else            
%             [x] = latinHypercubeSampling(paramInfo.min,paramInfo.max,DREAMPar.nChains);
%         end
%     case {'normal'}
%         
%         % Initialize chains with (multi)-normal distribution
%         [x] = repmat(paramInfo.mu,DREAMPar.nChains,1) + randn(DREAMPar.nChains,DREAMPar.nParams) * chol(paramInfo.cov);
%         
%     case {'prior'}
%         
%         % Create the initial position of each chain by drawing each parameter individually from the prior
%         for qq = 1:DREAMPar.nParams
%             for zz = 1:DREAMPar.nChains
%                 x(zz,qq) = eval(char(paramInfo.prior_marginal(qq)));
%             end
%         end
%         
%     otherwise
%         
%         error('unknown initial sampling method');
% end

% If specified do boundary handling ( "Bound","Reflect","Fold")
if isfield(paramInfo,'boundhandling')
    [x] = boundaryHandling(x,paramInfo);
end

% Now evaluate the model ( = pdf ) and return fx
fx = evaluateModel(x,DREAMPar,Meas_info,ratInputs);

% Calculate the log-likelihood and log-prior of x (fx)
[log_L_x,log_PR_x] = calcDensity(x,fx,DREAMPar,paramInfo,Meas_info,ratInputs);

% Define starting x values, corresponding density, log densty and simulations (Xfx)
X = [x log_PR_x(:) log_L_x];

% Store the model simulations (if appropriate)
% storeDREAMResults(DREAMPar,fx,Meas_info,'w+');

% Set the first point of each of the DREAMPar.nChains chain equal to the initial X values
chain(1,1:DREAMPar.nParams+2,1:DREAMPar.nChains) = reshape(X',1,DREAMPar.nParams+2,DREAMPar.nChains);

% Define selection probability of each crossover
pCR = (1/DREAMPar.nCR) * ones(1,DREAMPar.nCR);

% Generate the actula CR value, lCR and delta_tot
CR = drawCR(DREAMPar,pCR); 
%coder.varsize('CR',[100 1e4],[1 1]);

lCR = zeros(1,DREAMPar.nCR); 
delta_tot = zeros(1,DREAMPar.nCR);

% Save pCR values in memory
output.CR(1,1:DREAMPar.nCR+1) = [ DREAMPar.nChains pCR ]; 

% Save history log density of individual chains
log_L(1,1:DREAMPar.nChains+1) = [ DREAMPar.nChains log_L_x' ];

% Compute the R-statistic
[output.R_stat(1,1:DREAMPar.nParams+1)] = [ DREAMPar.nChains gelman(chain(1,1:DREAMPar.nParams,1:DREAMPar.nChains),DREAMPar) ];
