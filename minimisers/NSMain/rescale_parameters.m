function scaled = rescale_parameters(prior, params)

% scaled = rescale_parameters(prior, params)
%
% This function will do the reverse of scale_parameters.

lp = length(params);

scaled = zeros(lp,1);

for i=1:lp
    priortype = prior(i,1);

    if priortype == 1      %uniform
        p3 = prior(i,4);
        p4 = prior(i,5);
        scaled(i) = params(i)*(p4 - p3) + p3;
    elseif priortype == 2  %gaussian
        p3 = prior(i,2);
        p4 = prior(i,3);
        scaled(i) = params(i)*p4 + p3;
    elseif priortype == 3   %jeffreys
        p3 = prior(i,2);
        p4 = prior(i,3);
        scaled(i) = 10^(params(i)*(log10(p4) - log10(p3)) + log10(p3));
    end


    %     priortype = char(prior(i,2));
    %     p3 = prior{i,3};
    %     p4 = prior{i,4};
    %
    %     % currently only handles uniform or Gaussian priors
    %     if strcmp(priortype, 'uniform')
    %         scaled(i) = params(i)*(p4 - p3) + p3;
    %     elseif strcmp(priortype, 'gaussian')
    %         scaled(i) = params(i)*p4 + p3;
    %     elseif strcmp(priortype, 'jeffreys')
    %         scaled(i) = 10^(params(i)*(log10(p4) - log10(p3)) + log10(p3));
    %     end
end
