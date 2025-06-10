function plotBayes(problem, results)

    figure(10); clf; plotRefSLD(problem,results)
    
    figure(30); clf;
    bayesShadedPlot(problem,results,'keepAxes',true,'interval',95,'q4',true)
    
    h3 = figure(40); clf
    plotHists(results,'figure', h3, 'smooth', true)
    
    % h4 = figure(5); clf
    % cornerPlot(results,'figure',h4,'smooth',false)

    figure(60); clf
    plotChain(results);        
end