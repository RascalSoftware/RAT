
%Load in the r1 problem and convert it. Call RAT using
%this then plot what we get....
[problem,controls] = r1ToProblemDef('r1Model.mat');
problem.scalefactorFitYesNo = [0 0];

% controls.procedure = 'simplex';
% controls.maxFunEvals = 0;

[outProb,results] = RAT(problem,controls);
plotRefSLD(outProb,results);

oldResolution = results.reflectivity{1};

%Need to replece the 3 column R1 dataset
%with the 4 column version 
[header,data] = hdrload('PLP001536.dat');

%convert this to dq/q
%data(:,4) = data(:,4)./ 2.355; %FWHM to sigma
data(:,4) = data(:,4)./data(:,1);

%Need a resolution-free version of the simulation
%to play with
problem.resolutions = eps;
[outProb,results_zero] = RAT(problem,controls);
plotRefSLD(outProb,results_zero);

%Get this simulation and data
simulation = results_zero.reflectivity{1};
shiftData = results_zero.shifted_data{1};

%Apply the 4 column resolution
fourColResolution = resolution4Column(simulation(:,1),simulation(:,2),data(:,4));

%Apply the single valued resolution for comparison
points = length(simulation(:,1));
singleValResolution = resolution_polly(simulation(:,1),simulation(:,2),0.058,points);

figure(2);
clf
%plot(simulation(:,1),simulation(:,2),'k:');
hold on
plot(simulation(:,1),fourColResolution,'r-');
plot(simulation(:,1),oldResolution,'b-');
set(gca,'YScale','log','XScale','log');
ylim([1e-8 1.2]);
errorbar(shiftData(:,1),shiftData(:,2),shiftData(:,3),'k.');



