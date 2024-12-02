function results = parseBayesResults(chain,problemStruct,controls)
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
    values(par,2) = interp1(csu, bins(iu), 0.5-(probarea/2),'linear','extrap');

    % get upper bound on the interval
    values(par,3) = interp1(csu, bins(iu), 0.5+(probarea/2),'linear','extrap');
    
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
refs = cell(numCalcs,1);
slds = cell(numCalcs,1);
for i = 1:numCalcs
    problemStruct.fitParams = chain(i,1:end-1);
    problemStruct = unpackParams(problemStruct);
    result = reflectivityCalculation(problemStruct,controls);
    refs{i} = result.reflectivity;
    slds{i} = result.sldProfiles;
end

%Also calculate the best fit
problemStruct.fitParams = values(:,1);
problemStruct = unpackParams(problemStruct);
result = reflectivityCalculation(problemStruct,controls);
bestFit = result.reflectivity;


%Put the reflectivities for each contrast together
for n = 1:numCalcs
    for i = 1:problemStruct.numberOfContrasts
        %Since array size may vary if qz-shift is fitted
        %interpolate all curves onto the x-range of the first
        thisRef = refs{n}{i};
%         if n == 1
%             referenceRef = thisRef;
%             groupRefs{i}(:,n) = referenceRef(:,2);
%         else
            newRefy = interp1(thisRef(:,1),thisRef(:,2),bestFit{i}(:,1),'linear','extrap');
            groupRefs{i}(:,n) = newRefy;
        %end
    end
end

for i = 1:problemStruct.numberOfContrasts
    range.mins{i} = min(groupRefs{i},[],2);
    range.maxs{i} = max(groupRefs{i},[],2);
end

disp('debug');
debugPlot = 1;
switch debugPlot
    case 1
        figure(1); clf; hold on; set(gca,'YScale','log');set(gca,'YScale','log');set(gca,'XScale','log');
        for i = 1:problemStruct.numberOfContrasts
            if i == 1
                f = 1;
            else
                f = 1/(10^(2*i));
            end
            errorbar(result.shiiftedData{i}(:,1),result.shiftedData{i}(:,2)*f,result.shiftedData{i}(:,3)*f,'b.');
            semilogy(bestFit{i}(:,1),bestFit{i}(:,2)*f,'k-');
            semilogy(bestFit{i}(:,1),range.maxs{i}*f,'r-');
            semilogy(bestFit{i}(:,1),range.mins{i}*f,'r-');
        end
        %set(gca,'Xlim',[0.049 0.4])
end
            
results.bestFits = bestFit;
results.chain = outChain;
results.ranges = range;
results.bestParams = values(:,1);

end
