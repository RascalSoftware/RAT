function scaled = rescaleParameters(prior, params)

% scaled = rescaleParameters(prior, params)
%
% This function will convert from a unit hypercube to the true
% parameter values. For the Gaussian prior inverse transform
% sampling is used to convert from the unit hypercube to a Gaussian.

lp = length(params);

scaled = zeros(1, lp);

for i=1:lp
    priortype = prior(i,1);

    if priortype == 1      %uniform
        p3 = prior(i,4);
        p4 = prior(i,5);
        scaled(i) = params(i)*(p4 - p3) + p3;
    elseif priortype == 2  %gaussian
        p3 = prior(i,2);
        p4 = prior(i,3);
        scaled(i) = p3 + p4*sqrt(2)*erfinv(2.*params(i) - 1.);
    elseif priortype == 3   %jeffreys
        p3 = prior(i,4);
        p4 = prior(i,5);
        scaled(i) = 10^(params(i)*(log10(p4) - log10(p3)) + log10(p3));
    end
end
