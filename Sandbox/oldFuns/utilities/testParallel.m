function testParallel(problem);

controls = controlsDef;

num = 100;

controls.parallel = 'single';
disp('Running single');

timeThese = zeros(1,num);
for i = 1:num
    tic
    [outProb,results] = RAT_new(problem,controls); 
    timeThese(i) = toc;
end
timSingle = sum(timeThese(50:end))/50;


controls.parallel = 'points';
disp('Running points');
timeThese = zeros(1,num);
for i = 1:num
    tic
    [outProb,results] = RAT_new(problem,controls); 
    timeThese(i) = toc;
end
timPoints = sum(timeThese(50:end))/50;


controls.parallel = 'contrasts';
disp('Running contrasts');
timeThese = zeros(1,num);
for i = 1:num
    tic
    [outProb,results] = RAT_new(problem,controls); 
    timeThese(i) = toc;
end
timContrasts = sum(timeThese(50:end))/50;

% controls.parallel = 'all';
% disp('Running all');
% tic; 
% for i = 1:num
% [outProb,results] = RAT(problem,controls); 
% end
% timAll = toc/num;

all = [timSingle timPoints timContrasts];

figure(10); clf; box on
title('RAT Parallelisation Timing Test');
clf
bar(all);
set(gca,'xticklabel',{'Single', 'Points', 'Contrasts'})
ylabel('Time per calculation (s)');


