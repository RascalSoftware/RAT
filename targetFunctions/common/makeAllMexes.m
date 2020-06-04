path = '/Users/arwelhughes/coding/RAT/';
addpath(path)
addRatPaths;

disp('Mexing backSort');
backSort_makeMex;
disp('Mexing callReflectivity');
callReflectivity_makeMex;
disp('Mexing chiSquared');
chiSquared_makeMex;
disp('Mexing groupLayers');
groupLayers_Mod_makeMex;
disp('Mexing makeSLDProfiles');
makeSLDProfiles_makeMex;
disp('Mexing resampleLayers');
resampleLayers_makeMex;
disp('Mexing shiftData');
shiftdata_makeMex;
disp('Mexing standard_layers_mod');
standard_layers_mod_makeMex;
% disp('Mexing unpackparams');
% unpackPars_makeMex;
