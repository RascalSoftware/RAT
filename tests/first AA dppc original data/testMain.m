clear

sub_rough = 5;
oxideThickness = 30;
oxideCoverage = 0.9;
bilayerPosition = 70;
bilayerCoverage = 1;
bilayerRough = 5;

params(1) = sub_rough;
params(2) = oxideThickness;
params(3) = oxideCoverage;
params(4) = bilayerPosition;
params(5) = bilayerCoverage;
params(6) = bilayerRough;

bulkIn = 2.073e-6;
bulkOut = 0;
contrast = 1;

SLD = DPPC_customXY(params,bulkIn,bulkOut,contrast);

figure(1)
clf
plot(SLD(:,1),SLD(:,2));



