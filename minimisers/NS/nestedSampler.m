function [logZ, nest_samples, post_samples,H] = nestedSampler(data, ...
          nLive, nMCMC, tolerance, flike, model, prior, parnames)
% Perform nested sampling on a given likelihood function and set of data with priors.
%
% Parameters
% ----------
% data : array
%     The problem struct, controls, and problem limits.
% nLive : int
%     The number of live points to use.
% nMCMC : int
%     If 0, use MultiNest to draw points. if >0, use MCMC and differential evolution
%     with ``nMCMC`` chains.
% tolerance : float
%     The tolerance of maximum log-likelihood changes between iterations.
% flike : function
%     The log-likelihood function to use.
% model : function
%     The function handle of a model function to pass to the likelihood function.
% prior : array
%     A cell array of parameter names, prior types, prior parameters, and boundary handling.
% parnames : array
%     The names of the parameters to optimise.
%
% Returns
% -------
% logZ : float
%     The final log-evidence calculated.
% nest_samples : array
%     The full set of points sampled during the run.
% post_samples : array
%     The posterior values of each point in ``nest_samples``.
% H : float
%     The Shannon entropy of the evidence.

% If nMCMC > 0, new samples will be drawn from a proposal using an MCMC 
% and differential evolution. The sampling will stop once the 
% tolerance critereon has been reached. This method is that of Veitch & 
% Vecchio.
%
% If nMCMC = 0, new samples will be drawn from a set of bounding ellipsoids 
% constructed using the MultiNest algorithm for partitioning live points.
%
% The likelihood should be the function handle of a likelihood function to
% use. This should return the log likelihood of the model parameters given
% the data.
% 
% The model should be the function handle of the model function to be
% passed to the likelihood function.
%
% ------------------- STRUCTURE OF PRIOR CHANGED FOR RAT ----------------
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
% -----------------------------------------------------------------------

controls = data{2};

ns = 1;
mus = 1;
cholmat = 1;
coder.varsize('cholmat');

% get the number of parameters from the prior array
D = size(prior,1);

% initialise array of samples for posterior
nest_samples = zeros(1,D+1);
coder.varsize('nest_samples',[1e5 50],[1 1]);

% check certain values are positive integers or zero
if mod(nMCMC, 1) ~= 0 || nMCMC < 0
    coderException(coderEnums.errorCodes.domainError, 'NS Error: nMCMC must be an integer >= 0')
end

if mod(nLive, 1) ~= 0 || nLive < 0
    coderException(coderEnums.errorCodes.domainError, 'NS Error: nLive must be an integer >= 0')
end

% check total number of points is large enough if using MultiNest
if nMCMC == 0 && nLive < D+1
    coderException(coderEnums.errorCodes.domainError, 'NS Error: The number of live points must be larger than the number of fit parameters for MultiNest.'); 
end

% draw the set of initial live points from the unit hypercube
% (they will be rescaled below)
livepoints = rand(nLive, D);

% calculate the log likelihood of all the live points
logL = zeros(nLive,1);
extraparvals = [];
for i=1:nLive
    % rescale parameters based on their priors 
    parvals = rescaleParameters(prior, livepoints(i,:));
    logL(i) = flike(data,parvals);
end


% initial tolerance
tol = inf;

% initial width of prior volume (from X_0=1 to X_1=exp(-1/N))
logw = log(1 - exp(-1/nLive));

% initial log evidence (Z=0)
logZ = -inf; 

% initial information
H = 0; 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% some initial values if MCMC nested sampling is used
% value to scale down the covariance matrix - CAN CHANGE THIS IF REQUIRED
propscale = 0.1; 

