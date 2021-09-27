% How To Use the Test Files
% Start by loading in one of the test inputs 

% Load inputs for standard layers
theseInputs = load('customLayersInputs.mat');

% Split the input into the variables needed to call the function
problemDef = theseInputs.customLayersInputs.problemDef;
problemDef_cells = theseInputs.customLayersInputs.problemDef_cells;
problemDef_limits = theseInputs.customLayersInputs.problemDef_limits;
controls = theseInputs.customLayersInputs.controls;


% The inputs control which type of calculation is tested  (standard layers, 
% custom layers or cistom XY). Additionally, we need to pass two parameters controlling 
% parallelisation, and whether to use compiled or not....
whichParallel = 'contrasts';   % Test the single threaded calculation
useCompiled = false;        % Test the matlab code
[testOutProblem1,testOutResult1] = reflectivity_calculation_testing_wrapper(problemDef, problemDef_cells,problemDef_limits,...
                                                                                controls, useCompiled, whichParallel);

% Now run it again using the mex
whichParallel = 'single';
useCompied = true;
[testOutProblem2,testOutResult2] = reflectivity_calculation_testing_wrapper(problemDef, problemDef_cells,problemDef_limits,...
                                                                                controls, useCompiled, whichParallel);
                                                                            
% Asuucessful test should give the same outputs for both...
success = isequal(testOutProblem1,testOutProblem2);
if success
    disp('Comparison passed');
else
    disp('Comparison failed');
end

                                                                            % 