

inputs = load('customXYInputs.mat');
inputs = inputs.customXYInputs;

problemDef = inputs.problemDef;
problemDef_cells = inputs.problemDef_cells;
problemDef_limits = inputs.problemDef_limits;
controls = inputs.controls;

useCompiled = false;
whichParallel = 'single';

[problem,result] = reflectivity_calculation_testing_wrapper(problemDef,problemDef_cells,problemDef_limits,controls,useCompiled,whichParallel);

customXYOutput.problem = problem;
customXYOutput.result = result;

save('customXYOutput','customXYOutput');