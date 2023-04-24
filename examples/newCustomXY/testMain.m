

% Test of customXY bilayer model......

sub_rough = 3;
oxideThickness = 20;
oxideCoverage = 0.8;
waterThick = 7;
headThick = 10;
headSLD = 1.7e-6;
tailsThick = 20;
tailsSLD = -0.4e-6;
meThick = 5;
bilayerRough = 5;
headHydration = 0.3;
bilayerCoverage = 0.9;

params = [sub_rough,...
oxideThickness,...
oxideCoverage,...
waterThick,...
headThick,...
headSLD,...
tailsThick,...
tailsSLD,...
meThick,...
bilayerRough,...
headHydration,...
bilayerCoverage];
    

bulkIn = 2.073e-6;
bulkOuts = [-0.5e-6, 3.5e-6, 6.35e-6];

for i = 1:length(bulkOuts)
    slds{i} = DSPCCustomXY(params,bulkIn,bulkOuts,i);
end

figure(1); clf; hold on
for i = 1:length(slds)
    thisSLD = slds{i};
    plot(thisSLD(:,1),thisSLD(:,2));

end