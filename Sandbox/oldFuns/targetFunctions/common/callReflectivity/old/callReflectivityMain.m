a = load('testProblem2.mat');
problem = a.problem;
%problem = legacyChanges(problem);

nbairs = problem.nbairs;
nbsubs = problem.nbsubs;
simLimits = problem.simLimits;
repeatLayers = problem.repeatLayers;
allData = problem.shifted_data;
layers = problem.layers;
ssubs = problem.ssubs;
numberOfContrasts = problem.numberOfContrasts;
backs = problem.backgrounds;
res = problem.resolutions;

%[reflectivity{i},Simulation{i}] = callReflectivity(nbairs(i),nbsubs(i),simLimits{i},repeatLayers{i},shifted_data{i},layerSlds{i},outSsubs(i),numberOfContrasts,backgs(i),resols(i));
[reflectivity,Simulation] = callReflectivity_mex(nbairs(1),nbsubs(1),simLimits{1},repeatLayers{1},allData{1},layers{1},ssubs(1),backs(1),res(1));
problem.calculations.reflectivity = reflectivity;
problem.calculations.Simulation = Simulation;

figure(1);
clf
plot(Simulation(:,1),Simulation(:,2),'-')
set(gca,'YScale','log')

% Now do fresnel...
layers{1} = [0 0 0];
nbsubs(1) = 6.35e-6;
simLimits{1} = [0.01 0.9];
[reflectivity,Simulation] = callReflectivity(nbairs(1),nbsubs(1),simLimits{1},repeatLayers{1},allData{1},layers{1},ssubs(1),backs(1),res(1));

figure(1);
clf
plot(Simulation(:,1),Simulation(:,2),'-')
set(gca,'YScale','log')


