% Class based unit tests for the CustomXY layer

classdef standardTF_customLayers_tests < matlab.unittest.TestCase

    properties
    % Test data
    customLayersInputs;
    expectedOutputs;
    problemDef;
    problemDef_cells;
    problemDef_limits;
    controls;
    
    expectedProblem;
    expectedResult;
    
    tolerance = 20*eps;
    abs_tolerance = 1e-5;
    end

    methods (TestMethodSetup)
        
        % The inputs are being set


        % Load CustomXY layer inputs and expected outputs
        function customLayersInputs = load_test_data_inputs(testCase)
            % Load inputs
            testCase.customLayersInputs = load('customLayersInputs.mat');
        end
        
        function expectedOutputs = load_test_data_outputs(testCase)
            % Expected outputs
            testCase.expectedOutputs = load('customLayersOutputs.mat');
        end

        % Load problem definition
        function problemDef = setProblemDef(testCase)
            testCase.problemDef = testCase.customLayersInputs.inputs.problemDef;
        end
        
        function problemDef_cells = setProblemDef_cells(testCase)
            testCase.problemDef_cells = testCase.customLayersInputs.inputs.problemDef_cells;
        end
        
        
        function problemDef_limits = setProblemDef_limits(testCase)
            testCase.problemDef_limits = testCase.customLayersInputs.inputs.problemDef_limits;
        end

        function controls = setControl(testCase)
            testCase.controls = testCase.customLayersInputs.inputs.controls;
        end
        
        function expectedProblem = setexpectedProblem(testCase)
            testCase.expectedProblem = testCase.expectedOutputs.outputs.problem;
        end
        
        function expectedResult = setexpectedResult(testCase)
            testCase.expectedResult = testCase.expectedOutputs.outputs.result; 
        end
    end


    methods (Test)
        % MATLAB functions compares exisitng output and "Just run" output. % MEX does the same but with compiled/MEX versions of the functions
        function customLayers_single_MATLAB(testCase)
            % Test if the input is similar to the exercised output

            whichParallel = 'single';
            useCompiled = false;
            
            % Call the function
            [testOutProblem1,testOutResult1] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells, testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            testCase.verifyEqual(testOutProblem1,testCase.expectedProblem,"RelTol",testCase.tolerance);
            testCase.verifyEqual(testOutResult1,testCase.expectedResult,"RelTol",testCase.tolerance);
        end

        function customLayers_single_MEX(testCase)

            % now with the compiled version
            whichParallel = 'single';
            useCompiled = true;
            
            [testOutProblem2,testOutResult2] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            % Check the outputs are the same
            testCase.verifyEqual(testOutProblem2,testCase.expectedProblem,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);          
            testCase.verifyEqual(testOutResult2,testCase.expectedResult,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);
                    
        end

        function customLayers_parallel_points_MATLAB(testCase)
            
            % Test if the input is similar to the exercised output
            whichParallel = 'points';
            useCompiled = false;
            
            % Call the function
            [testOutProblem1,testOutResult1] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            testCase.verifyEqual(testOutProblem1,testCase.expectedProblem,"RelTol",testCase.tolerance);
            testCase.verifyEqual(testOutResult1,testCase.expectedResult,"RelTol",testCase.tolerance);

        end

        function customLayers_parallel_points_MEX(testCase)

            % now with the compiled version
            whichParallel = 'points';
            useCompiled = true;
            [testOutProblem2,testOutResult2] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            % Check the outputs are the same
            testCase.verifyEqual(testOutProblem2,testCase.expectedProblem,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);        
            testCase.verifyEqual(testOutResult2,testCase.expectedResult,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);

        end

        function customLayers_parallel_contrasts_MATLAB(testCase)
            % Test if the input is similar to the exercised output

            whichParallel = 'contrasts';
            useCompiled = false;
            
            % Call the function
            [testOutProblem1,testOutResult1] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            testCase.verifyEqual(testOutProblem1,testCase.expectedProblem,"RelTol",testCase.tolerance);
            testCase.verifyEqual(testOutResult1,testCase.expectedResult,"RelTol",testCase.tolerance);
        end
        
        function customLayers_parallel_contrasts_MEX(testCase)

            whichParallel = 'contrasts';
            useCompiled = true;
            [testOutProblem2,testOutResult2] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            % Check the outputs are the same
            testCase.verifyEqual(testOutProblem2,testCase.expectedProblem,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(testOutResult2,testCase.expectedResult,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            
        end

    end
end

    
    