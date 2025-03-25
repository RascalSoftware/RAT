% Written by Jasper A. Vrugt
function log_L = calcLogLikelihood(x,DREAMPar,ratInputs)
% Compute the log-likelihood of each d-vector of x values.
%
% If DREAMPar.CPU > 1, runs in parallel.
%
% Parameters
% ----------
% x : array
%     The points at which to calculate likelihood and log-likelihood.
% DREAMPar : struct 
%     Algorithmic control information for DREAM. 
% ratInputs : struct
%     Project and controls information from RAT.
%
% Returns
% -------
% log_L : array
%     The log-likelihood for each point in ``x``.
% 
log_L = zeros(DREAMPar.nChains, 1);
if ( DREAMPar.CPU == 1 )         % Sequential evaluation

    % Loop over each d-vector of parameter values of x using 1 worker
    for ii = 1:DREAMPar.nChains
        % Execute the model and return the model simulation
        log_L(ii,:) = DREAMWrapper(x(ii,:),ratInputs);
    end

else     % Parallel evaluation

    % Loop over each d-vector of parameter values of x using N workers
    parfor ii = 1:DREAMPar.nChains
        % Execute the model and return the model simulation
        log_L(ii,:) = DREAMWrapper(x(ii,:),ratInputs);
    end

end

end
