
sub_rough = 10;
oxide_thick = 20;
oxide_hydration = 0.3;
lipidAPM = 50;
headHydration = 0.1;
bilayerHydration = 0.05;
bilayerRough = 3;
waterThick = 9;

params = [sub_rough,oxide_thick,oxide_hydration,lipidAPM,headHydration,...
bilayerHydration,bilayerRough,waterThick];

bulkIn = 3e-6;
bulkOut = 5e-6;

contrast = 1;

output = customBilayer(params,bulkIn,bulkOut,contrast);
