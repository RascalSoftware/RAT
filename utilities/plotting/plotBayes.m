function plotBayes(problem,results,varargin)


        figure(1); clf; plotRefSLD(problem,results)

        h2 = figure(3); clf
        sf = results.contrastParams.scalefactors;
        bayesShadedPlot_dev(problem,results,sf,'q4',true,'fit','max')
        
        h3 = figure(4); clf
        mcmcplot(results.chain,[],results.fitNames,'hist');
        
%         h4 = figure(5); clf; 
%         plotBayesCorrFig(results.chain,results.fitNames,h4)      
        
        h6 = figure(6); clf
        mcmcplot(results.chain,[],results.fitNames,'chainpanel');  


end