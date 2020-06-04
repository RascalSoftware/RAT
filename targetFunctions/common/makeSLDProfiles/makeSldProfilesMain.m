problem = load('sldCalc_problem');
problem = problem.problem;
resam = [1 1 1 1 1 1 1];

nbairs = problem.nbairs;
nbsubs = problem.nbsubs;
outLayers = problem.layers;
outSsubs = problem.ssubs;
numberOfContrasts = problem.numberOfContrasts;
repeats = problem.repeatLayers;

for i = 1:7
    sldProfiles = makeSLDProfiles(nbairs(i),nbsubs(i),outLayers{i},outSsubs(i),repeats{i});
    problem.calculations.slds{i} = sldProfiles;
end

figure(1); clf; hold on
for i = 1:7
    sld = problem.calculations.slds{i};
    plot(sld(:,1),sld(:,2));
end


