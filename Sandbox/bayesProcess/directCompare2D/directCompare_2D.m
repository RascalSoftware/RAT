%Comparison of MCMC, NS and direct calculation.
%Load in the MCMC results.
MCMCresult = load('defaultProject_MCMC_2D.mat');
close all force

NSresult = load('defaultProject_NS_2D');
NSresult = NSresult.defaultProject_NS_2D;
NSresult = NSresult.result;

%Do the direct calculation first.
%Start by converting the R1 project to 
%the R2 case...
[d2oproblem,controls] = r1ToProblemDef('defaultProject_2D_bayesCompare.mat');
[outProb,results] = RAT(d2oproblem,controls);
figure(1); clf
plotRefSLD(outProb, results);
thisChisq = results.calculationResults.sum_chi;
fprintf('Chi squared in %d \n',thisChisq);


%Use a 60 x 60 grid.
%Make an array for the results...
gridSize = 60;
probArray = zeros(gridSize);

%Make a vector of roughness values..
minRough = outProb.paramConstr{1}(1);
maxRough = outProb.paramConstr{1}(2);
roughVector = linspace(minRough, maxRough, gridSize);

%Also background...
minBack = outProb.backgroundConstr{1}(1);
maxBack = outProb.backgroundConstr{1}(2);
backsVector = linspace(minBack, maxBack, gridSize);


%Now for the calculation.
counter = 1;
totalGrid = gridSize^2;

for r = 1:gridSize
    for b = 1:gridSize
        thisBack =  backsVector(b);
        thisRough = roughVector(r);
        d2oproblem.params(1) = thisRough;
        d2oproblem.backgrounds(1) = thisBack;
        [outProblem,results] = RAT(d2oproblem,controls);
        thisChi = results.calculationResults.sum_chi;
        probArray(r,b) = exp(-thisChi/2);
        percent = (counter/totalGrid)*100;
        fprintf('Calculated %1.1f percent \n',percent);
        counter = counter + 1;
    end
end

figure(2); clf
contour(backsVector,roughVector,probArray,'k-');

%Marginalise the distributions...
roughDist = sum(probArray,2);
roughDist = roughDist ./ max(roughDist);
roughDist = [roughVector(:) roughDist(:)];
%figure(3); subplot(1,2,1)


backDist = sum(probArray,1);
backDist = backDist ./ max(backDist);
backDist = [backsVector(:) backDist(:)];
%figure(3); subplot(1,2,2);
plot(backDist(:,1), backDist(:,2));

%Plot the DRAM result...
%MCMCresult = MCMCresult.output;
a = load('mcmcTest_metrHastings_2D.mat');
chain = a.chain;
MCMC_rough = chain(:,1);
MCMC_back = chain(:,2);

[n,bin] = hist(MCMC_rough,30);
n = n ./ max(n);
MCMC_rough_hist.n = n;
MCMC_rough_hist.bin = bin;

[n,bin] = hist(MCMC_back,30);
n = n ./ max(n);
MCMC_back_hist.n = n;
MCMC_back_hist.bin = bin;

figure(3); clf
subplot(1,2,1)
bar(MCMC_rough_hist.bin,MCMC_rough_hist.n,'FaceAlpha',0.4,'EdgeAlpha',0.1)
hold on
plot(roughDist(:,1),roughDist(:,2),'k-','LineWidth',2);

subplot(1,2,2)
bar(MCMC_back_hist.bin,MCMC_back_hist.n,'FaceAlpha',0.4,'EdgeAlpha',0.1)
hold on
plot(backDist(:,1), backDist(:,2),'k-','LineWidth',2);


%Plot the NS result...
NS_post_samples = NSresult.post_samples;

NS_rough = NS_post_samples(:,1);
[n,bin] = hist(NS_rough,30);
n = n ./ max(n);
figure(3)
subplot(1,2,1); hold on
bar(bin,n,'FaceAlpha',0.4,'EdgeAlpha',0.1)

NS_back = NS_post_samples(:,2);
[n,bin] = hist(NS_back,30);
n = n ./ max(n);
figure(3)
subplot(1,2,2); hold on
bar(bin,n,'FaceAlpha',0.4,'EdgeAlpha',0.1)


