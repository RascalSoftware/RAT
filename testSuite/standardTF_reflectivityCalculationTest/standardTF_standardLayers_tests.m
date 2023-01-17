% Class based unit tests from matlab.unittest.TestCase
% Run tests on the 'Standard Layers' case of the standard target function

classdef standardTF_standardLayers_tests < matlab.unittest.TestCase

    properties
        % Test data
        stanLayInputs;
        expectedOutputs;
        problemDef;
        problemDef_cells;
        problemDef_limits;
        controls;
        
        expectedProblem;
        expectedResult;
        
        tolerance = 1e-12;
        abs_tolerance = 1e-5;
    end

    methods (TestMethodSetup)
        
        function standLayInputs = load_test_data_inputs(testCase)
            % Load test data
            testCase.stanLayInputs = load('standardLayersInputs.mat');
        end
        
        function expectedOutputs = load_test_data_outputs(testCase)
            % Expected outputs
            testCase.expectedOutputs = load('standardLayersOutputs.mat');
        end
  
        function problemDef = setProblemDef(testCase)
            % Expected outputs
            testCase.problemDef = testCase.stanLayInputs.standardLayersInputs.problemDef;
        end
        
        function problemDef_cells = setProblemDef_cells(testCase)
            testCase.problemDef_cells = testCase.stanLayInputs.standardLayersInputs.problemDef_cells;
        end
        
        
        function problemDef_limits = setProblemDef_limits(testCase)
            testCase.problemDef_limits = testCase.stanLayInputs.standardLayersInputs.problemDef_limits;
        end

        function controls = setControl(testCase)
            testCase.controls = testCase.stanLayInputs.standardLayersInputs.controls;
        end
        
        function expectedProblem = setexpectedProblem(testCase)
            testCase.expectedProblem = testCase.expectedOutputs.standardLayersOutputs.problem;
        end
        
        function expectedResult = setexpectedResult(testCase)
            testCase.expectedResult = testCase.expectedOutputs.standardLayersOutputs.result;
        end
    end


    methods (Test)
    
        function standardLayers_single_MATLAB(testCase)
            % Test if the input is similar to the exercised output

            whichParallel = 'single';
            useCompiled = false;
            
            % Call the function
            [testOutProblem1,testOutResult1] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells, testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            testCase.verifyEqual(testOutProblem1,testCase.expectedProblem,"RelTol",testCase.tolerance);
            testCase.verifyEqual(testOutResult1,testCase.expectedResult,"RelTol",testCase.tolerance);
        end

        function standardLayers_single_MEX(testCase)

            % now with the compiled version
            whichParallel = 'single';
            useCompiled = true;
            
            [testOutProblem2,testOutResult2] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            % Check the outputs are the same
            testCase.verifyEqual(testOutProblem2,testCase.expectedProblem,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);          
            testCase.verifyEqual(testOutResult2,testCase.expectedResult,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);
                       
        end

        function standardLayers_parallel_points_MATLAB(testCase)
            
            % Test if the input is similar to the exercised output
            whichParallel = 'points';
            useCompiled = false;
            
            % Call the function
            [testOutProblem1,testOutResult1] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            testCase.verifyEqual(testOutProblem1,testCase.expectedProblem,"RelTol",testCase.tolerance);
            testCase.verifyEqual(testOutResult1,testCase.expectedResult,"RelTol",testCase.tolerance);

        end

        function standardLayers_parallel_points_MEX(testCase)

            % now with the compiled version
            whichParallel = 'points';
            useCompiled = true;
            [testOutProblem2,testOutResult2] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            % Check the outputs are the same
            testCase.verifyEqual(testOutProblem2,testCase.expectedProblem,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);        
            testCase.verifyEqual(testOutResult2,testCase.expectedResult,"RelTol",testCase.tolerance, "AbsTol", testCase.abs_tolerance);

        end

        function standardLayers_parallel_contrasts_MATLAB(testCase)
            % Test if the input is similar to the exercised output

            whichParallel = 'contrasts';
            useCompiled = false;
            
            % Call the function
            [testOutProblem1,testOutResult1] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDef_cells,testCase.problemDef_limits,...
            testCase.controls, useCompiled, whichParallel);

            testCase.verifyEqual(testOutProblem1,testCase.expectedProblem,"RelTol",testCase.tolerance);
            testCase.verifyEqual(testOutResult1,testCase.expectedResult,"RelTol",testCase.tolerance);
        end
        
        function standardLayers_parallel_contrasts_MEX(testCase)

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
