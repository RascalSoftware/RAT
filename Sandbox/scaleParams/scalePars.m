function [scaledParams, scaledConstr] = scalePars(vals,limits)

% Transforms actual value of parameters ont a range between
% 0 and 1, where 0 corresponds to the minimum range of the parameter
% and 1 corresponds the maximum limit. The actual parameter value is
% then transformed to a number between 0 and 1.

nParams = length(vals);
scaledParams = (vals(:) - limits(:,1))./(limits(:,2)-limits(:,1)); % Note enforce column vector
scaledConstr = [zeros(nParams,1) ones(nParams,1)]; 
scaledParams = reshape(scaledParams,1,[]);