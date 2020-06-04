


NS = load('R2_bayes_results.mat');
MC = load('R1_bayes_results.mat');

NS = NS.result;
MC = MC.R1results;

figure(1);clf;subplot(4,4,1);
R1chain = MC.chain;
R1bestPars = MC.bestPars;
for i = 1:16
    thisPar = R1chain(:,i);
    subplot(4,4,i);
    [n,bin] = hist(thisPar,20);
    n = n./max(n);
    bar(bin,n,'FaceAlpha',0.5,'EdgeAlpha',0.2);
    hold on;
    yscal = get(gca,'YLim');
    x = [R1bestPars(i) R1bestPars(i)];
    plot(x,yscal,'r-');
end

%figure(2);clf;subplot(4,4,1);
R2chain = NS.nest_samples;
%R1bestPars = MC.bestPars;
for i = 1:16
    thisPar = R2chain(:,i);
    [n,bin] = hist(thisPar,20);
    n = n./max(n);
    subplot(4,4,i);
    bar(bin,n,'FaceAlpha',0.5,'EdgeAlpha',0.2)
end

