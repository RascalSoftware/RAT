function plotBayes(problem,results)

        figure(1); clf; plotRefSLD(problem,results)

        h2 = figure(3); clf
        sf = results.contrastParams.scalefactors;
        bayesShadedPlot(h2,results.predlims,results.shifted_data,sf);
        
        h3 = figure(4); clf
        mcmcplot(results.chain,[],results.fitNames,'hist');
        
%         h4 = figure(5); clf; 
%         plotBayesCorrFig(results.chain,results.fitNames,h4)      
        
        h6 = figure(6); clf
        mcmcplot(results.chain,[],results.fitNames,'chainpanel');  


end