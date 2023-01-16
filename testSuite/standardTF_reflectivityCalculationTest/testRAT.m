classdef testRAT < matlab.unittest.TestCase
%%
% testRAT Class based unit tests for RAT, RATMain, singleCalculation &
% reflectivityCalculationWrapper
% Use the test case for a standard TF reflectivity calculation to test the
% high-level RAT routines.
%
% testRAT Properties:
%    standardLayersInputs - Test input parameters read from file
%    expectedOutputs - Test Output parameters read from file
%    problemDef - Input Parameters for the test problem
%    problemDefCells - Input cell arays for the test problem
%    problemDefLimits - Input limits for the test problem
%    controls - Instument controls for the input problem
%    expectedProblem - Expected output value of the problemDef struct
%    expectedResult - Expected output value of the results struct
%    tolerance - Relative tolerance when testing for equality of floats.
%                Parameter = 1.0e-12
%    abs_tolerance = Absolute tolerance when testing for equality of floats.
%                    Parameter = 1.0e-5
%
% testRAT Methods:
%    loadTestDataInputs
%    loadTestDataOutputs
%
% Paul Sharp 16/01/23
%
%%
    properties
        standardLayersInputs;
        expectedOutputs;
        problemDef;
        problemDefCells;
        problemDefLimits;
        controls;
        expectedProblem;
        expectedResult;
        tolerance = 1e-12;
        abs_tolerance = 1e-5;
    end

%%
    methods (TestClassSetup)

        function loadTestDataInputs(testCase)
            % loadTestDataInputs Read test input data from file

            testCase.standardLayersInputs = load('standardLayersInputs.mat');

            testCase.problemDef = testCase.stanLayInputs.standardLayersInputs.problemDef;
            testCase.problemDefCells = testCase.stanLayInputs.standardLayersInputs.problemDef_cells;
            testCase.problemDefLimits = testCase.stanLayInputs.standardLayersInputs.problemDef_limits;
            testCase.controls = testCase.stanLayInputs.standardLayersInputs.controls;
        end
        
        function loadTestDataOutputs(testCase)
            % loadTestDataOutputs Read expected values for outputs from file

            testCase.expectedOutputs = load('standardLayersOutput.mat');

            testCase.expectedProblem = testCase.expectedOutputs.standardLayersOutput.problem;
            testCase.expectedResult = testCase.expectedOutputs.standardLayersOutput.result;
        end

    end

%%