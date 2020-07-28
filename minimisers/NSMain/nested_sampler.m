function [logZ, nest_samples, post_samples,H] = nested_sampler(data, ...
          Nlive, Nmcmc, tolerance, likelihood, model, prior, extraparams)

% function [logZ, nest_samples, post_samples] = nested_sampler(data, ...
%           Nlive, Nmcmc, tolerance, likelihood, model, prior, extraparams)
%
% This function performs nested sampling of the likelihood function from
% the given prior (given a set of data, a model, and a set of extra model 
% parameters).
% 
% If Nmcmc > 0, new samples will be drawn from a proposal using an MCMC 
% and differential evolution. The sampling will stop once the 
% tolerance critereon has been reached. This method is that of Veitch & 
% Vecchio.
%
% If Nmcmc = 0, new samples will be drawn from a set of bounding ellipsoids 
% constructed using the MultiNest algorithm for partitioning live points.
%
% The likelihood should be the function handle of a likelihood function to
% use. This should return the log likelihood of the model parameters given
% the data.
% 
% The model should be the function handle of the model function to be
% passed to the likelihood function.
%
% The prior should be a cell array with each cell containing five values:
%   parameter name (string)
%   prior type (string) e.g. 'uniform', 'gaussian' of 'jeffreys'
%   minimum value (for uniform prior), or mean value (for Gaussian prior)
%   maximum value (for uniform prior), or width (for Gaussian prior)
%   parameter behaviour (string):
%       'reflect' - if the parameters reflect off the boundaries
%       'cyclic'  - if the parameter space is cyclic
%       'fixed'   - if the parameters have fixe boundaries
%       ''        - for gaussian priors
%   e.g., prior = {'h0', 'uniform', 0, 1, 'reflect'; 
%                  'r', 'gaussian', 0, 5, '';
%                  'phi', 'uniform', 0, 2*pi, 'cyclic'};
%
% extraparams is a cell array of fixed extra parameters (in addition
% to those specified by prior) used by the model 
% e.g.  extraparams = {'phi', 2;
%                      'x', 4};
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
global verbose;
global DEBUG;

verbose = 0;
DEBUG = 0;

% get the number of parameters from the prior array
D = size(prior,1);

% get all parameter names
parnames = prior(:,1);

% if ~isempty(extraparams)
%     extraparnames = extraparams{1};
%     extraparvals = extraparams{2};
%     parnames = [];%cat(1, parnames, extraparnames);
% else
%     extraparvals = [];
% end
    
% draw the set of initial live points from the prior
livepoints = zeros(Nlive, D);

for i=1:D
    priortype = char(prior(i,2));
    p3 = prior{i,3};
    p4 = prior{i,4};
    
    % currently only handles uniform or Gaussian priors
    if strcmp(priortype, 'uniform')
        livepoints(:,i) = p3 + (p4-p3)*rand(Nlive,1);
    elseif strcmp(priortype, 'gaussian')
        livepoints(:,i) = p3 + p4*randn(Nlive,1);
    elseif strcmp(priortype, 'jeffreys')
        % uniform in log space
        livepoints(:,i) = 10.^(log10(p3) + (log10(p4)-log10(p3))*rand(Nlive,1));
    end
end

% check whether likelihood is a function handle, or a string that is a 
% function name
if ischar(likelihood)
    flike = str2func(likelihood);
elseif isa(likelihood, 'function_handle')
    flike = likelihood;
else
    error('Error... Expecting a model function!');
end

