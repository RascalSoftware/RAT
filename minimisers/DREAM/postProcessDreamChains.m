
function collectChains = postProcessDreamChains(chain,nChains,lChains,nPars)

% DREAM has a tendency to accept (via metropolis rule) chains that are in
% the process of exploring beyond the current optimum. This can lead to
% long tails on the marginal posteriors. In this function we remove these
% using Matlab's 'rmoutlier' function. Then we gather the N paralell chains
% into a single chain.

% Collect chains and remove outliers
collectChains = [];     % Final collected chain 
for i = 1:nChains
    thisChain = chain(:,1:nPars,i);

    % Remove the outliers columnwise...
    thisChain = rmoutliers(thisChain);

    % Build up into a single chain...
    collectChains = [collectChains ; thisChain];
end

end