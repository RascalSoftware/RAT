clear
hFig = figure(1); clf

chain = load('chain');
chain = chain.chain;

chain = chain(:,1:10);


plotBayesCorrFig(chain,hFig);

disp('debug');

