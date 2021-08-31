function comparePredIntervals(problem,results,controls)


% Check of MCMCpred and Old method of calculating intervals:

% Set up the imputs for calculations later:
% Need to do the processing from RAT first...
[problemDefProc,problemDef_cells,problemDef_limits,priors,cntrl] = RatParseClassToStructs_new(problem,controls);
checks = cntrl.checks;
[problemDefProc,fitNames] = packparams(problemDefProc,problemDef_cells,problemDef_limits,checks);
cntrl.proc = 'calculate';
cntrl.calcSld = 1;

q4 = true;

% First calculate the limits using the MCMCpred method....
plimProb = {problemDefProc ; cntrl ; problemDef_limits ; problemDef_cells}; 
chain = results.chain;
data = results.shifted_data;
out = mcmcpred_dev(results.bayesRes,chain,[],data,plimProb,500);

pLims = out.predlims;
shifted_data = results.shifted_data;
numberOfContrasts = length(shifted_data);

% Calculate the fit from the 'mean' obtained from mcmc
bestFitMean = results.bayesRes.mean;
numberOfParameters = length(bestFitMean);
problemDefProc.fitpars = bestFitMean;
problemDefProc = unpackparams(problemDefProc,cntrl);
[outProblem,result] = reflectivity_calculation_wrapper(problemDefProc,problemDef_cells,problemDef_limits,cntrl);
result = parseResultToStruct(outProblem,result);
bestRefMean = result.reflectivity;
chiMean = result.calculationResults.sum_chi;

figure(10); clf; hold on
set(gca,'YScale','log','XScale','log');

for i = 1:numberOfContrasts
    
    thisRefMean = bestRefMean{i};
    thisData = shifted_data{i};
    
    switch q4
        case false
            if i == 1
                mult = 1;
            else
                mult = 2^(4*i);
            end
        otherwise
            mult = 2^(4*i);
            thisQ4 = thisData(:,1).^4;
    end
        
    % Get the limits
    theseLims = pLims{i}{:};
    
    % Get the ranges..
    thisMin = theseLims(3,:)./mult;
    thisMax = theseLims(7,:)./mult;
    thisBest = theseLims(5,:)./mult;         % Fit from plim calc at 0.5
    thisBestMean = thisRefMean(:,2)./mult;
    
    thisDataX = thisData(:,1);
    thisDataY = thisData(:,2)./mult;
    thisDataErr = thisData(:,3)./mult;
    
    switch q4
        case true
            thisMin = thisMin(:) .* thisQ4;
            thisMax = thisMax(:) .* thisQ4;
            thisBest = thisBest(:) .* thisQ4;
            thisBestMean = thisBestMean(:) .* thisQ4;
            thisDataY = thisDataY(:) .* thisQ4;
            thisDataErr = thisDataErr(:) .* thisQ4;
    end
    
    errorbar(thisDataX,thisDataY,thisDataErr,'k.');

    %thisMin
    plot(thisData(:,1),thisMin,'-','color',[0.8 0.8 0.8]);
    plot(thisData(:,1),thisMax,'-','color',[0.8 0.8 0.8]);
    %plot(thisData(:,1),thisBest,'k-');
    plot(thisData(:,1),thisBestMean,'g-','LineWidth',2.0);
    fillyy(thisData(:,1),thisMin,thisMax,[0.9 0.9 0.9]);
    
end
title('MCMCPred');


% Now do the same with the 'manual' calculation 
%[best, intervals, posteriors] = calcMCMCstatRefErrors(bayesResults,outProblemDef,problemDef_cells,problemDef_limits,controls);

% Calculate the bestFit_max values (rather than means)
chain = results.chain;
[bestFitMax,posteriors] = findPosteriorsMax(chain);

problemDefProc.fitpars = bestFitMax;
problemDefProc = unpackparams(problemDefProc,cntrl);
[outProblem,result] = reflectivity_calculation_wrapper(problemDefProc,problemDef_cells,problemDef_limits,cntrl);
result = parseResultToStruct(outProblem,result);
chiMax = result.calculationResults.sum_chi;

bestRefMax = result.reflectivity;
bestSldMax = result.sldProfiles;
shifted_data = result.shifted_data;

% % Now calculate the intervals the 'old' way...
% predInt = 0.95; %95% confidence intervals
% intervals_95 = confIntervals(chain,bestFitMax,predInt);
% 
% 
% % % Now Calculate the intervals on reflectivity and SLD
% [refShadedIntervals, sldShadedIntervals, outMessage] = refPredInterval_mod(chain,bestFit,bestSld,intervals_95,...
%     problemDefProc, problemDef_cells,problemDef_limits,cntrl,result);

