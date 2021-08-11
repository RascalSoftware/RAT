function [bestPars_max,posteriors] = processPosterors(output)

chain = output.chain;
numPars = size(chain,2);
posteriors = cell(1,numPars);
bestPars_max = zeros(numPars,1);

for i = 1:numPars
    [N,edges] = histcounts(chain(:,i), 'Normalization','pdf');
    edges2 = edges(2:end) - (edges(2)-edges(1))/2;
    N2 = smoothdata(N, 'sgolay');
    
    maxPos = find(N2 == max(N2));
    if length(maxPos) > 1; maxPos = mean(maxPos); end
    bestPars_max(i) = edges2(maxPos);  % Now maximum position on posterior fit, rather than mean.
    
    % Store the histograms and posteriors for eventual output
    thisPosterior.bins = edges2;
    thisPosterior.bincounts = N;
    posteriors{i} = thisPosterior;
end

end 