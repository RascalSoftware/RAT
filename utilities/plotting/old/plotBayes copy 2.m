function plotBayes(problem,results,varargin)


        figure(10); clf; plotRefSLD(problem,results)

        h2 = figure(30); clf; %subplot(1,2,1)
        sf = results.contrastParams.scalefactors;
        bayesShadedPlot_dev2(problem,results,sf,'q4',false,'fit','mean','KeepAxes',true,'interval',1.5)
        
%         subplot(1,2,2);
%         bayesSLDShadedPlot(problem,results,'fit','mean','KeepAxes',true)
        
        h3 = figure(40); clf
        mcmcplot(results.chain,[],results.fitNames,'hist');
        
%         h4 = figure(5); clf; 
%         plotBayesCorrFig(results.chain,results.fitNames,h4)      
        
        h6 = figure(60); clf
        mcmcplot(results.chain,[],results.fitNames,'chainpanel');  


end