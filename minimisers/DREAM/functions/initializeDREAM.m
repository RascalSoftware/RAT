function [chain,output,X,fx,CR,pCR,lCR,delta_tot,log_L] = initializeDREAM(DREAMPar,paramInfo,Meas_info,chain,output,log_L,ratInputs)
% Initialize the starting positions of the Markov chains.
%
% Parameters
% ----------
% DREAMPar : struct
%     Algorithmic control information for DREAM.
% paramInfo : struct
%     Prior, bound, and boundary handling information for each parameter.
% Meas_info : struct 
%     Struct with measurements to evaluate against.
% chain : array
%     The initial chain array created by setupDREAM.
% output : struct
%     The initial output struct created by setupDREAM.
% log_L : array
%     The array of log-likelihood values sampled from chains.
% ratInputs : struct
%     The project and controls inputs from RAT.
%
% Returns
% -------
% chain : array
%     The initial MCMC chain array.
% output : struct
%     The initial empty output struct.
% X : array
%     The starting Markov chains.
% fx : array
%     The likelihood and log-likelihood at the initial chain points.
% CR : array
%     The crossover values for each parameter. 
% pCR : array
%     The selection probability of crossover for each parameter.
% lCR : array
%     The jumping distance weights for each crossover value. 
% delta_tot : array
%     The initial normalised Euclidean distance for each crossover value.
% log_L : array
%     The initial log-likelihood for each chain value.
% 
[x] = repmat(paramInfo.min,DREAMPar.nChains,1) + rand(DREAMPar.nChains,DREAMPar.nParams) .* ( repmat(paramInfo.max - paramInfo.min,DREAMPar.nChains,1) );
        
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

lCR = zeros(1,DREAMPar.nCR); 
delta_tot = zeros(1,DREAMPar.nCR);

% Save pCR values in memory
output.CR(1,1:DREAMPar.nCR+1) = [ DREAMPar.nChains pCR ]; 

% Save history log density of individual chains
log_L(1,1:DREAMPar.nChains+1) = [ DREAMPar.nChains log_L_x' ];

% Compute the R-statistic
[output.R_stat(1,1:DREAMPar.nParams+1)] = [ DREAMPar.nChains gelman(chain(1,1:DREAMPar.nParams,1:DREAMPar.nChains),DREAMPar) ];