% Plot this out:
figure(10);
%clf; hold on

for i = 1:numberOfContrasts

    %subplot(1,2,1);
    thisData = shifted_data{i};
    thisRefs = refShadedIntervals{i};
    
    switch q4
        case false
            if i == 1
                mult = 1;
            else
                mult = 2^(4*i);
            end
        otherwise
            mult = 2^(4*i);
            thisQ4 = thisData(:,1).^4;
    end

    thisDataX = thisData(:,1);
    thisDataY = thisData(:,2) ./ mult;
    thisDataErr = thisData(:,3) ./ mult;

    thisRefX = bestRefMax(:,1);
    thisRefY = bestRefMax(:,2) ./ mult;
%     thisRefMin = thisRefs(:,3) ./ mult;
%     thisRefMax = thisRefs(:,4) ./ mult;
%     
    switch q4
        case true
%             thisRefMin = thisRefMin(:) .* thisQ4;
%             thisRefMax = thisRefMax(:) .* thisQ4;
            thisRefY = thisRefY(:) .* thisQ4;
%             thisDataY = thisDataY(:) .* thisQ4;
%             thisDataErr = thisDataErr(:) .* thisQ4;
    end
    
    %errorbar(thisDataX,thisDataY,thisDataErr,'.');
    %hold on
    
    plot(thisRefX,thisRefY,'r-','LineWidth',2.0);
    hold on
    %plot(thisRefX,thisRefMin,'r');
    %plot(thisRefX,thisRefMax,'r');
    
    
%     subplot(1,2,2);
%     hold on
%     thisSlds = sldShadedIntervals{n};
%     plot(thisSlds(:,1),thisSlds(:,2));
%     plot(thisSlds(:,1),thisSlds(:,2),'r-')
%     plot(thisSlds(:,1),thisSlds(:,3),'r-');
    
end
    
% set(gca,'YScale','log','XScale','log');
% title('Manual');
    

%figure(60);
%mcmcplot(results.chain,[],results.fitNames,'hist');




% Now run a simplex....
controls.procedure = 'simplex';
controls.maxIter = Inf;
controls.maxFunEvals = Inf;
%controls.numGenerations = 1000;

[problem,results] = RAT(problem,controls);

% Add the results of this to the graphs.
simplexRefs = results.reflectivity;
simplexPars = results.bestFitPars;

figure(10);

for i = 1:numberOfContrasts

    %subplot(1,2,1);
    thisData = shifted_data{i};
    thisRefs = simplexRefs{i};
    
    switch q4
        case false
            if i == 1
                mult = 1;
            else
                mult = 2^(4*i);
            end
        otherwise
            mult = 2^(4*i);
            thisQ4 = thisData(:,1).^4;
    end

    thisDataX = thisData(:,1);
    thisDataY = thisData(:,2) ./ mult;
    thisDataErr = thisData(:,3) ./ mult;

    thisRefX = thisRefs(:,1);
    thisRefY = thisRefs(:,2) ./ mult;
    
    switch q4
        case true
            thisRefY = thisRefY(:) .* thisQ4;
    end
    
    plot(thisRefX,thisRefY,'b-','LineWidth',2.0);
    hold on
end

legend('','','','Mean','','','','','','','','','','','','Max','','','Simplex');



% Now plot the posteriors to see what the parameter values are in
% each case
nCols = 4;
nRows = ceil(numberOfParameters / nCols);

figure(60); clf; hold on

for i = 1:numberOfParameters
    subplot(nRows,nCols,i);
    
    thisPosterior = posteriors{i};
    h(i) = bar(thisPosterior(:,1),thisPosterior(:,2),'w');
    hold on
    title(fitNames{i});
    
    % Find the Y limits
    ax = get(h(i),'Parent');
    axs(i) = ax;
    yLims = get(ax,'YLim');
    
    % Get the relevant 'best' patrameters
    thisBestMean = bestFitMean(i);
    thisBestMax = bestFitMax(i);
    thisBestSimplex = simplexPars(i);
    
    plot([thisBestMean thisBestMean],yLims,'g-','LineWidth',2.5);
    plot([thisBestMax thisBestMax],yLims,'r-','LineWidth',2.5);
    plot([thisBestSimplex thisBestSimplex],yLims,'b-','LineWidth',2.5);
        
end


fprintf('Simplex chisq is %f \n',results.calculationResults.sum_chi);
fprintf('Mean fit chi squared is %f \n',chiMean);
fprintf('Max fit chi squared is %f \n',chiMax);



end







