# Tests
## Testing `reflectivity_calculation`
There are 3 experiment types which need to be tested:
- `Standard_layer`
- `Custom_layers`
- `Custom_XY`

In addition, each must be tested over 3 types of parallelisation:
- Single Cored
- Parallelised over contrasts
- Parallelised over points

And each of these must be tested in both MATLAB and `mex`, giving 18 `reflectivity_calculation` tests.

## Testing wrapper function
The reflectivity calculation has four inputs and two outputs:

```matlab
[problem, result] = reflectivity_calculation(problemDef, problemDef_cells, problemDef_limits, controls);
```

The inputs and outputs will differ between problem types, but should be the same regardless of parallelisation or compilation. 
The testing strategy should first test single cored Matlab for each experiment type, 
and then ensure that the other 5 calculations for each type give the same answer.

Typical inputs for each type are in the testSuite/reflectivity_calculation folder. 
These are `customLayersInputs.mat`, `standardLayersInputs.mat` and `customXYInputs.mat`.
Each one contains a struct which has the relevant inputs for each type.

There is a new wrapper function, which accepts 4 inputs, and two other parameters:

- `whichParallel` – choose with parallelisation. Must be `single`, `points` or `contrasts`
- `useCompiled` – Boolean. Chooses whether the MATLAB or mex is run.

An example of how to launch this is in `usingTests_script.m`, as follows...

```matlab
% How to use the test files
% Start by loading in test inputs

% Load inputs for custom layers:
theseInputs = load('customLayersInputs.mat');

% Split the input into its variables
problemDef = theseInputs.customLayersInputs.problemDef;
problemDef_cells = theseInputs.customLayersInputs.problemDef_cells;
problemDef_limits = theseInputs.customLayersInputs.problemDef_limits;
controls = theseInputs.customLayersInputs.controls;

% The inputs control which type of calculation is tested  (standard layers, 
% custom layers or cistom XY). Additionally, we need to pass two parameters controlling 
% parallelisation, and whether to use compiled or not....
whichParallel = 'contrasts';   % Test the single threaded calculation
useCompiled = false;        % Test the matlab code
[testOutProblem1,testOutResult1] = reflectivity_calculation_testing_wrapper(problemDef, problemDef_cells,problemDef_limits,controls, useCompiled, whichParallel);
 
% Now run it again using the mex
whichParallel = 'single';
useCompiled = true;
[testOutProblem2,testOutResult2] = reflectivity_calculation_testing_wrapper(problemDef, problemDef_cells,problemDef_limits,controls, useCompiled, whichParallel);                                                               
% A successful test should give the same outputs for both...
success = isequal(testOutProblem1,testOutProblem2);
if success
    disp('Comparison passed');
else
    disp('Comparison failed');
end
```

We need to confirm that each experiment type gives equal results
for each combination of parallelisation or compilation settings.