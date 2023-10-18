

chain = ch;
nCols = size(chain,2);
clear newChain;

chainLength = size(chain,1);
trim = floor(0.9 * chainLength);

for i = 1:nCols
    thisCol = chain(:,i);
    filtCol = chainFilt(thisCol);

    % [f,xi] = ksdensity(hn);
    newChain(:,i) = filtCol(end-trim:end); %f(:);
end

h3 = figure(40); clf
mcmcplot(newChain,[],results.fitNames,'hist');