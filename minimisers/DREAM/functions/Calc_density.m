function [log_L,log_PR] = Calc_density(x,fx,DREAMPar,Par_info,Meas_info,ratInputs)
% Now calculate the likelihood (not used) and log-likelihood (used)

% % If number of measurements larger than 0 --> simulation
% if Meas_info.N > 0
%     
%     % Initialize "res" (residual matrix)
%     res = NaN(Meas_info.N,DREAMPar.N);
%     
%     % Loop over each model realization
%     for ii = 1 : DREAMPar.N
%         
%         % We now calculate the error residual
%         res(:,ii) = (Meas_info.Y(:) - fx(1:Meas_info.N,ii));
%         
%     end
%     
% else
%     
%     % Do nothing, fx is a density or log-density returned by the PDF handle
%     
% end

% ----------------------- Calculate log-prior  ----------------------------

% No ABC --> regular priors (pdfs)
if strcmp(DREAMPar.ABC,'no')
    
    % Calculate the log-prior
    if isfield(Par_info,'prior_marginal')
        
        % Compute prior densities for each parameter in each sequence
        for qq = 1 : DREAMPar.d
            for zz = 1 : DREAMPar.N
                % Compute prior density of proposal
                PR(zz,qq) = max ( eval(char(strrep(Par_info.prior_marginal(qq),'rnd(','pdf(x(zz,qq),'))) , 1e-299 );
            end
        end
        
        % Take the log of the densities and their sum
        log_PR = sum ( log ( PR ) , 2 );

    elseif isfield(Par_info,'mvnpdf')

        % RAT specific prior funtion (mvnpdf)
        PR = zeros(1,DREAMPar.N);
        for i = 1:DREAMPar.N                                  % Loop over all the chains..
            PR(i) = gaussLogPrior(x(i,:),ratInputs);          % mvnpdf automatically goes over all pars
        end
        
        % Take log of any non-zero values..
        log_PR = zeros(DREAMPar.N,1);
        for i = 1:length(PR)
            if PR(i) ~= 0
                log_PR(i) = log(PR(i));     % Does it even need to be log?
            else
                % Otherwise keep the zero values
                log_PR(i) = 0;
            end
        end
        log_PR = log_PR(:);         % Enforce column vector
    
    
    else
        % No use of prior --> set log-prior to zero (no effect in Metropolis)
        log_PR = zeros ( DREAMPar.N , 1 );
        
    end
    

else

    % Diagnostic Bayes --> if summary metric is defined as prior
    if isfield(DREAMPar,'prior_handle')
    
        % Evaluate distance between observed and simulated summary metrics
        for ii = 1 : DREAMPar.N
        
            % Calculate summary metrics for "fx"
            S_sim = DREAMPar.prior_handle ( fx(:,ii) );
        
            % Now calculate log-density (not a true log-density! - but does not matter)
            log_PR(ii,1) = max ( abs ( Meas_info.S(:) - S_sim(:) ) );
        
        end

    % Regular ABC with summary metrics as likelihood function
    else
    
        log_PR = zeros ( DREAMPar.N , 1 );
        
    end
                
end

% --------------------- End Calculate log-prior ---------------------------


% -------------------- Calculate log-likelihood ---------------------------

% Loop over each model realization and calculate log-likelihood of each fx
for ii = 1 : DREAMPar.N
    log_L(ii,1) = log ( fx(1,ii) );
end

% ------------------ End Calculate log-likelihood -------------------------