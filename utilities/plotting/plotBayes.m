function plotBayes(problem, results)

    figure(10); clf; plotRefSLD(problem,results)
    
    figure(30); clf;
    bayesShadedPlot(problem,results,'keepAxes',true,'interval',95,'q4',false)
    
    h3 = figure(40); clf
    plotHists(results,h3,'smooth',true)
    
    % h4 = figure(5); clf
    % cornerPlot(results,h4,'smooth',false)
    
    figure(60); clf
    mcmcplot(results.chain,[],results.fitNames,'chainpanel');        
end