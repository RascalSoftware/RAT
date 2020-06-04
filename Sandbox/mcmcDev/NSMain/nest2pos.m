function post_samples = nest2pos(nest_samples, Nlive)
%
% post_samples = nest2pos(nest_samples, Nlive)
% 
% Convert nested samples with Nlive livepoints
% to samples from the posterior distribution
% (logL values in last column of nest_samples)
%
% John Veitch 2009 (modified by J. Romano 2012)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

N=size(nest_samples, 1);
Ncol=size(nest_samples, 2);

% calculate logWt = log(L*w) = logL + logw = logL - i/Nlive
logL = nest_samples(:,end);
logw = -[(1:N-Nlive)' ; (N-Nlive)*ones(Nlive,1)]/Nlive;
logWt = logL + logw; 

% posterior samples are given by the normalized weight
logWtmax = max(logWt);
logWt = logWt - logWtmax; % Wt -> Wt/Wtmax

% accept a nested sample as a posterior sample only if its
% value is > than a random number drawn from a unif distribution 
logrand = log(rand(N,1));
idx = find(logWt>logrand);
post_samples = nest_samples(idx,:);

% attach log of posterior probabilities as final column of 
% the posterior samples
post_samples(:,Ncol+1) = logWt(idx); 

return

