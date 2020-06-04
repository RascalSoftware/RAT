


[problem,controls] = r1ToProblemDef('monolayer_7_contrasts_stanLay.mat');
%[problem,controls] = r1ToProblemDef('original_dspc_bilayer.mat');

 num = 10;

controls.parallel = 'single';
disp('Running single');
tic; 
for i = 1:num
[outProb,results] = RAT(problem,controls); 
end
timSingle = toc;


controls.parallel = 'points';
disp('Running points');
tic; 
for i = 1:num
[outProb,results] = RAT(problem,controls); 
end
timPoints = toc;


controls.parallel = 'contrasts';
disp('Running contrasts');
tic; 
for i = 1:num
[outProb,results] = RAT(problem,controls); 
end
timContrasts = toc;


all = [timSingle timPoints timContrasts];

figure(1)
clf
bar(all);
set(gca,'xticklabel',{'Single', 'Points', 'contrasts'})


