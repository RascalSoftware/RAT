classdef testRATAPI < matlab.unittest.TestCase
%%
% testRATAPI Class based unit tests for RAT API, the reflectivity
% calculation and pre- and post-processing routines.
%
% In this class, we test: RAT, RATMain, singleCalculation,
% reflectivityCalculationWrapper, reflectivityCalculation,
% RatParseClasstoStructs_new, parseResultToStruct,
% RATParseOutToProjectClass
%
% We are using the test cases for a standard TF reflectivity calculation
% to test the routines. We consider standard layers, custom layers and
% custom XY examples. For the reflectivity calculation itself, we consider
% the serial and parallel versions (both points and contrasts), using both
% the MATLAB and compiled (MEX) versions.
%
% Paul Sharp 19/01/23
%
%% Declare properties and parameters

    properties (ClassSetupParameter)
        inputsFile = {'standardLayersInputs.mat', 'customLayersInputs.mat', 'customXYInputs.mat'};     % Input test data
        outputsFile = {'standardLayersOutputs.mat', 'customLayersOutputs.mat', 'customXYOutputs.mat'}; % Output test data
    end

    properties (TestParameter)    
        whichParallel = {'single', 'points', 'contrasts'} % How the reflectivity calculation is parallelised
        useCompiled = {false, true}                       % Choose either the MATLAB or MEX version
    end

    properties
        inputs;                  % Test input parameters read from file
        outputs;                 % Test Output parameters read from file
        problemDefInput;         % Full set of input parameters
        problemDef;              % Input Parameters for the test problem
        problemDefCells;         % Input cell arays for the test problem
        problemDefLimits;        % Input limits for the test problem
        priors;                  % Input priors for the test problem
        controlsInput;           % Instument controls class for the input problem
        controls;                % Instument controls struct for the input problem
        expectedProblem;         % Expected output value of the problem object
        expectedProblemOut;      % Expected output value of the output problem object
        expectedProblemOutStruct % Expected output value of the output problem struct
        expectedResult;          % Expected output value of the results object
        expectedResultOut;       % Expected output value of the output results object
        expectedResultOutStruct  % Expected output value of the output results struct
        expectedBayesResults     % Expected output value of the results object
        tolerance = 1.0e-12;     % Relative tolerance for equality of floats
        abs_tolerance = 1.0e-5;  % Absolute tolerance for equality of floats
    end

%% Read in test data

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
            testCase.expectedProblemOut = testCase.outputs.outputs.problemOut;
            testCase.expectedProblemOutStruct = testCase.outputs.outputs.problemOutStruct;
            testCase.expectedResult = testCase.outputs.outputs.result;
            testCase.expectedResultOut = testCase.outputs.outputs.resultOut;
            testCase.expectedResultOutStruct = testCase.outputs.outputs.resultOutStruct;
            testCase.expectedBayesResults = testCase.outputs.outputs.bayesResults;
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
    methods (Test, ParameterCombination="exhaustive")
%% Test High Level RAT Routines

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

            testCase.verifyEqual(outProblemDef, testCase.expectedProblemOutStruct, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(bayesResults, testCase.expectedBayesResults, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
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

%% Test Reflectivity Calculation Routines

        function testReflectivityCalculation(testCase, whichParallel, useCompiled)
            % reflectivitySerialMATLAB Test a the reflectivity calculation.
            % We will test the serial and parallel (over both points and
            % contrasts) versions of the calculation, using both the MATLAB
            % and comiled (MEX) versions of each.
            
            [problem, result] = reflectivity_calculation_testing_wrapper(testCase.problemDef, testCase.problemDefCells, testCase.problemDefLimits, testCase.controls, useCompiled, whichParallel);

            testCase.verifyEqual(problem,testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result,testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

%% Test Pre- and Post-Processing Routines

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

        function testParseResultToStruct(testCase)
            % testParseResultToStruct Test the routine that partially
            % constructs a results struct
            resultStruct = parseResultToStruct(testCase.expectedProblem, testCase.expectedResult);
            testCase.verifyEqual(resultStruct, testCase.expectedResultOutStruct, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testRATParseOutToProjectClass(testCase)
            % testRATParseOutToProjectClass Test the routine that creates
            % an output problem class
            problemOut = RATparseOutToProjectClass(testCase.problemDefInput, testCase.expectedProblemOutStruct, testCase.expectedProblem, testCase.expectedResult);
            testCase.verifyEqual(problemOut, testCase.expectedProblemOut, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

    end
end