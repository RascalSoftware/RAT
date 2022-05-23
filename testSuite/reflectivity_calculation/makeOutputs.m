

inputs = load('customLayersInputs.mat');
inputs = inputs.customLayersInputs;

problemDef = inputs.problemDef;
problemDef_cells = inputs.problemDef_cells;
problemDef_limits = inputs.problemDef_limits;
controls = inputs.controls;

useCompiled = false;
whichParallel = 'single';

[problem,result] = reflectivity_calculation_testing_wrapper(problemDef,problemDef_cells,problemDef_limits,controls,useCompiled,whichParallel);

customLayersOutput.problem = problem;
customLayersOutput.result = result;

save('customLayersOutput','customLayersOutput');