%%%%%%%%%%%%%%%
% some initial values if MultiNest sampling is used
% FS is the ratio of the total volume of all our sample ellipsoids
% to the estimated volume of the region from which live points are sampled
% we recalculate the ellipsoids if that ratio is larger than h (i.e. the
% ellipsoids are more than 10% larger than they need to be)
% h is arbitrary; we choose 1.1 in line with
% section 5.2 of Feroz, Hobson & Bridges (https://arxiv.org/pdf/0809.3437)
h = 1.1; 
FS = h; 
coder.varsize('FS');
% number of ellipsoids; doesn't necessarily need to be defined here,
% but coder doesn't recognise that FS >= h is guaranteed on the first iteration
K = 1;  

% get maximum likelihood
logLmax = max(logL);
Bs = zeros(D,D);
VEs = zeros(D,1);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% initialise iteration counter
j = 1;


% MAIN LOOP
while tol > tolerance || j <= nLive

    % expected value of true remaining prior volume X
    VS = exp(-j/nLive);

    % find minimum of likelihoods
    [logLmin, idx] = min(logL);
    
    % set the sample to the minimum value
    % (Need to do some work brcause we are growing nest_samples in a loop)
    if j == 1
        nest_samples(j,:) = [livepoints(idx, :) logLmin];
    else
        toAdd = [livepoints(idx, :) logLmin];
        nest_samples = [nest_samples ; toAdd];
    end
    
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
    logZ = logPlus(logZ, logWt);
    H = exp(logWt - logZ)*logLmin + ...
        exp(logZold - logZ)*(Hold + logZold) - logZ;
    %logw = logw - logt(nLive);
    logw = logw - 1/nLive;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if nMCMC > 0
 
        % do MCMC nested sampling
 
        % get the Cholesky decomposed covariance of the live points
        % (we do this every 100th iteration - this is arbitrary!)
        if mod(j-1, 100) == 0
            % NOTE that for numbers of parameters >~10 covariances are often
            % not positive definite and cholcov will have "problems".
            % use modified Cholesky decomposition, which works even for
            % matrices that are not quite positive definite
            % (via http://stats.stackexchange.com/questions/6364
            % /making-square-root-of-covariance-matrix-positive-definite-matlab
            cv = cov(livepoints);
            [l, d] = mchol(propscale*cv);
            cholmat = l.'*sqrt(d);
        end
    
        % draw a new sample using mcmc algorithm
        [livepoints(idx, :), logL(idx)] = drawMCMC(livepoints, cholmat, ...
              logLmin, prior, data, flike, model, nMCMC, parnames, extraparvals);

    else 

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % do MultiNest nested sampling
        
        if FS >= h
            % NOTE: THIS CODE IS GUARANTEED TO RUN THE 1ST TIME THROUGH
            % calculate optimal ellipsoids        
            [Bs, mus, VEs, ns] = optimalEllipsoids(livepoints, VS);
            K = length(VEs); % number of ellipsoids (subclusters)

        else
            % simply rescale the bounding ellipsoids
            for k=1:K
                scalefac = max([1 (exp(-(j+1)/nLive)*ns(k)/nLive)/VEs(k)]);
 
                % scale bounding matrix and volume
                if scalefac ~= 1
                    Bs((k-1)*D+1:k*D,:) = Bs((k-1)*D+1:k*D,:)*scalefac^(2/D);
                    VEs(k) = scalefac*VEs(k);
                end
            end
        end

        % calculate ratio of volumes (FS>=1) and cumulative fractional volume
        Vtot = sum(VEs);
        FS = Vtot/VS;
        fracvol = cumsum(VEs)/Vtot;
        
        % draw a new sample using multinest algorithm
        [livepoints(idx, :), logL(idx)] = drawMultiNest(fracvol, ...
              Bs, mus, logLmin, prior, data, flike, model, ...
              parnames, extraparvals);

    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % update maximum likelihood if appropriate
    if logL(idx) > logLmax
        logLmax = logL(idx);
    end
    
    % work out tolerance for stopping criterion
    tol = logPlus(logZ, logLmax - (j/nLive)) - logZ;
    
    % display progress (optional)
    if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
        triggerEvent(coderEnums.eventTypes.Message, sprintf('log(Z): %.5e, tol = %.5e, K = %d, iteration = %d, H = %.5e\n', ...
                 logZ, tol, int32(K), int32(j), H));
    end
    if isRATStopped(controls.IPCFilePath)
        if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
            triggerEvent(coderEnums.eventTypes.Message, sprintf('Optimisation terminated by user\n'));
        end
        break;
    end
    % update counter    
    j = j+1;
end

% sort the remaining points (in order of likelihood) and add them on to 
% the evidence
[logL_sorted, isort] = sort(logL);
livepoints_sorted = livepoints(isort, :);

for i=1:nLive
    logZ = logPlus(logZ, logL_sorted(i) + logw);
end

% append the additional livepoints to the nested samples 
nest_samples = [nest_samples; livepoints_sorted logL_sorted];

% rescale the samples back to their true ranges
for i=1:length(nest_samples)
    nest_samples(i,1:end-1) = ...
     rescaleParameters(prior, nest_samples(i,1:end-1));
end

% convert nested samples into posterior samples - nest2pos assumes that the
% final column in the sample chain is the log likelihood
post_samples = nest2pos(nest_samples, nLive);

return
