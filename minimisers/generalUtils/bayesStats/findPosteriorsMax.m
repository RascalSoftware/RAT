function [bestParams_max,posteriors] = findPosteriorsMax(chain)

numPars = size(chain,2);
posteriors = cell(1,numPars);

for i = 1:numPars

    [N,edges] = histcounts(chain(:,i),'Normalization','pdf');
    edges2 = edges(2:end) - (edges(2)-edges(1))/2;
    N2 = smoothdata(N, 'sgolay');

    maxPos = find(N2 == max(N2));
    if length(maxPos) > 1 
        maxPos = maxPos(1); 
    end
    bestParams_max(i) = edges2(maxPos);  % Now maximum position on posterior fit, rather than mean.
    
    % Store the histograms and posteriors for eventual output
    thisPosterior = [];
    thisPosterior(:,1) = edges2(:);
    thisPosterior(:,2) = N2(:);
    posteriors{i} = thisPosterior;

end