function [accept,idx_accept] = metropolisRule(DREAMPar,log_L_xnew,log_PR_xnew,log_L_xold,log_PR_xold)
% Calculates candidate acceptance for each point using the Metropolis rule.
%
% Parameters
% ----------
% DREAMPar : struct
%     Algorithmic control information for DREAM.
% log_L_xnew : array 
%     The log-likelihood of the proposed new point for each chain. 
% log_PR_xnew : array
%     The log-prior of the proposed new point for each chain.
% log_L_xold :  array
%     The log-likelihood of the current newest point on the chain.
% log_PR_xold : array
%     The log-prior of the current newest point on the chain.
% 
% Returns
% -------
% accept : array
%     An array of bools of whether the proposal is accepted for each parameter. 
% idx_accept : array
%     The parameter indices for which proposals were accepted.
%
if ~DREAMPar.ABC

    % No ABC --> regular MCMC with prior and likelihood
    % Calculate the likelihood ratio
    alfa_L = exp ( log_L_xnew - log_L_xold );
    
    % Calculate the prior ratio
    alfa_PR = exp ( log_PR_xnew - log_PR_xold );
    
    % Calculate product of two probability ratios
    alfa = alfa_L .* alfa_PR;
    
    % Generate random numbers
    Z = rand ( DREAMPar.nChains , 1 );
    
    % Find which alfa's are greater than Z
    accept = ( alfa > Z );

% ABC --> check if summary metrics as prior (diagnostic Bayes) or likelihood (regular ABC)
else
        
    % Diagnostic Bayes (Vrugt and Sadegh, 2015)
    if isfield(DREAMPar,'prior_handle')
        
        % Preallocate vector accept
        accept = zeros(DREAMPar.nChains,1);
        
        % Check pairwise
        for z = 1 : DREAMPar.nChains
            
            % If proposal closer to observed summary metrics
            if ( log_PR_xnew(z) < log_PR_xold(z) )
                % If current state outside epsilon
                if log_PR_xold(z) > DREAMPar.epsilon
                    % Always accept proposal
                    accept(z,1) = 1;
                else
                    % Now ratio of log-likelihoods
                    alfa_L = exp ( log_L_xnew(z) - log_L_xold(z) );
                    % Accept with Metropolis probability
                    accept(z,1) = ( alfa_L > rand );
                end
            else
                % If proposal worse and outside epsilon
                if log_PR_xnew(z) > DREAMPar.epsilon
                    % Always reject proposal
                    %accept(z,1) = 0;
                else
                    % Now ratio of log-likelihoods
                    alfa_L = exp ( log_L_xnew(z) - log_L_xold(z) );
                    % Use
                    accept(z,1) = ( alfa_L > rand );
                end
            end
            
        end
    
    % ABC as likelihood (see Sadegh and Vrugt, 2014)
    else
        
        % Now determine which proposal to accept
        accept = ( log_L_xnew <= log_L_xold ) | ( log_L_xnew <= DREAMPar.epsilon );
        
    end
end

% Now derive which proposals to accept (row numbers of X)
idx_accept = find ( accept > 0 );
