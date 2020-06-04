


%NS = load('d2oRunBayes_NS.mat');
%NS = load('d2oRun_bayes_NS_newlogLike.mat');
NS = load('d2oRun_bayes_NS_largeRun.mat');
MC = load('d2oRunBayes.mat'); 
close all force 

NS = NS.result;
MC = MC.output;

figure(1);clf;hold on
R1chain = MC.chain;
R1bestPars = MC.results.mean;
for i = 1:3
    thisPar = R1chain(:,i);
    subplot(1,3,i);
    [n,bin] = hist(thisPar,20);
    n = n./max(n);
    bar(bin,n,'FaceAlpha',0.5,'EdgeAlpha',0.2);
    hold on;
    yscal = get(gca,'YLim');
    x = [R1bestPars(i) R1bestPars(i)];
    plot(x,yscal,'r-');
end

%figure(2);clf;subplot(4,4,1);
R2chain = NS.post_samples;
%R1bestPars = MC.bestPars;
for i = 1:3
    thisPar = R2chain(:,i);
    [n,bin] = hist(thisPar,20);
    n = n./max(n);
    subplot(1,3,i);
    bar(bin,n,'FaceAlpha',0.5,'EdgeAlpha',0.2)
end

