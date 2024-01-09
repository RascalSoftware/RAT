function results = parseBayesResults(chain,problemDef,problemDefCells,controls)
debug = 1;

numPars = size(chain,2)-1;
values = zeros(numPars,3);
outChain = chain;

%Work out the 95% confidence intervals from the cdfs'
for par = 1:numPars
   
    postvals = chain(:,par);

    % histogram the data to get the distribution
    [n, bins] = hist(postvals, 25);%length(postvals));
    maxn = round(mean(find(n==max(n))));
    
    
    switch debug
        case 1
            figure(1);clf;
            hist(postvals,30);
            drawnow
    end
    
    % get the cumulative probability distribution as normalise it
    cs = cumsum(n)/length(postvals);

    % the probability covered by Nsigma (or you could just set
    % e.g. probarea = 0.95, which is close to the 2sigma value)
    Nsigma = 1.5;
    probarea = erf(Nsigma/sqrt(2));

    % get unique values of the cdf (otherwise the interpolation function
    % complains)
    [csu, iu, ju] = unique(cs);

    % get lower bound on the interval
    values(par,2) = interp1(csu, bins(iu), 0.5-(probarea/2));

    % get upper bound on the interval
    values(par,3) = interp1(csu, bins(iu), 0.5+(probarea/2));
    
    %get best value
    %values(par,1) = mean(max(postvals));
    values(par,1) = bins(maxn);
    %disp(values(par,1));

end

%Test of iterative shortest intervals....
disp('Calculating confidence intervals...');
disp('iter debug');
iterRanges = iterShortest(chain,numPars,values);

%Remove any chains which have values outside the 95% confidence interval

% % for CDF's
% for i = 1:numPars
%    outOfRange = chain(:,i) < values(i,2) | chain(:,i) > values(i,3);
%    chain(outOfRange,:) = []; 
% end

%for iterative
for i = 1:numPars
   outOfRange = chain(:,i) < iterRanges.LB(i) | chain(:,i) > iterRanges.UB(i);
   chain(outOfRange,:) = []; 
end

%calculate the reflectivity and SLD for all the in-range fits.
numCalcs = size(chain,1);
allRefs = cell(numCalcs,1);
allSLDs = cell(numCalcs,1);
for i = 1:numCalcs
    problemDef.fitParams = chain(i,1:end-1);
    problemDef = unpackParams(problemDef,controls);
    [problem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);
    allRefs{i} = result{1};
    allSLDs{i} = result{5};
end

%Also calculate the best fit
problemDef.fitParams = values(:,1);
problemDef = unpackParams(problemDef,controls);
[problem,result] = reflectivityCalculation(problemDef,problemDefCells,controls);
bestFit = result{1};


%Put the reflectivities for each contrast together
for n = 1:numCalcs
    for i = 1:problemDef.numberOfContrasts
        %Since array size may vary if qz-shift is fitted
        %interpolate all curves onto the x-range of the first
        thisRef = allRefs{n}{i};
%         if n == 1
%             referenceRef = thisRef;
%             groupRefs{i}(:,n) = referenceRef(:,2);
%         else
            newRefy = interp1(thisRef(:,1),thisRef(:,2),bestFit{i}(:,1));
            groupRefs{i}(:,n) = newRefy;
        %end
    end
end

for i = 1:problemDef.numberOfContrasts
    range.mins{i} = min(groupRefs{i},[],2);
    range.maxs{i} = max(groupRefs{i},[],2);
end

disp('debug');
debugPlot = 1;
switch debugPlot
    case 1
        figure(1); clf; hold on; set(gca,'YScale','log');set(gca,'YScale','log');set(gca,'XScale','log');
        for i = 1:problemDef.numberOfContrasts
            if i == 1
                f = 1;
            else
                f = 1/(10^(2*i));
            end
            errorbar(result{3}{i}(:,1),result{3}{i}(:,2)*f,result{3}{i}(:,3)*f,'b.');
            semilogy(bestFit{i}(:,1),bestFit{i}(:,2)*f,'k-');
            semilogy(bestFit{i}(:,1),range.maxs{i}*f,'r-');
            semilogy(bestFit{i}(:,1),range.mins{i}*f,'r-');
        end
        %set(gca,'Xlim',[0.049 0.4])
end
            
results.bestFits = bestFit;
results.chain = outChain;
results.ranges = range;
results.bestPars = values(:,1);

end
