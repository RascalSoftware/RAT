figure(1); clf
sf = results.contrastParams.scalefactors;
mcmcplot(results.chain,[],results.fitNames,'hist');

figure(2); clf
plotRefSLD(problem,results);
