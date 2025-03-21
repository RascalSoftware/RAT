% John Veitch 2009 (modified by J. Romano 2012)
function post_samples = nest2pos(nest_samples, nLive)
% Convert nested samples to samples from the posterior distribution.
%
% Parameters
% ----------
% nest_samples : array
%     The samples from the nested sampler.
% nLive : int
%     The number of live points.
%
% Returns
% -------
% post_samples
%     The samples from the posterior distribution for each of ``nest_samples``.

N=size(nest_samples, 1);
Ncol=size(nest_samples, 2);

% calculate logWt = log(L*w) = logL + logw = logL - i/nLive
logL = nest_samples(:,end);
logw = -[(1:N-nLive)' ; (N-nLive)*ones(nLive,1)]/nLive;
logWt = logL + logw; 

% posterior samples are given by the normalized weight
logWtmax = max(logWt);
logWt = logWt - logWtmax; % Wt -> Wt/Wtmax

% accept a nested sample as a posterior sample only if its
% value is > than a random number drawn from a unif distribution 
logrand = log(rand(N,1));
idx = find(logWt>logrand);
dummy_post_samples = nest_samples(idx,:);
nTerms = size(dummy_post_samples,1);

% attach log of posterior probabilities as final column of 
% the posterior samples
%post_samples(:,Ncol+1) = logWt(idx); 
post_samples = zeros(nTerms,Ncol+1);
post_samples = [dummy_post_samples logWt(idx)];

return

