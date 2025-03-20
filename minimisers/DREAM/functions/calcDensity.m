function [log_L,log_PR] = calcDensity(x,fx,DREAMPar,paramInfo,Meas_info,ratInputs)
% Calculate the log-likelihood of a point and the log-prior of each chain.
% 
% Parameters
% ----------
% x : vector
%     The point in parameter space to evaluate.
% fx : vector
%     The likelihood and log-likelihood for each chain.
% DREAMPar : struct
%     The algorithmic control settings for DREAM.
% paramInfo : struct
%     Ranges, priors and boundary handling for each parameter.
% Meas_info : struct, optional
%     Struct with measurements to evaluate against.
% ratInputs : struct
%     Project and controls information from RAT.
%
% Returns
% -------
% log_L : array
%     The log-likelihood of each ``fx``.
% log_PR : array
%     The log-prior for each chain.

% RAT specific prior funtion (mvnpdf)
PR = zeros(1,DREAMPar.nChains);
for i = 1:DREAMPar.nChains                                  % Loop over all the chains..
    PR(i) = scaledGaussPrior(x(i,:),ratInputs);          % mvnpdf automatically goes over all pars
end

% Take log of any non-zero values..
log_PR = zeros(DREAMPar.nChains,1);
for i = 1:length(PR)
    if PR(i) ~= 0
        log_PR(i) = log(PR(i));
    else
        % Otherwise keep the zero values
        log_PR(i) = 0;
    end
end

% Loop over each model realization and calculate log-likelihood of each fx
log_L  = zeros(DREAMPar.nChains,1);
for ii = 1 : DREAMPar.nChains
    log_L(ii,1) =  fx(1,ii) ;
end

end
