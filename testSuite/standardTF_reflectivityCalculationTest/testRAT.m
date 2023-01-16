classdef testRAT < matlab.unittest.TestCase
%%
% testRAT Class based unit tests for RAT, RATMain, singleCalculation &
% reflectivityCalculationWrapper
% Use the test case for a standard TF reflectivity calculation to test the
% high-level RAT routines.
%
% Paul Sharp 16/01/23
%
%%
    properties
        inputs;              % Test input parameters read from file
        outputs;             % Test Output parameters read from file
        problemDef;          % Input Parameters for the test problem
        problemDefCells;     % Input cell arays for the test problem
        problemDefLimits;    % Input limits for the test problem
        controls;            % Instument controls for the input problem
        expectedProblem;     % Expected output value of the problem object
        expectedResult;      % Expected output value of the results object
        tolerance = 1.0e-12; % Relative tolerance for equality of floats
        abs_tolerance = 1.0e-5; % Absolute tolerance for equality of floats
    end

%%
    methods (TestClassSetup)

        function loadTestDataInputs(testCase)
            % loadTestDataInputs Read test input data from file

            testCase.inputs = load('standardLayersInputs.mat');

            testCase.problemDef = testCase.inputs.standardLayersInputs.problemDef;
            testCase.problemDefCells = testCase.inputs.standardLayersInputs.problemDef_cells;
            testCase.problemDefLimits = testCase.inputs.standardLayersInputs.problemDef_limits;
            testCase.controls = testCase.inputs.standardLayersInputs.controls;
        end
        
        function loadTestDataOutputs(testCase)
            % loadTestDataOutputs Read expected values for outputs from file

            testCase.outputs = load('standardLayersOutput.mat');

            testCase.expectedProblem = testCase.outputs.standardLayersOutput.problem;
            testCase.expectedResult = testCase.outputs.standardLayersOutput.result;
        end
    end

%%
    methods (Test)
    
        function testSingleCalculation(testCase)
            % testSingleCalculation Test the routine performing a single
            % reflectivity calculation
            [problem, result] = singleCalculation(testCase.problemDef,testCase.problemDefCells,testCase.problemDefLimits,testCase.controls);

            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testReflectivityCalculationWrapper(testCase)
            % testReflectivityCalculationWrapper Test the routine that
            % chooses how to perform the reflectivity calculation

            % Note that the routine is always set to choose the "mex"
            % version of the reflectivity calculation
            [problem, result] = reflectivity_calculation_wrapper(testCase.problemDef,testCase.problemDefCells,testCase.problemDefLimits,testCase.controls);

            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

    end

end