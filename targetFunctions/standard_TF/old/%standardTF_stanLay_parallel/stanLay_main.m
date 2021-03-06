inputs = load('stanLay_reflectivityCalculation_inputs.mat');

inputs = inputs.tfInputs;


problemDef = inputs{1};
problemDef_cells = inputs{2};
problemDef_limits = inputs{3};
controls = inputs{4};

[problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_stanLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
