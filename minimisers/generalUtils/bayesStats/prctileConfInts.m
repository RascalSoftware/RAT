function confidenceIntervals = prctileConfInts(chain)

CIFn = @(x,p)prctile(x,abs([0,100]-(100-p)/2));

percentile95 = CIFn(chain,95);
percentile65 = CIFn(chain,65);
meanValues = mean(chain);

confidenceIntervals.percentile95 = percentile95;
confidenceIntervals.percentile65 = percentile65;
confidenceIntervals.mean = meanValues;

end