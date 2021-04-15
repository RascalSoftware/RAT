addpath('/home/arwel/Documents/RascalDev/RAT'); %linux
addRatPaths

%a = load('standardLayersProblem.mat');     %Standard Layers Example
a = load('L1 DTSp ANTA hBamAB dCDE POPC +- hSurA.mat');


problem = a.problem;
problem = legacyChanges(problem);

tic
problem = test_reflectivity_calculation(problem);
toc

figure(1); clf; hold on;
for i = 1:problem.numberOfContrasts
    thisData = problem.shifted_data{i};
    mult = 10^(2*i);
    thisData(:,2) = thisData(:,2) / mult;
    thisData(:,3) = thisData(:,3) / mult;
    errorbar(thisData(:,1),thisData(:,2),thisData(:,3),'o');
    thisFit = problem.calculations.Simulation{i};
    thisFit(:,2) = thisFit(:,2) / mult;
    plot(thisFit(:,1),thisFit(:,2));
end
set(gca,'YScale','log','XScale','log','xlim',[0.05 0.4]);


figure(2); clf; hold on
for i = 1:problem.numberOfContrasts
    thisSld = problem.calculations.slds{i};
    plot(thisSld(:,1),thisSld(:,2));
end

%rmRatPaths





