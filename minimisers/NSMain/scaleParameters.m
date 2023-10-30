function scaled = scaleParameters(prior, params)

% scaled = scaleParameters(prior, params)
%
% This function will scale parameters based on their priors. If a prior is
% uniform over a range then the parameter will be scaled, such that the
% range covers 0->1. If a prior is Gaussian then the parameter will be
% scaled such that it will be a Gaussian with zero mean and unit variance.

lp = length(params);

scaled = zeros(lp,1);

for i=1:lp
    priortype = prior(i,1);

    if priortype == 1      %uniform
        p3 = prior(i,4);
        p4 = prior(i,5);
        scaled(i) = (params(i) - p3)/(p4 - p3);
    elseif priortype == 2  %gaussian
        p3 = prior(i,2);
        p4 = prior(i,3);
        scaled(i) = (params(i) - p3)/p4;
    elseif priortype == 3   %jeffreys
        p3 = prior(i,2);
        p4 = prior(i,3);
        scaled(i) = (log10(params(i)) - log10(p3))/(log10(p4) - log10(p3));
    end
    
end


%     priortype = char(prior(i,2));
%     p3 = prior{i,3};
%     p4 = prior{i,4};
%     
%     % currently only handles uniform or Gaussian priors
%     if strcmp(priortype, 'uniform')
%         scaled(i) = (params(i) - p3)/(p4 - p3);
%     elseif strcmp(priortype, 'gaussian')
%         scaled(i) = (params(i) - p3)/p4;
%     elseif strcmp(priortype, 'jeffreys')
%         scaled(i) = (log10(params(i)) - log10(p3))/(log10(p4) - log10(p3));
%     end
end
