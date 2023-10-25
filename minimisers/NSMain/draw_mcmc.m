function [sample, logL] = draw_mcmc(livepoints, cholmat, logLmin, ...
    prior, data, likelihood, model, Nmcmc, parnames, extraparvals)

% function [sample, logL] = draw_mcmc(livepoints, cholmat, logLmin, ...
%    prior, data, likelihood, model, Nmcmc, parnames, extraparvals)
%
% This function will draw a multi-dimensional sample from the prior volume
% for use in the nested sampling algorithm. The new point will have a
% likelihood greater than the value logLmin. The new point will be found by
% evolving a random multi-dimensional sample from within the sample array,
% livepoints, using an MCMC with Nmcmc iterations. The MCMC will use a 
% Students-t (with N=2 degrees of freedon) proposal distribution based on
% the Cholesky decomposed covariance matrix of the array, cholmat. 10% of 
% the samples will actually be drawn using differential evolution by taking
% two random points from the current live points. extraparvals is a vector
% of additional parameters needed by the model.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

global verbose;

logL = logLmin;
mcmcfrac = 0.9; 
l2p = 0.5*log(2*pi); % useful constant

Nlive = size(livepoints,1);
Npars = size(livepoints,2);

Ndegs = 2; % degrees of freedom of Students't distribution

% initialize counters
acctot = 0;
Ntimes = 1; 

while 1
    acc = 0;
    
    % get random point from live point array
    sampidx = ceil(rand*Nlive);
    sample = livepoints(sampidx, :);
    
    % get the sample prior
    currentPrior = -inf;
    
    for j=1:Npars
        priortype = prior(j,1);
%         p3 = prior{j,3};
%         p4 = prior{j,4};
                
        if priortype == 1
            p3 = prior(j,4);
            p4 = prior(j,5);
            pv = -log(p4-p3);
            currentPrior = logplus(currentPrior, pv);
        elseif priortype == 2
            p3 = prior(j,2);
            p4 = prior(j,3);
            pv = -l2p - log(p4) - (sample(j)-p3)^2/(2*p4^2);
            currentPrior = logplus(currentPrior, pv);
        elseif priortype == 3
            p3 = prior(j,2);
            p4 = prior(j,3);
            pv = -log(10^(sample(j)*(log10(p4) - log10(p3)) + log10(p3)));
            currentPrior = logplus(currentPrior, pv);
        end
    end
        
    for i=1:Nmcmc        
        if rand < mcmcfrac % use Students-t proposal
            % draw points from mulitvariate Gaussian distribution 
            gasdevs = randn(Npars,1);
            sampletmp = (cholmat*gasdevs)';
            
            % calculate chi-square distributed value
            chi = sum(randn(Ndegs,1).^2);
            
            % add value onto old sample
            sampletmp = sample + sampletmp*sqrt(Ndegs/chi);
        else % use differential evolution
            % draw two random (different points) A and B and add (B-A) to
            % the current sample
            idx1 = ceil(rand*Nlive);
            idx2 = idx1;
            while idx2 == idx1
                idx2 = ceil(rand*Nlive);
            end
            
            A = livepoints(idx1, :);
            B = livepoints(idx2, :);
            
            sampletmp = sample + (B-A);
        end
        
        % check sample is within the (scaled) prior
        newPrior = -inf;
        behaviour = 'cyclic';
        for j=1:Npars
            priortype = prior(j,1);
            % p3 = prior{j,3};
            % p4 = prior{j,4};
            
            if priortype ==1 % uniform
                dp = 1;
                p3 = prior(j,4);
                p4 = prior(j,5);
                
                if sampletmp(j) < 0 || sampletmp(j) > 1
                    if strcmp(behaviour, 'reflect')
                        % reflect the value from the boundary
                        sampletmp(j) = 1 - mod(sampletmp(j), dp);
                    elseif strcmp(behaviour, 'cyclic')
                        % wrap parameter from one side to the other
                        while sampletmp(j) > 1
                            sampletmp(j) = sampletmp(j) - 1;
                        end
                        
                        while sampletmp(j) < 0
                            sampletmp(j) = sampletmp(j) + 1;
                        end
                    else
                        newPrior = -inf;
                        break;
                    end
                
                end
                
                pv = -log(p4-p3);
                newPrior = logplus(newPrior, pv);
                
            elseif priortype == 2       % gaussian
                pv = -l2p - sampletmp(j)^2/2;
                newPrior = logplus(newPrior, pv);
            elseif priortype == 3 % 'jeffreys'
                p3 = prior(j,2);
                p4 = prior(j,3);
                % behaviour = char(prior(j,5));
                
                dp = 1;
                
                if sampletmp(j) < 0 || sampletmp(j) > 1
                    if strcmp(behaviour, 'reflect')
                        % reflect the value from the boundary
                        sampletmp(j) = 1 - mod(sampletmp(j), dp);
                    else
                        newPrior = -inf;
                        break;
                    end
                end
                
                pv = -log(10^(sampletmp(j)*(log10(p4) - log10(p3)) + log10(p3)));
                newPrior = logplus(newPrior, pv);
            end
        end
        
        if log(rand) > newPrior - currentPrior % reject point
            continue;
        end
        
        % rescale sample back to its proper range for likelihood
        sc = rescale_parameters(prior, sampletmp);
        
        % get the likelihood of the new sample
        %likestart = tic;
        % logLnew = likelihood(data, model, parnames, ...
        %               loopcell(sc));
        logLnew = likelihood(data,sc);
        %likedur = toc(likestart);
        %fprintf(1, 'liketime = %.6f\n', likedur);
        
        % if logLnew is greater than logLmin accept point
        if logLnew > logLmin
            acc = acc + 1;
            currentPrior = newPrior;
            sample = sampletmp;
            logL = logLnew;
        end
    end
    
    % only break if at least one point was accepted otherwise try again
    if acc > 0
        acctot = acc;
        break;
    end
    
    acctot = acctot + acc;
    Ntimes = Ntimes + 1;
end

% print out acceptance ratio
if verbose
    sendTextOutput(sprintf('Acceptance ratio: %1.4f, \n', acctot/(Ntimes*Nmcmc)));
end

return
