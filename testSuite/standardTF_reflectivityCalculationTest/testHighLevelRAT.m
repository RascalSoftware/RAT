classdef testHighLevelRAT < matlab.unittest.TestCase
%%
% test_high_level_RAT Class based unit tests for RAT, RATMain,
% singleCalculation & reflectivityCalculationWrapper
% Use the test case for a standard TF reflectivity calculation to test the
% high-level RAT routines. We consider standard layers, custom layers and
% custom XY examples.
%
% Paul Sharp 18/01/23
%
%%
    properties (ClassSetupParameter)
        inputsFile = {'standardLayersInputs.mat', 'customLayersInputs.mat', 'customXYInputs.mat'};
        outputsFile = {'standardLayersOutputs.mat', 'customLayersOutputs.mat', 'customXYOutputs.mat'};
    end

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
    methods (TestClassSetup, ParameterCombination="sequential")

        function loadTestDataInputs(testCase, inputsFile)
            % loadTestDataInputs Read test input data from file
            testCase.inputs = load(inputsFile);

            testCase.problemDefInput = testCase.inputs.inputs.problemDefInput;
            testCase.problemDef = testCase.inputs.inputs.problemDef;
            testCase.problemDefCells = testCase.inputs.inputs.problemDef_cells;
            testCase.problemDefLimits = testCase.inputs.inputs.problemDef_limits;
            testCase.priors = testCase.inputs.inputs.priors;
            testCase.controlsInput = testCase.inputs.inputs.controlsInput;
            testCase.controls = testCase.inputs.inputs.controls; 
        end
        
        function loadTestDataOutputs(testCase, outputsFile)
            % loadTestDataOutputs Read expected values for outputs from file
            testCase.outputs = load(outputsFile);

            testCase.expectedProblem = testCase.outputs.outputs.problem;
            testCase.expectedResult = testCase.outputs.outputs.result;
            testCase.expectedProblemOut = testCase.outputs.outputs.problemOut;
            testCase.expectedResultOut = testCase.outputs.outputs.resultOut;
        end

        function setEmptyBayesResults(testCase)
            % setEmptyBayes Initialise an empty Bayes Results object
            testCase.emptyBayesResults.res = [];
            testCase.emptyBayesResults.chain = [];
            testCase.emptyBayesResults.s2chain = [];
            testCase.emptyBayesResults.ssChain = [];
            testCase.emptyBayesResults.bestPars = [];
        end

        function setCurrentFolder(testCase)
            % setCurrentFolder Set the current folder to be the directory
            % recorded in the test data
            import matlab.unittest.fixtures.CurrentFolderFixture

            testDirectory = testCase.problemDefCells{14}{1}{3};

            % Check if a directory has been recorded, and apply if so
            if strlength(testDirectory) > 0
                testCase.applyFixture(CurrentFolderFixture(testDirectory));
            end
        end

    end

%%
    methods (Test)

        function testRAT(testCase)
            % testRAT Test the highest-level RAT routine
            [problem, result] = RAT(testCase.problemDefInput,testCase.controlsInput);

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
%%
        function testRatParseClasstoStructs_new(testCase)
            % testRATParseClasstoStructs_new Test the routine that converts
            % an input ProjectClass to a struct
            [problem, problem_cells, problem_limits, problem_priors, controls_struct] = RatParseClassToStructs_new(testCase.problemDefInput, testCase.controlsInput);

            testCase.verifyEqual(problem, testCase.problemDef, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(problem_cells, testCase.problemDefCells, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(problem_limits, testCase.problemDefLimits, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(problem_priors, testCase.priors, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(controls_struct, testCase.controls, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        %function testParseResultToStruct(testCase)
            % testParseResultToStruct Test the routine that constructs a
            % results struct
        %    result = parseResultToStruct(testCase.expectedProblem, testCase.expectedResult);
        %    testCase.verifyEqual(result, testCase.expectedResultOut, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        %end


        %function testRATParseOutToProjectClass(testCase)
            % testRATParseOutToProjectClass Test the routine that creates
            % an output problem class

        %    [problemOut, result] = RATparseOutToProjectClass(testCase.problemDefInput, , ~, ~)

        %    testCase.verifyEqual(problemOut, testCase.expectedProblemOut, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        %    testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        %end

    end

end