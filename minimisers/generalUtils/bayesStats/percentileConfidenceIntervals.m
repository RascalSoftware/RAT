function confidenceIntervals = percentileConfidenceIntervals(chain)
% Calculate percentile confidence intervals for a chain.
%
% Parameters
% ----------
% chain : array
%     The chain from an MCMC calculation.
% 
% Returns
% -------
% confidenceIntervals : array
%     The mean and the 65% and 95% confidence intervals for the chain.

CIFn = @(x,p)prctile(x,abs([0,100]-0.5*(100-p)),1);

percentile95 = CIFn(chain,95);
percentile65 = CIFn(chain,65);
meanValues = mean(chain,1);

confidenceIntervals.percentile95 = percentile95;
confidenceIntervals.percentile65 = percentile65;
confidenceIntervals.mean = meanValues;

end
