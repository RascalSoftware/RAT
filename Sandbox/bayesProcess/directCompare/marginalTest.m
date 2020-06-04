
[d2oproblem,controls] = r1ToProblemDef('defaultProject_D2O_bayesCompare.mat');
[outProb,results] = RAT(d2oproblem,controls);

%load MCMC results
mcmc = load('mcmcRun_D2O_bayesCompare');
mcmc = mcmc.output;
chain = mcmc.chain;
names = mcmc.names;
close all force;

%load Calculated results
probArray = load('probArray');
probArray = probArray.probArray;


figure(3); clf; hold on
set(gcf,'position',[909   576   962   482]);
subplot(1,3,1);
rough = chain(:,1);
[n,bin] = hist(rough,30);
n = n./max(n);
bar(bin,n,'FaceAlpha',0.5,'EdgeAlpha',0.2);
hold on;
title(names{1});

subplot(1,3,2);
back = chain(:,2);
[n,bin] = hist(back,30);
n = n ./ max(n);
bar(bin,n,'FaceAlpha',0.5,'EdgeAlpha',0.2);
hold on;
title(names{2});

subplot(1,3,3)
scale = chain(:,3);
[n,bin] = hist(scale,30);
n = n ./ max(n);
bar(bin,n,'FaceAlpha',0.5,'EdgeAlpha',0.2);
title(names{3});


%Make a vector of roughness values..
minRough = outProb.paramConstr{1}(1);
maxRough = outProb.paramConstr{1}(2);
roughVector = linspace(minRough, maxRough, gridSize);

%Also background...
minBack = outProb.backgroundConstr{1}(1);
maxBack = outProb.backgroundConstr{1}(2);
backsVector = linspace(minBack, maxBack, gridSize);

%..and scalefactor
minScale = outProb.scalefactorConstr{1}(1);
maxScale = outProb.scalefactorConstr{1}(2);
scaleVector = linspace(minScale, maxScale, gridSize);

mask = [1 0 0];
newArray = probArray;
for i = 1:3
    if mask(i) == 0
        newArray = trapz(newArray,i);
    end
end
newArrayRoughs = newArray ./ max(newArray);
subplot(1,3,1); hold on
plot(roughVector, newArrayRoughs);

mask = [0 1 0];
newArray = probArray;
for i = 1:3
    if mask(i) == 0
        newArray = trapz(newArray,i);
    end
end
newArray = squeeze(newArray);
newArray = reshape(newArray,[30 1]);
newArrayBacks = newArray ./ max(newArray);
subplot(1,3,2); hold on
plot(backsVector, newArrayBacks);
xlim([1e-6 2e-5]);


mask = [0 0 1];
newArray = probArray;
for i = 1:3
    if mask(i) == 0
        newArray = trapz(newArray,i);
    end
end
newArray = squeeze(newArray);
newArray = reshape(newArray,[30 1]);
newArrayScale = newArray ./ max(newArray);
subplot(1,3,3); hold on
plot(scaleVector, newArrayScale);
xlim([1e-6 2e-5]);





