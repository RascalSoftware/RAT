function [bestPars_max,posteriors] = makePosteriorPlots(problemDef,results)


h =figure(1);

% msgBoxTest('waitbar','Plotting posteriors - please wait',[]);
% figure(bayesHandles.hHists);


chain = results.nest_samples;
fitNames = results.fitNames;
numPars = length(fitNames);

rows = ceil(numPars/4);
cols = 4;
posteriors = cell(1,numPars);

for i = 1:numPars
    figure(h);
    subplot(rows,cols,i);

    [N,edges] = histcounts(chain(:,i),30, 'Normalization','pdf');
    edges2 = edges(2:end) - (edges(2)-edges(1))/2;
    N2 = smoothdata(N, 'sgolay');
    
    plot(edges2, N2, 'r-', 'LineWidth', 2);
    hold on
    
    bar(edges2,N);
    thisName = fitNames{i};
    title(thisName);
    drawnow limitrate
    
    maxPos = find(N2 == max(N2));
    if length(maxPos) > 1; maxPos = mean(maxPos); end
    bestPars_max(i) = edges2(maxPos);  % Now maximum position on posterior fit, rather than mean.
    
    % Store the histograms and posteriors for eventual output
    thisPosterior.bins = edges2;
    thisPosterior.bincounts = N;
    posteriors{i} = thisPosterior;

    drawnow;
end

drawnow
%msgBoxTest('close',[],[]);

end 