% calculate the log likelihood of all the live points
logL = zeros(Nlive,1);
extraparvals = [];
for i=1:Nlive
    parvals = cat(1, loopcell(livepoints(i,:))', extraparvals);
    logL(i) = flike(data, model, parnames, parvals);
end

% now scale the parameters, so that uniform parameters range from 0->1, 
% and Gaussian parameters have a mean of zero and unit standard deviation
for i=1:Nlive
    livepoints(i,:) = scale_parameters(prior, livepoints(i,:));
end

% initial tolerance
tol = inf;

% initial width of prior volume (from X_0=1 to X_1=exp(-1/N))
logw = log(1 - exp(-1/Nlive));

% initial log evidence (Z=0)
logZ = -inf; 

% initial information
H = 0; 

% initialize array of samples for posterior
nest_samples = zeros(1,D+1);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% some initial values if MCMC nested sampling is used
% value to scale down the covariance matrix - CAN CHANGE THIS IF REQUIRED
propscale = 0.1; 

%%%%%%%%%%%%%%%
% some initial values if MultiNest sampling is used
h = 1.1; % h values from bottom of p. 1605 of Feroz and Hobson
FS = h; % start FS at h, so ellipsoidal partitioning is done first time
K = 1; % start with one cluster of live points

% get maximum likelihood
logLmax = max(logL);
Bs = zeros(D,D);
VEs = zeros(D,1);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% initialize iteration counter
j = 1;

%figure;

% MAIN LOOP
while tol > tolerance || j <= Nlive

    % expected value of true remaining prior volume X
    VS = exp(-j/Nlive);

    % find minimum of likelihoods
    [logLmin, idx] = min(logL);
    
    % set the sample to the minimum value
    nest_samples(j,:) = [livepoints(idx, :) logLmin];

    % get the log weight (Wt = L*w)
    logWt = logLmin + logw;
    
    % save old evidence and information
    logZold = logZ;
    Hold = H;
    if isnan(H)
        Hold = 0;
    else
        Hold = H;
    end
    
    % update evidence, information, and width
    logZ = logplus(logZ, logWt);
    H = exp(logWt - logZ)*logLmin + ...
        exp(logZold - logZ)*(Hold + logZold) - logZ;
    %logw = logw - logt(Nlive);
    logw = logw - 1/Nlive;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if Nmcmc > 0
 
        % do MCMC nested sampling
 
        % get the Cholesky decomposed covariance of the live points
        % (do every 100th iteration - CAN CHANGE THIS IF REQUIRED)
        if mod(j-1, 100) == 0
            % NOTE that for numbers of parameters >~10 covariances are often
            % not positive definite and cholcov will have "problems".
            %cholmat = cholcov(propscale*cov(livepoints));
        
            % use modified Cholesky decomposition, which works even for
            % matrices that are not quite positive definite
            % from http://infohost.nmt.edu/~borchers/ldlt.html 
            % (via http://stats.stackexchange.com/questions/6364
            % /making-square-root-of-covariance-matrix-positive-definite-matlab
            cv = cov(livepoints);
            [l, d] = mchol(propscale*cv);
            cholmat = l.'*sqrt(d);
            
            %plot3(livepoints(:,1), livepoints(:,2), livepoints(:,3), 'r.');
            %drawnow();
        end
    
        % draw a new sample using mcmc algorithm
        [livepoints(idx, :), logL(idx)] = draw_mcmc(livepoints, cholmat, ...
              logLmin, prior, data, flike, model, Nmcmc, parnames, extraparvals);

    else 

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % do MultiNest nested sampling
        
        % separate out ellipsoids
        if FS >= h
            % NOTE: THIS CODE IS GUARANTEED TO RUN THE 1ST TIME THROUGH
            % calculate optimal ellipsoids        
            [Bs, mus, VEs, ns] = optimal_ellipsoids(livepoints, VS);
            K = length(VEs); % number of ellipsoids (subclusters)

        else
            % simply rescale the bounding ellipsoids
            for k=1:K
                scalefac = max([1 (exp(-(j+1)/Nlive)*ns(k)/Nlive)/VEs(k)]);
 
                % scale bounding matrix and volume
                if scalefac ~= 1
                    Bs((k-1)*D+1:k*D,:) = Bs((k-1)*D+1:k*D,:)*scalefac^(2/D);
                    VEs(k) = scalefac*VEs(k);
                end
           end

        end

        if DEBUG && D==2
           % plot 2-dimensionsal live points and bounding ellipses
           plot_2d_livepoints_with_ellipses(livepoints, Bs, mus);
        end

        % calculate ratio of volumes (FS>=1) and cumulative fractional volume
        Vtot = sum(VEs);
        FS = Vtot/VS;
        fracvol = cumsum(VEs)/Vtot;
        
        % draw a new sample using multinest algorithm
        [livepoints(idx, :), logL(idx)] = draw_multinest(fracvol, ...
              Bs, mus, logLmin, prior, data, flike, model, ...
              parnames, extraparvals);

    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % update maximum likelihood if appropriate
    if logL(idx) > logLmax
        logLmax = logL(idx);
    end
    
    % work out tolerance for stopping criterion
    tol = logplus(logZ, logLmax - (j/Nlive)) - logZ;
    
    % display progress (optional)
    %.....MODIFIED FOR RAT......AVH
%
if verbose
      out = sprintf('log(Z): %.5e, tol = %.5e, K = %d, iteration = %d, H = %d', ...
                 logZ, tol, K, j, H);
      ratSendTextOutput(out);
%             drawnow;
     end
    
    
    %............Modify end......AVH...
    
    % update counter    
    j = j+1;

end

% sort the remaining points (in order of likelihood) and add them on to 
% the evidence
[logL_sorted, isort] = sort(logL);
livepoints_sorted = livepoints(isort, :);

for i=1:Nlive
    logZ = logplus(logZ, logL_sorted(i) + logw);
end

% append the additional livepoints to the nested samples 
nest_samples = [nest_samples; livepoints_sorted logL_sorted];

% rescale the samples back to their true ranges
for i=1:length(nest_samples)
    nest_samples(i,1:end-1) = ...
     rescale_parameters(prior, nest_samples(i,1:end-1));
end

% convert nested samples into posterior samples - nest2pos assumes that the
% final column in the sample chain is the log likelihood
post_samples = nest2pos(nest_samples, Nlive);

return
