% Try an improved chain filter.....

chain = load('chain');
log_L = load('log_L');
problemDef = load('problemDef');
DREAMPar = load('DREAMPar');

chain = chain.chain;
log_L = log_L.log_L;
problemDef = problemDef.problemDef;
DREAMPar = DREAMPar.DREAMPar;

% Build up the single chain along with LogL
% Combine all chains....
nChains = DREAMPar.N;
lChains = DREAMPar.T;
nPars = DREAMPar.d;
logL = log_L(:,2:end);

collectChains = [];
collectLogL = [];
for i = 1:nChains
    thisChain = chain(:,1:nPars,i);
    thisLogL = logL(:,i);
    collectChains = [collectChains ; thisChain];
    collectLogL = [collectLogL ; thisLogL];
end

% Try the filter
newChain = filterChain(collectChains,collectLogl);



% -----------------------------------------------------------------------

function chain = filterChain(chain,logL)

% Try to remove outliers from the chains.









end



