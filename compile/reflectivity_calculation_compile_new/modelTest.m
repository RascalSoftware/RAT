% model test

mcmcStatFit = load('mcmcStatFit.mat');
mcmcStatFit = mcmcStatFit.mcmcStatFit;

problem = mcmcStatFit.problem;
results = mcmcStatFit.results;

sldProfiles = results.sldProfiles;
bestFitPars = results.bestFitPars;

figure(10); clf; hold on
for i = 1:7
    thisSLD = sldProfiles{i};
    plot(thisSLD(:,1),thisSLD(:,2));
end

