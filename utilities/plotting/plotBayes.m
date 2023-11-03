function plotBayes(problem, results)

        figure(10); clf; plotRefSLD(problem,results)

        h2 = figure(30); clf; %subplot(1,2,1)
        bayesShadedPlot(problem,results,'fit','average','KeepAxes',true,'interval',65,'q4',false)
        
        h3 = figure(40); clf
        %mcmcplot(results.chain,[],results.fitNames,'hist');
        plotHists(results.chain,results.fitNames,h3,'smooth',true)
        
%         h4 = figure(5); clf; 
%         plotBayesCorrFig(results.chain,results.fitNames,h4)      

        h6 = figure(60); clf
        mcmcplot(results.chain,[],results.fitNames,'chainpanel');
        
end