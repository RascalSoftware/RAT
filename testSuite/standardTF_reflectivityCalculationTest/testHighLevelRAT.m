classdef testHighLevelRAT < matlab.unittest.TestCase
%%
% test_high_level_RAT Class based unit tests for RAT, RATMain,
% singleCalculation & reflectivityCalculationWrapper
% Use the test case for a standard TF reflectivity calculation to test the
% high-level RAT routines.
%
% Paul Sharp 17/01/23
%
%%
    properties
        inputs;              % Test input parameters read from file
        outputs;             % Test Output parameters read from file
        problemDefInput;     % Full set of input parameters
        problemDef;          % Input Parameters for the test problem
        problemDefCells;     % Input cell arays for the test problem
        problemDefLimits;    % Input limits for the test problem
        priors;              % ?????
        controlsInput;       % Input value of instument controls for the input problem
        controls;            % Instument controls for the input problem
        expectedProblem;     % Expected output value of the problem object
        expectedResult;      % Expected output value of the results object
        expectedProblemOut;  % Expected output value of the output problem object
        expectedResultOut;   % Expected output value of the output results object
        emptyBayesResults    % An empty Bayes Results object for comparison
        tolerance = 1.0e-12; % Relative tolerance for equality of floats
        abs_tolerance = 1.0e-5; % Absolute tolerance for equality of floats
    end

%%
    methods (TestClassSetup)

        function loadTestDataInputs(testCase)
            % loadTestDataInputs Read test input data from file
            testCase.inputs = load('standardLayersInputs.mat');

            testCase.problemDefInput = testCase.inputs.standardLayersInputs.problemDefInput;
            testCase.problemDef = testCase.inputs.standardLayersInputs.problemDef;
            testCase.problemDefCells = testCase.inputs.standardLayersInputs.problemDef_cells;
            testCase.problemDefLimits = testCase.inputs.standardLayersInputs.problemDef_limits;
            testCase.priors = testCase.inputs.standardLayersInputs.priors;
            testCase.controlsInput = testCase.inputs.standardLayersInputs.controlsInput;
            testCase.controls = testCase.inputs.standardLayersInputs.controls; 
        end
        
        function loadTestDataOutputs(testCase)
            % loadTestDataOutputs Read expected values for outputs from file
            testCase.outputs = load('standardLayersOutputs.mat');

            testCase.expectedProblem = testCase.outputs.standardLayersOutputs.problem;
            testCase.expectedResult = testCase.outputs.standardLayersOutputs.result;
            testCase.expectedProblemOut = testCase.outputs.standardLayersOutputs.problemOut;
            testCase.expectedResultOut = testCase.outputs.standardLayersOutputs.resultOut;
        end

        function setEmptyBayesResults(testCase)
            % setEmptyBayes Initialise an empty Bayes Results object
            testCase.emptyBayesResults.res = [];
            testCase.emptyBayesResults.chain = [];
            testCase.emptyBayesResults.s2chain = [];
            testCase.emptyBayesResults.ssChain = [];
            testCase.emptyBayesResults.bestPars = [];
        end

    end

%%
    methods (Test)

        function testRAT(testCase)
            % testRAT Test the highest-level RAT routine
            [problem, result] = RAT(testCase.problemDefInput,testCase.controlsInput);

            % Tests fails due to postprocessing of problem and result
            testCase.verifyEqual(problem, testCase.expectedProblemOut, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResultOut, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testRATMain(testCase)
            % testRATMain Test the routine that determines the calculation
            % RAT will perform
            % Note that we test only a single reflectivity calculation at
            % present

            [outProblemDef, problem, result, bayesResults] = RAT_main(testCase.problemDef,testCase.problemDefCells,testCase.problemDefLimits,testCase.controls,testCase.priors);

            % First test is only true for a single calculation
            testCase.verifyEqual(outProblemDef, testCase.problemDef, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(bayesResults, testCase.emptyBayesResults, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

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