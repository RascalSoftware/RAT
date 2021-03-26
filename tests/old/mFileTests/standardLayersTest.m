% Check of the standard Layers Calcultion..
%
% In this sheet, we load in an existing SL
% project, and test the various reflectivity 
% calculations options.
%
% AVH. LAst modified 18/5/20



clear

% Load in the R1 Standard Layers project, and 
% convert it to RAT format....
[problem,controls] = r1ToProblemDef('monolayer_7_contrasts_stanLay.mat');

% This makes the to input classes to RAT, with paralellisation set
% to single. Now just run this.
tic;
for i = 1:100
    [outProb,results] = RAT(problem,controls);
end
sing = toc;

% Plot the output to check....
figure(1);
plotRefSLD(outProb,results);

% Now do the same paralelising on points
controls.parallel = 'points';
for i = 1:100
    [outProb,results] = RAT(problem,controls);
end
mul = toc;

figure(2);
plotRefSLD(outProb,results);






