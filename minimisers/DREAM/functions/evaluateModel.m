% Written by Jasper A. Vrugt
function [fx] = evaluateModel(x,DREAMPar,Meas_info,ratInputs)
% Compute the likelihood and log-likelihood of each d-vector of x values.
%
% If DREAMPar.CPU > 1, runs in parallel.
%
% Parameters
% ----------
% x : array
%     The points at which to calculate likelihood and log-likelihood.
% DREAMPar : struct 
%     Algorithmic control information for DREAM. 
% Meas_info : struct, optional
%     Struct with measurements to evaluate against.
% ratInputs : struct
%     Project and controls information from RAT.
%
% Returns
% -------
% fx : array
%     The likelihood and log-likelihood for each point in ``x``.
% 
fx = zeros(1,DREAMPar.nChains);
if ( DREAMPar.CPU == 1 )         % Sequential evaluation

    % Loop over each d-vector of parameter values of x using 1 worker
    for ii = 1:DREAMPar.nChains
        % Execute the model and return the model simulation
        %fx(:,ii) = f_handle(x(ii,:), ratInputs);
        fx(:,ii) = DREAMWrapper(x(ii,:),ratInputs);
    end

else     % Parallel evaluation

    % Loop over each d-vector of parameter values of x using N workers
    parfor ii = 1:DREAMPar.nChains
        % Execute the model and return the model simulation
        %fx(:,ii) = f_handle(x(ii,:), ratInputs);
        fx(:,ii) = DREAMWrapper(x(ii,:),ratInputs);
    end

end

end
