function log_PR = calcLogPrior(x, priors)
% Calculate the log-prior over a set of points.
%
% Parameters
% ----------
% x : array
%     A [nChains x nParams] array, where each row is a point in parameter
%     space.
% priors : array
%     The RAT input prior array, which is an [nParams x 5] array, where row
%     ``i`` is the prior type, mu, sigma, min, max for parameter ``i``.
%
% Returns
% -------
% log_PR : array
%     An [nChains x 1] array of the log-prior for each point.
%

% Our prior is independent for each parameter, 
% so for point (x1, ... xn) in parameter space,
% log(pr(x1, ... xn)) = log(pr1(x1)) + log(pr2(x2)) + ...
% where pr1 is the prior for parameter 1, etc.
sqrt_2pi = sqrt(2*pi);  % useful constant for gaussian priors

% first calculate log(pri(xi)) for each parameter
% we iterate over dimensions as each dimension has consistent prior
for i = 1:height(priors)
    paramPrior = priors(i, :);
    priorType = paramPrior(1);

    if priorType == 1  % uniform
        x(:, i) = -log(paramPrior(5) - paramPrior(4));
    elseif priorType == 2  % gaussian
        % log of Gaussian is -(x - mu)^2 / 2 sigma^2 - log(sqrt(2pi)*sigma)
        x(:, i) = -(((x(:, i) - paramPrior(2)).^2) / (2 * paramPrior(3)^2)) - log(sqrt_2pi * paramPrior(3));
    elseif priorType == 3  % jeffreys (1/x with a normalisation constant)
        x(:, i) = -log(log(paramPrior(5)/paramPrior(4))) - log(x(:, i));
    end
end
% finally, sum log(pr1(x1)) + log(pr2(x2)) + ... to get log(pr) for each chain
log_PR = sum(x, 2);